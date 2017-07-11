//Simple list of instrument models available to the tuner

#include "instrumentlist.h"
#include <cstring>

InstrumentList::InstrumentList()
{
    instSet = new std::vector<InstrumentModel *>();
}

InstrumentList::~InstrumentList()
{
    while (instSet->size() > 0) {
        delete instSet->back();
        instSet->pop_back();
    }
    delete instSet;
}

void InstrumentList::addInstrument(InstrumentModel *instrument)
{
    instSet->push_back(instrument);
}


void InstrumentList::removeInstrumentByNumber(int instrumentNo)
{
    delete instSet->at(instrumentNo);
    instSet->erase(instSet->begin() + instrumentNo);
}

//removes all instruments with a matching name
void InstrumentList::removeInstrumentByName(char *instrumentName)
{
    for (int i = 0; i < instSet->size(); i++) {
        InstrumentModel *inst = instSet->at(i);
        if (strlen(instSet->at(i)->getInstrumentName()) == strlen(instrumentName)
                && !strcmp(instSet->at(i)->getInstrumentName(), instrumentName)) {
            removeInstrumentByNumber(i);
            i--;
        }
    }
}

InstrumentModel *InstrumentList::getInstrumentByNumber(int instrumentNo)
{
    return instSet->at(instrumentNo);
}

InstrumentModel *InstrumentList::getInstrumentByName(char *instrumentName)
{
    for (int i = 0; i < instSet->size(); i++) {
        if (!strcmp(instSet->at(i)->getInstrumentName(), instrumentName)) {
            return instSet->at(i);
        }
    }
    return 0;
}

int InstrumentList::getNumInstruments()
{
    return instSet->size();
}
