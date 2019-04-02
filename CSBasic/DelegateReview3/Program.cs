using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateReview2
{
    class Program
    {
        static void Main(string[] args)
        {
            Action a1 = new Action(M1);
            a1();
            Action<string> a2 = new Action<string>(SayHello);
            a2("UU");
            Action<string, int> a3 = new Action<string, int>(SayHello2);
            a3("U",3);
            var func = new Func<int, int, int>(Add);
            int a=func(1,2);
            Console.WriteLine(a);

        }

        static void M1() {
            Console.WriteLine("M1 is called");
        }

        static void SayHello(string name) {
            Console.WriteLine($"Hello,{name}!");
        }
        static void SayHello2(string name,int round)
        {
            for (int i=0;i<round;i++) {
                Console.WriteLine($"Hello,{name}!");
            }
        }


        static int Add(int x, int y)
        {
            return x + y;
        }

        static double Mul(double x, double y)
        {
            return x * y;
        }
    }


}
