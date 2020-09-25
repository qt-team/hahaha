/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *action_11;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_3->setCheckable(false);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_4->setCheckable(false);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_6->setCheckable(false);
        action_6->setAutoRepeat(true);
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QStringLiteral("action_10"));
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QStringLiteral("action_11"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menu);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(menu_2->menuAction());
        menu->addAction(menu_3->menuAction());
        menu->addAction(menu_4->menuAction());
        menu_2->addAction(action_3);
        menu_2->addAction(action_6);
        menu_2->addAction(action_9);
        menu_3->addAction(action_4);
        menu_3->addAction(action_7);
        menu_3->addAction(action_10);
        menu_4->addAction(action_5);
        menu_4->addAction(action_8);
        menu_4->addAction(action_11);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\344\275\216\351\230\266", Q_NULLPTR));
        action_4->setText(QApplication::translate("MainWindow", "\344\275\216\351\230\266", Q_NULLPTR));
        action_5->setText(QApplication::translate("MainWindow", "\344\275\216\351\230\266", Q_NULLPTR));
        action_6->setText(QApplication::translate("MainWindow", "\344\270\255\351\230\266", Q_NULLPTR));
        action_7->setText(QApplication::translate("MainWindow", "\344\270\255\351\230\266", Q_NULLPTR));
        action_8->setText(QApplication::translate("MainWindow", "\344\270\255\351\230\266", Q_NULLPTR));
        action_9->setText(QApplication::translate("MainWindow", "\351\253\230\351\230\266", Q_NULLPTR));
        action_10->setText(QApplication::translate("MainWindow", "\351\253\230\351\230\266", Q_NULLPTR));
        action_11->setText(QApplication::translate("MainWindow", "\351\253\230\351\230\266", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\270\270\346\210\217", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\260\217", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\344\270\255", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\244\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
