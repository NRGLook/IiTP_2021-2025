using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laborotorywork4
{
    class Zhes
    {
        private string ZhesRegion;
        private string ZhesNumber;
        private int numberOfClients;
        private Monthcost Tarif = new Monthcost();
        private static Zhes Zhes1s = null;

        private Zhes() { }
        public void SetZhesRegion()
        {
            ZhesRegion = Console.ReadLine();
        }
        public void SetZhesNumber()
        {
            ZhesNumber = Console.ReadLine();
        }

        public void SetNumberOfClients()
        {
            while (!int.TryParse(Console.ReadLine(), out numberOfClients) ||
                numberOfClients > int.MaxValue || numberOfClients < 0) Console.WriteLine("Ошибка ввода! Пожалуйста, попробуйте еще раз:");
        }
        public void SetUtilities()
        {
            Tarif.SetUtilities();
        }
        public void SetPriceTarif()
        {
            Tarif.SetPriceofMonth();
        }
        public string TotalCostAllMonth()
        {
            return Tarif.TotalCostAllMonth();
        }
        public void UpPrice()
        {
            Tarif.UpPrice();
        }
        public void DownPrice()
        {
            Tarif.DownPrice();
        }
        public string ZhesRegion1
        {
            get { return ZhesRegion; }
        }
        public string ZhesNumber1
        {
            get { return ZhesNumber; }
        }
        public int NumberOfAllClients
        {
            get { return numberOfClients; }
        }
        public int NumberOfTarifsSold
        {
            get { return Tarif.NumberOfTarifsSold; }
        }
        public int PriceTarif
        {
            get { return Tarif.PriceTarif; }
        }
        public static Zhes Initialize()
        {
            if (Zhes1s == null) Zhes1s = new Zhes();
            return Zhes1s;
        }
    }
}
