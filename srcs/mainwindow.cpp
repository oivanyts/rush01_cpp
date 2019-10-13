#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "QTOut.hpp"


MainWindow::MainWindow(IMonitorDisplay &systemInfo, bool *NcursActive, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow), _sysInfo(systemInfo), _ncActive(NcursActive)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::refreshWindow);
    timer->start();
    ui->setupUi(this);
    refreshWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

MainWindow::MainWindow(const MainWindow &copy) {
    *this = copy;
}

MainWindow::MainWindow &operator = (const MainWindow &over) {
    return (*this);
}


void MainWindow::refreshWindow()
{
    _sysInfo.updateInfo();
    ui->labelHostName->setText(QString::fromStdString(_sysInfo.getHostStr()));
    ui->labelOsInfo->setText(QString::fromStdString(_sysInfo.getOsStr()));
    ui->labelDateTime->setText(QString::fromStdString(_sysInfo.getDateTime()));
    ui->labelCPU->setText(QString::fromStdString(_sysInfo.getCpuModel()));
    ui->cpuProgressBar->setTextVisible(true);

//    ui->cpuProgressBar->setStatusTip(QString::fromStdString(std::to_string(100 - static_cast<int>(_sysInfo->getCpuIdle()))));
    ui->cpuProgressBar->setValue(100 - static_cast<int>(_sysInfo.getCpuIdle()));
}


/*
 * ./CLionProjects/build-rush01-Desktop_Qt_5_13_0_clang_64bit-Debug/rush01.app/Contents/MacOS/rush01
 */
