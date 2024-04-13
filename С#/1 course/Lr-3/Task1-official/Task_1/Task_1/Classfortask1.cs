using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    class Classfortask1
    {
        public double resultationa;
        public double resultationb;
        public double a,b;
        public Classfortask1(double a, double b)
        {
            this.a = a;
            this.b = b;
        }
        public void minimum()
        {
            resultationa = a - Math.Sin(a);
            resultationb = b - Math.Cos(b);
            if (resultationb == resultationa) Console.WriteLine("Полученный результат:A=B");
            else if (resultationa > resultationb) Console.WriteLine("Полученный результат:A>B");
            else if (resultationa < resultationb) Console.WriteLine("Полученный результат:A<B");        }
    }
}
