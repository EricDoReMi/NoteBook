using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OperationExample6
{
    class Program
    {
        static void Main(string[] args)
        {
            //正数除以0显示正无穷大，负数除以0显示负无穷大
            double x = -5.0;
            double y = 0;
            double z = x / y;
            double a = double.PositiveInfinity;
            Console.WriteLine(a);
            Console.ReadKey();

            double k = 3.5;
            double p = 3;
            Console.WriteLine(x%p);
            Console.ReadKey();

            int x1 = 7;
            int y1 = x1 << 1;
            //已二进制形式输出，在前面补充0
            string strX1 = Convert.ToString(x1, 2).PadLeft(32,'0');
            string strY1 = Convert.ToString(y1, 2).PadLeft(32, '0');
            Console.WriteLine(strX1);
            Console.WriteLine(strY1);
            Console.ReadKey();




        }
    }
}
