#ifndef CLOSE_DLG_H
#define CLOSE_DLG_H

#include <QDialog>

namespace Ui {
class close_dlg;
}

class close_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit close_dlg(QWidget *parent = nullptr);
    ~close_dlg();

private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::close_dlg *ui;
};

#endif // CLOSE_DLG_H
