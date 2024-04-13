using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborotorywork8
{
    internal class Tarif
    {
        private Iknowprice _price;       //стоимость тарифа
        private string _titleTarif = "";//название тарифа

        //тариф со скидкой
        public Tarif(string title, int price, int discount)
        {
            _titleTarif = title;
            _price = new DiscountPrice(price,discount);
        }

        //тариф без скидки
        public Tarif(string title, int price)
        {
            _titleTarif = title;
            _price = new NoDiscountPrice(price);
        }

        public int GetPrice()
        {
            return _price.GetPrice();
        }
        public void Info()
        {
            Console.WriteLine(_titleTarif);
            _price.PriceInfo();
        }

        
    }
}
