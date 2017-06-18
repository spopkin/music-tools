#include "tuner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tuner w;


    w.show();

    return a.exec();
}
