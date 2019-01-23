#include "qt_widget.h"
#include "ui_qt_widget.h"

qt_widget::qt_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qt_widget)
{
    ui->setupUi(this);
}

qt_widget::~qt_widget()
{
    delete ui;
}
