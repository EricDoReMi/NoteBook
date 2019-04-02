using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateReview
{
    class Program
    {
        static void Main(string[] args)
        {
            MyDele dele1 = new MyDele(M1);
            Student s = new Student();
            dele1 += s.SayHello;
            //dele1.Invoke();
            dele1();

            MyDele2 mDele2 = new MyDele2(s.add);
            int res=mDele2(1,2);
            Console.WriteLine(res);
        }

        static void M1()
        {
            Console.WriteLine("M1 is called!");
        }
    }

    class Student {
        public void SayHello() {
            Console.WriteLine("Hello,I'm a student!");
        }

        public int add(int x,int y) {
            return x + y;
        }
    }

    //声明一个委托
    delegate void MyDele();
    delegate int MyDele2(int a,int b);
}
