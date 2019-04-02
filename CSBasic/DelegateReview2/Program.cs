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
            MyDele<int> deleAdd1 = new MyDele<int>(Add);
            int res = deleAdd1(100,200);
            MyDele<double> deleMul1 = new MyDele<double>(Mul);
            double resDouble = deleMul1(2,3);
            Console.WriteLine("{0},{1}",res,resDouble);
            Console.WriteLine(deleAdd1.GetType().IsClass);
        }

        static int Add(int x, int y) {
            return x + y;
        }

        static double Mul(double x,double y) {
            return x * y;
        }
    }

    //泛型委托了
    delegate T MyDele<T>(T a, T b);
}
