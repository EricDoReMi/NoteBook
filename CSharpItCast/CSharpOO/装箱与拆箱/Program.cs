using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 装箱与拆箱
{
    class Program
    {
        static void Main(string[] args)
        {
            //int n = 10;
            //object o = n;//装箱
            //int nn = (int)o;//拆箱


            //ArrayList list = new ArrayList();
            //List<int> list = new List<int>();
            ////这个循环发生了100万次装箱操作
            //Stopwatch sw = new Stopwatch();
            ////00:00:02.4370587
            ////00:00:00.2857600
            //sw.Start();
            //for (int i = 0; i < 10000000; i++)
            //{
            //    list.Add(i);
            //}
            //sw.Stop();
            //Console.WriteLine(sw.Elapsed);
            //Console.ReadKey();


            //这个地方没有发生任意类型的装箱或者拆箱
            //string str = "123";
            //int n = Convert.ToInt32(str);


            int n = 10;
            IComparable i = n;//装箱,int类型继承了IComparable接口

            //发生
        }
    }
}
