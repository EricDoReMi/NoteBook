using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 静态与非静态的区别
{
    class Person
    {
        private static string _name;
        private char _gender;

        public static string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        public char Gender
        {
            get { return _gender; }
            set { _gender = value; }
        }
        public void M1() {
            Console.WriteLine("Person M1!");
        }

        public static void M2() {
            Console.WriteLine("Static M2");
        }
    }
}
