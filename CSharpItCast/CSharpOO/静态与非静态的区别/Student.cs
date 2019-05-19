using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 静态与非静态的区别
{
    public static class Student
    {
        private static string _name;
        
        public static string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        public static void M1()
        {
            Console.WriteLine("Student M1!");
        }
    }
}
