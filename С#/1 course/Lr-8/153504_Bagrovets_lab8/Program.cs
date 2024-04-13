using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborotorywork8
{
    internal class Program
    {
        public static void Main()
        {
            Airport store = new Airport();

            store.AddProduct(new Tarif("Minsk", 100));
            store.AddProduct(new Tarif("Kiev", 230, 70));//название - цена - скидка

            store.FindLowestPrice();
        }
    }
}
