#include "newinstrumentdialog.h"
#include "ui_newinstrumentdialog.h"

#include "addstringdialog.h"

NewInstrumentDialog::NewInstrumentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewInstrumentDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a New Instrument");
    connect(ui->addStringButton, SIGNAL (released()), this, SLOT (button_press_add_string()));
    connect(ui->okButton, SIGNAL (released()), this, SLOT (button_press_ok()));
}

NewInstrumentDialog::~NewInstrumentDialog()
{
    delete ui;
}

void NewInstrumentDialog::button_press_add_string()
{
    AddStringDialog *addS = (new AddStringDialog(this));
    addS->exec();
    delete addS;
}

void NewInstrumentDialog::button_press_ok()
{


}
