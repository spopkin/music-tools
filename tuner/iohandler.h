#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "instrumentlist.h"

class IOHandler
{
public:
    IOHandler();
    ~IOHandler();
    InstrumentList *readInstrumentsListFromDisk();
    int writeInstrumentsListToDisk(InstrumentList *instruments, char *filename);

};

#endif // IOHANDLER_H
