#include <QApplication>
#include <QPixmap>
#include "widget.h"
#include "blurwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 自动调节模糊成都
    BlurWidget w;
    w.resize(800, 600);
    w.show();

    //auto pW = new Widget();
    //auto t = QPixmap("../../resources/p2.jpg");
    //t.save("1111aa.jpg");
    //pW->setPixmap(t);
    //pW->setFixedSize(800, 600);
    //pW->show();

    return a.exec();
}
