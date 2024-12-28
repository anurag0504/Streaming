/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_port;
    QWidget *renderingArea;
    QPushButton *pushButton_view;
    QPushButton *pushButton_stop;
    QTextEdit *textEdit_status;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(640, 511);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_port = new QLineEdit(centralwidget);
        lineEdit_port->setObjectName("lineEdit_port");

        verticalLayout->addWidget(lineEdit_port);

        renderingArea = new QWidget(centralwidget);
        renderingArea->setObjectName("renderingArea");
        renderingArea->setMinimumSize(QSize(320, 240));
        renderingArea->setMouseTracking(true);
        renderingArea->setTabletTracking(true);

        verticalLayout->addWidget(renderingArea);

        pushButton_view = new QPushButton(centralwidget);
        pushButton_view->setObjectName("pushButton_view");

        verticalLayout->addWidget(pushButton_view);

        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName("pushButton_stop");

        verticalLayout->addWidget(pushButton_stop);

        textEdit_status = new QTextEdit(centralwidget);
        textEdit_status->setObjectName("textEdit_status");

        verticalLayout->addWidget(textEdit_status);

        MainWindow->setCentralWidget(centralwidget);
        lineEdit_port->raise();
        pushButton_view->raise();
        pushButton_stop->raise();
        textEdit_status->raise();
        renderingArea->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 640, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GStreamer Viewer", nullptr));
        lineEdit_port->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter port number", nullptr));
        pushButton_view->setText(QCoreApplication::translate("MainWindow", "Start Viewing", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop Viewing", nullptr));
        textEdit_status->setPlaceholderText(QCoreApplication::translate("MainWindow", "Status messages will appear here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
