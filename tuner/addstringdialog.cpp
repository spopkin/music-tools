#include "addstringdialog.h"
#include "ui_addstringdialog.h"

AddStringDialog::AddStringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStringDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a String to an Instrument");
}

AddStringDialog::~AddStringDialog()
{
    delete ui;
}
