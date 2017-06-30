#ifndef INSTRUMENTLIST_H
#define INSTRUMENTLIST_H

#include "instrumentmodel.h"

class InstrumentList
{
public:
    InstrumentList();
    ~InstrumentList();

    void addInstrument(InstrumentModel *instrument);
    InstrumentModel *removeInstrumentByNumber(int instrumentNo);
    InstrumentModel *removeInstrumentByName(char *instrumentName);
    InstrumentModel *getInstrumentByNumber(int instrumentNo);
    InstrumentModel *getInstrumentByName(char *instrumentName);
};

#endif // INSTRUMENTLIST_H
