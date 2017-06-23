#include "newinstrumentdialog.h"
#include "ui_newinstrumentdialog.h"

NewInstrumentDialog::NewInstrumentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewInstrumentDialog)
{
    ui->setupUi(this);
}

NewInstrumentDialog::~NewInstrumentDialog()
{
    delete ui;
}
