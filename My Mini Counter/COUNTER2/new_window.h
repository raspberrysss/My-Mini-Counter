#ifndef NEW_WINDOW_H
#define NEW_WINDOW_H

#include <QWidget>
#include<QVector>
#include<QChar>
#include<QStack>


namespace Ui {
class new_window;
}

class new_window : public QWidget
{
    Q_OBJECT

public:
    explicit new_window(QWidget *parent = nullptr);
    ~new_window();
    void ui_connect();
    void change_m_l(QString &s1);//中缀表达式改为后缀,存到s1中
    int prior(QChar o1,QChar o2);//中缀转后缀时优先级判断
    void calculate(QString s);//计算后缀表达式,并直接显示，感觉显示写在槽函数里更好，有时间改一下
    double ca(double o1,double o2,QChar c);

private:
    Ui::new_window *ui;
    QStack<QChar> soptr;//操作符栈
    QStack<double> sopnd;//操作数栈,先不考虑多位数和小数，先实现再说
public slots:
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
};

#endif // NEW_WINDOW_H
