using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace HashTable概念
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建HashTable
            Hashtable ht = new Hashtable();
            ht.Add(1,"张三");
            ht.Add(2,true);
            ht.Add(3, '男');
            ht.Add(false,"错误的");
            ht[1] = "bbb";//用这种方式向Hashtable中添加数据,C#会自动判断是否有key这个键,若有则添加,若没有则不添加,Add方法则不会进行判断,是直接添加,若有会直接报错
            if (!ht.Contains(1)) {
                ht.Add(1,"aaa");
            }

            //在键值对集合中 是根据键去找值的
            Console.WriteLine(ht[1]);
            Console.WriteLine(ht[2]);
            Console.WriteLine(ht[3]);

            Console.WriteLine(ht[false]);

            Console.WriteLine("==========================");
            for (int i = 0; i < ht.Count; i++)
            {
                Console.WriteLine(ht[i]);
            }
            Console.ReadKey();

            //遍历Hashtable---通过键
            foreach (var item in ht.Keys)
            {
                Console.WriteLine("Key {0} Value {1}",item,ht[item]);
            }

            ht.Remove(3);//按Key去Remove数据
            ht.Clear();//清空集合中所有元素


        }
    }
}
