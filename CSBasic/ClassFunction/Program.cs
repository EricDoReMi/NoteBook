using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassFunction
{
    class Program
    {
        static void Main(string[] args)
        {

            //Calculator c = new Calculator();
            //c.PrintXTo1(5);
            //Console.WriteLine(c.SumFrom1ToX(100));

            //汉诺塔问题
            Stack<int> a = new Stack<int>();
            Stack<int> b = new Stack<int>();
            Stack<int> c = new Stack<int>();

            int count = 10;

            for (int i = count; i >0; i--)
            {
                a.Push(i);
        
            }

            HanNuoTa.toDoHanNuo(count,a,b, c);

            for (int i = count; i > 0; i--)
            {
                Console.WriteLine(c.Pop());

            }


            Console.ReadKey();
        }
    }

    class Calculator {
        public int AddNum(int a,int b) {
            int ret = a + b;
            return ret;
        }

        public string Today() {
            return DateTime.Now.Day.ToString();
        }

        public void PrintXTo1(int x) {
            if (x == 1) {
                Console.WriteLine(x);
                return;
            }

            Console.WriteLine(x);
            PrintXTo1(x-1);
        }


        public int SumFrom1ToX(int x) {
            if (x==1) {
                return 1;
            }
            return x + SumFrom1ToX(x-1);
        }
    }
}
