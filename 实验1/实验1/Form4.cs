using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验1
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = (Form2)Application.OpenForms["Form2"];
            ListViewItem t = new ListViewItem();
            t.Text = name.Text;
            t.SubItems.Add(classs.Text);
            t.SubItems.Add(score.Text);
            f2.listview1.Items.Add(t);
            this.Close();
        }

 
    }
}
