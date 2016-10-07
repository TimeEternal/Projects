namespace 实验1
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem(new string[] {
            "王焱伟",
            "计14-1",
            "100"}, -1);
            this.listview1 = new System.Windows.Forms.ListView();
            this.name = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.clsass = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.score = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.用户管理ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.用户增加ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.用户浏览ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.用户删除ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出系统ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.关于ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.版权声明ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listview1
            // 
            this.listview1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.name,
            this.clsass,
            this.score});
            this.listview1.Dock = System.Windows.Forms.DockStyle.Fill;
            listViewItem1.Checked = true;
            listViewItem1.StateImageIndex = 1;
            this.listview1.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1});
            this.listview1.Location = new System.Drawing.Point(0, 25);
            this.listview1.Name = "listview1";
            this.listview1.Size = new System.Drawing.Size(284, 236);
            this.listview1.TabIndex = 1;
            this.listview1.UseCompatibleStateImageBehavior = false;
            this.listview1.View = System.Windows.Forms.View.Details;
            // 
            // name
            // 
            this.name.Text = "姓名";
            // 
            // clsass
            // 
            this.clsass.Text = "班级";
            // 
            // score
            // 
            this.score.Text = "成绩";
            // 
            // 用户管理ToolStripMenuItem
            // 
            this.用户管理ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.用户增加ToolStripMenuItem,
            this.用户浏览ToolStripMenuItem,
            this.用户删除ToolStripMenuItem,
            this.退出系统ToolStripMenuItem});
            this.用户管理ToolStripMenuItem.Name = "用户管理ToolStripMenuItem";
            this.用户管理ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.用户管理ToolStripMenuItem.Text = "用户管理";
            // 
            // 用户增加ToolStripMenuItem
            // 
            this.用户增加ToolStripMenuItem.Name = "用户增加ToolStripMenuItem";
            this.用户增加ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.用户增加ToolStripMenuItem.Text = "用户增加";
            this.用户增加ToolStripMenuItem.Click += new System.EventHandler(this.用户增加ToolStripMenuItem_Click);
            // 
            // 用户浏览ToolStripMenuItem
            // 
            this.用户浏览ToolStripMenuItem.Name = "用户浏览ToolStripMenuItem";
            this.用户浏览ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.用户浏览ToolStripMenuItem.Text = "用户浏览";
            // 
            // 用户删除ToolStripMenuItem
            // 
            this.用户删除ToolStripMenuItem.Name = "用户删除ToolStripMenuItem";
            this.用户删除ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.用户删除ToolStripMenuItem.Text = "用户删除";
            this.用户删除ToolStripMenuItem.Click += new System.EventHandler(this.用户删除ToolStripMenuItem_Click);
            // 
            // 退出系统ToolStripMenuItem
            // 
            this.退出系统ToolStripMenuItem.Name = "退出系统ToolStripMenuItem";
            this.退出系统ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.退出系统ToolStripMenuItem.Text = "退出系统";
            this.退出系统ToolStripMenuItem.Click += new System.EventHandler(this.退出系统ToolStripMenuItem_Click);
            // 
            // 关于ToolStripMenuItem
            // 
            this.关于ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.版权声明ToolStripMenuItem});
            this.关于ToolStripMenuItem.Name = "关于ToolStripMenuItem";
            this.关于ToolStripMenuItem.Size = new System.Drawing.Size(44, 21);
            this.关于ToolStripMenuItem.Text = "关于";
            // 
            // 版权声明ToolStripMenuItem
            // 
            this.版权声明ToolStripMenuItem.Name = "版权声明ToolStripMenuItem";
            this.版权声明ToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.版权声明ToolStripMenuItem.Text = "版权声明";
            this.版权声明ToolStripMenuItem.Click += new System.EventHandler(this.版权声明ToolStripMenuItem_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.用户管理ToolStripMenuItem,
            this.关于ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(284, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.listview1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form2";
            this.Text = "系统界面";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ColumnHeader name;
        private System.Windows.Forms.ColumnHeader clsass;
        private System.Windows.Forms.ColumnHeader score;
        private System.Windows.Forms.ToolStripMenuItem 用户管理ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 用户增加ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 用户浏览ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 用户删除ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 退出系统ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 关于ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 版权声明ToolStripMenuItem;
        private System.Windows.Forms.MenuStrip menuStrip1;
        public System.Windows.Forms.ListView listview1;
    }
}