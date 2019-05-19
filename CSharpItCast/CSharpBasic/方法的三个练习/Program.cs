using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 方法的三个练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入yes或者no");
            string str = Console.ReadLine();
            string result = IsYesOrNo(str);
            Console.WriteLine(result);
            Console.ReadKey();
        }

        public static string IsYesOrNo(string input) {
            while (true) {
                if (input == "yes" || input == "no")
                {
                    return input;
                }
                else {
                    Console.WriteLine("只能输入了yes或者no,请重新输入");
                    input = Console.ReadLine();
                }
            }
        }
    }
}
