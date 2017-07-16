//Main Tuner window, ties together a number of components
//In MVC terms, largely a view module, with a little bit of
//controller thrown in.

#include "tuner.h"
#include "ui_tuner.h"
#include <iostream>

#include "aboutdialog.h"
#include "newinstrumentdialog.h"
#include "iohandler.h"

IOHandler *io = 0;

Tuner::Tuner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tuner)
{
    ui->setupUi(this);

    actionAbout = ui->actionAbout;
    actionEditInstruments = ui->actionEdit_Instruments;
    actionNewInstrument = ui->actionNew_Instrument;

    if (io == 0) {
        io = new IOHandler();
        //go ahead and load the default profile now
        //STUB: the file path is not yet configurable
        InstrumentList *iList = io->readInstrumentsListFromDisk("/home/sjp/Documents/music-tools/tuner/testfiles/test0.json");
        //STUB: more printing
//        std::cout << *(io->serializeToJSON(iList)) << std::endl;
        io->writeInstrumentsListToDisk(iList, "/tmp/tuner-test0.txt");
    }

    connect(actionAbout, SIGNAL (triggered()), this, SLOT (on_menu_about_activated()));
    connect(actionEditInstruments, SIGNAL (triggered()), this, SLOT (on_menu_edit_instruments()));
    connect(actionNewInstrument, SIGNAL (triggered()), this, SLOT (on_menu_new_instrument()));
}

Tuner::~Tuner()
{
    delete ui;
    if (io != 0) {
        delete io;
        io = 0;
    }
}

//Handles the main_menu->help->about event
//Creates an about dialog
void Tuner::on_menu_about_activated()
{
    AboutDialog *about = new AboutDialog(this);
    std::cout << "about" << std::endl;
    about->exec();
    delete about;
}

//Handles the main_menu->edit->new_instrument event
//Creates a dialog to add a new instrument
void Tuner::on_menu_new_instrument()
{
    NewInstrumentDialog *newInst = new NewInstrumentDialog(this);
    std::cout << "new instrument" << std::endl;
    newInst->exec();
    delete newInst;
}

//Handles the main_menu->edit->edit_instruments event
//TODO: creates a dialog to edit existing instruments
void Tuner::on_menu_edit_instruments()
{
    std::cout << "edit instruments" << std::endl;
}

