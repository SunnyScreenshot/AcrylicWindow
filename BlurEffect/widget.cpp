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

    auto btn = new QPushButton("观察此子控件是否模糊", this);
    btn->move(10, 10);
}

void Widget::setPixmap(const QPixmap &pix)
{
    m_pix = pix;
//    m_pix.save("p22.jpg");
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (!m_pix.isNull())
        painter.drawPixmap(rect(), m_pix);

    QPainter pa(this);
    pa.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    if (!m_pix.isNull())
        pa.drawPixmap(rect(), m_pix);

//    // 解开就是遮罩效果
//    QColor colBrush("#131313");
//    colBrush.setAlphaF(0.6);
//    pa.setBrush(colBrush);
//    QColor colPen("#FFFFFF");
//    colPen.setAlphaF(0.1);
//    QPen pen(colPen, 1);
//    pa.setPen(pen);

//    const int margin1 = 1;
//    pa.drawRoundedRect(contentsRect().adjusted(margin1, margin1, -margin1, -margin1), 4, 4);

//    colPen.setNamedColor("#000000");
//    colPen.setAlphaF(0.1);
//    pa.setPen(colPen);
//    pa.setBrush(Qt::NoBrush);
//    const int margin2 = 0;
//    pa.drawRoundedRect(contentsRect().adjusted(margin2, margin2, -margin2, -margin2), 4, 4);
}
