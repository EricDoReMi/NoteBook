using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ticket练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Ticket t = new Ticket(90);
            t.ShowTicket();
            Console.ReadKey();
        }
    }
}
