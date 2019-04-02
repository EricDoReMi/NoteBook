using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClassAndInstance
{
    class Program
    {
        static void Main(string[] args)
        {
            Form myForm;
            Form myForm2;
            myForm = new Form();
            myForm2 = myForm;
            myForm2.Text = Math.Pow(2,3).ToString();
            myForm.ShowDialog();
        }
    }
}
