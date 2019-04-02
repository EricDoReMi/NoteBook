using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyLib.MyNameSpace;

namespace ClassDemo2
{
    //类的访问控制符
    //public 所有的solution内的地方都可以引用
    //internal 在一个项目中可以引用
    //private 仅当该class是另一个的class的成员时才可以使用
    class Program
    {
        static void Main(string[] args)
        {
            Calculator cal = new Calculator();
            double res = cal.Add(1.1,2.2);
            Console.WriteLine(res);
        }
    }
}

