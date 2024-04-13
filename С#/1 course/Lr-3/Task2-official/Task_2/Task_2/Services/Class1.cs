using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_2
{
    class Class1
    {
        public int z;


        public Class1(int z)
        {
            this.z = z;
        }
        public void func()
        {
            double x;
            if (z < -1)
            {
                x = -z/3;
                Console.WriteLine("x = " + x);
            }
            else
            {
                x = Math.Abs(z);
                Console.WriteLine("x = " + x);
            }
            Console.WriteLine((Math.Log(x+0.5) + Math.Exp(x) + Math.Exp(-x)));
        }
    }
}


