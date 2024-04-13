using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab4.Interfaces
{
    interface IFileService<T>
    {
        IEnumerable<T> ReadFile(string fileName);

        void SaveData(IEnumerable<T> data, string fileName);
    }
}
