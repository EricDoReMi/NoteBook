using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 方法的重载
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(M(1,2));
            Console.WriteLine(M(1.1, 20));
            Console.ReadKey();
        }

        public static int M(int n1,int n2) {
            return  n1 + n2;
        }

        public static double M(double n1, double n2) {
            return n1 + n2;
        }

    }
}
