using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PropertyExample
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Student s1 = new Student();
                s1.SetAge(10);
                Student s2 = new Student();
                s2.SetAge(20);
                Student s3 = new Student();
                s3.SetAge(15);

                Teacher t1 = new Teacher();
                t1.Age = 20;
                t1.Age = 30;

                Car c1 = new Car();
                c1.Age = 18;
                Console.WriteLine(c1.CanWork);
            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
            }
            

        }
    }

    class Student
    {
        private int age;
        public int GetAge() {
            return this.age;
        }
        public void SetAge(int value) {
            if (value >= 0 && value <= 120)
            {
                this.age = value;
            }
            else
            {
                throw new Exception("Age value has error ! ");
            }
        }
    }

    class Teacher
    {
        private int age;
        public int Age//age字段的包装器，相当于get,set方法
        {
            get
            {
                return this.age;
            }

            set
            {
                if (value >= 0 && value <= 120)//value是上线文变量，是用于传递set参数
                {
                    this.age = value;
                }
                else
                {
                    throw new Exception("Age value has error ! ");
                }
            }
        }
    }

    class Car
    {
        private int age;

        //属性的完整声明
        public int Age
        {
            get { return age; }
            set { age = value; }
        }

        private static int amount;

        public static int Amount
        {
            get { return amount; }
            set { amount = value; }
        }

        //属性的简略声明
        public int Account { get; set; }

        //动态计算值的属性
        public bool CanWork { get

            {
                if (this.Age >= 16)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

        }


    }


}
