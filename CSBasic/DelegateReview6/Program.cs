using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateReview6
{
    class Program
    {
        static void Main(string[] args)
        {
            DoSomeCal<int>((a,b)=> { return a + b;},12,15);
        }

        static void DoSomeCal<T>(Func<T, T, T> func, T x, T y) {
            T res=func(x,y);
            Console.WriteLine(res);
        }
    }
}
