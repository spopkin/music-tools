//Dialog that is used to create new instrument models

#include "newinstrumentdialog.h"
#include "ui_newinstrumentdialog.h"

#include "addstringdialog.h"

#include "instrumentmodel.h"


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

//Handles the "add string" button press
//Creates a dialog that adds a string to the instrument
void NewInstrumentDialog::button_press_add_string()
{
    AddStringDialog *addS = (new AddStringDialog(this));
    addS->exec();
    delete addS;
}

//TODO: handles the acceptance and final creation of the current instrument
void NewInstrumentDialog::button_press_ok()
{

}
