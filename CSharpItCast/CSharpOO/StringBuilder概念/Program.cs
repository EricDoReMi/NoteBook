using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace StringBuilder概念
{
    class Program
    {
        static void Main(string[] args)
        {
            //string str = null;
            StringBuilder sb = new StringBuilder();
            //创建一个计时器，用来记录程序运行的时间
            Stopwatch sw = new Stopwatch();
            sw.Start();
            for (int i = 0; i < 10000000; i++)
            {
                //str += i;
                sb.Append(i);
            }

            sw.Stop();

            Console.WriteLine(sw.Elapsed);

            Console.WriteLine(sb.ToString());

            Console.ReadKey();
        }
    }
}
