using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Params练习
{
    class Program
    {
        static void Main(string[] args)
        {
            TestParams("小白",1,2,3,5,6,7,8,9,10);
            TestParams("小丸子",new int[]{ 100,100,100});
            Console.WriteLine(GetSum(5,6,7,8,9));
            Console.WriteLine(GetSum(5,6,7,8,11));
            Console.ReadKey();
        }

        public static void TestParams(string names,params int[] score) {
            int sum = 0;
            for (int i = 0; i < score.Length; i++)
            {
                sum += score[i];
            }
            Console.WriteLine("{0}这次考试的总成绩是{1}",names,sum);
        }

        /// <summary>
        /// 求任意长度数组的总和
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int GetSum(params int[] n) {
            int sum = 0;
            for (int i = 0; i < n.Length; i++)
            {
                sum += n[i];
            }
            return sum;
        }
    }
}
