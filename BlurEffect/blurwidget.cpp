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
    , m_blurVal(5)
    , m_pw1(nullptr)
    , m_pw2(nullptr)
    , m_pBlurEffect(nullptr)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(10);
    layout->addSpacing(50);

    QPixmap pix("../resources/p2.jpg");
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
    slider->setValue(m_blurVal);
    slider->setRange(0, 200);
    slider->setPageStep(1);
    connect(slider, &QSlider::valueChanged, this, [&](int value){
        m_blurVal = value;
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
    m_pBlurEffect->setBlurRadius(m_blurVal);
    m_pBlurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    m_pw2->setGraphicsEffect(m_pBlurEffect);
    m_pw2->lower();
}

void BlurWidget::resizeEvent(QResizeEvent *event)
{
    m_pw2->setGeometry(0, 0, width() , height());  // 最底层放置一层模糊的图片
    return QWidget::resizeEvent(event);
}


void BlurWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    setWindowTitle(QString("blur:%1").arg(m_blurVal));

    //QPainter pa(this);
    //pa.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //pa.setBrush(Qt::NoBrush);
    //pa.setPen(QPen(Qt::red, 2));

    //pa.drawText(QPoint(rect().x(), rect().bottom() - 50), QString("blur:%1").arg(m_blurVal));
}
