using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace secondsem_readyfor1lab
{
    class Person
    {
        public const string type = "Person";
        public string? name;
        public int age;

        public Person() {
            string name1 = "b";
            string name2 = "c";
            int age2=18;
            }
        public void Print()
        {
            Console.WriteLine($"Имя {name} Возвраст {age}");
        }
    }
}
