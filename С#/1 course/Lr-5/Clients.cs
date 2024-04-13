using System;
using System.Collections.Generic;//подключаем обобщ коллекции
using System.Linq;//запросы
using System.Text;
using System.Threading.Tasks;//инструменты многопоточности

namespace LaborotoryWork5
{
    // выбираем тариф клиента
   public enum StatusType { StandartStatus, StatuswithDiscount, StatuforElederpeople }//определяем тип перечисления (по умолчанию int)
   public class Clients
    {
        private List <TarrifOfServices> priceTariff = new List <TarrifOfServices> (0); //не просто создаем, но и указываем тип 
        public string name;
        public string statustype;// статус клиента
        public string infoaboutClient;

        public Clients(string name, string infoClient, StatusType type)
        {
            this.infoaboutClient = infoClient;
            this.name = name;
            switch (type)
            {
                case StatusType.StatuforElederpeople:
                    {
                        statustype = "Status for elder people.";
                        break;
                    }
                case StatusType.StandartStatus:
                    {
                        statustype = "Standart Status.";
                        break;
                    }
                case StatusType.StatuswithDiscount:
                    {
                        statustype = "Status with Discount.";
                        break;
                    }
            }
        }

        //добавление сервисов
        public void BuyService(string PriceServices)
        {
            string a = ""; int b = 0;
            for(int i = 0; i<HousingandMaintenanceServices.GetPriceList().Count; i++)
            {
                if(PriceServices == HousingandMaintenanceServices.GetPriceList()[i].Services())
                {
                    a = PriceServices;
                    b = HousingandMaintenanceServices.GetPriceList()[i].Price();
                }
            }

            TarrifOfServices t = new TarrifOfServices(a, b);
            priceTariff.Add(t);
        }

        public string ListT()
        { 
            string str = "";
            for(int i = 0; i < priceTariff.Count(); i++)
            {
                str += priceTariff[i].Services() + "\t"+ priceTariff[i].Price().ToString() + "\n";
            }
            return str + "\n";
        }

        //подсчет сервисов
        public int Sum()
        {
            int sum = 0;
            for (int i = 0; i < priceTariff.Count; i++)
            {
                sum += priceTariff[i].Price();
            }
            return sum;
        }

        public string  GetTyype()
        {
            return statustype;
        }
        
    }
}
