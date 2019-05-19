using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 关键字New
{
    class Program
    {
        static void Main(string[] args)
        {
            Reporter rep = new Reporter("记者", 11, '男', "偷拍");
            rep.SayHello();
            rep.Test();
            Console.ReadKey();
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


        public Person(string name, int age, char gender)
        {
            this.Name = name;
            this.Age = age;
            this.Gender = gender;
        }

        public void Test()
        {
            Console.WriteLine("测试");
        }

        public void SayHello()
        {
            Console.WriteLine("大家好，我是人类");
        }
    }


    public class Reporter : Person
    {
        public Reporter(string name, int age, char gender, string hobby)
            : base(name, age, gender)
        {
            this.Hobby = hobby;
        }


        private string _hobby;

        public string Hobby
        {
            get { return _hobby; }
            set { _hobby = value; }
        }

        public void ReporterSayHello()
        {
            Console.WriteLine("我叫{0},我是一名狗仔，我的爱好是{1}，我是{2}生，我今年{3}岁了", this.Name, this.Hobby, this.Gender, this.Age);
        }


        public new void SayHello()
        {
            Console.WriteLine("大家好，我是记者");
        }
    }


    public class Programmer : Person
    {
        private int _workYear;

        public int WorkYear
        {
            get { return _workYear; }
            set { _workYear = value; }
        }

        public void ProgrammerSayHello()
        {
            Console.WriteLine("我叫{0}，我是一名程序猿，我是{1}生，我今年{2}岁了，我的工作年限是{3}年", this.Name, this.Gender, this.Age, this.WorkYear);
        }


        public Programmer(string name, int age, char gender, int workYear)
            : base(name, age, gender)
        {
            this.WorkYear = workYear;
        }


        //隐藏从父类那里继承过来的同名成员
        public new void SayHello()
        {
            Console.WriteLine("大家好，我是程序员");
        }
    }
}
