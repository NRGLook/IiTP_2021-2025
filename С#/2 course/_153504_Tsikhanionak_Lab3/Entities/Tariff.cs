using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab3.Entities
{
    public class Tariff
    {
        private double price = 10;
        private string path = "Minsk";
        private List<Passenger> passes = new List<Passenger>(); 

        public Tariff(double price, string path)
        {
            this.price = price;
            this.path = path;
        }

        public string Path
        {
            get => path;
        }

        public double Price
        {
            get => price;
        }

        public void AddPassenger(Passenger pass)
        {
            passes.Add(pass);
        }
    }
}
