using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Enum01
{
    class Program
    {
        static void Main(string[] args)
        {
            Person person = new Enum01.Person();
            person.Level = Level.Employee;

            Person boss = new Enum01.Person();
            boss.Level = Level.Boss;


        }
    }

    enum Level {
        Employee,//0
        Manager,//1
        Boss,//2
        BigBoss//3
    }

    //枚举类型的比特位用法
    enum Skill {
        Drive=1,
        Cook=2,
        Program=4,
        Teach=8
    }

    class Person {
        public int ID { get; set; }
        public string Name { get; set; }
        public Level Level { get; set; }
        public Skill Skill { get; set; }
    }
}
