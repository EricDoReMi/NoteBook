using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 静态与非静态的区别
{
    class Program
    {
        static void Main(string[] args)
        {
            Person p = new Person();
            p.M1();//通过实例调用非静态方法
            Person.M2();//通过类名直接调用静态方法
            Person.Name = "小白";
        }
    }
}
