//A simple class to handle IO operations and populate lists of
//instrument models

#include "iohandler.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

IOHandler::IOHandler()
{

}

IOHandler::~IOHandler()
{

}

//Reads, decodes, and returns a list from a given file by name
InstrumentList *IOHandler::readInstrumentsListFromDisk(std::string filename)
{
    std::fstream readFile;
    readFile.open(filename);

    //use boost to read the json
    boost::property_tree::ptree jsonTree;
    boost::property_tree::read_json(readFile, jsonTree);
    readFile.close();

    return deserializeFromJSON(&jsonTree);
//    return 0;
}

//Encodes and writes a list to a given file by name
int IOHandler::writeInstrumentsListToDisk(InstrumentList *instruments, std::string filename)
{
    std::fstream writeFile;
    writeFile.open(filename);

    //do writes and processing here

    writeFile.close();

    return 0;
}

//creates a sendable, storable json string.
std::string *IOHandler::serializeToJSON(InstrumentList *instSet)
{
    //basically, just keep using string concatination
    //format:
    //{
    //  "instList": [
    //      {
    //          "instName": "$instName",
    //          "strings": [
    //              {
    //                  "stringName": "$strName",
    //                  "stringFreq": $strFreq
    //              },...
    //          ]
    //      },...
    //  ]
    //}

    std::string direct = "";

    direct += "{\n";
    direct += "\t\"instList\": [\n";

    for (int i = 0; i < instSet->getNumInstruments(); i++) {
        std::string *name = instSet->getInstrumentByNumber(i)->getInstrumentName();

        //open instrument dictionary
        direct += "\t\t{\n";

        //set instrument name
        direct += "\t\t\t\"instName\": \"" + *name + "\",\n";

        //open strings array
        direct += "\t\t\t\"strings\": [\n";

        //foreach string, get string json
        for (int j = 0; j < instSet->getInstrumentByNumber(i)->getNumberOfStrings(); j++) {
            direct += "\t\t\t\t{\n";
            std::string stringName = *(instSet->getInstrumentByNumber(i)->getStringName(j));
            double stringFreq = instSet->getInstrumentByNumber(i)->getStringFrequency(stringName);

            std::string freqString = std::to_string(stringFreq);
            direct += "\t\t\t\t\t\"stringName\": \"" + stringName + "\",\n";
            direct += "\t\t\t\t\t\"stringFreq\": " + freqString + "\n";
            direct += "\t\t\t\t}";


            //fencepost the current string dictionary
            if (j < instSet->getInstrumentByNumber(i)->getNumberOfStrings() - 1) {
                direct += ",";
            }
            direct += "\n";
        }


        //close strings array
        direct += "\t\t\t]\n";

        //close current instrument dictionary
        direct += "\t\t}";

        //if this isn't the last instrument, append a comma
        if (i < instSet->getNumInstruments() - 1) {
            direct += ",";
        }

        //end the current instrument dictionary line, whether it
        //is or isn't the last one
        direct += "\n";

    }

    direct += "\t]\n";
    direct += "}";


    std::string *jsonRep = new std::string(direct);

    return jsonRep;
}

//creates an InstrumentList from a json string
InstrumentList *IOHandler::deserializeFromJSON(boost::property_tree::ptree *jsonTree)
{
    InstrumentList *instList = new InstrumentList();
    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, jsonTree->get_child("instList"))
    {
        InstrumentModel *instModel = new InstrumentModel();
        std::cout << "instrument name: " << v.second.get<std::string>("instName") << std::endl;
        instModel->setInstrumentName(v.second.get<std::string>("instName"));

        BOOST_FOREACH(boost::property_tree::ptree::value_type &w, v.second.get_child("strings"))
        {
            std::cout << "\t" << w.second.get<std::string>("stringName") << ": ";
            std::cout << w.second.get<std::string>("stringFreq") << std::endl;
            instModel->addString(w.second.get<std::string>("stringName"), w.second.get<double>("stringFreq"));
        }

        instList->addInstrument(instModel);
    }

    return instList;
}
