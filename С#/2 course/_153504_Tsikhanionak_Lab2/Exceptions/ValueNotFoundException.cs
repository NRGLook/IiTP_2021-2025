using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tihanenok_Lab2.Exceptions
{
    public class ValueNotFoundException : Exception
    {
        public ValueNotFoundException(string message)
        : base(message) { }
    }
}
