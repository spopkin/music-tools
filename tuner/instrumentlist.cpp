//Simple list of instrument models available to the tuner

#include "instrumentlist.h"

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

void InstrumentList::removeInstrumentByName(char *instrumentName)
{

}

InstrumentModel *InstrumentList::getInstrumentByNumber(int instrumentNo)
{
    return instSet->at(instrumentNo);
}

InstrumentModel *InstrumentList::getInstrumentByName(char *instrumentName)
{

}

int InstrumentList::getNumInstruments()
{
    return instSet->size();
}
