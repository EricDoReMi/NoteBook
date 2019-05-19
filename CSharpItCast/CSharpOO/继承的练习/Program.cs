using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 继承的练习
{
    class Program
    {
        static void Main(string[] args)
        {
            //记者：我是记者  我的爱好是偷拍 我的年龄是34 我是一个男狗仔
            //司机：我叫舒马赫 我的年龄是43 我是男人  我的驾龄是 23年
            //程序员：我叫孙全 我的年龄是23 我是男生 我的工作年限是 3年

            Reporter rep = new Reporter("狗仔", 34, '男', "偷拍");

            rep.ReporterSayHello();


            Programmer pro = new Programmer("程序猿", 23, '男', 3);
            pro.ProgrammerSayHello();

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
    }
}
