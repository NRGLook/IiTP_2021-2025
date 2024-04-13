using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laborotorywork4
{
    class Monthcost
    {
        private int priceOfTarif;
        private int numberOfTarifClient;
        public Monthcost() { }

        private Monthcost(int priceOfTarif)
        {
            this.priceOfTarif = priceOfTarif;
        }
        private Monthcost(int priceMonth, int utilities)
        {
            this.priceOfTarif = priceMonth;
            this.numberOfTarifClient = utilities;
        }

        public void SetUtilities()
        {
            while (!int.TryParse(Console.ReadLine(), out numberOfTarifClient) ||
                numberOfTarifClient > int.MaxValue || numberOfTarifClient < 0) Console.WriteLine("Ошибка ввода! Пожалуйста, попробуйте еще раз: ");
        }
        public void SetPriceofMonth()
        {
            while (!int.TryParse(Console.ReadLine(), out priceOfTarif) ||
                priceOfTarif > int.MaxValue || priceOfTarif < 0) Console.WriteLine("Ошибка ввода! Пожалуйста, попробуйте еще раз: ");
        }
        public string TotalCostAllMonth()
        {
            return (priceOfTarif * numberOfTarifClient).ToString();
        }
        public void UpPrice()
        {
            int buf;
            while (!int.TryParse(Console.ReadLine(), out buf) ||
                buf > int.MaxValue || buf < 0) Console.WriteLine("Ошибка ввода! Пожалуйста, попробуйте еще раз: ");
            priceOfTarif += buf;
        }
        public void DownPrice()
        {
            int buf;
            while (!int.TryParse(Console.ReadLine(), out buf) ||
                buf > priceOfTarif || buf < 0) Console.WriteLine("Ошибка ввода! Пожалуйста, попробуйте еще раз: ");
            priceOfTarif -= buf;
        }
        public int PriceTarif
        {
            get { return priceOfTarif; }
        }
        public int NumberOfTarifsSold
        {
            get { return numberOfTarifClient; }
        }
    }
}

