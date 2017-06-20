#include "tuner.h"
#include "ui_tuner.h"
#include <iostream>

Tuner::Tuner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tuner)
{
    ui->setupUi(this);

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
}

void Tuner::on_menu_about_activated() {
    std::cout << "about" << std::endl;
}

void Tuner::on_menu_new_instrument() {
    std::cout << "new instrument" << std::endl;
}

void Tuner::on_menu_edit_instruments() {
    std::cout << "edit instruments" << std::endl;
}

