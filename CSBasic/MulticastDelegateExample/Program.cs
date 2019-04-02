using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace MulticastDelegateExample
{
    class Program
    {
        static void Main(string[] args)
        {
            //多播委托调用,委托的执行顺序是按照封装方法的先后顺序执行
            Student stu1 = new MulticastDelegateExample.Student() { ID=1,PenColor=ConsoleColor.Yellow};
            Student stu2 = new MulticastDelegateExample.Student() { ID=2, PenColor = ConsoleColor.Green};
            Student stu3 = new MulticastDelegateExample.Student() { ID=3, PenColor = ConsoleColor.Red};
            Action action1 = new Action(stu1.DoHomework);
            Action action2 = new Action(stu2.DoHomework);
            Action action3 = new Action(stu3.DoHomework);

            action1 += action2;
            action1 += action3;

            action1();
                                    
        }
    }

    class Student
    {
        public int ID { get; set; }
        public ConsoleColor PenColor { get; set; }

        public void DoHomework()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.ForegroundColor = this.PenColor;
                Console.WriteLine("Student {0} doing homework {1} hours",this.ID,i);
                Thread.Sleep(1000);
            }
        }
    }
}
