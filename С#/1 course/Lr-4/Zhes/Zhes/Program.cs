//Выполнил: Тиханёнок Илья Александрович - вариант 3

/*Предметная область: ЖЭС-Тариф. В классе хранить информацию о районе, к которому принадлежит ЖЭС,
                                                            номер ЖЭС,
                                                            число жильцов,
                                                            оплату за месяц (для всех жильцов одна),
                                                            число оплативших.
Реализовать метод для подсчета выручки со всех жильцов. Реализовать возможность изменения (увеличения и уменьшения) тарифа.*/

using System;

namespace laborotorywork4
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 1;
            Zhes zhes = Zhes.Initialize();
            while (true)
            {
                switch (n)
                {
                    case 1:
                        Console.Clear();
                        Console.WriteLine("Введите район, в котором находится ЖЭС: ");
                        zhes.SetZhesRegion();
                        Console.Clear();
                        Console.WriteLine("Введите номер ЖЭС: ");
                        zhes.SetZhesNumber();
                        Console.Clear();
                        Console.WriteLine("Введите оплату за месяц: ");
                        zhes.SetPriceTarif();
                        Console.Clear();
                        Console.WriteLine("Введите число жильцов,зарегистрированных в данном ЖЭС: ");
                        zhes.SetNumberOfClients();
                        Console.Clear();
                        Console.WriteLine("Введите число жильцов, внесших плату за месяц: ");
                        zhes.SetUtilities();
                        n = 5;
                        break;
                    case 2:
                        Console.Clear();
                        Console.WriteLine("Месячная плата:" + zhes.PriceTarif);
                        Console.WriteLine("\nВведите на сколько увеличить тариф: ");
                        zhes.UpPrice();
                        n = 5;
                        break;
                    case 3:
                        Console.Clear();
                        Console.WriteLine("Месячная плата:" + zhes.PriceTarif);
                        Console.WriteLine("\nВведите на сколько уменьшить тариф: ");
                        zhes.DownPrice();
                        n = 5;
                        break;
                    case 4:
                        return;
                    case 5:
                        Console.Clear();
                        Console.WriteLine("Введенные данные:" +
                                          "\n *Район, в котором находится данный ЖЭС:" + zhes.ZhesRegion1 +
                                          "\n *Номер ЖЭС:" + zhes.ZhesNumber1 +
                                          "\n *Месячная плата:" + zhes.PriceTarif +
                                          "\n *Число жильцов, зарегестрированных в данном ЖЭС:" + zhes.NumberOfAllClients +
                                          "\n *Число жильцов, оплативших месячную плату:" + zhes.NumberOfTarifsSold +
                                          "\n *Общая стоимость выручки со всех жильцов:" + zhes.TotalCostAllMonth());
                        Console.WriteLine("\n\n1 - Перезапустить.\n2 - Увеличить ежемесячную плату.\n3 - Уменьшить ежемесячную плату.\n4 - Покинуть приложение.");
                        while (!int.TryParse(Console.ReadLine(), out n) || n > 4 || n < 1) Console.WriteLine("Ошибка ввода! Пожалуйста, попробуйте еще раз:");
                        break;
                }
            }
        }
    }
}
