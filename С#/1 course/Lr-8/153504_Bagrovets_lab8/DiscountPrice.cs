using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborotorywork8
{
    internal class DiscountPrice : Iknowprice
    {
        private int _price = 0;
        private int _discount = 0;

        public DiscountPrice(int price,int discount)
        {
            _price = price - price * discount / 100;
            _discount = discount;
        }

        public int GetPrice()
        {
            return _price;
        }

        public void PriceInfo()
        {
            Console.WriteLine("Tarrif with discount");
            Console.WriteLine($"Price with discount - {_price}, discount {_discount}%");
        }
    }
}
