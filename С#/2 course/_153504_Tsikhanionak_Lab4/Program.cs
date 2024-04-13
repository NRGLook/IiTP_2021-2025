using System;
using System.Linq;
using _153504_Tsikhanionak_Lab4.Entities;

namespace _153504_Tsikhanionak_Lab4 
{
    class Program
    {
        static void Main(string[] args)
        {
            List<BankDeposit> bankDeposits = new List<BankDeposit>();
            string[] names = new string[5] { "Alpha", "Tinkoff", "Sber", "Belarus", "Agroprom"};
            int[] periods = new int[5] { 132, 999999, 4841, 256, 4563 };
            for (int i = 0; i < 5; i++)
            {
                bankDeposits.Add(new BankDeposit(periods[i], names[i], i % 2 == 0));
            }
            FileService fileService = new FileService();
            string fileName = "saving.dat", newFileName = "newFile.dat";
            fileService.SaveData(bankDeposits, fileName);

            if(File.Exists(newFileName)) File.Delete(newFileName);
            
            File.Move(fileName, newFileName); //rename file

            List<BankDeposit> bankDepositsList = new List<BankDeposit>();
            foreach (var dep in fileService.ReadFile(newFileName)) // fill new collection from file
            {
                bankDepositsList.Add(dep);
            }

            bankDepositsList = bankDepositsList.OrderBy(dep => dep, new BankDepositComparer()).ToList();

            Console.WriteLine("Not sorted collection:");
            bankDeposits.ForEach(dep => Console.WriteLine(dep));

            Console.WriteLine("\nSorted by name collection:");
            bankDepositsList.ForEach(dep => Console.WriteLine(dep));

            Console.WriteLine("\nSort by period of deposit:");     
            var sortedByPeriod = from dep in bankDepositsList     //sort by period of deposit
                                 orderby dep.Period
                                 select dep;
            //bankDepositsList.OrderBy(dep => dep.Period); using lambda expression
            foreach (var deposit in sortedByPeriod) Console.WriteLine(deposit);
        }
    }
}