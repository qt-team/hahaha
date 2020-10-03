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
    int a;
    int b;
    QPainter *painter;
    bool ispause;
    QMediaPlayer *player;
    JiaoCheng *jc;
    int bcnum=0;
    int mnum=0;
    void musicchange();

signals:
    void sendpara(int a,int b);
private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();




private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
