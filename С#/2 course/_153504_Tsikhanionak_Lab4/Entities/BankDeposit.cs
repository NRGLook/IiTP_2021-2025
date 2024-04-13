using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab4.Entities
{
    public class BankDeposit
    {
        private int period = 200;
        private bool isRepaid = false;
        private string name = string.Empty;

        public BankDeposit(int period, string name, bool isRepaid)
        {
            this.period = period;
            this.name = name;
            this.isRepaid = isRepaid;
        }

        public int Period
        {
            get { return period; }
        }

        public string Name
        {
            get { return name; }
        }

        public bool IsRepaid
        {
            get { return isRepaid; }
        }

        public override string ToString()
        {
            return $"Period: {period}, Name: {name}, isRepaid: {isRepaid}";
        }
    }
}
