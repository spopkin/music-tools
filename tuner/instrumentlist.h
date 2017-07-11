#ifndef INSTRUMENTLIST_H
#define INSTRUMENTLIST_H

#include "instrumentmodel.h"
#include <vector>

class InstrumentList
{
public:
    InstrumentList();
    ~InstrumentList();

    void addInstrument(InstrumentModel *instrument);
    void removeInstrumentByNumber(int instrumentNo);
    void removeInstrumentByName(char *instrumentName);
    InstrumentModel *getInstrumentByNumber(int instrumentNo);
    InstrumentModel *getInstrumentByName(char *instrumentName);

    int getNumInstruments();

    char *serializeToJSON();
    InstrumentList *deserializeFromJSON(char *json);

private:
    std::vector<InstrumentModel *> *instSet;
};

#endif // INSTRUMENTLIST_H
