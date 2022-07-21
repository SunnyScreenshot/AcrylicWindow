#include "widget.h"

#include <QGraphicsBlurEffect>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
//    QGraphicsBlurEffect* m_pBlurEffect = new QGraphicsBlurEffect();
//    m_pBlurEffect->setBlurRadius(10);
//    m_pBlurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
//    this->setGraphicsEffect(m_pBlurEffect);
//    setWindowFlags(Qt::FramelessWindowHint);

    auto btn = new QPushButton("btn", this);
    btn->move(10, 10);
}

void Widget::setPixmap(const QPixmap &pix)
{
    m_pix = pix;

    m_pix.save("12qw.png");
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (!m_pix.isNull())
        painter.drawPixmap(rect(), m_pix);
}
