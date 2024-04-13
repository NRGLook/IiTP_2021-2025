using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6
{
    //базовый класс - абстрактный(нет экземпляров)
    abstract class Etanol
    {
        private int volume;
        private string form;
        public Etanol(string Form)
        {
            form = Form;
            Console.WriteLine("\nCreate class 'Etanol'");
        }
        public void Print()
        {
            Console.WriteLine("Volume:" + volume + "     Form:" + form + '\n');
        }

        public void PrintClassEtanol()
        {
            Console.WriteLine("\n(hiding the method)There should be a class here 'Etanol'");
        }

        //объявляем без реализации - реализуем в классе наследнике
        public abstract void increase(int buf);
        public abstract void decrease(int buf);
        public int Volume
        {
            get
            {
                return volume;
            }
            set { volume = value; }
        }
        public string Form
        {
            get { return form; }
        }

    }

}
