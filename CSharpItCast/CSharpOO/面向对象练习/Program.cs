using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 面向对象练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Student xbStu = new Student("小白", 18, '男', 90, 90, 80);
            Student xlStu = new Student("小榄",18,'女',95,80,95);

            Student zsStu = new Student("张三",18,'男');

            zsStu.ShowScore();
            Console.ReadKey();
        }
    }
}
