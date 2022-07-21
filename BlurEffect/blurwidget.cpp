#include "blurwidget.h"
#include <QColor>
#include <QGraphicsBlurEffect>
#include <QPainter>
#include <QPen>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QDir>

BlurWidget::BlurWidget(QWidget *parent)
    : QWidget(parent)
    , m_pw1(nullptr)
    , m_pw2(nullptr)
    , m_pBlurEffect(nullptr)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(10);
    layout->addSpacing(50);

    // 氪，默认是 .exe 的路径，采用 MSVC 会多一层 {debug/release}, 则多以额 .. , gcc 则少一个 ..
    
    QString path("../resources/p2.jpg");
    QDir dir(path);

    bool b = false;
    if (!dir.exists()) {
        path = QString("../") + path;

        dir.setPath(path);
    }

    QPixmap pix(path);
    m_pw1 = new Widget();
    m_pw1->setPixmap(pix);
    m_pw1->setFixedSize(200, 200);
    m_pw1->show();
    layout->addWidget(m_pw1, 0, Qt::AlignTop | Qt::AlignHCenter);

    QPushButton* btn = new QPushButton(tr("Observe button effect"));
    layout->addWidget(btn, 0, Qt::AlignTop | Qt::AlignHCenter);

    QSlider* slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setFixedWidth(width() * 2 / 3);
    slider->setValue(5);
    slider->setRange(0, 200);
    slider->setPageStep(1);
    connect(slider, &QSlider::valueChanged, this, [&](int value){
        if (m_pBlurEffect)
            m_pBlurEffect->setBlurRadius(value);
    });
    layout->addStretch(3);
    layout->addWidget(slider, 0, Qt::AlignTop | Qt::AlignHCenter);
    layout->addStretch(1);


    m_pw2 = new Widget(this);
    m_pw2->setPixmap(pix);

    // Effect
    m_pBlurEffect = new QGraphicsBlurEffect();
    m_pBlurEffect->setBlurRadius(5);
    m_pBlurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    m_pw2->setGraphicsEffect(m_pBlurEffect);
    m_pw2->lower();
}

void BlurWidget::resizeEvent(QResizeEvent *event)
{
    m_pw2->setGeometry(0, 0, width(), height());  // 最底层放置一层模糊的图片
    return QWidget::resizeEvent(event);
}


void BlurWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter pa(m_pw2);
    pa.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QColor colBrush(Qt::red);  // "#131313"
    colBrush.setAlphaF(1);
    pa.setBrush(colBrush);
    QColor colPen("#FFFFFF");
    colPen.setAlphaF(0.1);
    QPen pen(colPen, 1);
    pa.setPen(pen);

    const int margin1 = 1;
    const int B_RADIRS = 6;
    pa.drawRoundedRect(contentsRect().adjusted(margin1, margin1, -margin1, -margin1), B_RADIRS, B_RADIRS);

    colPen.setNamedColor("#000000");
    colPen.setAlphaF(0.1);
    pa.setPen(colPen);
    pa.setBrush(Qt::NoBrush);
    const int margin2 = 0;
    pa.drawRoundedRect(contentsRect().adjusted(margin2, margin2, -margin2, -margin2), B_RADIRS, B_RADIRS);
}
