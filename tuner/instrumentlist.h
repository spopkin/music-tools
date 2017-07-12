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
//    void removeInstrumentByName(char *instrumentName);
    int removeInstrumentByName(std::string instrumentName);
    InstrumentModel *getInstrumentByNumber(int instrumentNo);
    //    InstrumentModel *getInstrumentByName(char *instrumentName);
    InstrumentModel *getInstrumentByName(std::string instrumentName);

    int getNumInstruments();

    char *serializeToJSON();
    InstrumentList *deserializeFromJSON(char *json);

private:
    std::vector<InstrumentModel *> *instSet;

    int getInstrumentNum(std::string instrumentName);
};

#endif // INSTRUMENTLIST_H
