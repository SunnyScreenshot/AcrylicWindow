#ifndef EXWIDGET_H
#define EXWIDGET_H

#include <QWidget>

class ExWidget : public QWidget
{
    Q_OBJECT

public:
    ExWidget(QWidget *parent = nullptr);
    ~ExWidget() = default;
};
#endif // EXWIDGET_H
