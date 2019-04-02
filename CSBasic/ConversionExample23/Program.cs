using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConversionExample23
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(ushort.MaxValue);
            uint x = 65536;
            ushort y = (ushort)x;
            Console.WriteLine(y);
            int t = Convert.ToInt32("123");

         }
    }
}
