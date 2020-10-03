#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*setStyleSheet("background-image:url(..:/new/prefix1/C:/Users/zqy/Desktop/QQ图片20200927164859.jpg)");

    painter=new QPainter(this);

    QPixmap backgp=QPixmap("..:/new/prefix1/C:/Users/zqy/Desktop/QQ图片20200927164859.jpg");
    painter->drawPixmap(this->rect(),backgp);*/
    ui->setupUi(this);
    setFixedSize(1100,900);//设置大小
    setWindowTitle("黑白迭代");//设置标题
    music=new QPushButton(this);
    music->setText("切换音乐");
    music->setGeometry(this->width()*0.1-music->width()*0.1,this->height()*0.9,100,70);

    startbutton=new QPushButton(this);
    jiaocheng=new QPushButton(this);
    play=new PlayScene(this);
    startbutton->setText("开始");
    jiaocheng->setText("游戏说明");
    jiaocheng->setGeometry(this->width()*0.5-startbutton->width()*0.5,this->height()*0.7,150,70);
    connect(this,SIGNAL(sendpara(int ,int )),play,SLOT(receivepara(int ,int )));
    connect(ui->action_3,&QAction::triggered,[=]{
        a=5;
        b=5;
        emit sendpara(a,b);
    });
    connect(ui->action_4,&QAction::triggered,[=]{
        a=6;
        b=6;
        emit sendpara(a,b);
    });
    connect(ui->action_5,&QAction::triggered,[=]{
        a=7;
        b=7;
        emit sendpara(a,b);
    });
    connect(ui->action_6,&QAction::triggered,[=]{
        a=5;
        b=10;
        emit sendpara(a,b);
    });
    connect(ui->action_7,&QAction::triggered,[=]{
        a=6;
        b=12;
        emit sendpara(a,b);
    });
    connect(ui->action_8,&QAction::triggered,[=]{
        a=7;
        b=14;
        emit sendpara(a,b);
    });
    connect(ui->action_9,&QAction::triggered,[=]{
        a=5;
        b=15;
        emit sendpara(a,b);
    });
    connect(ui->action_10,&QAction::triggered,[=]{
        a=6;
        b=18;
        emit sendpara(a,b);
    });
    connect(ui->action_11,&QAction::triggered,[=]{
        a=7;
        b=21;
        emit sendpara(a,b);
    });
    startbutton->setGeometry(this->width()*0.5-startbutton->width()*0.5,this->height()*0.5,150,70);
    connect(startbutton,&QPushButton::clicked,[=]{
        this->hide();
        play->setGeometry(this->geometry());
        connect(play,&PlayScene::back,this,[=]{
            this->setGeometry(play->geometry());
            play->hide();
            this->show();//跳转到主界面
        });
        play->timeinitial();
        play->btnsetting_();
        play->show();//跳转到游戏界面
    });
    jc=new JiaoCheng(this);
    connect(jiaocheng,&QPushButton::clicked,[=]{

        this->hide();
        jc->setGeometry(this->geometry());
        connect(jc,&JiaoCheng::back,this,[=]{
            this->setGeometry(jc->geometry());
            jc->hide();
            this->show();//跳转到主界面
        });
        jc->show();
    });


    player = new QMediaPlayer(this);
    //connect(player, SIGNAL(positionChanged(qint64)),this,SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\e4e2%2Fe816%2F5465%2F85acb333dcc921758ad943f4e9eb6f92.mp3"));
    player->setVolume(80);
    ispause=false;
    player->play();
    QPalette palette;
    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/C:/Users/zqy/Desktop/图片2.png")));
    this->setPalette(palette);
    connect(music,&QPushButton::clicked,[=]{
        musicchange();
    });

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::musicchange()
{
    mnum=(mnum+1)%6;
    switch (mnum) {
        case 0:
        player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\e4e2_e816_5465_85acb333dcc921758ad943f4e9eb6f92.mp3"));
        player->play();
        break;
    case 1:
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\4892%2Fcd8a%2F7738%2F096f9430c02a4604d66cb505542fb39a.mp3"));
    player->play();
    break;
    case 2:
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\836e%2Fdd8a%2F9723%2F7b7bc7d1ea64c173de2fb38804d888c6.mp3"));
    player->play();
    break;
    case 3:
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\0709%2F6a01%2F17a3%2F2eaa8c805e8bc2094674068843e767e9.mp3"));
    player->play();
    break;
    case 4:
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\9bb7%2F2819%2Fed2c%2Fcc5adde7fefe84171fb6db942af23c88.mp3"));
    player->play();
    break;
    case 5:
    player->setMedia(QUrl::fromLocalFile("D:\\Cloudmusic\\0e3f%2Ffbeb%2Fa8c1%2F56560b363521072c1b0d76964c05b54b.mp3"));
    player->play();
    break;
    default:
        break;

    }
}


void MainWindow::on_pushButton_clicked()
{
    if(ispause){
        ispause=false;
        ui->pushButton->setStyleSheet("border-image: url(:/new/prefix1/C:/Users/zqy/Desktop/声音开1.png);");
        player->play();
        return;
    }
    else{
        ispause=true;
        ui->pushButton->setStyleSheet("border-image: url(:/new/prefix1/C:/Users/zqy/Desktop/声音关1.png);");
        player->pause();
        return;
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QPalette palette;
    this->setAutoFillBackground(true);
    bcnum=(bcnum+1)%2;
    switch(bcnum){
    case 0:
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/C:/Users/zqy/Desktop/1155116835193446_b.jpg")));
        break;
    case 1:
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/C:/Users/zqy/Desktop/230543kwwonap0fwmztw25.jpg")));
        break;
    default:
        break;
    }
    this->setPalette(palette);

}
