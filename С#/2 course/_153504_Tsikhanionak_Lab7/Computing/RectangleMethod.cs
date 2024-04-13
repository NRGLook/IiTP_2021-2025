using System.Diagnostics;

namespace Computing
{
    public class RectangleMethod
    {
        public delegate void ExecTime(TimeSpan timeSpan);
        public event ExecTime? ExecutionTime;

        public delegate void ProgressFactor(int res);
        public event ProgressFactor? Progress;

        private Semaphore semaphore = new Semaphore(2, 2);

        public RectangleMethod() { }

        public void ComputeIntegralSin(double step, double from, double to)
        {
            double result = 0;
            int lastProgress = 0;
            semaphore.WaitOne();
            Stopwatch sw = Stopwatch.StartNew();
            for(double i = from; i <= to; i+=step)
            {
                result += step * Math.Sin(i);
                for(int j = 0; j < 100000; j++)
                {
                    int a = j + j;
                }
                int progress = Convert.ToInt32((i - from) / (to - from) * 100.0) / 10 * 10;
                if (progress != lastProgress)
                {
                    Progress?.Invoke(progress);
                    lastProgress = progress;
                }
            }
            ExecutionTime?.Invoke(sw.Elapsed);
            semaphore.Release();    
        }
    }
}