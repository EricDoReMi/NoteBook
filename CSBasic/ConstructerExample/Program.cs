using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstructerExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Student stu = new Student(1,"Mr.AllRight");
            Console.WriteLine(stu.ID);
            Console.WriteLine(stu.Name);
            Student stu2 = new Student();
            Console.WriteLine(stu2.ID);
            Console.WriteLine(stu2.Name);
            Calculator c1 = new Calculator();
            int r1 = c1.Add(1, 2);

        }
    }
    class Student
    {   //构造器
        public Student(int initId,string initName) {
            this.ID = initId;
            this.Name = initName;
            
        }
        public Student() {
            this.ID = 0;
            this.Name = "no Names";
        }
        public int ID;
        public string Name;

     

    }

    class Calculator
    {


        public int Add(int a,int b)
        {
            return a + b;
        }

        public int Add(int a,int b,int c)
        {
            return a + b + c;
        }

        public int Add<T>(int a,int b)
        {
            T t;
            return a + b;
        }

        public int Add(ref int a,int b) {
            return a + b;
        }


        public double Add(double a, double b)
        {
            return a + b;
        }

    }
}
