using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace 使用File类操作文件
{
    class Program { 
        static void Main(string[] args)
        {
        //byte[] buffer = File.ReadAllBytes(@"C:\Users\SpringRain\Desktop\1.txt");


        //EncodingInfo[] en = Encoding.GetEncodings();
        //foreach (var item in en)
        //{
        //    Console.WriteLine(item.DisplayName);
        //}
        //Console.ReadKey();
        //将字节数组转换成字符串
        //string s = Encoding.UTF8.GetString(buffer);
        //Console.WriteLine(s);
        // Console.WriteLine(buffer.ToString());
        //编码格式：指的就是你以怎样的形式来存储字符串
        //a-z 0-9  Ascii  117 u---->汉字--->GB2312 GBK
        //int n = (int)'u';
        //char c = (char)188;
        //Console.WriteLine(c);
        ////Console.WriteLine(n);


        //string s="今天天气好晴朗，处处好风光";
        ////将字符串转换成字节数组
        //byte[] buffer=  Encoding.Default.GetBytes(s);
        ////以字节的形式向计算机中写入文本文件
        //File.WriteAllBytes(@"C:\Users\SpringRain\Desktop\1.txt", buffer);
        //Console.WriteLine("写入成功");
        //Console.ReadKey();


        //使用File类来实现一个多媒体文件的复制操作

        //读取
        byte[] buffer = File.ReadAllBytes(@"C:\Users\SpringRain\Desktop\12333.wmv");
        Console.ReadKey();

        ////写入
        //File.WriteAllBytes(@"C:\Users\SpringRain\Desktop\new.wav", buffer);
        //Console.WriteLine("复制成功");
        //Console.ReadKey();


        //byte[] buffer=new byte[1024*1024*5];
        //while (true)
        //{
        //    File.WriteAllBytes(@"C:\Users\SpringRain\Desktop\123.wmv", buffer);
        //}

    }
}
}
