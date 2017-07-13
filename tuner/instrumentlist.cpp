//Simple list of instrument models available to the tuner

#include "instrumentlist.h"
#include <cstring>
#include <iostream>

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
std::string *InstrumentList::serializeToJSON()
{
    //basically, just keep using string concatination
    //format:
    //{
    //  "instList": [
    //      {
    //          "instName": "$instName",
    //          "strings": [
    //              {
    //                  "name": "$strName",
    //                  "freq": $strFreq
    //              },...
    //          ]
    //      },...
    //  ]
    //}

    std::string direct = "";

    direct += "{\n";
    direct += "\t\"instList\": [\n";

    for (int i = 0; i < instSet->size(); i++) {
        std::string *name = instSet->at(i)->getInstrumentName();
        direct += "\t\t{\n";
        direct += "\t\t\t\"instName\": \"" + *name + "\",\n";
        direct += "\t\t\t\"strings\": []\n";
        direct += "\t\t}\n";
    }

    direct += "\t]\n";
    direct += "}";

    std::string *jsonRep = new std::string(direct);

    return jsonRep;
}

//creates an InstrumentList from a json string
InstrumentList *InstrumentList::deserializeFromJSON(std::string *json)
{
    return 0;
}

void InstrumentList::okImDoneWithTheJSONNow(std::__cxx11::string *oldJSON)
{
    delete oldJSON;
}
