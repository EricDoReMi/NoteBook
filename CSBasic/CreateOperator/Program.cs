using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreateOperator
{
    class Program
    {
        static void Main(string[] args)
        {
            Person person1 = new Person();
            Person person2 = new Person();
            person1.Name = "XiaonXin";
            person2.Name = "XiaoWanZi";
            List<Person> pList = person1 + person2;
            Console.WriteLine(1+2);

            foreach (var p in pList)
            {
                Console.WriteLine(p.Name);
            }

            //委托
            Action myAction = new Action(Person.sayHello);
            myAction();
            Console.ReadKey();


        }
    }

    class Person
    {
        public string Name;
        public static List<Person> operator + (Person p1,Person p2)
        {
            List<Person> people = new List<Person>();
            people.Add(p1);
            people.Add(p2);
            for (int i=0;i<11;i++)
            {
                Person child = new Person();
                child.Name = p1.Name+"&"+p2.Name+"&"+"'s child";
                people.Add(child);
            }
            return people;
        }

        public static void sayHello() {
            Console.WriteLine("hello");
        }
    }
}
