using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConversionExample5
{
    class Program
    {
        static void Main(string[] args)
        {
            Stone stone = new Stone();
            stone.Age = 5000;
            Monkey m =(Monkey)stone;//implicit不用加(Monkey)
            Console.WriteLine(m.Age);
        }
    }

    class Stone
    {
        public int Age;
        //强制类型转换操作符 explicit 表示显示类型转换，operator 表示操作符
        //若改成implicit则表示显示类型转换
        public static explicit operator Monkey(Stone stone)
        {
            Monkey m = new Monkey();
            m.Age = stone.Age / 500;
            return m;   
        }
    }

    class Monkey
    {
        public int Age;
    }

}
