using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Tsikhanionak_Lab1.Collections;

namespace _153504_Tsikhanionak_Lab1.Entities
{
    public class Tariff
    {
        private double price = 10;
        private string path = "Minsk";
        private MyCustomCollection<Passenger> passes = new MyCustomCollection<Passenger>();
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

        public void PrintPassengers()
        {
            passes.Reset();
            for(int i = 0; i < passes.Count; i++)
            {
                Console.WriteLine(passes.Current().Id);
                passes.Next();
            }
        }

        public void AddPassenger(Passenger pass)
        {
            passes.Add(pass);
        }
    }
}
