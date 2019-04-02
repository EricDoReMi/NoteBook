using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConversionExample7
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 7;
            int y = 28;
            int z = x & y;
            string strX1 = Convert.ToString(x, 2).PadLeft(32, '0');
            string strY1 = Convert.ToString(y, 2).PadLeft(32, '0');
            string strZ1 = Convert.ToString(z, 2).PadLeft(32, '0');
            Console.WriteLine(strX1);
            Console.WriteLine(strY1);
            Console.WriteLine(strZ1);

            //Nullable表示可空类型
            Nullable<int> x3 = null;
            x3 = 100;
            Console.WriteLine(x3);

            //判断x3是否有值了
            Console.WriteLine(x3.HasValue);

            //等价于
            int? x5 = null;
            int y3 = x5 ?? 1;//若x5为null 则赋值成为1
            Console.WriteLine(y3);
            x5 = 5;
            int y5 = x5 ?? 1;
            Console.WriteLine(y5);

        }
    }
}
