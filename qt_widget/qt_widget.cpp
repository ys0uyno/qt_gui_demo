#include "qt_widget.h"
#include "ui_qt_widget.h"
#include <QtWidgets>

qt_widget::qt_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qt_widget)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
}

qt_widget::~qt_widget()
{
    delete ui;
}

void qt_widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void qt_widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
