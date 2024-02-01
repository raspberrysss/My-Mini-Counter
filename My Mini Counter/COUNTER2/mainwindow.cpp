#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVector>
#include<QChar>
#include<QStack>//QStack继承于QVector，也可使用其方法
#include<QErrorMessage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_connect();
    soptr.push('=');//定义的时候char就不行，Qstring就行了，为什么？''qchar可以
    qDebug()<<"=入栈";
    //操作符栈先放上=
}

void MainWindow::after_click_button0()
{
        qDebug()<<"0";//显示在控制台了
        if(ui->show2->text()=='0')//如果show2显示的是0，则显示其他数字的时候先替换
        {
            ui->show2->clear();
        }
        ui->show2->insert("0");//在show2上显示,用insert函数显示
}

void MainWindow:: after_click_button1()
{
    qDebug()<<"1";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("1");//在show2上显示
}

 void MainWindow::after_click_button2()
{
     qDebug()<<"2";//显示在控制台了
     if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
     {
         ui->show2->clear();
     }
     ui->show2->insert("2");//在show2上显示
}

void MainWindow:: after_click_button3()
{
    qDebug()<<"3";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("3");//在show2上显示
}

void MainWindow:: after_click_button4()
{
    qDebug()<<"4";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("4");//在show2上显示
}

void MainWindow:: after_click_button5()
{
    qDebug()<<"5";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("5");//在show2上显示
}

void MainWindow:: after_click_button6()
{
    qDebug()<<"6";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("6");//在show2上显示
}

void MainWindow:: after_click_button7()
{
    qDebug()<<"7";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("7");//在show2上显示
}

void MainWindow:: after_click_button8()
{
    qDebug()<<"8";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("8");//在show2上显示
}

void MainWindow:: after_click_button9()
{
    qDebug()<<"9";//显示在控制台了
    if(ui->show2->text()=="0")//如果show2显示的是0，则显示其他数字的时候先替换
    {
        ui->show2->clear();
    }
    ui->show2->insert("9");//在show2上显示
}

void MainWindow:: after_click_xiaoshu()
{
    qDebug()<<".";//显示在控制台了
    ui->show2->insert(".");//在show2上显示
}

void MainWindow:: after_click_jia()
{
    qDebug()<<"+";//显示在控制台了
    ui->show2->insert("+");//在show2上显示
   // soptr.append("+");
   // qDebug()<<"+入栈";//不行，这样只能一直入栈，没有办法比较优先级出栈
}

void MainWindow:: after_click_jian()
{
    qDebug()<<"-";//显示在控制台了
    ui->show2->insert("-");//在show2上显示
    //soptr.append("-");
    //qDebug()<<"-入栈";
}

void MainWindow:: after_click_cheng()
{
    qDebug()<<"*";//显示在控制台了
    ui->show2->insert("*");//在show2上显示
    //soptr.append("*");
    //qDebug()<<"*入栈";
}

void MainWindow:: after_click_chu()
{
    qDebug()<<"/";//显示在控制台了
    ui->show2->insert("/");//在show2上显示
    //soptr.append("/");
    //qDebug()<<"/入栈";
}

void MainWindow:: after_click_left()
{
    qDebug()<<"(";//显示在控制台了
    ui->show2->insert("(");//在show2上显示
     //soptr.append("(");
     //qDebug()<<"（入栈";
}

void MainWindow:: after_click_right()
{
    qDebug()<<"(";//显示在控制台了
    ui->show2->insert(")");//在show2上显示
    //soptr.append(")");
    //qDebug()<<"）入栈";
}

void MainWindow:: after_click_clean()
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

void MainWindow:: after_click_delete()
{
    qDebug()<<"D";//显示在控制台了
    ui->show2->setCursorPosition(ui->show2->cursorPosition()-1);//把光标前移一位
    ui->show2->del();//！要先移动光标，才能用del把光标后的删除，不然光标后没有数字，也无法删除在show2删除
}

void MainWindow::after_click_dengyu()
{

    //!不止计算，需要匹配，不然无法停止
    //! 算完一次再点等号的时候，应该先将=入栈，不然，栈顶开始就是空,不用在这里实现，得出结果后直接清空栈并且将=入栈即可
    ui->show2->insert("=");
    calculate();
}

void MainWindow::after_click_CA()
{
    qDebug()<<"CA";
    ui->show1->clear();
    ui->show2->clear();
    sopnd.clear();
    soptr.clear();
    soptr.push('=');
}

int MainWindow::prior(QChar o1, QChar o2)
{
    //o1是栈顶元素，o2是扫描到的元素

    if(o1=='+'&&o2=='+')
        return 1;
    else if(o1=='+'&&o2=='-')
        return 1;
    else if(o1=='+'&&o2=='*')
        return -1;
    else if(o1=='+'&&o2=='/')
        return -1;
    else if(o1=='+'&&o2=='(')
        return -1;
    else if(o1=='+'&&o2==')')
        return 1;
    else if(o1=='+'&&o2=='=')
        return 1;
    else if(o1=='-'&&o2=='+')
        return 1;
    else if(o1=='-'&&o2=='-')
        return 1;
    else if(o1=='-'&&o2=='*')
        return -1;
    else if(o1=='-'&&o2=='/')
        return -1;
    else if(o1=='-'&&o2=='(')
        return -1;
    else if(o1=='-'&&o2==')')
        return 1;
    else if(o1=='-'&&o2=='=')
        return 1;
    else if(o1=='*'&&o2=='+')
        return 1;
    else if(o1=='*'&&o2=='-')
        return 1;
    else if(o1=='*'&&o2=='*')
        return 1;
    else if(o1=='*'&&o2=='/')
        return 1;
    else if(o1=='*'&&o2=='(')
        return -1;
    else if(o1=='*'&&o2==')')
        return 1;
    else if(o1=='*'&&o2=='=')
        return 1;
    else if(o1=='/'&&o2=='+')
        return 1;
    else if(o1=='/'&&o2=='-')
        return 1;
    else if(o1=='/'&&o2=='*')
        return 1;
    else if(o1=='/'&&o2=='/')
        return 1;
    else if(o1=='/'&&o2=='(')
        return -1;
    else if(o1=='/'&&o2==')')
        return 1;
    else if(o1=='/'&&o2=='=')
        return 1;
    else if(o1=='('&&o2=='+')
        return -1;
    else if(o1=='('&&o2=='-')
        return -1;
    else if(o1=='('&&o2=='*')
        return -1;
    else if(o1=='('&&o2=='/')
        return -1;
    else if(o1=='('&&o2=='(')
        return -1;
    else if(o1=='('&&o2==')')
        return 0;
    else if(o1=='('&&o2=='=')
        return 2;
    else if(o1==')'&&o2=='+')
        return 1;
    else if(o1==')'&&o2=='-')
        return 1;
    else if(o1==')'&&o2=='*')
        return 1;
    else if(o1==')'&&o2=='/')
        return 1;
    else if(o1==')'&&o2=='(')
        return 2;
    else if(o1==')'&&o2==')')
        return 1;
    else if(o1==')'&&o2=='=')
        return 1;
    else if(o1=='='&&o2=='+')
        return -1;
    else if(o1=='='&&o2=='-')
        return -1;
    else if(o1=='='&&o2=='*')
        return -1;
    else if(o1=='='&&o2=='/')
        return -1;
    else if(o1=='='&&o2=='(')
        return -1;
    else if(o1=='='&&o2==')')
        return 2;
    else if(o1=='='&&o2=='=')
        return 0;
    return 2;//无匹配，算错误情况
}

double MainWindow::ca(double o1_p,double o2_p,QChar c)
{
    if(c=='+')
    {
        return o1_p+o2_p;
    }
    else if(c=='-')
    {
        return o1_p-o2_p;
    }
    else if(c=='*')
    {
        return o1_p*o2_p;
    }
    else if(c=='/')
    {
        return o1_p/o2_p;
    }
       return 0;
}

void MainWindow::calculate()
{
    //在计算函数里整体实现入栈出栈转换等操作
    QString str=ui->show2->text();//定义Qstring
    int length=str.length();
    qDebug()<<length;//输出了
    //int w=0;这里可以输出，qdebug没有问题
    //qDebug()<<"shuzi"<<w;
    int i;
    i=0;
    int flag=1;
    //int flag1=1;
    for(int w=0;w<length-1;w++)
    {
        if(str[w]>='0'&&str[w]<='9')
        {
            flag=1;
        }
        else {
            qDebug()<<str[w]<<str[w+1];
            if(str[w]=='+'&&str[w+1]=='+')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='+'&&str[w+1]=='-')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='+'&&str[w+1]=='*')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='+'&&str[w+1]=='/')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='-'&&str[w+1]=='+')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='-'&&str[w+1]=='-')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='-'&&str[w+1]=='*')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='-'&&str[w+1]=='/')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='*'&&str[w+1]=='+')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='*'&&str[w+1]=='-')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='*'&&str[w+1]=='*')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='*'&&str[w+1]=='/')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='/'&&str[w+1]=='+')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='/'&&str[w+1]=='-')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='/'&&str[w+1]=='*')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
            else if(str[w]=='/'&&str[w+1]=='/')
            {

                qDebug()<<flag;
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;
                break;//有错误马上退出循环，防止flag又被赋成1
                //!成功，牛！
            }
        }
    }
    qDebug()<<flag;

    while(!soptr.empty()&&flag==1)//没走完时一直进入这个循环
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            qDebug()<<i;
            double re_mid_s=0;
            while(str[i]>='0'&&str[i]<='9')
            {
                int b;
                if(str[i]=='0')
                b=0;
                else if(str[i]=='1')
                {
                    qDebug()<<"11";
                    b=1;
                }

                else if(str[i]=='2')
                b=2;
                else if(str[i]=='3')
                b=3;
                else if(str[i]=='4')
                b=4;
                else if(str[i]=='5')
                b=5;
                else if(str[i]=='6')
                b=6;
                else if(str[i]=='7')
                b=7;
                else if(str[i]=='8')
                b=8;
                else if(str[i]=='9')
                b=9;
                re_mid_s=re_mid_s*10+b;

                i++;
                qDebug()<<i;
            }

            if(str[i]=='.')
            {
                i++;
                double re2=0.1;
                while(str[i]>='0'&&str[i]<='9')
                {
                    double b2;
                    if(str[i]=='0')
                    b2=0;
                    else if(str[i]=='1')
                    b2=1;
                    else if(str[i]=='2')
                    b2=2;
                    else if(str[i]=='3')
                    b2=3;
                    else if(str[i]=='4')
                    b2=4;
                    else if(str[i]=='5')
                    b2=5;
                    else if(str[i]=='6')
                    b2=6;
                    else if(str[i]=='7')
                    b2=7;
                    else if(str[i]=='8')
                    b2=8;
                    else if(str[i]=='9')
                    b2=9;
                    b2=b2*re2;
                    re_mid_s=re_mid_s+b2;
                    b2=b2*0.1;
                    i++;
                }

            }
            //i--;
            sopnd.push(re_mid_s);
             qDebug()<<re_mid_s;
        }
       /* if(str[i]=='1')
          {
              sopnd.push(1.00);
              qDebug()<<"数字1入操作数栈";
              i++;
          }
          else if(str[i]=='2')
          {
              sopnd.push(2.00);
              qDebug()<<"数字2入操作数栈";
              i++;
          }
          else if(str[i]=='3')
          {
              sopnd.push(3.00);
              qDebug()<<"数字3入操作数栈";
              i++;
          }
         else if(str[i]=='4')
          {
              sopnd.push(4.00);
              qDebug()<<"数字4入操作数栈";
              i++;
          }
          else if(str[i]=='5')
          {
              sopnd.push(5.00);
              qDebug()<<"数字5入操作数栈";
              i++;
          }
          else if(str[i]=='6')
          {
              sopnd.append(6.00);
              qDebug()<<"数字6入操作数栈";
              i++;
          }
          else if(str[i]=='7')
          {
              sopnd.push(7.00);
              qDebug()<<"数字7入操作数栈";
              i++;
          }
          else if(str[i]=='8')
          {
              sopnd.push(8.00);
              qDebug()<<"数字8入操作数栈";
              i++;
          }
          else if(str[i]=='9')
          {
              sopnd.push(9.00);
              qDebug()<<"数字9入操作数栈";
              i++;
          }
            else if(str[i]=='0')
            {
                sopnd.push(0.00);
                qDebug()<<"数字9入操作数栈";
                i++;
            }*/

        else
        {
            QChar c=soptr.top();//取栈顶元素
            qDebug()<<"此时栈顶元素为"<<c;
            int p;
            p=prior(c,str[i]);//用p记录优先级
            if(p==-1)//要入栈的优先级更强，要入栈
            {
                qDebug()<<str[i]<<"已入栈";
                //qDebug()>>"将操作符">>str[i]>>"入栈";
                soptr.push(str[i]);
                i++;
            }
            else if(p==1)
            {
                //当要入栈的优先级更小，则栈顶出栈，两个操作数出栈，进行栈顶计算后，数据再入栈
                //!此时要入栈的操作符先不入栈，一直比较，直到栈顶元素优先级更低
                //! 怎么一直比较呢，直到p=-1了，才继续
                QChar c2=soptr.top();//取当前栈顶进行计算
                QChar c3;
                qDebug()<<"将"<<c2<<"出栈进行计算";
                soptr.pop();//将栈顶出栈
                c3=soptr.top();
                qDebug()<<"此时的栈顶为"<<c3;
                double o1,o2;
                o2=sopnd.top();
                sopnd.pop();
                o1=sopnd.top();
                sopnd.pop();
                double result;
                result=ca(o1,o2,c2);
                sopnd.push(result);
                qDebug()<<result<<"入栈";
                //int p2=prior(c,str[i]);

            }
            else if(p==0)
          {
                soptr.pop();
                i++;//控制循环不用i，所以右括号进来不用单列一种情况，直接++
            }
            else if(p==2)
            {
                QErrorMessage* dialog=new QErrorMessage(this);
                dialog->setWindowTitle("发生错误");
                dialog->showMessage("输入表达式有问题！请重新输入！");
                flag=0;

            }
        }
        //i++;//!循环这里还是有问题

       qDebug()<<"i=="<<i;
    }
    if(flag==1)
    {
        double re_end;
        re_end=sopnd.top();
        qDebug()<<re_end;
        QString result_s;//需要把double类型转为Qstring才可以显示在屏幕上
        result_s= QString::number(re_end,'.',2);//!没有加入小数运算时，这里一定是0，不然继续计算没有办法把.入栈
        ui->show2->clear();
        ui->show2->insert(result_s);
        ui->show1->clear();
        ui->show1->insert(result_s);
    }
    else if(flag==0)
    {
        ui->show2->clear();
    }
   /* if(flag1==0)
    {
        ui->show2->clear();
    }*/
    soptr.clear();
    sopnd.clear();
    qDebug()<<"将运算符栈与操作数栈全清空，再入栈‘=’";
    //目前只能算一位数，所以第一回的的数必须先是一位数
    soptr.push('=');

}

void MainWindow::ui_connect()//把ui需要用到的东西统一起来，实现按钮的信号与槽
{
    connect(ui->button0,&QPushButton::clicked,this,&MainWindow::after_click_button0);//!这里的函数是clicked才可以
    connect(ui->button1,&QPushButton::clicked,this,&MainWindow::after_click_button1);
    connect(ui->button2,&QPushButton::clicked,this,&MainWindow::after_click_button2);
    connect(ui->button3,&QPushButton::clicked,this,&MainWindow::after_click_button3);
    connect(ui->button4,&QPushButton::clicked,this,&MainWindow::after_click_button4);
    connect(ui->button5,&QPushButton::clicked,this,&MainWindow::after_click_button5);
    connect(ui->button6,&QPushButton::clicked,this,&MainWindow::after_click_button6);
    connect(ui->button7,&QPushButton::clicked,this,&MainWindow::after_click_button7);
    connect(ui->button8,&QPushButton::clicked,this,&MainWindow::after_click_button8);
    connect(ui->button9,&QPushButton::clicked,this,&MainWindow::after_click_button9);
    connect(ui->xiaoshu,&QPushButton::clicked,this,&MainWindow::after_click_xiaoshu);
    connect(ui->jia,&QPushButton::clicked,this,&MainWindow::after_click_jia);
    connect(ui->jian,&QPushButton::clicked,this,&MainWindow::after_click_jian);
    connect(ui->cheng,&QPushButton::clicked,this,&MainWindow::after_click_cheng);
    connect(ui->chufa,&QPushButton::clicked,this,&MainWindow::after_click_chu);
    connect(ui->left,&QPushButton::clicked,this,&MainWindow::after_click_left);
    connect(ui->right,&QPushButton::clicked,this,&MainWindow::after_click_right);
    connect(ui->clean_button,&QPushButton::clicked,this,&MainWindow::after_click_clean);
    connect(ui->delete_2,&QPushButton::clicked,this,&MainWindow::after_click_delete);
    connect(ui->dengyu,&QPushButton::clicked,this,&MainWindow::after_click_dengyu);
    connect(ui->CA,&QPushButton::clicked,this,&MainWindow::after_click_CA);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    new_win=new new_window;
    new_win->show();
}
