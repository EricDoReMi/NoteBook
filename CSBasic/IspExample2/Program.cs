using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IspExample2
{
    class Program
    {
        static void Main(string[] args)
        {
            IKiller killer = new WarmKiller();
            killer.Kill();
            var wk = killer as WarmKiller;
            wk.Love();
          
        }
    }

    interface IGentleman {
        void Love();
    }

    interface IKiller {
        void Kill();
    }

    class WarmKiller : IGentleman, IKiller {

        public void Love() {
            Console.WriteLine("I will love you forever...");
        }

        void IKiller.Kill()
        {
            Console.WriteLine("I will kill!!!");
        }
    }
}
