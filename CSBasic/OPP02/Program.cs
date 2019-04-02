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
            Car car = new Car("A");
            
        }
    }

    class Vehicle
    {
        public string Owner { get; set; }
        public Vehicle(string owner)
        {
            this.Owner = owner;
        }
    }

    //Car 继承了 Vehicle，在C#中一个类只能有一个基类，但可以实现很多接口
    //子类的访问级别不能超过父类
    class Car : Vehicle
    {
        //子类构造器必须先调用父类构造器
        public Car(string owner):base(owner)
        {
            
        }

        public void ShowOwner() {
            Console.WriteLine(this.Owner);
            Console.WriteLine(base.Owner);

        }
    }

    class RaceCar : Car
    {
        public RaceCar(string owner) : base(owner)
        {
        }
    }
}
