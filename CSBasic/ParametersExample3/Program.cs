using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParametersExample3
{
    class Program
    {
        static void Main(string[] args)
        {
            int result = CalculateSum(1,2,3);
            Console.WriteLine(result);

            int x = 100;
            int y = 200;
            int z = x + y;
            Console.WriteLine("{0}+{1}={2}",x,y,z);

            string str = "Tim;Tom,Amy.Lisa";
            string[] strArr = str.Split(',', ';', '.');
            foreach (var item in strArr)
            {
                Console.WriteLine(item);
            }
        }

        //数组参数必须是形参列表中的最后一个，由params修饰
        static int CalculateSum(params int[] intArray)
        {
            int sum = 0;
            foreach (var item in intArray)
            {
                sum += item;
            }
            return sum;
        }
    }
}
