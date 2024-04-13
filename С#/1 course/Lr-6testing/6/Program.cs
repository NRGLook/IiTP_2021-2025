using System;

namespace _6
{
    class Program
    {
        static void Main(string[] args)
        {
            Antiseptic Antiseptic = new Antiseptic("The average glass", "Drunk cherry: ");
            Antiseptic.milliliters = 500;
            Antiseptic.Volume = 600;
            Rasolforcucucmbers cocktail = new Rasolforcucucmbers("Usual glass", "Drunk cherry: ", 50);
            cocktail.amount = 3;
            cocktail.milliliters = 450;
            cocktail.Volume = 500;

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("Overloading the parent method");
            Console.WriteLine("Rasolforcucucmbers.Print()");
            cocktail.Print();
            Console.WriteLine("Rasolforcucucmbers.Print(int)");
            cocktail.Print(3);

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("Virtual method");
            Console.WriteLine("Composition.PrintInfo()");
            Antiseptic.PrintInfo();
            Console.WriteLine("\nRasolforcucucmbers.PrintInfo()");
            cocktail.PrintInfo();

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("Hiding method");
            Console.WriteLine("public new void PrintClassEtanol()");
            Antiseptic.PrintClassGlass();

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("Abstract method");
            Console.WriteLine("milliliters = " + cocktail.milliliters);
            Console.WriteLine("public abstract void increase(int buf)");
            cocktail.increase(25);
            Console.WriteLine("milliliters = " + cocktail.milliliters);
            Console.WriteLine("public abstract void decrease(int buf)");
            cocktail.decrease(70);
            Console.WriteLine("milliliters = " + cocktail.milliliters);
        }
    }
}
