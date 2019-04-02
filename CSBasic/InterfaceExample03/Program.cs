using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceExample03
{
    class Program
    {
        static void Main(string[] args)
        {
            var user = new PhoneUser(new NokiaPhone());
            user.UsePhone();
        }
    }

    interface IPhone {
        void Dail();
        void PickUp();
        void Send();
        void Receive();
    }

    class PhoneUser {
        private IPhone _phone;
        public PhoneUser(IPhone phone) {
            _phone = phone;
        }
        public void UsePhone() {
            _phone.Dail();
            _phone.PickUp();
            _phone.Send();
            _phone.Receive();
        }
    }

    class NokiaPhone : IPhone
    {
        public void Dail()
        {
            Console.WriteLine("Nokia Dailed");
        }

        public void PickUp()
        {
            Console.WriteLine("Nokia PickUped");
        }

        public void Receive()
        {
            Console.WriteLine("Nokia Received");
        }

        public void Send()
        {
            Console.WriteLine("Nokia sended");
        }
    }

    class EricssonPhone : IPhone
    {
        public void Dail()
        {
            Console.WriteLine("Ericsson Dailed");
        }

        public void PickUp()
        {
            Console.WriteLine("Ericsson PickUped");
        }

        public void Receive()
        {
            Console.WriteLine("Ericsson Received");
        }

        public void Send()
        {
            Console.WriteLine("Ericsson Sended");
        }
    }
}
