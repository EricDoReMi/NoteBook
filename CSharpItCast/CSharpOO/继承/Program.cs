using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 继承
{
    class Program
    {
        static void Main(string[] args)
        {
            //Student s = new Student();

            //Driver d = new Driver();
            Student s = new Student("学生", 18, '男', 101);
        }
    }

    public class Person
    {
        private string _name;

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        private int _age;

        public int Age
        {
            get { return _age; }
            set { _age = value; }
        }

        private char _gender;

        public char Gender
        {
            get { return _gender; }
            set { _gender = value; }
        }

        public void CHLSS()
        {
            Console.WriteLine("吃喝拉撒睡");
        }



        public Person(string name, int age, char gender)
        {
            this.Name = name;
            this.Age = age;
            this.Gender = gender;
        }

        //public Person()
        //{

        //}


    }
    public class Student : Person
    {

        public Student(string name, int age, char gender, int id)
            : base(name, age, gender)
        {
            //this.Name = name;
            //this.Age = age;
            //this.Gender = gender;
            this.Id = id;
        }


        private int _id;

        public int Id
        {
            get { return _id; }
            set { _id = value; }
        }



        public void Study()
        {
            Console.WriteLine("学生会学习");
        }
    }
    public class Teacher : Person
    {

        public Teacher(string name, int age, char gender, double salary)
            : base(name, age, gender)
        {
            this.Salary = salary;
        }

        private double _salary;
        public double Salary
        {
            get { return _salary; }
            set { _salary = value; }
        }
        public void Teach()
        {
            Console.WriteLine("老师会讲课");
        }
    }
    public class Driver : Person
    {

        public Driver(string name, int age, char gender, int driveTime)
            : base(name, age, gender)
        {
            this.DirveTime = driveTime;
        }


        private int _dirveTime;
        public int DirveTime
        {
            get { return _dirveTime; }
            set { _dirveTime = value; }
        }
        public void Drive()
        {
            Console.WriteLine("司机会开车");
        }
    }
}
