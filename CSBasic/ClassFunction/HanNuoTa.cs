using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassFunction
{       /// <summary>
        /// 汉诺塔问题递归实现
        /// </summary>
    class HanNuoTa
    {
        public static void toDoHanNuo(int num,Stack<int> a,Stack<int> b,Stack<int> c) {
            if (num == 0) {
                return;
            }

            toDoHanNuo(num - 1, a, c, b);
            c.Push(a.Pop());
            toDoHanNuo(num - 1, b, a, c);

            
        }
    }
}
