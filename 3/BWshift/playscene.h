#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<QPushButton>
#include"mypushbutton.h"
#include<QMessageBox>
#include<QTimer>
#include<QLabel>
#include<QTime>
#include<QLCDNumber>
#include<QtGlobal>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QDataStream>
#include<QByteArray>
#include<QMediaPlayer>
#include<QSound>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    QPushButton *backbtn;
    QPushButton *newbtn;
    QPushButton *tipbtn;
    QPushButton *restartbtn;
    void xshift(int i,int j);
    int x[8][8];//和每一个按钮的state值一致
    bool y_[8][8];//记录初始化时是否已经操作，确保按钮不重复
    bool z[8][8];
    MyPushButton *btng[8][8];
    bool iswin();
    QMessageBox *mess;
    QTimer *ptimer;
    QTime basetime;
    QString timestr;
    QLCDNumber *l;
    QString recom;
    void writerecord();
    void getrecord();

    void stoptime();
    void btnsetting();
    void sizelevelrelate();
    int playsize=5;
    int level=5;
    int backgr=0;
    bool istip=false;
    void saverecord();
    void readrecord();
    void comparerecord();
    QMediaPlayer *player;
    void backchange();

    QLabel *best;
    QLabel *be;
    QString record;

signals:
    void back();//监听返回主界面的信号
    void trans();

public slots:
    void timeinitial();
    void btnsetting_();
    void updatetime();
    void receivepara(int a,int b);
    void startsound();
    void receivebackn(int n);





};

#endif // PLAYSCENE_H
