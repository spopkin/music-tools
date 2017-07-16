#ifndef INSTRUMENTLIST_H
#define INSTRUMENTLIST_H

#include "instrumentmodel.h"
#include <vector>
#include <string>

class InstrumentList
{
public:
    InstrumentList();
    ~InstrumentList();

    void addInstrument(InstrumentModel *instrument);
    void removeInstrumentByNumber(int instrumentNo);
    int removeInstrumentByName(std::string instrumentName);
    InstrumentModel *getInstrumentByNumber(int instrumentNo);
    InstrumentModel *getInstrumentByName(std::string instrumentName);

    int getNumInstruments();

private:
    std::vector<InstrumentModel *> *instSet;

    int getInstrumentNum(std::string instrumentName);
};

#endif // INSTRUMENTLIST_H
