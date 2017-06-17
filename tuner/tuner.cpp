#include "tuner.h"
#include "ui_tuner.h"

Tuner::Tuner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tuner)
{
    ui->setupUi(this);
}

Tuner::~Tuner()
{
    delete ui;
}


