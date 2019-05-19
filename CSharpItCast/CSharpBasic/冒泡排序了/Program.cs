using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 冒泡排序了
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

            for (int i = 0; i < nums.Length-1; i++)
            {
                for (int j = 0; j < nums.Length-1-i; j++)
                {

                    if (nums[j] > nums[j + 1]) {
                        int tmp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = tmp;
                    }
                }
            }

            Array.Sort(nums);//调用Sort对数组进行升序排序
            Array.Reverse(nums);//用于反转数组

            for (int i = 0; i < nums.Length; i++)
            {
                Console.WriteLine(nums[i]);
            }

            Console.ReadKey();
        }
    }
}
