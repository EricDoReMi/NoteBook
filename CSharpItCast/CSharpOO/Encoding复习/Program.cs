using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Encoding复习
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
             里氏转换：
             * 1、子类可以赋值给父类(如果有一个方法需要一个父类作为参数，我们可以传第一个子类对象)
             * 2、如果父类中装的是子类对象，则可以将这个父类强转为子类对象
             */

            //Person p = new Student();
            ////is as
            //Student ss = p as Student;
            //ss.StudentSayHello();
            //Console.ReadKey();
            //if (p is Student)
            //{
            //    ((Student)p).StudentSayHello();
            //}
            //else
            //{
            //    Console.WriteLine("转换失败");
            //}
            //Console.ReadKey();


            //ArrayList list = new ArrayList();
            //Remove RemoveAt  RemoveRange  Clear  Insert  InsertRange
            //Reverse  Sort

            //Hashtable ht = new Hashtable();
            //ht.Add(1, "张三");
            //ht.Add(true, '男');
            //ht.Add(3.14, 5000m);
            ////在键值对集合中 键必须是唯一的
            ////ht.Add(1, "李四");
            //ht[1] = "李四";
            ////ht.ContainsKey
            //foreach (var item in ht.Keys)
            //{
            //    Console.WriteLine("{0}------------{1}",item,ht[item]);
            //}
            //Console.ReadKey();

            //Path


            //File
            //Create  Delete Copy Move

            //byte[] buffer = File.ReadAllBytes(@"C:\Users\SpringRain\Desktop\抽象类特点.txt");
            ////将字节数组中的每一个元素都要按照我们指定的编码格式解码成字符串
            ////UTF-8  GB2312 GBK ASCII  Unicode
            //string s = Encoding.Default.GetString(buffer);

            //Console.WriteLine(s);
            //Console.ReadKey();

            //没有这个文件的话 会给你创建一个 有的话 会给你覆盖掉
            //string str="今天天气好晴朗处处好风光";
            ////需要将字符串转换成字节数组
            //byte[] buffer= Encoding.Default.GetBytes(str);
            //File.WriteAllBytes(@"C:\Users\SpringRain\Desktop\new.txt", buffer);
            //Console.WriteLine("写入成功");
            //Console.ReadKey();


            //string[] contents = File.ReadAllLines(@"C:\Users\SpringRain\Desktop\抽象类特点.txt", Encoding.Default);
            //foreach (string item in contents)
            //{
            //    Console.WriteLine(item);
            //}
            //Console.ReadKey();


            //string str = File.ReadAllText("抽象类特点.txt", Encoding.Default);
            //Console.WriteLine(str);
            //Console.ReadKey();

            //File.WriteAllLines(@"C:\Users\SpringRain\Desktop\new.txt", new string[] { "aoe", "ewu" });
            //Console.WriteLine("OK");
            //Console.ReadKey();


            //File.WriteAllText(@"C:\Users\SpringRain\Desktop\new.txt", "张三李四王五赵六");
            //Console.WriteLine("OK");
            //Console.ReadKey();

            //File.AppendAllText(@"C:\Users\SpringRain\Desktop\new.txt", "看我有木有把你覆盖掉");
            //Console.WriteLine("OK");
            //Console.ReadKey();

        }
    }


    public class Person
    {
        public void PersonSayHello()
        {
            Console.WriteLine("我是老师");
        }
    }

    public class Student : Person
    {
        public void StudentSayHello()
        {
            Console.WriteLine("我是学生");
        }
    }
}
