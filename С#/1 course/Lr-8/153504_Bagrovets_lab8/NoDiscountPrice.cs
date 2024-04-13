using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborotorywork8
{
    internal class NoDiscountPrice : Iknowprice
    {
        private int _price  = 0;

        public NoDiscountPrice(int price)
        {
            _price = price;
        }

        public int GetPrice()
        {
            return _price;
        }

        public void PriceInfo()
        {
            Console.WriteLine("Tarrif without discount");
            Console.WriteLine($"Price - {_price}");
        }
    }
}
