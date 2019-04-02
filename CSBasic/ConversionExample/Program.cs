using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConversionExample
{
    class Program
    {
        static void Main(string[] args)
        {
            //从控制台读入一个数据
            /*string str1 = Console.ReadLine();
            string str2 = Console.ReadLine();
            int x = Convert.ToInt32(str1);
            int y = Convert.ToInt32(str2);

            int z = int.MaxValue;
            long zl = z;*/

            Teacher t = new Teacher();
            var result = t is Teacher;
            Console.WriteLine(result.GetType().FullName);
            Console.WriteLine(result);
            result = t is Animal;
            Console.WriteLine(result);
            t.Teach();
            Human h = t;
            h.Think();
            Animal a = t;
            a.Eat();

            object o = new Teacher();
            //as操作符 将一个object类判断是不是具体类，若是则转换，若不是，则返回null
            Teacher t1= o as Teacher;

            if (t != null) {
                t1.Teach();
            }



            }

    }

    class Animal
    {
        public void Eat()
        {
            Console.WriteLine("Eat");
        }
    }

    class Human : Animal
    {
        public void Think()
        {
            Console.WriteLine("Think");
         }
    }

    class Teacher : Human
    {
        public void Teach()
        {
            Console.WriteLine("Teach");
        }
    }

    class Car
    {
        public void Run()
        {
            Console.WriteLine("Running");
        }
    }
}
