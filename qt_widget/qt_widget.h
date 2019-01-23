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

private:
    Ui::qt_widget *ui;
};

#endif // QT_WIDGET_H
