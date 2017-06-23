#include "tuner.h"
#include "ui_tuner.h"
#include <iostream>

Tuner::Tuner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tuner)
{
    ui->setupUi(this);

//    about = new AboutDialog(this);

    actionAbout = ui->actionAbout;
    actionEditInstruments = ui->actionEdit_Instruments;
    actionNewInstrument = ui->actionNew_Instrument;

    connect(actionAbout, SIGNAL (triggered()), this, SLOT (on_menu_about_activated()));
    connect(actionEditInstruments, SIGNAL (triggered()), this, SLOT (on_menu_edit_instruments()));
    connect(actionNewInstrument, SIGNAL (triggered()), this, SLOT (on_menu_new_instrument()));
}

Tuner::~Tuner()
{
    delete ui;
//    delete about;
}

void Tuner::on_menu_about_activated()
{
    AboutDialog *about = new AboutDialog(this);
    std::cout << "about" << std::endl;
    about->exec();
    delete about;
}

void Tuner::on_menu_new_instrument()
{
    NewInstrumentDialog *newInst = new NewInstrumentDialog(this);
    std::cout << "new instrument" << std::endl;
    newInst->exec();
    delete newInst;
}

void Tuner::on_menu_edit_instruments()
{
    std::cout << "edit instruments" << std::endl;
}

