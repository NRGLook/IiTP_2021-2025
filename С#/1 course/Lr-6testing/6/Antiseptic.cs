using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6
{
    class Antiseptic : Etanol
    {
        private string compositionOfСocktail;
        public int milliliters;

        public Antiseptic(string Form, string CompositionOfСocktail) : base(Form)
        {
            Console.WriteLine("Create class 'Antiseptic'\nClass <- Antiseptic");
            compositionOfСocktail = CompositionOfСocktail;
        }

        //перегрузка
        public void Print(int buf)
        {
            Console.WriteLine("Повтор " + buf + " раз");
            for (int a = 0; a < buf; a++)
            {
                Console.WriteLine("CompositionOfСocktail: " + compositionOfСocktail + "Milliliters: " + milliliters);
            }
        }

        public virtual void PrintInfo()
        {
            Console.WriteLine("Volume - milliliters = " + (Volume - milliliters));
        }
        public override void increase(int buf)
        {
            milliliters += buf;
        }
        public override void decrease(int buf)
        {
            milliliters -= buf;

        }

      //public new void PrintClassGlass() new - если скрывает доступный метод
        static public void PrintClassGlass()//статик так как мы не  обращаемся к данным экземпляров
        {
            Console.WriteLine("(hiding the method) There should be an 'Etanol' class here, but it's 'Antiseptic'");
        }
    }
}
