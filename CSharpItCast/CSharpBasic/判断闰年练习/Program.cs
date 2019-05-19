using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 判断闰年练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(IsRun(1999));
            Console.ReadKey();
        }

        /// <summary>
        /// 判断给定的年份是否是润健
        /// </summary>
        /// <param name="year">要判断的年份</param>
        /// <returns>是否是闰年</returns>
        public static bool IsRun(int year) {
            bool b = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
            return b;
        }
    }
}
