using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParametersExample2
{
    class Program
    {
        static void Main(string[] args)
        {
            int y = 1;
            IWantSideEffect(ref y);
            Console.WriteLine(y);

            Student outterStu = new Student() { Name="Tim"};
            Console.WriteLine("HashCode={0},Name={1}", outterStu.GetHashCode(), outterStu.Name);
            Console.WriteLine("-----------------");
            IWantSideEffect(ref outterStu);
            Console.WriteLine("HashCode={0},Name={1}", outterStu.GetHashCode(), outterStu.Name);
           
        }

        //引用参数会直接把外部变量的地址传入方法中，而不是直接创建外部变量的副本

        //值类型的引用参数
        static void IWantSideEffect(ref int x)
        {
            x = x + 100;
        }

        //引用类型的引用参数
        static void IWantSideEffect(ref Student stu)
        {
            stu = new Student() { Name = "Tom" };
            Console.WriteLine("HashCode={0},Name={1}",stu.GetHashCode(),stu.Name);
        }
    }

    class Student
    {
        public string Name { get; set; }
    }
}
