using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Domain;

namespace _Serializer
{
    interface ISerializer
    {
        IEnumerable<Station> DeSerializeByLINQ(string fileName);
        IEnumerable<Station> DeSerializeByXML(string fileName);
        IEnumerable<Station> DeSerializeByJSON(string fileName);
        void SerializeByLINQ(IEnumerable<Station> value, string fileName);
        void SerializeByXML(IEnumerable<Station> value, string fileName);
        void SerializeByJSON(IEnumerable<Station> value, string fileName);
    }
}
