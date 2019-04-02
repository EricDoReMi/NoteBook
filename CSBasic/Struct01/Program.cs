using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Struct01
{
    class Program
    {
        static void Main(string[] args)
        {
            Student student = new Struct01.Student() { ID=101,Name="aaa"};
            object obj = student;//装箱，将值类型复制到堆内存中，用obj引用堆内存中的对象
            Student student2 = (Student)obj;//拆箱
            student.Name = "a";
            student2.Name = "b";//对于结构体类型，因为是值类型，所以复制都是直接复制
            Console.WriteLine(student.Name);


        }
    }

    interface ISpeak {
        void Speak();
    }

    //结构体都是值类型
    struct Student :ISpeak{
        public int ID { get; set; }
        public string Name { get; set; }

        public void Speak()
        {
            Console.WriteLine("Say Hello");
        }
    }
}
