#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
 * 用mianwindow这个才能实现多窗体
 */
#include <QMainWindow>
#include"new_window.h"

#include<QVector>
#include<QChar>
#include<QStack>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    new_window *new_win;
    void ui_connect();//在这里实现ui信号与槽的联系
    //bool is_number_c(QChar c);//判断是否为数字字符，若是，将其转化为 相应数字（负数，小数，多位数）
    //void to_number(double &num);
    void calculate();//计算
    int prior(QChar o1,QChar o2);//判定优先级
    double ca(double o1_p,double o2_p,QChar c);

public slots://槽函数，通过信号实现什么操作
    void after_click_button0();
    void after_click_button1();
    void after_click_button2();
    void after_click_button3();
    void after_click_button4();
    void after_click_button5();
    void after_click_button6();
    void after_click_button7();
    void after_click_button8();
    void after_click_button9();
    void after_click_xiaoshu();
    void after_click_jia();
    void after_click_jian();
    void after_click_cheng();
    void after_click_chu();
    void after_click_left();
    void after_click_right();
    void after_click_clean();
    void after_click_delete();
    void after_click_dengyu();
    void after_click_CA();//清除所有，show1和show2

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
   // QWidget *wid=centralWidget();
    QStack<QChar> soptr;//操作符栈
    QStack<double> sopnd;//操作数栈,先不考虑多位数和小数，先实现再说
};

#endif // MAINWINDOW_H
