using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndexerExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Student stu = new Student();
            stu["Math"] = 100;
            var mathScore = stu["Math"];
            Console.WriteLine(stu["Math"]);
        }
    }

    class Student
    {
        private Dictionary<string, int> scoreDictionary = new Dictionary<string, int>();
        public int? this[string subject] //索引器 int? 表示接收一个可以为空的int类型
        {
            get
            {
                if (this.scoreDictionary.ContainsKey(subject))
                {
                    return this.scoreDictionary[subject];
                }
                else {
                    return null;
                }
            }
            set {
                if (value.HasValue)//判断value是否为null
                {
                    if (this.scoreDictionary.ContainsKey(subject))
                    {
                        this.scoreDictionary[subject] = value.Value;//取得value真正的值了
                    }
                    else
                    {
                        this.scoreDictionary.Add(subject, value.Value);
                    }
                }
                else {
                    throw new Exception("Score can not be null");
                }
            }
        }
    }
}
