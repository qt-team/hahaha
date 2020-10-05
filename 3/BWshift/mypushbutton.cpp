#include "mypushbutton.h"

MyPushButton::MyPushButton(QPushButton *parent) : QPushButton (parent)
{

    setFixedSize(80,80);

}

void MyPushButton::change()//初始化游戏界面按钮
{
    if(state==1){
        this->setStyleSheet("background:black");
        state=0;
    }
    else if(state==0){
       this->setStyleSheet("background:white");
        state=1;
    }
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(state==1){
        this->setStyleSheet("background:black");
        state=0;
    }
    else if(state==0){
       this->setStyleSheet("background:white");
        state=1;
    }
    return QPushButton::mouseReleaseEvent(e);
}
