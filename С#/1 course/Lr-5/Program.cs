using System;

namespace LaborotoryWork5
{
    class Program
    {
        static void Main(string[] args)
        {
            HousingandMaintenanceServices Boss = new HousingandMaintenanceServices();// создаем 'объект ЖЭС'
            int action = 0;
            //через do-while чтобы удобнее было работать с выбором через ввод + релизуем ввод
            do
            {
                Console.Clear();
                Console.WriteLine("Choose option that you are gonna to do:" +
                    "\n1: Add services(tarrif). " +
                    "\n2: Add client. " +
                    "\n3: Search by client. " +
                    "\n4: Choose a client and services of this client. " +
                    "\n5: Whole info. " +
                    "\nOther input: exit. ");
                action = int.Parse(Console.ReadLine());//преобразуем строку в число
                
                switch (action)
                {
                    case 1:
                        {
                            string serv; int price;
                            Console.Clear();
                            Console.WriteLine("Input Service: ");
                            serv = Console.ReadLine();
                            Console.WriteLine("Input Сost For This Service: ");
                            price = int.Parse(Console.ReadLine());
                            Boss.AddPrice(serv, price);
                            break;
                        }
                    case 2:
                        {
                            string n = " "; string p = " "; int t = 0;
                            Console.Clear();
                            Console.WriteLine("Input name of the client: ");
                            n = Console.ReadLine();
                            Console.WriteLine("Input surname number of the client: ");
                            p = Console.ReadLine();
                            do
                            {
                                Console.WriteLine("Choose type of the client: " +
                                    "1) Standart price: " +
                                    "2) All inclusive: " +
                                    "3) Child status: ");
                                t = int.Parse(Console.ReadLine());

                            } while (t != 1 && t != 2 && t != 3);
                            switch (t)
                            {
                                case 1:
                                    {
                                        Boss.AddClient(n, p, StatusType.StatuswithDiscount);
                                        break;
                                    }
                                case 2:
                                    {
                                        Boss.AddClient(n, p, StatusType.StandartStatus);
                                        break;
                                    }
                                case 3:
                                    {
                                        Boss.AddClient(n, p, StatusType.StatuforElederpeople);
                                        break;
                                    }
                            }
                            
                            break;
                        }
                    case 3:
                        {

                            int N;
                            Console.WriteLine("Choose a client for search: ");
                            Console.WriteLine(Boss.Clients());
                            N = int.Parse(Console.ReadLine());
                            if (N > 0 && N <= HousingandMaintenanceServices.GetClients().Count)
                            {
                                Console.WriteLine(Boss.SearchName(HousingandMaintenanceServices.GetClients()[N-1].name));
                            }

                            Console.ReadKey();
                            break;
                        }
                  
                    case 5:
                        {
                            Console.Clear();
                            Console.WriteLine("Total cost: " + Boss.GetWholeCost().ToString() + "\t");
                            for (int i = 0; i < HousingandMaintenanceServices.GetClients().Count; i++)
                                Console.WriteLine(Boss.SearchName(HousingandMaintenanceServices.GetClients()[i].name));
                            Console.ReadKey();
                            break;
                        }
                    case 4:
                        {
                            Console.Clear();
                            int N;
                            Console.WriteLine("Choose a client from the list: ");
                            Console.WriteLine(Boss.Clients());
                            N = int.Parse(Console.ReadLine());
                            if (N > 0 && N <= HousingandMaintenanceServices.GetClients().Count)
                            {
                                //Console.Clear();
                                Boss.LogIn(N);
                                Console.WriteLine("Choose, what should pay this person: ");
                                Console.WriteLine(Boss.Pricee());
                                int NN = int.Parse(Console.ReadLine());
                                if (NN > 0 && NN <=HousingandMaintenanceServices.GetPriceList().Count)
                                Boss.SellPrice(NN);
                                Boss.LogOut();
                            }
                              
                            
                            break;
                        }
                        //выход из панели выбора
                    default: break;
                }




            } while (action >=1 && action <=5);

        }
    }
}
