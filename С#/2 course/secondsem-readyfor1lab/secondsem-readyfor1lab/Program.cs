
    /*int[] nums = { 10, -22, 34, 43, 34, 34, 7, 8, 105 };

    int temp;
    for(int i = 0; i < nums.Length - 1; i++)
    {
        for (int j = i + 1; j < nums.Length - 1; j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }     
    }
    Console.WriteLine("You massiv:");
    foreach(int z in nums)
    {
        Console.WriteLine(z);
    }
    void PrentPerson(string name,int age=23)
    {
        Console.WriteLine($"Name:{name};Age:{age}");
        return;//чисто для того чтобы выйти из меода
    }


    PrentPerson("Ilya",age:99);
    string SayHello()
    {
        return "hello";
    }
    string message = SayHello();
    Console.WriteLine(message);

    int ret = 9;
    Console.WriteLine($"Before incremention{ret}");
    Increment(out ret);
    Console.WriteLine(ret);

    void Increment(out int numberone)
    {
        numberone=ret++;
    }

    Console.WriteLine($"After all operation{ret}\n\n\n");


    //использование ключевого слово params
    void SumElseNumbers(int n, params int[] k)
    {
        int reasult = n;
        foreach (var z in k)
        {
            reasult += z;
        }

        Console.WriteLine(reasult);
    }

    int[] numberone = { 1, 2, 3, 4, 5, 6 };


    SumElseNumbers(10, numberone);
    SumElseNumbers(1, 2, 3, 4);
    SumElseNumbers(20);

    int Factorial(int n)
    {
        if (n == 1)//условие выхода чтобы избежать бесконечного цикла
        {
            return 1;
        }
        else
        {
            return n * Factorial(n - 1);//
        }
    }

    Console.WriteLine(Factorial(3));

    int Fibonachi(int k)
    {
        if (k == 0 || k == 1) return k;

        return Fibonachi(k - 1) + Fibonachi(k - 2);
    }


    Console.WriteLine(Fibonachi(2));


    static int Fibonachi2(int n)
    {
        int result = 0;
        int b = 1;
        int tmp;

        for (int i = 0; i < n; i++)
        {
            tmp = result;
            result = b;
            b += tmp;
        }

        return result;
    }

    Console.WriteLine(Fibonachi2(2));


    void Compare(int[] numbers1, int[] numbers2)
    {
        int numbers1Sum = Sum(numbers1);
        int numbers2Sum = Sum(numbers2);

        if (numbers1Sum > numbers2Sum)
            Console.WriteLine("сумма чисел из массива numbers1 больше");
        else
            Console.WriteLine("сумма чисел из массива numbers2 больше");

        int Sum(int[] numbers)
        {
            int limit = 0;
            int result = 0;
            foreach (int number in numbers)
            {
                if (IsPassed(number,limit)) result += number;
            }
            return result;

            static bool IsPassed(int number, int lim)
            {
                return number > lim;
            }
        }
    }

    int DoOperation(int op, int a, int b)
    {
        int result = op switch
        {
            1 => a + b,
            2 => a - b,
            3 => a * b,
            _ => 0
        };
        return result;
    }

    DoOperation(10, 5, Operation.Add);          // 15
    DoOperation(10, 5, Operation.Subtract);     // 5
    DoOperation(10, 5, Operation.Multiply);     // 50
    DoOperation(10, 5, Operation.Divide);       // 2

    void DoOperation(double x, double y, Operation op)
    {
    double result = op switch
    {
    Operation.Add => x + y,
    Operation.Subtract => x - y,
    Operation.Multiply => x * y,
    Operation.Divide => x / y
    };
    Console.WriteLine(result);
    }
    enum Operation
    {
        Add,
        Subtract,
        Multiply,
        Divide
    }*/
    





