using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;

namespace TypeClasss
{
    class Program
    {
        static void Main(string[] args)
        {
            int x;
            x = 100;
            long y;
            y = 100L;
            //x = 100L;不能将长整型放入短整型中

            bool b;
            b = true;

            if (x == 200) {
                Console.WriteLine("It's ok");
                Console.ReadKey();
            }

            //C#模仿动态语言
            /*dynamic myVar = 100;
            Console.WriteLine(myVar);
            myVar = "Mr.Okay!";
            Console.WriteLine(myVar);
            Console.ReadKey();*/

            //反射的基础原理了
            Type myType = typeof(Form);
            Console.WriteLine(myType.FullName);
            PropertyInfo[] pInfos = myType.GetProperties();
            MethodInfo[] mInfos = myType.GetMethods();

            foreach (var item in mInfos)
            {
                Console.WriteLine(item.Name);

            }

            Console.ReadKey();

            Form f = new Form();
            //枚举类型了
            f.WindowState = FormWindowState.Maximized;
            f.ShowDialog();

            //小的类型可以存入大的类型中
            short t = 200;
            int c = t;




        }
    }
}
