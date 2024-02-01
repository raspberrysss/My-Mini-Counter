#include "new_window.h"
#include "ui_new_window.h"
#include <QDebug>
#include <QVector>
#include<QChar>
#include<QStack>//QStack继承于QVector，也可使用其方法
#include<QErrorMessage>
#include<QQueue>

new_window::new_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_window)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui_connect();
    soptr.push('=');//定义的时候char就不行，Qstring就行了，为什么？''qchar可以
    qDebug()<<"=入栈";
}

void new_window::after_click_button0()
{
        qDebug()<<"0";//显示在控制台了
        if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
        {
            ui->show2->clear();
        }
        ui->show2->insert("0");//在show2上显示,用insert函数显示
}

void new_window:: after_click_button1()
{
    qDebug()<<"1";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("1");//在show2上显示
}

 void new_window::after_click_button2()
{
     qDebug()<<"2";//显示在控制台了
     if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
     {
         ui->show2->clear();
     }
     ui->show2->insert("2");//在show2上显示
}

void new_window:: after_click_button3()
{
    qDebug()<<"3";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("3");//在show2上显示
}

void new_window:: after_click_button4()
{
    qDebug()<<"4";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("4");//在show2上显示
}

void new_window:: after_click_button5()
{
    qDebug()<<"5";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("5");//在show2上显示
}

void new_window:: after_click_button6()
{
    qDebug()<<"6";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("6");//在show2上显示
}

void new_window:: after_click_button7()
{
    qDebug()<<"7";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("7");//在show2上显示
}

void new_window:: after_click_button8()
{
    qDebug()<<"8";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("8");//在show2上显示
}

void new_window:: after_click_button9()
{
    qDebug()<<"9";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("9");//在show2上显示
}

void new_window:: after_click_xiaoshu()
{
    qDebug()<<".";//显示在控制台了
    ui->show2->insert(".");//在show2上显示
}

void new_window:: after_click_jia()
{
    qDebug()<<"+";//显示在控制台了
    ui->show2->insert("+");//在show2上显示
   // soptr.append("+");
   // qDebug()<<"+入栈";//不行，这样只能一直入栈，没有办法比较优先级出栈
}

void new_window:: after_click_jian()
{
    qDebug()<<"-";//显示在控制台了
    ui->show2->insert("-");//在show2上显示
    //soptr.append("-");
    //qDebug()<<"-入栈";
}

void new_window:: after_click_cheng()
{
    qDebug()<<"*";//显示在控制台了
    ui->show2->insert("*");//在show2上显示
    //soptr.append("*");
    //qDebug()<<"*入栈";
}

void new_window:: after_click_chu()
{
    qDebug()<<"/";//显示在控制台了
    ui->show2->insert("/");//在show2上显示
    //soptr.append("/");
    //qDebug()<<"/入栈";
}

void new_window:: after_click_left()
{
    qDebug()<<"(";//显示在控制台了
    ui->show2->insert("(");//在show2上显示
     //soptr.append("(");
     //qDebug()<<"（入栈";
}

void new_window:: after_click_right()
{
    qDebug()<<"(";//显示在控制台了
    ui->show2->insert(")");//在show2上显示
    //soptr.append(")");
    //qDebug()<<"）入栈";
}

void new_window:: after_click_clean()
{
    qDebug()<<"C";//显示在控制台了
    ui->show2->clear();//在show2上清除
    soptr.clear();
    qDebug()<<"操作符栈被清空";
   // qDebug()<<"操作数1栈被清空";
    qDebug()<<"操作数栈被清空";
    soptr.push('=');
    //重新入栈，不然栈顶会是随机的

}

void new_window:: after_click_delete()
{
    qDebug()<<"D";//显示在控制台了
    ui->show2->setCursorPosition(ui->show2->cursorPosition()-1);//把光标前移一位
    ui->show2->del();//！要先移动光标，才能用del把光标后的删除，不然光标后没有数字，也无法删除在show2删除
}

void new_window::after_click_dengyu()
{

    //!不止计算，需要匹配，不然无法停止
    //! 算完一次再点等号的时候，应该先将=入栈，不然，栈顶开始就是空,不用在这里实现，得出结果后直接清空栈并且将=入栈即可
    ui->show2->insert("=");
    QString s2;
    change_m_l(s2);
    qDebug()<<"中缀转后缀后为";
        for(int j=0;j<s2.length();j++)
        {
            qDebug()<<s2[j];
        }
        calculate(s2);
   //只要中缀不错，后缀不会错，报错提示在中缀那里找



    //calculate();
}

void new_window::after_click_CA()
{
    qDebug()<<"CA";
    ui->show1->clear();
    ui->show2->clear();
    sopnd.clear();
    soptr.clear();
    soptr.push('=');
}

int new_window::prior(QChar o1, QChar o2)
{
    //o1是栈内的，o2是栈外的
    //当栈内的优先级更高，则返回1，若栈内的小于栈外的，则返回-1，若相等返回0，若错误，返回2
    if(o1=='='&&o2=='=')
    {
        return 0;
    }
    else if(o1=='='&&o2=='(')
    {
        return -1;
    }
    else if(o1=='='&&o2=='(')
    {
        return -1;
    }
    else if(o1=='='&&o2=='*')
    {
        return -1;
    }
    else if(o1=='='&&o2=='/')
    {
        return -1;
    }
    else if(o1=='='&&o2=='+')
    {
        return -1;
    }
    else if(o1=='='&&o2=='-')
    {
        return -1;
    }
    else if(o1=='='&&o2==')')
    {
        return -1;
    }
    else if(o1=='('&&o2=='=')
    {
        return 1;
    }
    else if(o1=='('&&o2=='(')
    {
        return -1;
    }
    else if(o1=='('&&o2=='*')
    {
        return -1;
    }
    else if(o1=='('&&o2=='/')
    {
        return -1;
    }
    else if(o1=='('&&o2=='+')
    {
        return -1;
    }
    else if(o1=='('&&o2=='-')
    {
        return -1;
    }
    else if(o1=='('&&o2==')')
    {
        return 0;
    }
    else if(o1=='*'&&o2=='=')
    {
        return 1;
    }
    else if(o1=='*'&&o2=='(')
    {
        return -1;
    }
    else if(o1=='*'&&o2=='*')
    {
        return 1;
    }
    else if(o1=='*'&&o2=='/')
    {
        return 1;
    }
    else if(o1=='*'&&o2=='+')
    {
        return 1;
    }
    else if(o1=='*'&&o2=='-')
    {
        return 1;
    }
    else if(o1=='*'&&o2==')')
    {
        return 1;
    }
    else if(o1=='/'&&o2=='=')
    {
        return 1;
    }
    else if(o1=='/'&&o2=='(')
    {
        return -1;
    }
    else if(o1=='/'&&o2=='*')
    {
        return 1;
    }
    else if(o1=='/'&&o2=='/')
    {
        return 1;
    }
    else if(o1=='/'&&o2=='+')
    {
        return 1;
    }
    else if(o1=='/'&&o2=='-')
    {
        return 1;
    }
    else if(o1=='/'&&o2==')')
    {
        return 1;
    }
    else if(o1=='+'&&o2=='=')
    {
        return 1;
    }
    else if(o1=='+'&&o2=='(')
    {
        return -1;
    }
    else if(o1=='+'&&o2=='*')
    {
        return -1;
    }
    else if(o1=='+'&&o2=='/')
    {
        return -1;
    }
    else if(o1=='+'&&o2=='+')
    {
        return 1;
    }
    else if(o1=='+'&&o2=='-')
    {
        return 1;
    }
    else if(o1=='+'&&o2==')')
    {
        return 1;
    }
    else if(o1=='-'&&o2=='=')
    {
        return 1;
    }
    else if(o1=='-'&&o2=='(')
    {
        return -1;
    }
    else if(o1=='-'&&o2=='*')
    {
        return -1;
    }
    else if(o1=='-'&&o2=='/')
    {
        return -1;
    }
    else if(o1=='-'&&o2=='+')
    {
        return 1;
    }
    else if(o1=='-'&&o2=='-')
    {
        return 1;
    }
    else if(o1=='-'&&o2==')')
    {
        return 1;
    }
    else if(o1==')'&&o2=='=')
    {
        return 1;
    }
    else if(o1==')'&&o2=='(')
    {
        return 0;
    }
    else if(o1==')'&&o2=='*')
    {
        return 1;
    }
    else if(o1==')'&&o2=='/')
    {
        return 1;
    }
    else if(o1==')'&&o2=='+')
    {
        return 1;
    }
    else if(o1==')'&&o2=='-')
    {
        return 1;
    }
    else if(o1=='+'&&o2==')')
    {
        return 1;
    }
    return 2;
}

void new_window::change_m_l(QString &s1)//!后缀转换为小数，多位数计算如何做呢，都是不同的？
{
    //!在转换的时候直接在一个完整数字字符串的后面加上#，计算时再将其忽视
    QString str2=ui->show2->text();//把中缀表达式转换为字符串
    //qDebug()<<str2[0];
    //此时把左括号的栈外优先级设到最高，让其一定入栈，同时让左括号的栈内优先级最低，让其他的运算符入栈，右括号与左括号是唯一相等的，直接出栈
   //QQueue<double> q2;
    QQueue<QChar> q1;
    int i;
    i=0;
    int length=str2.length();
    QStack<QChar> s_o;
    s_o.push('=');
    qDebug()<<"bbb";
    while(i<length)
    {
        //qDebug()<<"aaa";
        if(str2[i]>='0'&&str2[i]<='9')
        {
            /*while(str2[i]>='0'&&str2[i]<='9')
            {
                q1.enqueue(str2[i]);
                i++;
            }
            if(str2[i]=='.')
            {
                q1.enqueue(str2[i]);
                i++;
                while(str2[i]>='0'&&str2[i]<='9')
                {
                    q1.enqueue(str2[i]);

                }
            }
            q1.enqueue('#');*/

           // s1[i]=str2[i];
            q1.enqueue(str2[i]);
            //s1[i]=str2[i];
            qDebug()<<"将"<<str2[i]<<"入输出队列";
            qDebug()<<str2[i];
            i++;
            qDebug()<<i;

        }
        else
        {
            QChar t=s_o.top();
            int p=prior(t,str2[i]);//当栈顶的优先级小于要进来的，则让其进栈
            if(p==-1)//栈内的优先级低一些，让栈外的入栈,
            {
                s_o.push(str2[i]);
               //s1[i]=str2[i];
                qDebug()<<str2[i]<<"入栈";
                i++;
            }
            else if(p==1)//当栈顶优先级更大，则出栈
            {

                QChar t1=s_o.top();
                if(t1==')')//如果栈顶是右括号，则出栈
                {
                    s_o.pop();
                    qDebug()<<"将"<<t1<<"出栈";
                    //直接出栈，但不入输出对列，相当于将其前面的都入输出队列，后删除右括号
                }
                QChar t2=s_o.top();//取t2为当前栈顶，经历过if判断，会不一样
                q1.enqueue(t2);//将这个操作符放在输出队列中
                qDebug()<<"将"<<t2<<"入输出队列";
                //s1[i]=t2;
                s_o.pop();//将当前栈顶出栈，输出
                                                }
            else if(p==0)
            {
                QChar t3;
                t3=s_o.top();
                s_o.pop();
                qDebug()<<"将"<<t3<<"出栈";
                i++;

                /*if(t=='(')
                {
                    s_o.pop();
                }*/
            }
        }

    }
    qDebug()<<q1.length();
    int length2=q1.length();
    for(int j=0;j<length2;j++)
    {
        s1[j]=q1.dequeue();
        qDebug()<<s1[j];

    }
    /*QQueue<QChar>::iterator q_p;//为什么这样赋值不上！问！
    int j=0;
    for(q_p=q1.begin();q_p!=q1.end();q_p++)
    {
        qDebug()<<*q_p;
        s1[j]=*q_p;
        j++;//不能用for循环，不然一直在覆盖
        qDebug()<<j;
        qDebug()<<s1[j];
    }*/


}

double new_window::ca(double o1, double o2, QChar c)
{
    if(c=='+')
    {
        return o1+o2;
    }
    else if(c=='-')
    {
        return o1-o2;
    }
    else if(c=='*')
    {
        return o1*o2;
    }
    else if(c=='/')
    {
        return o1/o2;
    }
    return 0;
}

void new_window::calculate(QString s)
{
    int i=0;
    int length=s.length();
    while(i<length)
    {
        if(s[i]=='1')
        {
            sopnd.push(1.00);
            qDebug()<<"将数字1入操作数栈";

        }
        else if(s[i]=='2')
        {
            sopnd.push(2.00);
            qDebug()<<"将数字2入操作数栈";

        }
        else if(s[i]=='3')
        {
            sopnd.push(3.00);
            qDebug()<<"将数字3入操作数栈";

        }
        else if(s[i]=='4')
        {
            sopnd.push(4.00);
            qDebug()<<"将数字4入操作数栈";

        }
        else if(s[i]=='5')
        {
            sopnd.push(5.00);
            qDebug()<<"将数字5入操作数栈";

        }
        else if(s[i]=='6')
        {
            sopnd.push(6.00);
            qDebug()<<"将数字6入操作数栈";

        }
        else if(s[i]=='7')
        {
            sopnd.push(7.00);
            qDebug()<<"将数字7入操作数栈";

        }
        else if(s[i]=='8')
        {
            sopnd.push(8.00);
            qDebug()<<"将数字8入操作数栈";

        }
        else if(s[i]=='9')
        {
            sopnd.push(9.00);
            qDebug()<<"将数字9入操作数栈";

        }
        else if(s[i]=='0')
        {
            sopnd.push(0.00);
            qDebug()<<"将数字0入操作数栈";

        }
        else
        {
             double o2=sopnd.top();
             qDebug()<<"此时的栈顶为"<<o2<<",将其作为操作数2，进行后续计算";
             sopnd.pop();
             double o1=sopnd.top();
             qDebug()<<"此时的栈顶为"<<o1<<",将其作为操作数1，进行后续计算";
             sopnd.pop();
             qDebug()<<"将两个操作数出栈";
             double result_m;
             result_m=ca(o1,o2,s[i]);
             sopnd.push(result_m);
             qDebug()<<"将"<<result_m<<"入操作数栈，进行继续计算";
        }
        i++;
    }
    double re_end;
    re_end=sopnd.top();
    qDebug()<<re_end;
    QString result_s;//需要把double类型转为Qstring才可以显示在屏幕上
    result_s= QString::number(re_end,'.',0);//!没有加入小数运算时，这里一定是0，不然继续计算没有办法把.入栈
    ui->show2->clear();
    ui->show2->insert(result_s);
    ui->show1->clear();
    ui->show1->insert(result_s);
}

void new_window::ui_connect()//把ui需要用到的东西统一起来，实现按钮的信号与槽
{
    connect(ui->button0,&QPushButton::clicked,this,&new_window::after_click_button0);//!这里的函数是clicked才可以
    connect(ui->button1,&QPushButton::clicked,this,&new_window::after_click_button1);
    connect(ui->button2,&QPushButton::clicked,this,&new_window::after_click_button2);
    connect(ui->button3,&QPushButton::clicked,this,&new_window::after_click_button3);
    connect(ui->button4,&QPushButton::clicked,this,&new_window::after_click_button4);
    connect(ui->button5,&QPushButton::clicked,this,&new_window::after_click_button5);
    connect(ui->button6,&QPushButton::clicked,this,&new_window::after_click_button6);
    connect(ui->button7,&QPushButton::clicked,this,&new_window::after_click_button7);
    connect(ui->button8,&QPushButton::clicked,this,&new_window::after_click_button8);
    connect(ui->button9,&QPushButton::clicked,this,&new_window::after_click_button9);
    connect(ui->xiaoshu,&QPushButton::clicked,this,&new_window::after_click_xiaoshu);
    connect(ui->jia,&QPushButton::clicked,this,&new_window::after_click_jia);
    connect(ui->jian,&QPushButton::clicked,this,&new_window::after_click_jian);
    connect(ui->cheng,&QPushButton::clicked,this,&new_window::after_click_cheng);
    connect(ui->chufa,&QPushButton::clicked,this,&new_window::after_click_chu);
    connect(ui->left,&QPushButton::clicked,this,&new_window::after_click_left);
    connect(ui->right,&QPushButton::clicked,this,&new_window::after_click_right);
    connect(ui->clean_button,&QPushButton::clicked,this,&new_window::after_click_clean);
    connect(ui->delete_2,&QPushButton::clicked,this,&new_window::after_click_delete);
    connect(ui->dengyu,&QPushButton::clicked,this,&new_window::after_click_dengyu);
    connect(ui->CA,&QPushButton::clicked,this,&new_window::after_click_CA);

}

new_window::~new_window()
{
    delete ui;
}
