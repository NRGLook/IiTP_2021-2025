using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Domain
{
    [Serializable]
    public class Station
    {
        public Station() { }
        public Station(double luggageCompartmentCapacity, bool isFull = false)
        {
            LuggageCompartment = new LuggageCompartment(luggageCompartmentCapacity, isFull);
        }

        public Station(double luggageCompartmentCapacity, bool isFull, List<string> directions)
        {
            LuggageCompartment = new LuggageCompartment(luggageCompartmentCapacity, isFull);
            Directions = directions;
        }

        public List<string> Directions
        {
            get; set;
        }

        public LuggageCompartment LuggageCompartment
        {
            get; set;
        }

        public override string ToString()
        {
            return string.Join(" ", Directions) + " " + LuggageCompartment.ToString();
        }
    }
}
