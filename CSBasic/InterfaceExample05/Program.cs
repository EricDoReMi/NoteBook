using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceExample05
{
    class Program
    {
        static void Main(string[] args)
        {
            var fan = new DeskFan(new PowerSupply());
            Console.WriteLine(fan.Work());
        }
    }

   public interface IpowerSupply {
        int GetPower();
    }

    public class PowerSupply:IpowerSupply {
        public int GetPower() {
            return 100;
        }
    }

    public class DeskFan {
        private IpowerSupply _powerSupply;
        public DeskFan(IpowerSupply powerSupply) {
            _powerSupply = powerSupply;
        }

        public string Work() {
            int power = _powerSupply.GetPower();
            if (power <= 0)
            {
                return "Won't work";
            }
            else if (power < 100)
            {
                return "Slow";
            }
            else if (power < 200)
            {
                return "Work fine";
            }
            else {
                return "warning";
            }
        }
    }
}
