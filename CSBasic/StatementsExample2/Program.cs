using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatementsExample2
{
    class Program
    {
        static void Main(string[] args)
        {
            var x=100;
            Console.WriteLine(x.GetType().FullName);
            int[] myArray = { 1, 2, 3 };

            Console.WriteLine("Result is {0}",myArray[0]);

            //常量的使用
            const int y= 200;

            Console.ReadKey();
            
        }
    }
}
