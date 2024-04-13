using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6
{
    //запрещаем наследоваться от нашего класса
    sealed class Rasolforcucucmbers : Antiseptic
    {
        public Rasolforcucucmbers(string Form, string CompositionOfСocktail, int Price) : base(Form, CompositionOfСocktail)
        {
            Console.WriteLine("Create class 'Rasolforcucucmbers'\nEtanol <- Antiseptic <- Rasolforcucucmbers");
            price = Price;
        }
        private int price;
        public int amount = 1;

        //переопределяем функция принтинфо
        public override void PrintInfo()
        {
            base.PrintInfo();//отразит новую информацию - о новом объеме
            Console.WriteLine("Total cost: " + price * amount);
        }
    }
}
