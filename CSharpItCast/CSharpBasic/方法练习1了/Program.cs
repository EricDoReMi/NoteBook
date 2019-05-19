using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 方法练习1了
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入数字了");
            string input = Console.ReadLine();
            int number=InputNum(input);
        }

        public static int InputNum(string input) {
            while (true) {
                
                try
                {
                    int num = Convert.ToInt32(input);
                    return num;
                }
                catch (Exception)
                {

                    Console.WriteLine("输入的有错误");
                    input = Console.ReadLine();
                }
               
            }
            
            Console.ReadKey();
        }
    }
}
