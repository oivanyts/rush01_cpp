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
    explicit MainWindow(IMonitorDisplay &systemInfo, bool *NcursActive, QWidget *parent = nullptr);
    ~MainWindow();
    MainWindow(const MainWindow &copy);
    MainWindow &operator = (const MainWindow &over);
    void refreshWindow();


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
    bool	*_ncActive;

};

#endif // MAINWINDOW_HPP
