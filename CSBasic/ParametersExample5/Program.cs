using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq;

namespace ParametersExample5
{
    class Program
    {
        static void Main(string[] args)
        {
            //传入具名参数,score是可选参数
            PrintInfo(age:18,name:"Tim");

            double x = 3.141592653;
            double y = x.Round(3);
            Console.WriteLine(y);

            List<int> myList = new List<int>() { 11,12,13,9,15};
            bool result = myList.All(i=>i>10);//判断一个集合中的元素是否都大于10
            Console.WriteLine(result);
        }

        static void PrintInfo(string name,int age,int score=30)
        {
            Console.WriteLine("Hello {0},you are {1},score:{2}",name,age,score);
        }
    }

    //扩展方法(this参数)
    /***
     * 方法必须是共有，静态的，即被public static所修饰
     * 必须是形参列表中的第一个参数，由this修饰
     * 必须由一个静态类（一般类名为SomeTypeExtension）来统一收纳对SomeType类型的扩展方法了
     * 
     * 
     * **/
    static class DoubleExtension
    {
        public static double Round(this double input, int digits)
        {
            double result = Math.Round(input, digits);
            return result;
        }
    }

    
}
