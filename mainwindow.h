#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include"playscene.h"
#include<QAction>

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
    PlayScene *play;



private slots:


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
