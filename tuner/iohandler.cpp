//A simple class to handle IO operations and populate lists of
//instrument models

#include "iohandler.h"
#include <fstream>
#include <iostream>

//anticipated disk sector size in bytes
//modern drives tend to have 4KB sectors.
#define SECTOR_SIZE 4096

IOHandler::IOHandler()
{

}

IOHandler::~IOHandler()
{

}

//Reads, decodes, and returns a list from a given file by name
InstrumentList *IOHandler::readInstrumentsListFromDisk(std::string filename)
{
    std::fstream readFile;
    readFile.open(filename);

    std::string jsonData = "";
    do {
        char *inBuffer = (char *) calloc(sizeof(char), (SECTOR_SIZE + 1));
        readFile.readsome(inBuffer, (SECTOR_SIZE * sizeof(char)));
        std::string *bufferized = new std::string(inBuffer);
        jsonData += *bufferized;
        delete bufferized;
        free(inBuffer);
    } while(readFile.gcount() > 0);

    readFile.sync();

    //STUB: dump to console
    std::cout << jsonData << std::endl;

    //do reads and processing here

    readFile.close();
    return 0;
}

//Encodes and writes a list to a given file by name
int IOHandler::writeInstrumentsListToDisk(InstrumentList *instruments, std::string filename)
{
    std::fstream writeFile;
    writeFile.open(filename);

    //do writes and processing here

    writeFile.close();

    return 0;
}

