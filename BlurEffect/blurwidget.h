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
    int m_blurVal;     // 模糊参数
    Widget* m_pw1;     // 上层，和底部进行效果对比
    Widget* m_pw2;     // 置于底层且添加模糊
    QGraphicsBlurEffect* m_pBlurEffect;
};

#endif // BLURWIDGET_H
