using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SwitchExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Level myLevel = Level.High;
            switch (myLevel)
            {
                case Level.High:
                    Console.WriteLine("High Level!");
                    break;
                case Level.Mid:
                    Console.WriteLine("Mid Level!");
                    break;
                case Level.Low:
                    Console.WriteLine("Low Level!");
                    break;
                default:
                    Console.WriteLine("Error");
                    break;
            }
        }
    }

    enum Level
    {
        High,
        Mid,
        Low
    }
}
