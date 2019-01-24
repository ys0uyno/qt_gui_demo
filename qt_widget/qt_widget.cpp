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

    pngBackGround.load(":./images/background.png");
    if (pngBackGround.isNull()) {
        qDebug("load backround image failed");
    }

    pngBackGround = pngBackGround.scaled(size());
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

    QPainter paint(this);
    paint.drawPixmap(0, 0, pngBackGround);
}
