#include "getfit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    getFit w;
    w.show();
    return a.exec();
}
