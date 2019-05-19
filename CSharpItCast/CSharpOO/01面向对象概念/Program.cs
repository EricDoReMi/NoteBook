using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _01面向对象概念
{
    class Program
    {
        static void Main(string[] args)
        {
            Person sunQuan = new Person();
            sunQuan.Name = "孙权";
            sunQuan.Age = -5;
            sunQuan.Gender = '春';
            sunQuan.CHLSS();
            Console.ReadKey();
        }
    }
}
