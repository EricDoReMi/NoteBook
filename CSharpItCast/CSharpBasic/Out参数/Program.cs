using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Out参数
{
    class Program
    {
        static void Main(string[] args)
        {
            //写一个方法，求一个数组的最大值,最小值,总和,平均值
            int[] numberArr = { 1, 2, 3, 5, 6, 7, 8, 9 };

            int max,min,sum,avg;
            GetMaxMinSumAvg(numberArr,out max,out min,out sum,out avg);
            Console.WriteLine("Max {0} Min {1} Sum {2} Avg {3}",max,min,sum,avg);
            Console.ReadKey();
        }

        public static void GetMaxMinSumAvg(int[] numArr,out int max,out int min,out int sum,out int avg) {
            max = int.MinValue;
            min = int.MaxValue;
            sum = 0;
            for (int i = 0; i < numArr.Length; i++)
            {
                max=max > numArr[i] ? max : numArr[i];
                min = min < numArr[i] ? min : numArr[i];
                sum += numArr[i];
            }

            avg = sum / numArr.Length;
        }

        public static bool MyTryParse(string s, out int result) {
            result = 0;
            try
            {
                result = Convert.ToInt32(s);
                return true;
            }
            catch (Exception)
            { 
                return false;
            }
        }
    }
}
