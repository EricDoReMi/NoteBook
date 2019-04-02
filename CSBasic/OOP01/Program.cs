using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP01
{
    class Program
    {
        static void Main(string[] args)
        {
            Type t = typeof(Car);
            Type tb = t.BaseType;
            Console.WriteLine(tb.FullName);

            //一个子类的实例也是一个父类的实例
            Car car = new Car();
            Console.WriteLine(car is Vehicle);//true
            Console.WriteLine(car is Object);//true

            //父类类型变量引用子类类型实例
            Vehicle vehicle = new Car();
            Object o1 = new Vehicle();
            Object o2 = new Car();
        }
    }

    //使用sealed修饰的类是不能再被其他类继承的
    sealed class Man {

    }

    class Vehicle {
        public string Owner { get; set; }
    }

    //Car 继承了 Vehicle，在C#中一个类只能有一个基类，但可以实现很多接口
    //子类的访问级别不能超过父类
    class Car:Vehicle {

    }

    class RaceCar : Car {

    }
}
