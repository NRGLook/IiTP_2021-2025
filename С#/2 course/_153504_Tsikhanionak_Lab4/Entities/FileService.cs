using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using _153504_Tsikhanionak_Lab4.Interfaces;

namespace _153504_Tsikhanionak_Lab4.Entities
{
    public class FileService : IFileService<BankDeposit>
    {
        public IEnumerable<BankDeposit> ReadFile(string fileName)
        {
            using (BinaryReader br = new BinaryReader(File.Open(fileName, FileMode.Open), Encoding.ASCII))
            {
                int period = 0;
                string name = string.Empty;
                bool isRepaid = false;
                while (br.PeekChar() > -1)
                {
                    try
                    {
                        period = br.ReadInt32();
                        name = br.ReadString();
                        isRepaid = br.ReadBoolean();
                    }
                    catch
                    {
                        yield break;
                    }
                    yield return new BankDeposit(period, name, isRepaid);
                }
            }
        }

        public void SaveData(IEnumerable<BankDeposit> data, string fileName)
        {
            if (File.Exists(fileName))
            {
                File.Delete(fileName);
            }
            using (BinaryWriter bw = new BinaryWriter(File.OpenWrite(fileName)))
            {
                foreach (var dep in data)
                {
                    bw.Write(dep.Period);
                    bw.Write(dep.Name);
                    bw.Write(dep.IsRepaid);
                }
            }
        }
    }
}
