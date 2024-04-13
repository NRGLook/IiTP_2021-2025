using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using Bank;
using LoremNET;
using Service;

namespace Source
{
    public class Program
    {
        static IProgress<string> progress = new Progress<string>(s => Console.WriteLine(s));
        static Random random = new Random();

        static async Task Main(string[] args)
        {
            BankClient[] bankClients = new BankClient[1000];
            for(int i = 0; i < bankClients.Length; i++)
            {
                int num = random.Next((int)1e9);
                bankClients[i] = new BankClient(num , Lorem.Words(1), num % 3 == 0); //creating clients
            }

            Console.WriteLine($"Thread \"{Thread.CurrentThread.ManagedThreadId}\" starts working.");

            string fileName = "file.json";
            StreamService<BankClient> streamService = new StreamService<BankClient>();
            using (MemoryStream stream = new MemoryStream())
            {
                var task = streamService.WriteToStreamAsync(stream, bankClients, progress);

                //await Task.WhenAll(task);
                await Task.Delay(100);

                var task2 = streamService.CopyFromStreamAsync(stream, fileName, progress);

                await Task.WhenAll(task2);
                int count = await streamService.GetStatisticsAsync(fileName, x => x.OpenedAccount);
                Console.WriteLine($"{count} people opened account in this year.");
            }
        }
    }
}