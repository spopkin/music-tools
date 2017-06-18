#include "tuner.h"
#include "ui_tuner.h"
#include <iostream>

Tuner::Tuner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tuner)
{
    ui->setupUi(this);

    actionAbout = ui->actionAbout;
    connect(actionAbout, SIGNAL (triggered()), this, SLOT (on_menu_about_activated()));
}

Tuner::~Tuner()
{
    delete ui;
}

void Tuner::on_menu_about_activated() {
//    std::cout << "about" << std::endl;
}
