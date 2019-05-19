using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ArrayList练习
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建一个集合，里面添加一些数字，求平均值与和,最大值，最小值
            //ArrayList list = new ArrayList();
            //list.AddRange(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
            //int sum = 0;
            //int max = (int)list[0];
            //for (int i = 0; i < list.Count; i++)
            //{
            //    if ((int)list[i] > max)
            //    {
            //        max = (int)list[i];
            //    }
            //    sum += (int)list[i];
            //}
            //Console.WriteLine(sum);
            //Console.WriteLine(max);
            //Console.WriteLine(sum/list.Count);
            //Console.ReadKey();
            //写一个长度为10的集合，要求在里面随机地存放10个数字（0-9），
            //但是要求所有的数字不重复
            //ArrayList list = new ArrayList();
            //Random r = new Random();
            //for (int i = 0; i <10; i++)
            //{
            //    int rNumber = r.Next(0, 10);
            //    //集合中没有这个随机数
            //    if (!list.Contains(rNumber))
            //    {
            //        list.Add(rNumber);
            //    }
            //    else//集合中有这个随机数
            //    {
            //        //一旦产生了重复的随机数 这次循环就不算数
            //        i--;
            //    }

            //}


            //for (int i = 0; i < list.Count; i++)
            //{
            //    Console.WriteLine(list[i]);
            //}
            //Console.ReadKey();



            string str = "2++b/c*d/e";
            string[] strNew = str.Split(new char[] { '+', '-', '*', '/' });



            StringBuilder sb = new StringBuilder();//capcity count

            sb.Append("12312312312312312");
            Console.WriteLine(sb.Capacity);
            //char[] chs=  {'1','2','3'};
            Console.ReadKey();

        }
    }
}
