using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IspExample
{
    class Program
    {
        static void Main(string[] args)
        {
            var driver = new Driver(new HeavyTank());
            driver.Drive();
        }
    }

    class Driver {
        private IVehicle _vehicle;
        public Driver(IVehicle vehicle) {
            _vehicle = vehicle;
        }
        public void Drive() {
            _vehicle.Run();
        }
    }

    interface IVehicle {
        void Run();
    }

    class Car : IVehicle
    {
        public void Run()
        {
            Console.WriteLine("Car Run");
        }
    }

    class Truck : IVehicle
    {
        public void Run()
        {
            Console.WriteLine("Truck Run");
        }
    }

    interface IWeapon {
        void Fire();
    }

    interface ITank : IWeapon, IVehicle {

    }
    class LightTank : ITank
    {
        public void Fire()
        {
            Console.WriteLine("Bo!");
        }

        public void Run()
        {
            Console.WriteLine("TankRun!");
        }
    }

    class MediumTank : ITank
    {
        public void Fire()
        {
            Console.WriteLine("Bo!!");
        }

        public void Run()
        {
            Console.WriteLine("TankRun!!");
        }
    }

    class HeavyTank : ITank
    {
        public void Fire()
        {
            Console.WriteLine("Bo!!!");
        }

        public void Run()
        {
            Console.WriteLine("TankRun!!!");
        }
    }

}
