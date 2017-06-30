//Dialog to edit the list of existing instruments

#include "editinstrumentsdialog.h"
#include "ui_editinstrumentsdialog.h"

EditInstrumentsDialog::EditInstrumentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInstrumentsDialog)
{
    ui->setupUi(this);
}

EditInstrumentsDialog::~EditInstrumentsDialog()
{
    delete ui;
}
