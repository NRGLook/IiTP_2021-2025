using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Domain
{
    [Serializable]
    public class LuggageCompartment
    {
        public LuggageCompartment(double capacity, bool isFull)
        {
            Capacity = capacity;
            IsFull = isFull;
        }

        public LuggageCompartment() { }

        public double Capacity
        {
            get; set; 
        }

        public bool IsFull
        {
            get; set;
        }

        public override string ToString()
        {
            return Capacity.ToString() + " " + IsFull.ToString();
        }
    }
}
