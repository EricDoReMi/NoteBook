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

    //接口
    interface IVehicle
    {
        void Stop();
        void Fill();
        void Run();
    }

    abstract class Vehicle : IVehicle
    {
        public  void Stop()
        {
            Console.WriteLine("Stoped!");
        }
        public  void Fill()
        {
            Console.WriteLine("Pay and fill");
        }

        public abstract void Run();
    }

    class Car : Vehicle
    {
        public override  void Run()
        {
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


}

/*
 * 为做基类而生的“抽象类”与“开放/关闭原则”
 */
