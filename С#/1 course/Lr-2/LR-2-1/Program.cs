using System;

namespace FirstTask
{
    class Program
    {
        static void Main(string[] args)
        {
            int x;
            do
            {
                Console.Write("What are you going to do?\n1 - enter data;\n2 - exit.\n");
                x = Convert.ToInt32(Console.ReadLine());
                switch (x)
                {
                    case 1:
                        {
                            double a;
                            Console.Write("Enter the number.Program can help you to know even number or not: ");
                            a = Convert.ToDouble(Console.ReadLine());
                            if (a % 2 == 0)
                            {
                                Console.Write("The number is an even.\n");
                            }
                            else
                            {
                                Console.Write("The number isn't even.\n");
                            }
                            break;
                        }
                    case 2:
                        {
                            Console.Write("You close your program.\n");
                            break;
                        }
                }
            }
            while (x == 1 || x==2);
        }
    }
}
