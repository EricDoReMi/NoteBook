using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ref练习
{
    class Program
    {
        static void Main(string[] args)
        {
            int n1 = 5, n2 = 6;
            ExchangeNum(ref n1,ref n2);
            Console.WriteLine(n1);
            Console.WriteLine(n2);
            Console.ReadKey();
        }

        public static void ExchangeNum(ref int n1,ref int n2) {
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
    }
}
