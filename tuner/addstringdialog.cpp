#include "addstringdialog.h"
#include "ui_addstringdialog.h"

AddStringDialog::AddStringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStringDialog)
{
    ui->setupUi(this);
}

AddStringDialog::~AddStringDialog()
{
    delete ui;
}
