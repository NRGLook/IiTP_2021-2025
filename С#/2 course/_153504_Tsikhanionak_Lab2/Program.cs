using System;
using _153504_Tihanenok_Lab2.Collections;
using _153504_Tihanenok_Lab2.Interfaces;
using _153504_Tihanenok_Lab2.Entities;
using _153504_Tihanenok_Lab2.Exceptions;
using System.Collections;


//variant #2
namespace Program
{
    public class Program
    {
        public static void Main()
        {
            Station station = new Station();
            Journal journal = new Journal();
            //link event with action
           // station.Modified+=journal.SaveEventInfo;
            //add lambda expression like function
            station.Purchased += (string message) => Console.WriteLine(message);
            //add passengers and tariffs
            station.AddPassenger("Ilya");      //will  
            station.AddPassenger("Sasha");     //be 
            station.AddTariff(100, "Minsk");   //in
            station.AddTariff(200, "Vitebsk"); //journal
            station.BuyTicketToPassenger("Ilya", "Minsk");   //will print
            station.BuyTicketToPassenger("Sasha", "Soligorsk");//in console

            journal.PrintEventsInfo();
            MyCustomCollection<int> list = new MyCustomCollection<int>();
            list.Add(1);
        }
    }

}