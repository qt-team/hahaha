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

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    QPushButton *backbtn;
    void xshift(int i,int j);
    int x[8][8];//和每一个按钮的state值一致
    int y[8][8];//记录初始化时是否已经操作，确保按钮不重复
    MyPushButton *btng[8][8];
    bool iswin();
    QMessageBox *mess;
    QTimer *ptimer;
    QTime basetime;
    QString timestr;
    QLCDNumber *l;
    void timeinitial();
    void stoptime();
    void btnsetting();
    void sizelevelrelate();
    int playsize;
    int level;

signals:
    void back();//监听返回主界面的信号

public slots:
    void updatetime();
    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

};

#endif // PLAYSCENE_H
