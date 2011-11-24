#include <QtGui/QApplication>
#include "loqiwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoqiWindow w;
    w.show();
    return a.exec();
}
