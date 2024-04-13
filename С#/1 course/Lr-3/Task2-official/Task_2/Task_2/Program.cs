using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_2
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Введите z:");
            int z = Convert.ToInt32(Console.ReadLine());
            Class1 obj = new Class1(z);
            //double y = obj.func();
            //Console.WriteLine(y);
            obj.func();
            if (z >= -1)
                Console.WriteLine("Ветка №2(x = |z| при z>=-1");
            else Console.WriteLine("Ветка №1(x = -z/3) при z<-1");
        }
    }
}