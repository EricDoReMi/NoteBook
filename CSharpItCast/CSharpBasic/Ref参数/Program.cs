﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ref参数
{
    class Program
    {
        static void Main(string[] args)
        {
            double salary = 5000;
            JiangJin(ref salary);
            Console.WriteLine(salary);
            FaKuan(ref salary);
            Console.WriteLine(salary);
            Console.ReadKey();
        }

        public static void JiangJin(ref double s) {
            s += 500;
        }

        public static void FaKuan(ref double s) {
            s -= 500;
        }
    }
}
