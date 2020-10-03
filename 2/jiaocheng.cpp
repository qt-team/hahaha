#include "jiaocheng.h"

JiaoCheng::JiaoCheng(QWidget *parent) : QMainWindow(parent)
{
    backbtn=new QPushButton(this);
    backbtn->setText("<-");
    backbtn->setGeometry(0,0,100,60);
    connect(backbtn,&QPushButton::clicked,[=]{
        emit this->back();

    });
}
