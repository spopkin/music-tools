#ifndef NEWINSTRUMENTDIALOG_H
#define NEWINSTRUMENTDIALOG_H

#include <QDialog>

namespace Ui {
class NewInstrumentDialog;
}

class NewInstrumentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewInstrumentDialog(QWidget *parent = 0);
    ~NewInstrumentDialog();

private:
    Ui::NewInstrumentDialog *ui;
};

#endif // NEWINSTRUMENTDIALOG_H
