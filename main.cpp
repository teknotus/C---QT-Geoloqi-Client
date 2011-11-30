#include <QtGui/QApplication>
#include "loqiwindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoqiWindow w;
    MainWindow m;
    w.show();
    m.show();
    return a.exec();
}
