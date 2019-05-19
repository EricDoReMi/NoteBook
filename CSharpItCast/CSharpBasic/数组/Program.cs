using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 数组
{
    class Program
    {
        static void Main(string[] args)
        {

            //声明了一个长度为10的int类型的数组,默认0
            int[] nums = new int[10];
            nums[6] = 5;
            for (int i = 0; i < nums.Length; i++)
            {
                nums[i] = i;
            }

            for (int i = 0; i < nums.Length; i++)
            {
                Console.WriteLine(nums[i]);
            }

            //string 类型的数组默认值为null
            string[] strArr = new string[10];

            bool[] boolArrs = new bool[10];

            //数组的声明方式了
            int[] numArr2 = { 1, 2, 3, 5, 6 ,7};
            int[] numArr3 = new int[3] { 1, 2, 3 };
            int[] numArr5 = new int[] { 1, 2, 3, 5, 6 };

            Console.ReadKey();
        }
    }
}
