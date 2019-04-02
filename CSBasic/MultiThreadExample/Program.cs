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

            Student stu1 = new MulticastDelegateExample.Student() { ID = 1, PenColor = ConsoleColor.Yellow };
            Student stu2 = new MulticastDelegateExample.Student() { ID = 2, PenColor = ConsoleColor.Green };
            Student stu3 = new MulticastDelegateExample.Student() { ID = 3, PenColor = ConsoleColor.Red };

            //Action action1 = new Action(stu1.DoHomework);
            //Action action2 = new Action(stu2.DoHomework);
            //Action action3 = new Action(stu3.DoHomework);
            //BeginInvoke方法实现了隐式的异步调用，第一个参数是回调函数
            //action1.BeginInvoke(null,null);
            //action2.BeginInvoke(null, null);
            //action3.BeginInvoke(null, null);

            //使用Thread进行显示的异步调用
            //Thread thread1 = new Thread(new ThreadStart(stu1.DoHomework));
            //Thread thread2 = new Thread(new ThreadStart(stu2.DoHomework));
            //Thread thread3 = new Thread(new ThreadStart(stu3.DoHomework));
            //thread1.Start();
            //thread2.Start();
            //thread3.Start();

            //使用Task
            Task task1 = new Task(new Action(stu1.DoHomework));
            Task task2 = new Task(new Action(stu2.DoHomework));
            Task task3 = new Task(new Action(stu3.DoHomework));
            task1.Start();
            task2.Start();
            task3.Start();

            for (int i=0;i<10;i++)
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.WriteLine("Main thread{0}",i);
                Thread.Sleep(1000);
            }


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
                Console.WriteLine("Student {0} doing homework {1} hours", this.ID, i);
                Thread.Sleep(1000);
            }
        }
    }
}
