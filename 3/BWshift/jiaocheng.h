#ifndef JIAOCHENG_H
#define JIAOCHENG_H

#include <QMainWindow>
#include<QPushButton>

class JiaoCheng : public QMainWindow
{
    Q_OBJECT
public:
    explicit JiaoCheng(QWidget *parent = nullptr);
    QPushButton *backbtn;

signals:
    void back();
public slots:
};

#endif // JIAOCHENG_H
