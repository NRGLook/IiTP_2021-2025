using System;

namespace FirstTask {
    class Program {
        static void Main(string[] args) {
            int a;
            do
            {
                Console.Write("What are you going to do?\n1 - enter data;\n2 - exit.\n");
                a = Convert.ToInt32(Console.ReadLine());
                if (a != 1)
                {
                    Console.Write("You just close your program.\n");
                    break;
                }
                switch (a)
                {
                    case 1:
                        {
                            double x, y;
                            Console.Write("Enter the number.Program tells you, where is your number.Please, enter coordinates (x and y): ");
                            x = Convert.ToDouble(Console.ReadLine());
                            y = Convert.ToDouble(Console.ReadLine());
                            if ((-15 <= x && x <= 0 && y == 0) || (x == 0 && 0 <= y && y <= -15) || (-15 <= x && x <= 0 && y == -15) || (x == -15 && 0 <= y && y <= -15))
                            {
                                Console.Write("The number is on the border.\n");
                            }
                            else if (-15 < x && x < 0 && y < 0 && y > -15)
                            {
                                Console.Write("The number is inside.(outside the scope of definition).\n");
                            }
                            else
                            {
                                Console.Write("The number is outside.(in the field of definition).\n");
                            }
                            break;
                        }
                    default:
                        {
                            Console.Write("You just close your program.\n");
                            break;
                        }
                }
            }
            while (a == 1 || a==2);
        }
    }
}