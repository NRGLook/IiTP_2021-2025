using System.Collections;
using System;
using _153504_Tsikhanionak_Lab3.Exceptions;

namespace _153504_Tsikhanionak_Lab3.Entities
{
    public class Station
    {
        private List<Passenger> passengers = new List<Passenger>();
        private Dictionary<string, Tariff> tariffs = new Dictionary<string, Tariff>();

        public delegate void Handler(string message);
        public event Handler? Modified;
        public event Handler? Purchased;

        public Station() { }

        public void AddPassenger(string idData)
        {
            passengers.Add(new Passenger(idData));
            Modified?.Invoke($"New Passenger \"{idData}\" was added.");
        }

        public void AddModificationsHandler(Handler handler)
        {
            Modified += handler; 
        }

        public void AddPurchaseHandler(Handler handler)
        {
            Purchased += handler;
        }

        public void BuyTicketToPassenger(string passIdData, string path)
        {
            if (tariffs.ContainsKey(path))
            {
                Tariff? tariff = tariffs[path]; //find such ticket
                var pass = passengers.Find(p => p.Id == passIdData); //find passenger
                if(pass == null)
                {
                    Console.WriteLine("There is no passenger with such id data.");
                }
                else
                {
                    pass.BuyTicket(tariff);
                    tariff.AddPassenger(pass);
                    //emit event
                    Purchased?.Invoke($"{pass.Id} purchase a ticket to {tariff.Path}.");
                }
            }
            else
            {
                Console.WriteLine("There is no tariff with such path.");
            }
        }

        public void AddTariff(double price, string path)
        {
            tariffs.Add(path, new Tariff(price, path));
            Modified?.Invoke($"New Tariff to {path} with price {price} was added.");
        }

        public double PriceOfAllPurchasedTickets()
        {
            return passengers.Sum(p => p.GetPriceOfPurchasedTickets());    
        }

        public double PriceOfPurchasedByPassTickets(string id)
        {
            var res = passengers.FirstOrDefault(p => p.Id == id)?.GetPriceOfPurchasedTickets();
            return  res.HasValue 
                ? res.Value
                : throw new ValueNotFoundException($"There is no passenger with id {id}.");   
        }

        public List<string> GetAllTariffsSortedByPrice()
        {
            return tariffs.OrderBy(p => p.Value.Price).Select(p => p.Key).ToList();
        }

        public string? GetIdOfPassWhoPaidMaxSum()
        {
            return passengers.MaxBy(p => p.GetPriceOfPurchasedTickets())?.Id;
        }

        public int GetAmountOfPassesWhoPaidMoreThan(double value)
        {
            return passengers.Aggregate(0, (ans, p) => ans += p.GetPriceOfPurchasedTickets() > value ? 1 : 0);
        }

        public IEnumerable<(string Direction, double Price)> GetSumListForEachPath(string passId)
        {
            var pass = passengers.FirstOrDefault(p => p.Id == passId);
            if(pass == null) throw new ValueNotFoundException($"There is no passenger with id {passId}.");
            return pass.PurchasedTickets.GroupBy(t => t.Path).Select(g=>(g.Key, g.Sum(t=>t.Price)));
        }
    }
}
