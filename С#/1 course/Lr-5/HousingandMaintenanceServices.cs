using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LaborotoryWork5
{

    //все функции ЖЭС
   public class HousingandMaintenanceServices
    {
       private static List<TarrifOfServices> poss = new List<TarrifOfServices>(0);
       private static List<Clients> residents = new List<Clients>(0);
       private int currentCus = 0;

        public void AddPrice(string dest, int pr) //добавление стоимости
        {
            TarrifOfServices a = new TarrifOfServices(dest, pr);
            poss.Add(a);
        }
        
        public static List<TarrifOfServices> GetPriceList() //получение стоимости услуг
        { 
            return poss;
        }

        public static List<Clients> GetClients() //получаем клиента
        {
            return residents; 
        }

        public int GetWholeCost() //Получаем всю инфу
        {
            int sum = 0;
            for(int i = 0; i < residents.Count(); i++)
            {
                sum += residents[i].Sum();
            }
            return sum;
        }

        public void AddClient(string n, string p, StatusType t) //добавляем клиента(имя, фамилия и статус)
        {
            Clients cus = new Clients(n, p, t);
            residents.Add(cus);
        }

        public void LogIn(int val) //регистрация клиента
        {
            currentCus = val - 1;
        }

        public void LogOut() // размые
        {
            currentCus = 0;
        }

        public string SearchName(string name) //поиск по имени
        {
            string str = ""; int ind = 0;
            for(int i = 0; i < residents.Count; i++)
            {
                if (name == residents[i].name)
                {
                    ind = i; break;
                }
            }
            str += "\n" + residents[ind].Sum().ToString()
                + "\n" + residents[ind].name + " " + residents[ind].GetTyype() + " " + "\n" + residents[ind].infoaboutClient
                + "\n" + residents[ind].ListT();
            return str;
        }
        public string Clients() //клиенты
        {
            string str = "";

            for(int i = 0; i < residents.Count; i++)
            {
                str += "\n" + (i + 1).ToString() + ":\t" + residents[i].name;
            }


            return str;
        }
        public string Pricee() //стоимость
        {
            string str = "";

            for (int i = 0; i < poss.Count; i++)
            {
                str += "\n" + (i + 1).ToString() + ":\t" + poss[i].Services();
            }


            return str;
        }

        public void SellPrice(int val) //рассчитываем 'зарплату'
        {
            residents[currentCus].BuyService(poss[val - 1].Services());
        }

    }
}
