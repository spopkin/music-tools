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

//removes the first instrument with a matching name
int InstrumentList::removeInstrumentByName(std::string instrumentName)
{
    int num = getInstrumentNum(instrumentName);
    if (num >= 0) {
        removeInstrumentByNumber(num);
        return 0;
    }
    return -1;
}

InstrumentModel *InstrumentList::getInstrumentByNumber(int instrumentNo)
{
    return instSet->at(instrumentNo);
}

//retrieves an instrument's index in the vector
int InstrumentList::getInstrumentNum(std::string instrumentName)
{
    for (int i = 0; i < instSet->size(); i++) {
        if (!instSet->at(i)->getInstrumentName()->compare(instrumentName)) {
            return i;
        }
    }
    return -1;
}

//get the instrument pointer for the first instrument with a matching name
InstrumentModel *InstrumentList::getInstrumentByName(std::string instrumentName)
{
    int num = getInstrumentNum(instrumentName);
    if (num >= 0) {
        return instSet->at(num);
    }
    return 0;
}

//returns the number of instruments stored in the list
int InstrumentList::getNumInstruments()
{
    return instSet->size();
}

//creates a sendable, storable json string.
char *InstrumentList::serializeToJSON()
{
    //compute the length of the wrapper elements
    //for each instrument
        //compute the length of the instrument model string
    //use those lengths to compute the total string length
    //malloc that
    //strcpy the opening metadata
    //strcpy each instrument's data
    //strcpy the closing metadata/curly braces

    //format:
    //{
    //  "instList": [
    //      {
    //          "name": "$instName",
    //          "strings": [
    //              {
    //                  "name": "$strName",
    //                  "freq": $strFreq
    //              },...
    //          ]
    //      },...
    //  ]
    //}

    //size of everything up to the first square bracket
    //plus the size of everything from the line of the last one.
    long len = (long) sizeof(char) * (strlen("{\n\t\"instList\": [\n\t]\n}") + 1);

    for (int i = 0; i < instSet->size(); i++) {

    }
    return 0;
}

//creates an InstrumentList from a json string
InstrumentList *InstrumentList::deserializeFromJSON(char *json)
{
    return 0;
}
