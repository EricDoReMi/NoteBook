using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatementsExample3
{
    class Program
    {
        static void Main(string[] args)
        {
            int score = 101;
            switch (score/10)
            {
                case 10:
                    if (score == 100)
                    {
                        goto case 8;
                    }
                    else {
                        goto default;
                    }
                    break;
                case 8:
                case 9:
               
                    Console.WriteLine("A");
                    break;
                case 6:
                case 7:
                    Console.WriteLine("B");
                    break;
                case 4:
                case 5:
                    Console.WriteLine("C");
                    break;
                case 0:
                case 1:
                case 2:
                case 3:
                    Console.WriteLine("D");
                    break;
                default:
                    Console.WriteLine("Error");
                    break;
                
            }

            Console.ReadKey();
        }
    }


}
