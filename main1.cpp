#include "here/mainwindow.hpp"
#include <QApplication>
#include "here/QTOut.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMonitorDisplay *qtGeneral = new QTOut();

    MainWindow w(*qtGeneral);
    w.show();
    return a.exec();
}
