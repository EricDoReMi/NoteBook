using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EventExample8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.button3.Click += this.ButtonClicked;
            this.button4.Click += (object sender, EventArgs e) => {
                this.textBox1.Text = "Ho";
            };
            this.button5.Click += delegate (object sender, EventArgs e) {
                this.textBox1.Text = "Yaa";
            };
        }

        private void ButtonClicked(object sender, EventArgs e)
        {
            if (sender == this.button1) {
                this.textBox1.Text = "Hello";
            }

            if (sender == this.button2) {
                this.textBox1.Text = "World";
            }

            if (sender == this.button3)
            {
                this.textBox1.Text = "Hello";
            }
        
            
        }
    }
}
