using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TypeCShape
{
    class Program
    {
        static void Main(string[] args)
        {
            Student s = new Student();
            Student.Amount = 100;
            Console.WriteLine(Student.Amount);//静态成员变量
            s.Age = 1;//实例变量
            int[] array = new int[100];
            array[99] = 15;

            Student stu = new Student();

            const int aaa = 100;//常量

            int c = 100;
            //装箱
            object obj = c;
            //拆箱
            int y = (int)obj;
        }
    }

    class Student
    {
        public static int Amount;
        public int Age;
        public string Name;
        uint ID;
        ushort Score;
        public double Add(double a,double b)
        {
            double result = a + b;
            return result;
        }    
    }
}
 
