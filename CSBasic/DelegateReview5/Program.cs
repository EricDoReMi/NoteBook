using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateReview5
{
    class Program
    {
        static void Main(string[] args)
        {
            //Lambda
            //1.匿名方法
            //2.Inline方法
            Func<int, int, int> func = new Func<int, int, int>((int a,int b)=> { return a + b; });
            int res = func(100,200);
            Console.WriteLine(res);
            func = new Func<int, int, int>((int x,int y)=> { return x * y; });
            res = func(2,3);
            Console.WriteLine(res);


        }
    }
}
