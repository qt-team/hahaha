#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>
#include<QPushButton>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QPushButton *parent = nullptr);
    int state;//按钮的状态，0代表黑色，1代表白色；
    int x,y;
    void change();
    void mouseReleaseEvent(QMouseEvent *e)override;//改变按钮的颜色；
signals:
    void check();


public slots:

};

#endif // MYPUSHBUTTON_H
