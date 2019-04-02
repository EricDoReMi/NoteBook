using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OPP05
{
    class Program
    {
        static void Main(string[] args)
        {
            Vehicle v = new Car();
            v.Run();
        }
    }

    //纯抽象类了，实际上可以改为接口
    abstract class VehicleBase {
        abstract public void Stop();
        abstract public void Fill();
        public abstract void Run();
    }

    abstract class Vehicle:VehicleBase {
        public override void Stop() {
            Console.WriteLine("Stoped!");
        }
        public override void Fill() {
            Console.WriteLine("Pay and fill");
        }
        
    }

    class Car:Vehicle {
        public override void Run() {
            Console.WriteLine("Car is running...");
        }
    }

    class Truck : Vehicle
    {
        public override void Run()
        {
            Console.WriteLine("Truck is running...");
        }
    }

    abstract class Student {
        //没有被实现的函数成员
        abstract public void Study();
    }
}

/*
 * 为做基类而生的“抽象类”与“开放/关闭原则”
 */