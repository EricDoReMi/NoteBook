using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OperatorsExample
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] myIntArray = new int[10];
            int[] myIntArray2 = new int[] { 1,2,3,4,5};

            Console.WriteLine(myIntArray[0]);
            Console.WriteLine(myIntArray2[myIntArray2.Length-1]);
           

            Dictionary<string, Student> stuDic = new Dictionary<string, Student>();
            for (int i = 1; i <= 100; i++)
            {
                Student stu = new Student();
                stu.Name = "s_" + i.ToString();
                stu.Score = 100;
                stuDic.Add(stu.Name,stu);
            }

            Student number6 = stuDic["s_6"];
            Console.WriteLine(number6.Score);

            Type t = typeof(int);
            Console.WriteLine(t.Namespace);
            Console.WriteLine(t.FullName);
            Console.WriteLine(t.Name);
            int c = t.GetMethods().Length;
            foreach (var item in t.GetMethods()) 
            {
                Console.WriteLine(item.Name);
            }

            int x = default(int);
            double d = default(double);
            Form myForm = default(Form);
            Console.WriteLine(myForm==null);

            Level level = default(Level);
            Console.WriteLine(level);

            Level2 level2 = default(Level2);
            Console.WriteLine(level2);

            Console.ReadKey();
        }
    }

    class Student
    {
        public string Name;
        public int Score;
    }


    enum Level
    {//枚举类型第一个对应的是0，往后就对应1，2 ...
    //在使用枚举类型时，其中的一个值要给0
        Low,
        Mid,
        High
    }

    enum Level2
    {
        Low=1,
        Mid=0,
        High=3
    }
}
