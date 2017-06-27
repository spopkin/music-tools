#include "iohandler.h"
#include <fstream>
#include <iostream>

IOHandler::IOHandler()
{

}

IOHandler::~IOHandler()
{

}

InstrumentList *IOHandler::readInstrumentsListFromDisk(char *filename)
{
    std::fstream readFile;
    readFile.open(filename);

    //do reads and processing here

    readFile.close();
    return 0;
}

int IOHandler::writeInstrumentsListToDisk(InstrumentList *instruments, char *filename)
{
    std::fstream writeFile;
    writeFile.open(filename);

    //do writes and processing here

    writeFile.close();

    return 0;
}

