using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LaborotoryWork5
{
   public class TarrifOfServices
    {
        string services;// тариф
        int price;// стоимость тарифа
        public TarrifOfServices(string a, int b)
        {
            services = a;
            price = b;
        }
        public string Services()
        {
            return services;
        }
        public int Price()
        {
            return price;
        }
    }
}
