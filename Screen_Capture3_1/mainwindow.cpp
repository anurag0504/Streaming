#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), gstProcess(new QProcess(this)) {
    ui->setupUi(this);

    // Connect buttons to their slots
    connect(ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::startScreenSharing);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &MainWindow::stopScreenSharing);

    // Log GStreamer output
    connect(gstProcess, &QProcess::readyReadStandardOutput, this, [this]() {
        ui->textEdit_status->append("GStreamer Output: " + gstProcess->readAllStandardOutput());
    });
    connect(gstProcess, &QProcess::readyReadStandardError, this, [this]() {
        ui->textEdit_status->append("GStreamer Error: " + gstProcess->readAllStandardError());
    });
    connect(gstProcess, QOverload<QProcess::ProcessError>::of(&QProcess::errorOccurred), this, [this](QProcess::ProcessError error) {
        ui->textEdit_status->append("GStreamer Process Error: " + gstProcess->errorString());
    });
}

MainWindow::~MainWindow() {
    if (gstProcess->state() == QProcess::Running) {
        gstProcess->terminate();
        gstProcess->waitForFinished();
    }
    delete ui;
}

/*void MainWindow::startScreenSharing() {
    QString ip = ui->lineEdit_ip->text();
    QString port = ui->lineEdit_port->text();

    if (ip.isEmpty() || port.isEmpty()) {
        ui->textEdit_status->append("Please enter both IP and Port.");
        return;
    }

    QString pipeline = QString(
                           "D:/gstreamer/1.0/msvc_x86_64/bin/gst-launch-1.0 d3d11screencapturesrc ! queue ! videoconvert ! queue ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! queue ! rtph264pay config-interval=1 pt=96 ! queue ! udpsink host=%1 port=%2"
                           ).arg(ip, port);
    QString pipeline = "D:/gstreamer/1.0/msvc_x86_64/bin/gst-launch-1.0 --version";



    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PATH", "D:/gstreamer/1.0/msvc_x86_64/bin;" + env.value("PATH")); // Adjust path as needed
    gstProcess->setProcessEnvironment(env);

    gstProcess->start(pipeline);
    if (!gstProcess->waitForStarted()) {
        ui->textEdit_status->append("Failed to start screen sharing.");
    } else {
        ui->textEdit_status->append("Screen sharing started.");
        ui->pushButton_start->setDisabled(true);
        ui->lineEdit_ip->setDisabled(true);
        ui->lineEdit_port->setDisabled(true);
    }
} */

void MainWindow::startScreenSharing() {
    QString ip = ui->lineEdit_ip->text();
    QString port = ui->lineEdit_port->text();

    if (ip.isEmpty() || port.isEmpty()) {
        ui->textEdit_status->append("Please enter both IP and Port.");
        return;
    }

    if (port.toInt() < 1024 || port.toInt() > 65535) {
        ui->textEdit_status->append("Invalid port number. Please use a port between 1024 and 65535.");
        return;
    }

    QString pipeline = QString(
                           "D:/gstreamer/1.0/msvc_x86_64/bin/gst-launch-1.0 d3d11screencapturesrc ! queue ! videoconvert ! queue ! x264enc tune=zerolatency bitrate=500 speed-preset=superfast ! queue ! rtph264pay config-interval=1 pt=96 ! queue ! udpsink host=\"%1\" port=\"%2\""
                           ).arg(ip,port);


    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PATH", "D:/gstreamer/1.0/msvc_x86_64/bin;" + env.value("PATH"));
    gstProcess->setProcessEnvironment(env);

    qDebug() << "Executing pipeline:" << pipeline;
    gstProcess->start(pipeline);

    if (!gstProcess->waitForStarted()) {
        qDebug() << "Failed to start process. Error:" << gstProcess->errorString();
        ui->textEdit_status->append("Failed to start screen sharing. Error: " + gstProcess->errorString());
    } else {
        ui->textEdit_status->append("Screen sharing started.");
    }

    // Log GStreamer output and errors
    connect(gstProcess, &QProcess::readyReadStandardOutput, this, [this]() {
        ui->textEdit_status->append("GStreamer Output: " + gstProcess->readAllStandardOutput());
    });

    connect(gstProcess, &QProcess::readyReadStandardError, this, [this]() {
        ui->textEdit_status->append("GStreamer Error: " + gstProcess->readAllStandardError());
    });

    if (gstProcess->waitForStarted()) {
        ui->textEdit_status->append("Screen sharing started.");
        ui->pushButton_start->setDisabled(true);
        ui->pushButton_stop->setEnabled(true);
    } else {
        ui->textEdit_status->append("Failed to start screen sharing.");
    }

}




void MainWindow::stopScreenSharing() {
    if (gstProcess->state() == QProcess::Running) {
        gstProcess->terminate();
        gstProcess->waitForFinished();
        ui->textEdit_status->append("Screen sharing stopped.");
    }
    ui->pushButton_start->setEnabled(true);
    ui->lineEdit_ip->setEnabled(true);
    ui->lineEdit_port->setEnabled(true);
    ui->pushButton_start->setDisabled(true);
    ui->pushButton_stop->setEnabled(true);

}

