using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 方法
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("M:{0}",GetMax(5,6));
            TestReturn();
            Console.ReadKey();
        }

        /// <summary>
        /// 计算两个整数的最大值，并且将最大值返回
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns></returns>
        public static int GetMax(int n1, int n2) {
            return n1 > n2 ? n1 : n2;
        }

        public static void TestReturn() {
            while (true) {
                return;
            }
        }
    }
}
