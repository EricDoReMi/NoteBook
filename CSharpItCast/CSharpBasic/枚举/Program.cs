using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 枚举
{

    //申明了一个枚举，枚举类型为Gender
    public enum Gender {
        男,
        女
    }

    public enum Sesons {
        春,
        夏,
        秋,
        冬
    }

    public enum QQState {
        OnLine,
        OffLine,
        Leave,
        Busy,
        QMe
    }
    class Program
    {
        static void Main(string[] args)
        {
            //使用枚举类型
            Gender gender = Gender.男;
            Sesons seson = Sesons.夏;

            #region 将枚举类型转换为int类型
            Console.WriteLine((int)QQState.OnLine);
            Console.WriteLine((int)QQState.OffLine);
            Console.WriteLine((int)QQState.Leave);
            Console.WriteLine((int)QQState.Busy);
            Console.WriteLine((int)QQState.QMe);
            #endregion

            #region 将int类型强转为枚举类型
            int n1 = 3;
            QQState state = (QQState)n1;
            Console.WriteLine(state);
            #endregion

            #region 将枚举类型转换为字符串
            //所有的类型都可以转换为string类型
            int n2 = 10;
            string str=n2.ToString();

            QQState state1 = QQState.OnLine;
            Console.WriteLine(state1.ToString());
            #endregion


            #region 将字符串转换为枚举类型
            string s = "0";
            //将s转换为枚举类型
            QQState state2 = (QQState)Enum.Parse(typeof(QQState),s);
            #endregion
            Console.ReadKey();

        }
    }
}
