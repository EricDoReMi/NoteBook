using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 方法的综合练习了
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numArr = { 1, 2, 11 };
            double avg = GetAvg(numArr);
            //保留两位小数
            string s = avg.ToString("0.00");
            avg = Convert.ToDouble(s);
            Console.WriteLine(avg);
            Console.ReadKey();
        }

        public static double GetAvg(params int[] numArr) {
            double sum = 0;
            for (int i = 0; i < numArr.Length; i++)
            {
                sum += numArr[i];
            }

            return sum / numArr.Length;

        }

       
    }
}
