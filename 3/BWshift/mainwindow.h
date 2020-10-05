#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include"playscene.h"
#include"jiaocheng.h"
#include<QAction>
#include<QDebug>
#include<QMediaPlayer>
#include<QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton *startbutton;
    QPushButton *jiaocheng;
    PlayScene *play;
    QPushButton *music;
    QPushButton *backg;
    int a;
    int b;
    QPainter *painter;
    bool ispause;
    QMediaPlayer *player;
    JiaoCheng *jc;
    int bcnum=0;
    int mnum=0;
    void musicchange();
    void backgroundclicked();

signals:
    void sendpara(int a,int b);
    void sendbackn(int a);
private slots:



    void on_pushButton_clicked();






private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
