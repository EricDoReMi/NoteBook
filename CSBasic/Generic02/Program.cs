using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generic02
{
    class Program
    {
        static void Main(string[] args)
        {
            Student<int> stu = new Student<int>();
            stu.ID = 101;
            stu.Name = "a";

            Teacher t1 = new Teacher();
            t1.ID = 10000000000000000001;
            
        }
    }

    interface IUnique<TId> {
        TId ID { get; set; }
    }

    class Student<TId> : IUnique<TId> {
        public TId ID { get; set; }
        public string Name { get; set; }
    }

    class Teacher : IUnique<ulong> {
           public ulong ID { get; set;}
    }
}
