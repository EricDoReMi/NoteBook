using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 枚举练习
{
    public enum QQState
    {
        OnLine=1,//枚举默认从0开始，这样就可以让枚举默认从1开始了
        OffLine,
        Leave,
        Busy,
        QMe
    }
    /// <summary>
    /// 枚举练习了，提示用户选择一个在线状态，并将用户的输入类型转换为枚举类型
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请选择您的qq在线的状态 1--OnLine 2--OffLine 3--Leave 4--Busy");
            string input = Console.ReadLine();
            switch (input) {
                case "1":
                    QQState s1 = (QQState)Enum.Parse(typeof(QQState), input);
                    Console.WriteLine("您选择的状态是{0}",s1);
                    break;
                case "2":
                    QQState s2 = (QQState)Enum.Parse(typeof(QQState),input);
                    Console.WriteLine("您选择的状态是{0}", s2);
                    break;
                case "3":
                    QQState s3 = (QQState)Enum.Parse(typeof(QQState), input);
                    Console.WriteLine("您选择的状态是{0}", s3);
                    break;
                case "4":
                    QQState s4 = (QQState)Enum.Parse(typeof(QQState), input);
                    Console.WriteLine("您选择的状态是{0}", s4);
                    break;
                case "5":
                    QQState s5 = (QQState)Enum.Parse(typeof(QQState), input);
                    Console.WriteLine("您选择的状态是{0}", s5);
                    break;
            }

            Console.ReadKey();

        }
    }
}
