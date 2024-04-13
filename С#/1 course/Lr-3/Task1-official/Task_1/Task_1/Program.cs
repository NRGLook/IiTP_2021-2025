using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Введите точку, в которой хотим узнать значение функции(точка A):");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите точку, в которой хотим узнать значение функции(точка B):");
            double b = Convert.ToDouble(Console.ReadLine());
            Classfortask1 obj = new (a,b);
            obj.minimum ();
            Console.WriteLine("Результат в точке A и B соответственно:");
            Console.WriteLine(obj.resultationa);
            Console.WriteLine(obj.resultationb);
        }
    }
}
