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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_ip;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QLabel *label_status;
    QTextEdit *textEdit_status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit_ip = new QLineEdit(centralwidget);
        lineEdit_ip->setObjectName("lineEdit_ip");
        lineEdit_ip->setGeometry(QRect(140, 30, 200, 25));
        lineEdit_port = new QLineEdit(centralwidget);
        lineEdit_port->setObjectName("lineEdit_port");
        lineEdit_port->setGeometry(QRect(140, 70, 200, 25));
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setGeometry(QRect(50, 120, 130, 30));
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setGeometry(QRect(220, 120, 130, 30));
        label_status = new QLabel(centralwidget);
        label_status->setObjectName("label_status");
        label_status->setGeometry(QRect(20, 180, 360, 20));
        textEdit_status = new QTextEdit(centralwidget);
        textEdit_status->setObjectName("textEdit_status");
        textEdit_status->setGeometry(QRect(20, 210, 360, 60));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Screen Capture Application", nullptr));
        lineEdit_ip->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Destination IP", nullptr));
        lineEdit_port->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Destination Port", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start Screen Sharing", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop Screen Sharing", nullptr));
        label_status->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
