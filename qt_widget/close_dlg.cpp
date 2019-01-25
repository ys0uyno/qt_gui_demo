#include "close_dlg.h"
#include "ui_close_dlg.h"

close_dlg::close_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::close_dlg)
{
    ui->setupUi(this);
}

close_dlg::~close_dlg()
{
    delete ui;
}

void close_dlg::on_okBtn_clicked()
{
    this->accept();
}

void close_dlg::on_cancelBtn_clicked()
{
    this->reject();
}
