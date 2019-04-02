using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpMethodExample
{
    class Program
    {
        static void Main(string[] args)
        {
           // Calculator c = new Calculator();
            double a=11;
            a = Calculator.GetConeVolumn(100,100);
            Console.WriteLine(a);
            Console.ReadKey();
        }
    }

    class Calculator
    {
        public static double GetCircleArea(double r)
        {
            return Math.PI * r * r;
        }

        public static double GetCylinderVolume(double r,double h)
        {
            double a = GetCircleArea(r);
            return a * h;
        }

        public static double GetConeVolumn(double r,double h)
        {
            double cv = GetCylinderVolume(r,h);
            return cv / 3;
        }
    }
}
