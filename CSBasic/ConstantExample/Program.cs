using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstantExample
{
    class Program
    {
        static void Main(string[] args)
        {
            const int x = 100;
            Console.WriteLine(WASPEC.WebsiteURL);


        }

    }

    class WASPEC
    {
        public const string WebsiteURL = "http://www.waspec.org";
        //public const Building location = new Building() { Address = "some Address" };这样声明会报错
        public static readonly Building location = new Building() {Address="some Address"};//只能用静态只读字段来声明
        
    }

    class Building
    {
        public Building() {

        }
        public Building(string address) {
            this.Address = address;
        }
        public string Address { get; set; }
    }
    
}
