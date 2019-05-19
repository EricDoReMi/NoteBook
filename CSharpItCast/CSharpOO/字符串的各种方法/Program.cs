using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 字符串的各种方法
{
    class Program
    {
        static void Main(string[] args)
        {
            //长度
            string names = "Sweet";
            Console.WriteLine(names.Length);

            //比较
            string lesson1 = "C#";
            string lesson2 = "c#";
            lesson1 = lesson1.ToUpper();
            lesson2 = lesson2.ToUpper();
            if (lesson1.Equals(lesson2, StringComparison.OrdinalIgnoreCase)) {
                Console.WriteLine("相等");
            }

            //分割
            string s = "a b      dfd _ + fjdsd = ,,, a";
            char[] chs = {' ','_','+','-',','};
            //将空项移除的split方法
            string[] str = s.Split(chs,StringSplitOptions.RemoveEmptyEntries);

            string dateStrName = "2018-08-08";
            char[] chsDateStrName = { '-' };
            string[] strDateStrName = dateStrName.Split(chsDateStrName, StringSplitOptions.RemoveEmptyEntries);
            Console.WriteLine("年:{0},月:{1},日:{2}",strDateStrName[0], strDateStrName[1], strDateStrName[2]);

            //替换
            string contents = "国家关键人物小白";
            if (contents.Contains("小白")) {
                contents=contents.Replace("小白","***");
            }
            Console.WriteLine(contents);

            //截取
            string myStr = "今天天气好好,我们在谈论天气";
            myStr = myStr.Substring(1, 2);
            Console.WriteLine(myStr);

            if (myStr.StartsWith("今天")) {
                Console.WriteLine("今天开始了");
            }

            int index = myStr.IndexOf("天");
            int index2 = myStr.IndexOf("天",2);

            string pathD = @"c:\a\b\c\d\e\aaa.avi";
            int lastIndex = pathD.LastIndexOf(@"\");
            pathD = pathD.Substring(lastIndex+1);
            Console.WriteLine(pathD);

            string str11 = "          abc         ";
            str11 = str11.Trim();
            Console.WriteLine(str11);

            string str22 = null;
            //string str22="";
            if (string.IsNullOrEmpty(str22)) {
                Console.WriteLine("是空或者是null");
            }

            //拼接
            string[] nameStrs = { "张三", "李四", "王五", "赵六", "田七" };
            string newStr = string.Join("|", nameStrs);
            Console.WriteLine(newStr);
            
            Console.ReadKey();
        }
    }
}
