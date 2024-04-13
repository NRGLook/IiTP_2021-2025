using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Tihanenok_Lab2.Collections;

namespace _153504_Tihanenok_Lab2.Entities
{
    public class Passenger
    {
        private string idData = "Kirya";
        private double priceOfPurchasedTickets = 0;

        public Passenger(string idData)
        {
            this.idData = idData;
        }

        public string Id
        {
            get => idData;
        }

        public double PriceOfPurchasedTickets
        {
            get => priceOfPurchasedTickets;
        }

        public void BuyTicket(Tariff ticket)
        {
            priceOfPurchasedTickets += ticket.Price;
        }
    }
}
