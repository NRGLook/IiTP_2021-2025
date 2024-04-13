using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab3.Entities
{
    public class Journal
    {
        private List<string> eventsInfo = new List<string>();

        public Journal() { }

        public void SaveEventInfo(string info)
        {
            eventsInfo.Add(info);
        }

        public void PrintEventsInfo()
        {
            Console.WriteLine("************Event information**************************");
            eventsInfo.ForEach(e => Console.WriteLine(e));
            Console.WriteLine("*******************************************************");
        }
    }
}
