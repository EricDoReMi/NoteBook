using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OutParameterExample2
{
    class Program
    {
        static void Main(string[] args)
        {
            Student stu = new Student();
            StudentFactory.Create("xiaole", 32, out stu);
            Console.WriteLine("Name:{0},Age:{1}",stu.Name,stu.Age);
        }
    }

    class Student
    {
        public int Age { get; set; }
        public string Name { get; set; }
    }

    class StudentFactory
    {
        public static bool Create(string stuName, int stuAge, out Student result)
        {
            result = null;
            if (string.IsNullOrEmpty(stuName))
            {
                return false;
            }

            if (stuAge < 20 || stuAge > 80)
            {
                return false;
            }

            result = new Student() { Age = stuAge, Name = stuName };
            return true;
        }
        }
    }
