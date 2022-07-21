#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPixmap;
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    void setPixmap(const QPixmap &pix);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap m_pix;
};

#endif // WIDGET_H
