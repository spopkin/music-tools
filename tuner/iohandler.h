#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "instrumentlist.h"
#include <string>
#include <boost/property_tree/ptree.hpp>

class IOHandler
{
public:
    IOHandler();
    ~IOHandler();
    InstrumentList *readInstrumentsListFromDisk(std::string filename);
    int writeInstrumentsListToDisk(InstrumentList *instruments, std::string sfilename);

    std::string *serializeToJSON(InstrumentList *instSet);
    InstrumentList *deserializeFromJSON(boost::property_tree::ptree *jsonTree);
};

#endif // IOHANDLER_H
