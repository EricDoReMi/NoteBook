using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SecondDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("This is my Second Demo");
        }

        /// <summary>
        /// 求两个整数的最大值
        /// </summary>
        /// <param name="x">第一个整数</param>
        /// <param name="y">第二个整数</param>
        /// <returns>最大值</returns>
        public static int GetMax(int x, int y)
        {
            return x > y ? x : y;
        }
    }

    /// <summary>
    /// 人类
    /// </summary>
    public class Person
    {
        #region 注释
        //Hello
        //Hello
        //Hello
        //Hello
        //Hello
        #endregion
        public string Name { get; set; }
        public int age { get; set; }
    }
}
