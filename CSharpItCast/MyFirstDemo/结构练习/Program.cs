using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 结构练习
{
    public struct MyColor {
        public int _red;
        public int _green;
        public int _blue;
    }
    class Program
    {
        static void Main(string[] args)
        {
            //1.定义一个结构叫MyColor，有三个成员，分别定义为int类型的red，green，blue 2.声明一个了MyColor类型的变量，并对其成员赋值，使MyColor可以表示成一个红色

            MyColor mc;
            mc._red = 255;
            mc._blue = 0;
            mc._green = 0;

        }
    }
}
