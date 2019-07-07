#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "QTOut.hpp"


MainWindow::MainWindow(IMonitorDisplay &systemInfo, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow), _sysInfo(systemInfo)
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

void MainWindow::refreshWindow()
{
    _sysInfo.updateInfo();
    ui->labelHostName->setText(QString::fromStdString(_sysInfo.getHostStr()));
    ui->labelOsInfo->setText(QString::fromStdString(_sysInfo.getOsStr()));
    ui->labelDateTime->setText(QString::fromStdString("TIME"));
    ui->labelCPU->setText(QString::fromStdString(_sysInfo.getCpuModel()));
    ui->cpuProgressBar->setTextVisible(true);

//    ui->cpuProgressBar->setStatusTip(QString::fromStdString(std::to_string(100 - static_cast<int>(_sysInfo->getCpuIdle()))));
    ui->cpuProgressBar->setValue(100 - static_cast<int>(_sysInfo.getCpuIdle()));
}

void MainWindow::on_switchButton_clicked()
{

}

