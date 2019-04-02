using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassDemo01
{
    class Program
    {
        static void Main(string[] args)
        {
            Student stu = new Student(1,"xiaotu");
            stu.Report();

            //反射
            Type t = typeof(Student);
            object o = Activator.CreateInstance(t,2,"shimao");
            Student stuShiMao = o as Student;
            Console.WriteLine(stuShiMao.Name);

            dynamic stuXiaoXi = Activator.CreateInstance(t,3,"XiaoXi");
            Console.WriteLine(stuXiaoXi.Name);

            Console.WriteLine(Student.Amount);

        }
    }

    class Student {
        public int ID { get; set; }
        public string Name { get; set; }
        public static int Amount { get; set; }
        static Student()
        {
            //静态构造器用于构建静态成员
            Amount = 100;
        }
        public Student(int id,string name)
        {
            this.ID = id;
            this.Name = name;
            Amount++;
        }
        //析构器
        ~Student() {
            Amount--;
            Console.WriteLine("ByeBye");
        }
        public void Report() {
            Console.WriteLine($"I'm #{ID} student,my name is {Name}.");
        }
    }
}
