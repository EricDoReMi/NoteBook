using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 方法的递归
{
    class Program
    {
        static void Main(string[] args)
        {
            TellStory();
            Console.ReadKey();
        }

        public static int i = 0;
        public static void TellStory() {
            Console.WriteLine("从前有个山");
            Console.WriteLine("山里有个庙");
            Console.WriteLine("庙里有个老和尚在讲故事");
            i++;
            if (i >= 10) {
                return;
            }
            TellStory();
        }
    }
}
