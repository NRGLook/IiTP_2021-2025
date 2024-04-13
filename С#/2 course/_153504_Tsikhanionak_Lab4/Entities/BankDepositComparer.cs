using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab4.Entities
{
    class BankDepositComparer : IComparer<BankDeposit>
    {
        public int Compare(BankDeposit? x, BankDeposit? y)
        {
            if (x == null || y == null)
            {
                throw new ArgumentNullException("Arguments are null");
            }
            return x.Name.CompareTo(y.Name);
        }
    }
}
