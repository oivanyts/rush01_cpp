#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

#include "QTOut.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(IMonitorDisplay &systemInfo, QWidget *parent = nullptr);
    ~MainWindow();
    void refreshWindow();

private slots:
    void on_switchButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer  *timer;
    QLabel *m_label;
    IMonitorDisplay   &_sysInfo;
    HostnameModule hostnameModule;
    OSInfoModule osInfoModule;
    DateTimeModule dateTimeModule;
    CPUModule cpuModule;
    RAMModule ramModule;

};

#endif // MAINWINDOW_HPP
