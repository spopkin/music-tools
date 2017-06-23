#ifndef NEWINSTRUMENTDIALOG_H
#define NEWINSTRUMENTDIALOG_H

#include <QDialog>
#include "addstringdialog.h"

namespace Ui {
class NewInstrumentDialog;
}

class NewInstrumentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewInstrumentDialog(QWidget *parent = 0);
    ~NewInstrumentDialog();

public slots:
    void button_press_add_string();

private:
    Ui::NewInstrumentDialog *ui;
};

#endif // NEWINSTRUMENTDIALOG_H
