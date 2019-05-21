using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace File类
{
    class Program
    {
        static void Main(string[] args)
        {

            //创建一个文件
            //File.Create(@"C:\Users\SpringRain\Desktop\new.txt");
            //Console.WriteLine("创建成功");
            //Console.ReadKey();

            //删除一个文件
            //File.Delete(@"C:\Users\SpringRain\Desktop\new.txt");
            //Console.WriteLine("删除成功");
            //Console.ReadKey();
            //1024byte=1kb
            //1024kb=1M
            //1024M=1G
            //1024G=1T
            //1024T=1PT

            //复制一个文件
            //File.Copy(@"C:\Users\SpringRain\Desktop\code.txt", @"C:\Users\SpringRain\Desktop\new.txt");
            //Console.WriteLine("复制成功");
            //Console.ReadKey();


            //剪切
            File.Move(@"C:\Users\SpringRain\Desktop\code.txt", @"C:\Users\SpringRain\Desktop\newnew.txt");
            Console.WriteLine("剪切成功");
            Console.ReadKey();


            //Console.WriteLine(sizeof(char));
            //Console.ReadKey();
            //Console.WriteLine(sizeof(string));a  "dsfdsfds"
            //Console.ReadKey();
        }
    }
}
