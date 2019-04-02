using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TryPaseDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            string str1 = Console.ReadLine();
            string str2 = Console.ReadLine();

            int a, b;

            if (int.TryParse(str1, out a) && int.TryParse(str2, out b))
            {
                Console.WriteLine(a+b);
            }
            else
            {
                Console.WriteLine("解析失败了!");
            }

            Console.ReadKey();
        }
    }
}
