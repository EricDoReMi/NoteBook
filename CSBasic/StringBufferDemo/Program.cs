using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace StringBuilderDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            //计时器
            Stopwatch sw1 = new Stopwatch();
            Stopwatch sw2 = new Stopwatch();



            sw1.Start();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 100000; i++) {
                sb.Append(i.ToString());
            }

            sw1.Stop();
            Console.WriteLine("StringBuilderTime:{0}",sw1.ElapsedMilliseconds);

            sw2.Start();

            string str = string.Empty;//等价于string str="";
            for (int i = 0; i < 100000; i++) {
                str += i.ToString();
            }
            sw2.Stop();
            Console.WriteLine("StringTime:{0}", sw2.ElapsedMilliseconds);

            Console.ReadKey();


        }
    }
}
