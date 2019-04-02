using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConversionExample6
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 5;
            double y = 3.0;
            var result = x < y;
            Console.WriteLine(result.GetType().FullName);
            Console.WriteLine(result);

            var char1 = 'a';
            var char2 = 'A';
            var result2 = char1 > char2;
            ushort uchar1 = (ushort) char1;
            ushort uchar2 = (ushort)char2;
            Console.WriteLine(uchar1);
            Console.WriteLine(uchar2);

            string str1 = "abc";
            string str2 = "Abc";

            Console.WriteLine(str1.ToLower()==str2.ToLower());
            int result3=string.Compare(str1,str2);
            //result3 0 相等，负数 第一个小于第二个，正数 第一个大于第二个


        }
    }
}
