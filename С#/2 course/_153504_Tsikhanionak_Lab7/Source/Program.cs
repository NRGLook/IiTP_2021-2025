using System;
using System.ComponentModel;
using Computing;

namespace Source // Note: actual namespace depends on the project name.
{
    class Program
    {
        static Mutex mutexObj = new();

        static void Main(string[] args)
        {
            RectangleMethod rectMethod = new RectangleMethod();
            double step = 1e-6, from = 0.0, to = 1.0;

            //creating threads
            Thread highPriorityThread = new Thread(() => rectMethod.ComputeIntegralSin(step, from, to));
            Thread lowPriorityThread = new Thread(() => rectMethod.ComputeIntegralSin(step, from, to));
            Thread Thread3 = new Thread(() => rectMethod.ComputeIntegralSin(step, from, to));
            Thread Thread4 = new Thread(() => rectMethod.ComputeIntegralSin(step, from, to));
            Thread Thread5 = new Thread(() => rectMethod.ComputeIntegralSin(step, from, to));

            highPriorityThread.Priority = ThreadPriority.Highest;
            lowPriorityThread.Priority = ThreadPriority.Lowest;

            Console.WriteLine($"High priority thread id:{highPriorityThread.ManagedThreadId}\n");
            Console.WriteLine($"Low priority thread id:{lowPriorityThread.ManagedThreadId}\n");

            //subscribing to events
            rectMethod.Progress += (res) => ProgressOutput(res);
            rectMethod.ExecutionTime += (interval) => Console.WriteLine($"\nThread {Thread.CurrentThread.ManagedThreadId} " +
                $"finished computing in {interval}\n");

            //start computing
            highPriorityThread.Start();
            lowPriorityThread.Start();
            Thread3.Start();
            Thread4.Start();
            Thread5.Start();
        }

        public static void ProgressOutput(int res)
        {
            mutexObj.WaitOne();
            Console.Write($"ThreadId: {Thread.CurrentThread.ManagedThreadId} [");
            for(int i = 1; i <= res / 10; i++)
            {
                Console.Write('=');
            }
            for(int i = res/10 + 1; i <= 10; i++)
            {
                Console.Write('*');
            }
            Console.WriteLine($"]{res}%");
            mutexObj.ReleaseMutex();
        }
    }
}