//A simple class to handle IO operations and populate lists of
//instrument models

#include "iohandler.h"
#include <fstream>
#include <iostream>
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


    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, jsonTree.get_child("instList"))
    {
        std::cout << "instrument name: " << v.second.get<std::string>("instName") << std::endl;

        BOOST_FOREACH(boost::property_tree::ptree::value_type &w, v.second.get_child("strings"))
        {
            std::cout << "\t" << w.second.get<std::string>("stringName") << ": ";
            std::cout << w.second.get<std::string>("stringFreq") << std::endl;
        }
    }

    readFile.close();
    return 0;
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

