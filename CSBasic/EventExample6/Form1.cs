using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EventExample6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.button1.Click += ButtonClick;
        }

        private void ButtonClick(object sender, EventArgs e)
        {
            this.textBox1.Text = "HelloWorld!";
        }
    }
}
