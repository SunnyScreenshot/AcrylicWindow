#ifndef BLURWIDGET_H
#define BLURWIDGET_H

#include <QWidget>
#include "widget.h"

class QGraphicsBlurEffect;
class BlurWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BlurWidget(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Widget* m_pw1;
    Widget* m_pw2;
    QGraphicsBlurEffect* m_pBlurEffect;
};

#endif // BLURWIDGET_H
