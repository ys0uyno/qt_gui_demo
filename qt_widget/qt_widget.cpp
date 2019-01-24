#include "qt_widget.h"
#include "ui_qt_widget.h"
#include <QtWidgets>

qt_widget::qt_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qt_widget)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
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

void qt_widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
