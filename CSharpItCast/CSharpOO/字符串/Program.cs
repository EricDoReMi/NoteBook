using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            string s1 = "张三";
            string s2 = "张三";

            //可以将string类型 看做是char类型的一个只读数组
            string s = "abcdefg";
            Console.WriteLine(s[1]);

            //将字符串转换为char类型的数组
            char[] chs = s.ToCharArray();
            chs[0] = 'b';
            //将字符数组转换为字符串
            s = new string(chs);
            Console.WriteLine(s);
            Console.ReadKey();
        }
    }
}
