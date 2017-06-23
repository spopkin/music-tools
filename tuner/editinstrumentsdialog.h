#ifndef EDITINSTRUMENTSDIALOG_H
#define EDITINSTRUMENTSDIALOG_H

#include <QDialog>

namespace Ui {
class EditInstrumentsDialog;
}

class EditInstrumentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditInstrumentsDialog(QWidget *parent = 0);
    ~EditInstrumentsDialog();

private:
    Ui::EditInstrumentsDialog *ui;
};

#endif // EDITINSTRUMENTSDIALOG_H
