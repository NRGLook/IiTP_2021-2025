using System.Runtime.Serialization.Formatters.Binary;
using System.Text.Json;

namespace Service
{
    public class StreamService<T>
    {
        Semaphore mutex = new Semaphore(1,1);
        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
        {
            progress.Report($"Start writing to thread \"{Thread.CurrentThread.ManagedThreadId}\"");
            
            mutex.WaitOne();
            await JsonSerializer.SerializeAsync(stream, data);
            

            await Task.Run(() => Process());    

            progress.Report($"\nEnd writing to thread \"{Thread.CurrentThread.ManagedThreadId}\"");
            mutex.Release();
        }

        public async Task CopyFromStreamAsync(Stream stream, string fileName, IProgress<string> progress)
        {
            mutex.WaitOne();
            progress.Report($"Start reading from thread \"{Thread.CurrentThread.ManagedThreadId}\"");

            
            using (FileStream file = new FileStream(fileName, FileMode.Create))
            {
                stream.Position = 0;
                await stream.CopyToAsync(file);   
            }

            
            await Task.Run(() => Process());
            
            progress.Report($"\nEnd reading from thread \"{Thread.CurrentThread.ManagedThreadId}\"");
            mutex.Release();
        }

        public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
        {
            using FileStream file = new FileStream(fileName, FileMode.Open);

            IEnumerable<T> temp = await JsonSerializer.DeserializeAsync<IEnumerable<T>>(file);

            return temp.Where(filter).Count();
        }

        private async Task Process()
        {
            var p = new Progress<string>(m =>
            {
                Console.Write($"\rThread \"{Thread.CurrentThread.ManagedThreadId}\" {m}");
            });

            await GetProgress(p);
        }

        private async Task GetProgress(IProgress<string> progress)
        {
            for (int i = 0; i <= 100; i += 10)
            {
                await Task.Delay(200);
                progress?.Report(new string($"Ended on : {i} %"));
            }
        }
    }
}