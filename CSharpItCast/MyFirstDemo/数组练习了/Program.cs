using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 数组练习了
{
    class Program
    {
        static void Main(string[] args)
        {

            //练习1：从一个整数数组中取出最大值，最小值，总和，平均值
            int[] numArr = { 1, 2, 3, 5, 6, 7, 8, 9, 11 };

            int max = int.MinValue;
            int min = int.MaxValue;
            int sum = 0;
            for (int i = 0; i < numArr.Length; i++)
            {
                max=numArr[i] > max ? numArr[i] : max;
                min = numArr[i] < min ? numArr[i] : min;
                sum += numArr[i];
            }

            Console.WriteLine("Max:{0},Min:{1},Sum:{2},Arrage:{3}",max,min,sum,sum/numArr.Length);

            //练习2：将{a,b,c,d,e} 反转为 {e,d,c,b,a}
            //将n个元素交换需要进行n/2次
            string[] strArr = { "a", "b", "c", "d", "e","f"};
            for (int i = 0; i < strArr.Length/2; i++)
            {
                string tmp = strArr[i];
                strArr[i] = strArr[strArr.Length - 1 - i];
                strArr[strArr.Length - 1 - i] = tmp;

            }
            for (int i = 0; i < strArr.Length; i++)
            {
                Console.WriteLine(strArr[i]);
            }

            Console.ReadKey();
        }
    }
}
