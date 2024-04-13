using System;
namespace FirstTask
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b, x;
            Console.Write("Enter the first number that you are gonna to devide: ");
            a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter the second number that you are gonna to share: ");
            b = Convert.ToDouble(Console.ReadLine());
            x = a / b;
            Console.WriteLine(x);
        }
    }
}