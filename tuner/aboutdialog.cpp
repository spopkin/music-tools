//A simple help->about dialog

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("About this Tuner");
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
