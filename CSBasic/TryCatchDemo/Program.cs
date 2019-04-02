using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TryCatchDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Calculator c = new Calculator();
            try
            {
                int r = c.Add(null, "1");
            }
            catch (OverflowException oe)
            {
                Console.WriteLine(oe.Message);    
            }
        }
    }

    class Calculator
    {
        public int Add(string arg1,string arg2) {
            int a = 0;
            int b = 0;
            bool hasError = false;
            try
            {
                a = int.Parse(arg1);
                b = int.Parse(arg2);
            }
            catch (ArgumentNullException ane)
            {
                Console.WriteLine(ane.Message);
                hasError = true;
            }
            catch (OverflowException ofe)
            {
                Console.WriteLine(ofe.Message);
                throw ofe;
                hasError = true;
            }
            catch (FormatException fe)
            {
                Console.WriteLine(fe.Message);
                hasError = true;
            }
            finally
            {
                if (hasError)
                {
                    Console.WriteLine("Execution has error");
                }
                else
                {
                    Console.WriteLine("Done!");
                }
            }
            int result = a + b;
            return result;
        }
    }
}
