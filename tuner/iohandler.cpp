//A simple class to handle IO operations and populate lists of
//instrument models

#include "iohandler.h"
#include <fstream>
#include <iostream>

IOHandler::IOHandler()
{

}

IOHandler::~IOHandler()
{

}

//Reads, decodes, and returns a list from a given file by name
InstrumentList *IOHandler::readInstrumentsListFromDisk(char *filename)
{
    std::fstream readFile;
    readFile.open(filename);

    //do reads and processing here

    readFile.close();
    return 0;
}

//Encodes and writes a list to a given file by name
int IOHandler::writeInstrumentsListToDisk(InstrumentList *instruments, char *filename)
{
    std::fstream writeFile;
    writeFile.open(filename);

    //do writes and processing here

    writeFile.close();

    return 0;
}

