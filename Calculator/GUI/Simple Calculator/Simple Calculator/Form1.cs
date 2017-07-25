using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Simple_Calculator
{
    public partial class calculator : Form
    {
        int x;
        int y;
        char op;
        bool c;
        bool cc;
        public calculator()
        {
            InitializeComponent();
        }

        private void zero_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "0";
                c = false;
            }
            else
                screen.Text = screen.Text + "0";
        }

        private void one_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "1";
                c = false;
            }
            else
                screen.Text = screen.Text + "1";
        }

        private void two_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "2";
                c = false;
            }
            else
                screen.Text = screen.Text + "2";
        }

        private void three_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "3";
                c = false;
            }
            else
                screen.Text = screen.Text + "3";
        }

        private void four_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "4";
                c = false;
            }
            else
                screen.Text = screen.Text + "4";
        }

        private void five_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "5";
                c = false;
            }
            else
                screen.Text = screen.Text + "5";
        }

        private void six_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "6";
                c = false;
            }
            else
                screen.Text = screen.Text + "6";
        }

        private void seven_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "7";
                c = false;
            }
            else
                screen.Text = screen.Text + "7";
        }

        private void eight_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "8";
                c = false;
            }
            else
                screen.Text = screen.Text + "8";
        }

        private void nine_Click(object sender, EventArgs e)
        {
            if (c == true)
            {
                screen.Text = null;
                screen.Text = screen.Text + "9";
                c = false;
            }
            else 
            screen.Text = screen.Text + "9";
        }

        private void plus_Click(object sender, EventArgs e)
        {
            if (cc == true)
            {
                op = '+';
                cc = false;
                screen.Text = null;
            }
            else
            {
                if (x == 0)
                {
                    x = Convert.ToInt32(screen.Text);
                    op = '+';
                    screen.Text = null;
                }
                else
                {
                    y = Convert.ToInt32(screen.Text);
                    switch (op)
                    {
                        case '+':
                            {
                                x = x + y;
                                break;
                            }
                        case '-':
                            {
                                x = x - y;
                                break;
                            }
                        case '*':
                            {
                                x = x * y;
                                break;
                            }
                        case '/':
                            {
                                x = x / y;
                                break;
                            }
                        default:
                            {
                                screen.Text = "ERROR!";
                                x = 0;
                                y = 0;
                                op = ' ';
                                break;
                            }
                    }
                    y = 0;
                    c = true;
                    screen.Text = "" + x;
                    op = '+';
                }
            }
        }

        private void minus_Click(object sender, EventArgs e)
        {
            if (cc == true)
            {
                op = '-';
                cc = false;
                screen.Text = null;
            }
            else
            {
                if (x == 0)
                {
                    x = Convert.ToInt32(screen.Text);
                    op = '-';
                    screen.Text = null;
                }
                else
                {
                    y = Convert.ToInt32(screen.Text);
                    switch (op)
                    {
                        case '+':
                            {
                                x = x + y;
                                break;
                            }
                        case '-':
                            {
                                x = x - y;
                                break;
                            }
                        case '*':
                            {
                                x = x * y;
                                break;
                            }
                        case '/':
                            {
                                x = x / y;
                                break;
                            }
                        default:
                            {
                                screen.Text = "ERROR!";
                                x = 0;
                                y = 0;
                                op = ' ';
                                break;
                            }
                    }
                    y = 0;
                    c = true;
                    screen.Text = "" + x;
                    op = '-';
                }
            }
        }

        private void multi_Click(object sender, EventArgs e)
        {
            if (cc == true)
            {
                op = '*';
                cc = false;
                screen.Text = null;
            }
            else
            {
                if (x == 0)
                {
                    x = Convert.ToInt32(screen.Text);
                    op = '*';
                    screen.Text = null;
                }
                else
                {
                    y = Convert.ToInt32(screen.Text);
                    switch (op)
                    {
                        case '+':
                            {
                                x = x + y;
                                break;
                            }
                        case '-':
                            {
                                x = x - y;
                                break;
                            }
                        case '*':
                            {
                                x = x * y;
                                break;
                            }
                        case '/':
                            {
                                x = x / y;
                                break;
                            }
                        default:
                            {
                                screen.Text = "ERROR!";
                                x = 0;
                                y = 0;
                                op = ' ';
                                break;
                            }
                    }
                    y = 0;
                    c = true;
                    screen.Text = "" + x;
                    op = '*';
                }
            }
        }

        private void division_Click(object sender, EventArgs e)
        {
            if (cc == true)
            {
                op = '/';
                cc = false;
                screen.Text = null;
            }
            else
            {
                if (x == 0)
                {
                    x = Convert.ToInt32(screen.Text);
                    op = '/';
                    screen.Text = null;
                }
                else
                {
                    y = Convert.ToInt32(screen.Text);
                    switch (op)
                    {
                        case '+':
                            {
                                x = x + y;
                                break;
                            }
                        case '-':
                            {
                                x = x - y;
                                break;
                            }
                        case '*':
                            {
                                x = x * y;
                                break;
                            }
                        case '/':
                            {
                                x = x / y;
                                break;
                            }
                        default:
                            {
                                screen.Text = "ERROR!";
                                x = 0;
                                y = 0;
                                op = ' ';
                                break;
                            }
                    }
                    y = 0;
                    c = true;
                    screen.Text = "" + x;
                    op = '/';
                }
            }

        }

        private void equal_Click(object sender, EventArgs e)
        {
            if (x != 0)
            {
                y = Convert.ToInt32(screen.Text);
                switch (op)
                {
                    case '+':
                        {
                            x = x + y;
                            break;
                        }
                    case '-':
                        {
                            x = x - y;
                            break;
                        }
                    case '*':
                        {
                            x = x * y;
                            break;
                        }
                    case '/':
                        {
                            x = x / y;
                            break;
                        }
                    default:
                        {
                            screen.Text = "ERROR!";
                            x = 0;
                            y = 0;
                            op = ' ';
                            break;
                        }
                }
                y = 0;
                c = false;
                cc = true;
                screen.Text = "" + x;
            }

        }

        private void sign_Click(object sender, EventArgs e)
        {
            if (screen.Text != "" )
            screen.Text = "" + Convert.ToInt32(screen.Text) * (-1);
        }

        private void clear_Click(object sender, EventArgs e)
        {
            screen.Text = null;
            c = false;
            cc = false;
            x = 0;
            y = 0;
            op = ' ';
        }
    }
}
