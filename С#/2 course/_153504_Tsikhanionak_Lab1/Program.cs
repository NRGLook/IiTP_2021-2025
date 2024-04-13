using System;
using _153504_Tsikhanionak_Lab1.Collections;
using _153504_Tsikhanionak_Lab1.Interfaces;
using _153504_Tsikhanionak_Lab1.Entities;
using System.Collections;


//variant #2
namespace Program
{
    public class Program
    {
        static void Main()
        {
            Station station = new Station();
            string name1 = "Tihanenok Ilya", name2 = "Ilya";
            string path1 = "Minsk", path2 = "Vitebsk";
            station.AddTariff(10, path1);
            station.AddTariff(20, path2);
            station.AddPassenger(name1);
            station.BuyTicketToPassenger(name1, path2);
            station.BuyTicketToPassenger(name1, path1);
            station.AddPassenger(name2);
            station.BuyTicketToPassenger(name2, path1);
            station.PrintPassengersByTicketPath(path1);
            var price = station.PriceOfPurchasedTickets(name1);
            if (price != null)
            {
                Console.WriteLine($"Price of purchased tickets by {name1}:" + price.ToString());
            }

        } 
    }
}