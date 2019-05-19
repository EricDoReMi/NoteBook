using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _01面向对象概念
{
    public class Person
    {
        private string _name;
        private int _age;
        private char _gender;

        public string Name {
            get { return _name; }
            set { _name = value; }
        }

        public int Age {
            get { return _age; }
            set {

                if (value < 0 || value > 200) {
                    value = 0;
                }
                _age = value;

            }
        }

        public char Gender {
            get {
                if (_gender != '男' && _gender != '女') {
                    return _gender = '男';
                }
                return _gender;
            }
            set { _gender = value; }
        }

        public void CHLSS()
        {
            Console.WriteLine("我是{0},今年{1}岁,我是{2},我爱吃喝拉撒睡!",this.Name,this.Age,this.Gender);
        }
    }

    
}
