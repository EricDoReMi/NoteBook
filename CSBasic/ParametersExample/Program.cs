using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParametersExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Student stu = new Student();
            int y = 100;
            stu.AddOne(y);
            Console.WriteLine(y);

            Student2 stu2 = new Student2() { Name="Tim"};
            SomeMethod(stu2);
            //GetHashCode方法可以获得每个对象的hashcode唯一值，每个对象的hashcode都不一样了
            Console.WriteLine(stu2.GetHashCode());
        }

        //引用类型变量的传值
        static void SomeMethod(Student2 stu)
        {
            stu = new Student2() { Name = "Tom" };
            Console.WriteLine(stu.GetHashCode());
        }
        
    }

    class Student
    {
        //x是一个值参数
        public void AddOne(int x)
        {
            x = x + 1;
            Console.WriteLine(x);
        }
    }

    class Student2
    {
        public string Name { get; set; }
    }
}
