using System.Collections;
using _153504_Tsikhanionak_Lab1.Collections;

namespace _153504_Tsikhanionak_Lab1.Entities
{
    public class Station
    {
        private MyCustomCollection<Passenger> passengers = new MyCustomCollection<Passenger>();
        private MyCustomCollection<Tariff> tariffs = new MyCustomCollection<Tariff>();

        public Station() { }

        public void AddPassenger(string idData)
        {
            passengers.Add(new Passenger(idData));
        }

        public void BuyTicketToPassenger(string passIdData, string path)
        {
            passengers.Reset();
            //find such ticket
            tariffs.Reset();
            Tariff? tariff = null;
            for (int j = 0; j < tariffs.Count; j++)
            {
                var curr = tariffs.Current();
                if (curr.Path == path)
                {
                    tariff = curr;
                    break;
                }
                tariffs.Next();
            }

            if(tariff != null)
            {
                //find passenger
                for (int i = 0; i < passengers.Count; i++)
                {
                    var curr = passengers.Current();
                    if (curr.Id == passIdData)
                    {
                        curr.BuyTicket(tariff);
                        tariff.AddPassenger(curr);
                        return;
                    }
                    passengers.Next();
                }
                Console.WriteLine("There is no passenger with such id data.");
            }
            else
            {
                Console.WriteLine("There is no tariff with such path.");
            }
        }

        public void AddTariff(double price, string path)
        {
            tariffs.Add(new Tariff(price, path));
        }

        public void PrintPassengersByTicketPath(string ticketPath)
        {
            tariffs.Reset();
            for(int i = 0; i < tariffs.Count; i++)
            {
                var curr = tariffs.Current();
                if(curr.Path == ticketPath)
                {
                    Console.WriteLine($"People who will go to {curr.Path}:");
                    curr.PrintPassengers();
                    return;
                }
                tariffs.Next();
            }
            Console.WriteLine("There is no ticket with such path.");
        }

        public double? PriceOfPurchasedTickets(string idData)
        {
            passengers.Reset();
            for(int i = 0; i < passengers.Count; i++)
            {
                var curr = passengers.Current();
                if(curr.Id == idData)
                {
                    return curr.PriceOfPurchasedTickets;
                }
            }
            return null;
        }
    }
}
