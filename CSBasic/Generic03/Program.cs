using System;
using System.Collections.Generic;
//CShape提供的泛型接口了

namespace Generic03
{
    class Program
    {
        static void Main(string[] args)
        {
            IList<int> list = new List<int>();
            for (int i = 0; i < 100; i++)
            {
                list.Add(i);
            }

            IDictionary<int, string> dict = new Dictionary<int, string>();
            dict[1] = "a";
            dict[2] = "b";

            int[] a1 = { 1, 2, 3, 4, 5 };
            int[] a2 = { 1, 2, 3, 4, 5, 6 };
            var result = Zip<int>(a1, a2);
            Console.WriteLine(string.Join(",",result));
        }

        static T[] Zip<T>(T[] a, T[] b) {
            T[] zipped = new T[a.Length + b.Length];
            int ai = 0, bi = 0, zi = 0;
            do {
                if (ai < a.Length) zipped[zi++] = a[ai++];
                if (bi < b.Length) zipped[zi++] = b[bi++];
            } while (ai<a.Length||bi<b.Length);

            return zipped;
        }
    }
}
