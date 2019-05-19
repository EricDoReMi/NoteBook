
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    namespace ToString的问题
    {
        class Program
        {
            static void Main(string[] args)
            {
                //我们将一个对象输出到控制台  默认情况下 打印的就是这个对象所在的类的命名空间
                int[] nums = { 1, 2, 3, 4, 5 };
                Console.WriteLine(nums.ToString());
                Person p = new Person();
                Console.WriteLine(p.ToString());
                Console.ReadKey();
            }
        }
        public class Person
        {
            public void SayHello()
            {
                Console.WriteLine("我是人类");
            }
        }
    }


