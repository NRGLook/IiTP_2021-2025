using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab3.Exceptions
{
    public class ValueNotFoundException : Exception
    {
        public ValueNotFoundException(string message)
        : base(message) { }
    }
}
