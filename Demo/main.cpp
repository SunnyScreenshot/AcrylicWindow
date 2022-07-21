#include <QApplication>
#include "exwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ExWidget w;
    w.show();

    return a.exec();
}
