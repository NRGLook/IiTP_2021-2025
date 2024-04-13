using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborotorywork8
{
    internal class Airport
    {

        private List<Tarif> tarifservice = new List<Tarif>();

        public int TotalPrice()
        {
            int totalPrice = 0;

            //добавляем тариф в тарифы сервисов
            foreach(Tarif tarifproduct in tarifservice)
            {
                totalPrice += tarifproduct.GetPrice();
            }

            return totalPrice;
        }

        public void TarifInfo()
        {
            foreach(Tarif tarif in tarifservice)
            {
                tarif.Info();
                Console.WriteLine("\n");
            }
        }

        public void AddProduct(Tarif tarif)
        {
            tarifservice.Add(tarif);
        }

        public void FindLowestPrice()
        {
            Console.WriteLine($"Minimal price - {tarifservice.Min(tarif => tarif.GetPrice())}");
        }
    }
}
