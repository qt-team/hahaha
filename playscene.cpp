#include "playscene.h"
#include<QDebug>


PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

    timeinitial();
    backbtn=new QPushButton(this);
    backbtn->setText("<-");
    connect(backbtn,&QPushButton::clicked,[=]{
        emit this->back();

    });//一个可以发送返回主界面信号的按钮
    mess=new QMessageBox(this);//用来显示游戏胜利的messagebox
    btnsetting();

}

void PlayScene::xshift(int i,int j)//判断上下左右是否在可操作的范围内，若是则操作
{
    if(x[i][j]){
        x[i][j]=0;
    }
    else{
        x[i][j]=1;
    }
    if(i-1>=0){
        if(x[i-1][j]){
            x[i-1][j]=0;
        }
        else{
            x[i-1][j]=1;
        }
    }
    if(i+1<=playsize){
        if(x[i+1][j]){
            x[i+1][j]=0;
        }
        else{
            x[i+1][j]=1;
        }
    }if(j-1>=0){
        if(x[i][j-1]){
            x[i][j-1]=0;
        }
        else{
            x[i][j-1]=1;
        }
    }
    if(j+1<=playsize){
            if(x[i][j+1]){
                x[i][j+1]=0;
            }
            else{
                x[i][j+1]=1;
            }
    }
}

bool PlayScene::iswin()//判断x数组是否全部为1
{
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            if(!x[i][j])
                return false;
        }
    }
    return true;
}

void PlayScene::timeinitial()
{
    ptimer=new QTimer(this);
    ptimer->start(10);
    basetime=basetime.currentTime();
    l=new QLCDNumber(this);
    l->setGeometry(820,100,240,80);
    l->display("00:00:00:000");
    l->setDigitCount(12);
    connect(ptimer,SIGNAL(timeout()),this,SLOT(updatetime()));
}
void PlayScene::updatetime()
{
    QTime curtime=QTime::currentTime();
    int t=basetime.msecsTo(curtime);
    QTime showtime(0,0,0,0);
    showtime=showtime.addMSecs(t);
    timestr=showtime.toString("hh:mm:ss:zzz");
    l->display(timestr);
}

void PlayScene::stoptime()
{
    ptimer->stop();
}

void PlayScene::btnsetting()
{
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            x[i][j]=1;//1为白色
            y[i][j]=0;//0代表为操作
        }
    }
    for(int i=0;i<level;){
        int ranx=qrand()%8;
        int rany=qrand()%8;
        if(!y[ranx][rany]){
            y[ranx][rany]=1;
            i++;
        }
    }
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            if(y[i][j]){
                xshift(i,j);

            }
        }
    }
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
           MyPushButton *btn=new MyPushButton;
           btn->setParent(this);
           btn->state=x[i][j];
           btn->x=i;
           btn->y=j;
           if(btn->state){
               btn->setStyleSheet("background:white");
           }
           else{
               btn->setStyleSheet("background:black");
           }
           btn->move(100+88*i,100+88*j);//按钮的背景颜色，大小，位置初始化
           btng[i][j]=btn;//把按钮放到二位指针中，便于控制
           connect(btn,&MyPushButton::clicked,[=]{
               xshift(btn->x,btn->y);//x数组随之改变
               if(btn->x>0){
                   btng[btn->x-1][btn->y]->change();
               }
               if(btn->x<playsize-1){
                   btng[btn->x+1][btn->y]->change();
               }
               if(btn->y>0){
                   btng[btn->x][btn->y-1]->change();
               }
               if(btn->y<playsize-1){
                   btng[btn->x][btn->y+1]->change();
               }//上下左右改变
               if(iswin()){
                   mess->setText("win");
                   mess->show();
                   stoptime();
               }//判断游戏是否结束
           });
        }
    }
}
void PlayScene::on_action_3_triggered()
{
    playsize=4;
    level=3;
}

void PlayScene::on_action_4_triggered()
{
    playsize=6;
    level=5;
}

void PlayScene::on_action_5_triggered()
{
    playsize=8;
    level=6;
}

void PlayScene::on_action_6_triggered()
{
    playsize=4;
    level=6;
}

void PlayScene::on_action_7_triggered()
{
    playsize=6;
    level=8;
}

void PlayScene::on_action_8_triggered()
{
    playsize=8;
    level=10;
}

void PlayScene::on_action_9_triggered()
{
    playsize=4;
    level=8;
}

void PlayScene::on_action_10_triggered()
{
    playsize=6;
    level=10;
}

void PlayScene::on_action_11_triggered()
{
    playsize=8;
    level=13;
}



