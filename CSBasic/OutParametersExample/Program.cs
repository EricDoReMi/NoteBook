using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OutParametersExample
{
    class Program
    {
        static void Main(string[] args)
        {
            /* Console.WriteLine("Please input first number ! ");
             string arg1 = Console.ReadLine();
             double x = 0;
             bool b1 = double.TryParse(arg1,out x);


             if (b1 == false)
             {
                 Console.WriteLine("parse error ! ");
                 return;
             }
             else {
                 Console.WriteLine(x);
                 return; 
             }*/

            double x = 0;
            bool b = DoubleParser.TryParse("169",out x);
            if (b)
            {
                Console.WriteLine(x+1);
            }
        }

    }

    class DoubleParser
    {
        public static bool TryParse(string input, out double result)
        {
            try
            {
                result = double.Parse(input);
                return true;
            }
            catch (Exception)
            {

                result = 0;
                return false;
            }
        }
    }


}
