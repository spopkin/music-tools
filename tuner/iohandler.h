#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "instrumentlist.h"
#include <string>

class IOHandler
{
public:
    IOHandler();
    ~IOHandler();
    InstrumentList *readInstrumentsListFromDisk(std::string filename);
    int writeInstrumentsListToDisk(InstrumentList *instruments, std::string sfilename);

};

#endif // IOHANDLER_H
