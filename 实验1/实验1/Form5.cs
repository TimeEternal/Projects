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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = (Form2)Application.OpenForms["Form2"];
            ListViewItem t = new ListViewItem();
            for (int i = 0; i < f2.listview1.Items.Count; i++)
            {
                if (textBox1.Text == f2.listview1.Items[i].Text)
                    t = f2.listview1.Items[i];
            }
            f2.listview1.Items.Remove(t);
            this.Close();
        }
    }
}
