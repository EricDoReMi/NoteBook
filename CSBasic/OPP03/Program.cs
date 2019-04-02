using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OPP03
{
    class Program
    {
        static void Main(string[] args)
        {
            Car car = new Car();
            car.Run();
            var v = new Vehicle();
            v.Run();

            Vehicle v1 = new Car();
            v1.Run();

            Vehicle v2 = new RaseCar();
            v2.Run();
        }
    }

    class Vehicle {
        private int _speed;
        public virtual int Speed {
            get {
                return _speed;
            }
            set {
                _speed = value;
            }
        }
        public virtual void Run() {
            Console.WriteLine("I'm running");
            _speed = 100;
        }
    }

    class Car : Vehicle {
        private int _rpm;

        public override int Speed {
            get {
                return _rpm / 100;
            }
            set {
                _rpm = value * 100;
            }
        }

        //重写父类方法
        public override void Run()
        {
            Console.WriteLine("Car is running");
            _rpm = 5000;
        }
    }

    class RaseCar : Car {
        public override void Run()
        {
            Console.WriteLine("Rase Car is running");
        }
    }
}
