﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Software
{
    public partial class CEO : Form
    {
        public CEO()
        {
            InitializeComponent();
        }

        private void CEO_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }
    }
}
