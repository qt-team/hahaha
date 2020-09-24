#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1100,900);//设置大小
    setWindowTitle("黑白迭代");//设置标题
    startbutton=new QPushButton(this);
    startbutton->setText("开始");
    startbutton->setGeometry(this->width()*0.5-startbutton->width()*0.5,this->height()*0.7,100,50);
    connect(startbutton,&QPushButton::clicked,[=]{
        this->hide();
        play=new PlayScene(this);
        play->setGeometry(this->geometry());
        play->show();//跳转到游戏界面
        connect(ui->action_3,SIGNAL(triggered(bool)),play,SLOT(on_action_3_triggered()));
        connect(ui->action_4,SIGNAL(triggered(bool)),play,SLOT(on_action_4_triggered()));
        connect(ui->action_5,SIGNAL(triggered(bool)),play,SLOT(on_action_5_triggered()));
        connect(ui->action_6,SIGNAL(triggered(bool)),play,SLOT(on_action_6_triggered()));
        connect(ui->action_7,SIGNAL(triggered(bool)),play,SLOT(on_action_7_triggered()));
        connect(ui->action_8,SIGNAL(triggered(bool)),play,SLOT(on_action_8_triggered()));
        connect(ui->action_9,SIGNAL(triggered(bool)),play,SLOT(on_action_9_triggered()));
        connect(ui->action_10,SIGNAL(triggered(bool)),play,SLOT(on_action_10_triggered()));
        connect(ui->action_11,SIGNAL(triggered(bool)),play,SLOT(on_action_11_triggered()));
        connect(play,&PlayScene::back,this,[=]{
            this->setGeometry(play->geometry());
            play->hide();
            this->show();//跳转到主界面
            delete play;
            play=nullptr;
        });
    });





}

MainWindow::~MainWindow()
{
    delete ui;
}

