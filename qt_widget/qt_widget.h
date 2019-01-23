#ifndef QT_WIDGET_H
#define QT_WIDGET_H

#include <QWidget>

namespace Ui {
class qt_widget;
}

class qt_widget : public QWidget
{
    Q_OBJECT

public:
    explicit qt_widget(QWidget *parent = nullptr);
    ~qt_widget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::qt_widget *ui;
    QPoint dragPosition;
};

#endif // QT_WIDGET_H
