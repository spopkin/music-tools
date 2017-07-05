//Models an instrument and its properties

#include "instrumentmodel.h"
#include <vector>


//Struct to model a single instrument string
//Can probably also be used with non-string instruments, but this is
//supposed to be a guitar tuner anyway.
struct instrumentString
{
    char *stringName;
    //char *note;   //this can probably just be computed on the fly
    int frequency;
};

//Holds the set of string structs
std::vector<instrumentString> *stringSet;

//The name of the current instrument
char *instrumentName;


InstrumentModel::InstrumentModel()
{
    stringSet = new std::vector<instrumentString>();
}

InstrumentModel::~InstrumentModel()
{
    //go through and free all instrumentStrings in the set,
    //then delete the vector itself.
}

//returns the number of strings in this instrument model
int InstrumentModel::getNumberOfStrings()
{
    return 0;
}

//returns the name of a given string
char *InstrumentModel::getStringName(int stringNumber)
{
    return "";
}

//returns the correct frequency in Hz of a given string
int InstrumentModel::getStringFrequency(int stringNumber)
{
    return 0;
}

//returns the note of a given string
char *InstrumentModel::getStringNote(int stringNumber)
{
    return "";
}
