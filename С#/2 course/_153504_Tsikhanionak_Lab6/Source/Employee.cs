using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Source
{
    public class Employee
    {

        public Employee() { }

        public Employee(int id, bool isDeleted, string name)
        {
            Id = id;
            IsDeleted = isDeleted;
            Name = name;
        }

        public int Id
        {
            get; set;
        }

        public bool IsDeleted
        {
            get; set;
        }

        public string Name
        {
            get; set;
        }

    }
}
