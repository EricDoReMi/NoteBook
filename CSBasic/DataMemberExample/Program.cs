using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataMemberExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Student.Amount);
            Student stu1 = new Student(1);
            stu1.Age = 60;
            stu1.Score = 90;

            Student stu2 = new Student(1);
            stu2.Age = 25;
            stu2.Score = 60;

            List<Student> stuList = new List<Student>();

            for (int i=0;i<100;i++) {
                Student stu = new Student(i);
                stu.Age = 25;
                stu.Score = i;
                stuList.Add(stu);
            }

            int totalAge = 0;
            int totalScore = 0;

            foreach (var stu in stuList)
            {
                totalAge += stu.Age;
                totalScore += stu.Score;
             }

            Student.AverageScore = totalScore / Student.Amount;
            Student.AverageAge = totalAge / Student.Amount;

            Student.ReportAmount();
            Student.ReportAverageAge();
            Student.ReportAverageScore();

        }
    }

    struct Color
    {
        public int Red;
        public int Green;
        public int Blue;
    }

    class Brush
    {
        public static readonly Color DefaultColor;
        static Brush()
        {
            Brush.DefaultColor = new Color() { Red=0,Green=0,Blue=0};//为结构体赋值
        }
    }

    class Student
    {
        public readonly int ID;//只读实例字段只在构造函数时赋值，以后就不能修改了
        public int Age=20;//实例字段了，实例成员变量在实例新建时初始化
        public int Score;
        public static int AverageAge;
        public static int AverageScore;
        public static int Amount=100;//静态成员变量在类加载时初始化，只初始化一次

        //当一个数据类型被加载时，它的静态构造器会被调用，并且只调用一次
        static Student(){
            Student.Amount = 200;
        }

        public Student(int id)
        {
            this.ID = id;
            Student.Amount++;
        }

        public static void ReportAmount() {
            Console.WriteLine(Student.Amount);
        }

        public static void ReportAverageAge()
        {
            Console.WriteLine(Student.AverageAge);
        }

        public static void ReportAverageScore()
        {
            Console.WriteLine(Student.AverageScore);
        }

    }
}
