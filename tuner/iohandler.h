#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "instrumentlist.h"

class IOHandler
{
public:
    IOHandler();
    ~IOHandler();
    InstrumentList *readInstrumentsListFromDisk(char *filename);
    int writeInstrumentsListToDisk(InstrumentList *instruments, char *filename);

};

#endif // IOHANDLER_H
