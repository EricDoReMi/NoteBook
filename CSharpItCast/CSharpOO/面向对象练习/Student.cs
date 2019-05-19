using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 面向对象练习
{
    public class Student
    {

        //析构函数了
        //帮助我们释放资源
        ~Student() {
            Console.WriteLine("我是析构函数");
        }

        //构造函数的访问修饰符必须是public
        public Student(string name,int age,char gender,int chinese,int math,int english) {
            this.Name = name;
            this.Age = age;
            this.Gender = gender;
            this.Chinese = chinese;
            this.Math = math;
            this.English = english;

        }

        //构造函数可以重载,通过this可以调用这个类里的其他构造函数
        public Student(string name, int age, char gender):this(name,age,gender,0,0,0)
        {
                

        }

        // 重写无参构造函数
        public Student():this("",0,'女',0,0,0) {
            
        }
        private string _name;

        public string Name { get => _name; set => _name = value; }

        private int _age;
        public int Age { get => _age;
            set {
                if (value < 0 || value > 200)
                {
                    value = 0;
                }
                _age = value;
            }
                
            
        }

        private char _gender;
        public char Gender { get => _gender; set
                {
                if (value != '男' && value != '女') {
                    value = '女';
                }
                _gender = value;
            }

        }

        private int _math;
        public int Math { get => _math; set => _math = value; }

        private int _english;
        public int English { get => _english; set => _english = value; }

        private int _chinese;
        public int Chinese { get => _chinese; set => _chinese = value; }

        
        public void SayHello() {
            Console.WriteLine("我是{0},今年{1}岁,我是{2}生",this.Name,this.Age,this.Gender);
        }

        public void ShowScore() {
            Console.WriteLine("我是{0},语文{1},数学{2},英语{3},平均{4}",this.Name,this.Chinese,this.Math,this.English,(this.Chinese+this.Math+this.English)/3);
        }
    }
}
