using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;

namespace FileService
{
    public class FileSevice<T> : IFileService<T> where T : class
    {
        public IEnumerable<T> ReadFile(string fileName)
        {
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                return JsonSerializer.Deserialize(fs, typeof(List<T>)) as IEnumerable<T>;
            }
        }

        public void SaveData(IEnumerable<T> data, string fileName)
        {
            var json = JsonSerializer.Serialize(data.ToList());
            File.WriteAllBytes(fileName, Encoding.ASCII.GetBytes(json));
        }
    }
}