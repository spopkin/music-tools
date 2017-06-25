#ifndef ADDSTRINGDIALOG_H
#define ADDSTRINGDIALOG_H

#include <QDialog>

namespace Ui {
class AddStringDialog;
}

class AddStringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStringDialog(QWidget *parent = 0);
    ~AddStringDialog();

private:
    Ui::AddStringDialog *ui;
};

#endif // ADDSTRINGDIALOG_H
