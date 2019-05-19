using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 结构
{
    public enum Gender {
        男,
        女
    }
    public struct Person {
        public string _name;
        public int _age;
        public Gender _gender;
    }
    class Program
    {
        static void Main(string[] args)
        {
            Person zsPerson;
            zsPerson._name = "张三";
            zsPerson._age = 21;
            zsPerson._gender = Gender.男;

            Person lsPerson;
            lsPerson._name = "李四";
            lsPerson._age = 22;
            lsPerson._gender = Gender.男;

            Console.WriteLine(zsPerson._name);
            Console.WriteLine(lsPerson._name);
            Console.ReadKey();

        }
    }
}
