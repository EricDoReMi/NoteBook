using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceExample02
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num1 = new int[] { 1, 2, 3, 4, 5 };
            ArrayList num2 = new ArrayList { 1,2,3,4,5};
            Console.WriteLine(Sum(num1));
            Console.WriteLine(Avg(num2));
        }

        static int Sum(IEnumerable arr)
        {
            int sum = 0;
            foreach (var item in arr)
            {
                sum += (int)item;
            }

            return sum;
        }

        static double Avg(IEnumerable arr) {
            double sum = 0;double count = 0;
            foreach (var item in arr)
            {
                sum += (int)item;
                count++;
            }

            return sum / count;

        }
    }


}
