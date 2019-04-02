using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Calculator calculator = new Calculator();
            
            Action action = new Action(calculator.Report);
            //action委托
            calculator.Report();
            action.Invoke();
            action();

            //Function委托
            Func<int, int, int> func1 = new Func<int, int, int>(calculator.Add);
            Func<int, int, int> func2 = new Func<int, int, int>(calculator.Sub);
            int x = 100;
            int y = 200;
            int z = 0;
            z = func1.Invoke(x,y);//func1(x,y);
            Console.WriteLine(z);
            z = func2.Invoke(x,y);//func2(x,y);
            Console.WriteLine(z);

           }
    }

    class Calculator
    {
        public void Report()
        {
            Console.WriteLine("I have 3 methods . ");

        }

        public int Add(int a, int b)
        {
            int result = a + b;
            return result;
        }

        public int Sub(int a, int b)
        {
            int result = a - b;
            return result;
        }
    }
}
