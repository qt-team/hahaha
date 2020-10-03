#include "playscene.h"
#include<QDebug>


PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{
    backbtn=new QPushButton(this);
    backbtn->setText("<-");
    backbtn->setGeometry(0,0,100,60);
    connect(backbtn,&QPushButton::clicked,[=]{
        emit this->back();
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                     delete btng[i][j];
            }
        }
        stoptime();
    });//一个可以发送返回主界面信号的按钮

    restartbtn=new QPushButton(this);
    restartbtn->setText("restart");
    restartbtn->setGeometry(870,500,100,60);
    connect(restartbtn,&QPushButton::clicked,[=]{
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                x[i][j]=1;//1为白色
            }
        }
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                z[i][j]=y_[i][j];
                if(z[i][j]){
                    xshift(i,j);
                }
            }
        }
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                btng[i][j]->state=x[i][j];
                if(btng[i][j]->state){
                    btng[i][j]->setStyleSheet("background:white");
                }
                else{
                    btng[i][j]->setStyleSheet("background:black");
                }
            }
       }
    });
    tipbtn=new QPushButton(this);
    tipbtn->setText("tip");
    tipbtn->setGeometry(870,400,100,60);
    connect(tipbtn,&QPushButton::clicked,[=]{
        bool flag=true;
        for(int i=0;i<playsize&&flag;i++){
            for(int j=0;j<playsize&&flag;j++){
                if(z[i][j]){
                    xshift(i,j);//x数组随之改变
                    btng[i][j]->change();
                    if(i>0){
                        btng[i-1][j]->change();
                    }
                    if(i<playsize-1){
                        btng[i+1][j]->change();
                    }
                    if(j>0){
                        btng[i][j-1]->change();
                    }
                    if(j<playsize-1){
                        btng[i][j+1]->change();
                    }//上下左右改变
                    if(iswin()){
                        mess->setText("win");
                        mess->show();
                        ptimer->stop();
                        writerecord();
                        getrecord();
                    }//判断游戏是否结束
                    flag=false;
                    z[i][j]=0;
                }
            }
        }
    });
    newbtn=new QPushButton(this);
    newbtn->setText("new");
    newbtn->setGeometry(870,300,100,60);
    connect(newbtn,&QPushButton::clicked,[=]{
        stoptime();
        timeinitial();
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                x[i][j]=1;//1为白色
                y_[i][j]=0;
            }
        }
        QTime t;
        t=QTime::currentTime();
        qsrand(unsigned(QTime(0,0,0).secsTo(QTime::currentTime())));
        for(int i=0;i<level;){
            int ranx=qrand()%playsize;
            int rany=qrand()%playsize;
            if(!y_[ranx][rany]){
                y_[ranx][rany]=1;
                i++;
            }
        }
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                z[i][j]=y_[i][j];
                if(z[i][j]){
                    xshift(i,j);
                }
            }
        }
        for(int i=0;i<playsize;i++){
            for(int j=0;j<playsize;j++){
                btng[i][j]->state=x[i][j];
                if(btng[i][j]->state){
                    btng[i][j]->setStyleSheet("background:white");
                }
                else{
                    btng[i][j]->setStyleSheet("background:black");
                }
            }
       }
    });//一个可以发送返回主界面信号的按钮
    mess=new QMessageBox(this);//用来显示游戏胜利的messagebox
    ptimer=new QTimer(this);
    l=new QLCDNumber(this);
    l->setGeometry(820,100,240,80);
    l->display("00:00:00:000");
    l->setDigitCount(12);
    connect(ptimer,SIGNAL(timeout()),this,SLOT(updatetime()));
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
    }
    if(j-1>=0){
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

void PlayScene::writerecord()
{
    QFile file("../record.txt");
    bool isok=file.open(QIODevice::WriteOnly);
    if(isok==true){
        QTextStream stream;
        stream.setDevice(&file);
        stream<<timestr;
        file.close();
    }

}

void PlayScene::getrecord()
{
    QFile file("../record.txt");

    bool isok=file.open(QIODevice::ReadOnly);
    if(isok==true){

        QTextStream stream(&file);
        stream.setDevice(&file);
        stream>>recom;
        qDebug()<<recom;
        file.close();
    }

}

void PlayScene::timeinitial()
{
    ptimer->start(1);
    basetime=basetime.currentTime();
}
void PlayScene::updatetime()
{
    QTime curtime=QTime::currentTime();
    QTime showtime(0,0,0,0);
    int t=basetime.msecsTo(curtime);
    showtime=showtime.addMSecs(t);
    timestr=showtime.toString("hh:mm:ss:zzz");
    l->display(timestr);
}

void PlayScene::receivepara(int a, int b)
{
    playsize=a;
    level=b;
    emit trans();
    qDebug()<<"k";
}

void PlayScene::startsound()
{
    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)),this,SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\Steerner,Martell - Sky (Radio Edit).mp3"));
    player->setVolume(80);
    player->play();
}

void PlayScene::stoptime()
{
    ptimer->stop();
    l->display("00:00:00:000");
}

void PlayScene::btnsetting()
{
    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            x[i][j]=1;//1为白色
            y_[i][j]=0;//0代表为操作
        }
    }
    for(int i=0;i<level;){
        int ranx=qrand()%playsize;
        int rany=qrand()%playsize;
        if(!y_[ranx][rany]){
            y_[ranx][rany]=1;
            i++;
        }
    }
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            z[i][j]=y_[i][j];
        }
    }
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            if(y_[i][j]){
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
               if(z[btn->x][btn->y]!=0){
                   z[btn->x][btn->y]=0;
               }
               else {
                   z[btn->x][btn->y]=1;
               }
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
                   ptimer->stop();
                   writerecord();
                   getrecord();
               }//判断游戏是否结束
           });
        }
    }
}

void PlayScene::saverecord()
{
    QString filename=QFileDialog::getSaveFileName(this,"save",".","Txt(*.txt);;c files(*.c);;c++ files(*.cpp)");
    if(filename.isEmpty()==false){
        QFile file(filename);
        bool isok=file.open(QIODevice::WriteOnly);
        if(isok){
            QString str=timestr;
            file.write(str.toUtf8());
        }
        file.close();
    }
}

void PlayScene::readrecord()
{
    QString filename=QFileDialog::getSaveFileName(this,"save",".","Txt(*.txt);;c files(*.c);;c++ files(*.cpp)");
    if(filename.isEmpty()==false){
        QFile file(filename);
        bool isok=file.open(QIODevice::ReadOnly);
        if(isok){
            QByteArray array;
            while(file.atEnd()==false){
               array+=file.readLine();
            }
        }
        file.close();
    }
}

void PlayScene::comparerecord()
{

}
void PlayScene::btnsetting_()
{
    qDebug()<<"x";
    QTime t;
    t=QTime::currentTime();
    qsrand(unsigned(QTime(0,0,0).secsTo(QTime::currentTime())));
    qDebug()<<"a";
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            x[i][j]=1;//1为白色
            y_[i][j]=0;//0代表为操作

        }
    }

    qDebug()<<"b";
    for(int i=0;i<level;){
        int ranx=qrand()%playsize;
        int rany=qrand()%playsize;
        if(!y_[ranx][rany]){
            y_[ranx][rany]=1;
            i++;
        }
    }
    qDebug()<<"c";
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            if(y_[i][j]){
                xshift(i,j);

            }
        }
    }
    qDebug()<<y_[0][1];
    for(int i=0;i<playsize;i++){
        for(int j=0;j<playsize;j++){
            z[i][j]=y_[i][j];
        }
    }
    qDebug()<<"d";
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
               if(z[btn->x][btn->y]!=0){
                   z[btn->x][btn->y]=0;
               }
               else{
                   z[btn->x][btn->y]=1;
               }
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
                   ptimer->stop();
                   writerecord();
                   getrecord();
               }//判断游戏是否结束
           });
        }
    }
    qDebug()<<"p";
}

