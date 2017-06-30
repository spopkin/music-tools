//Models an instrument and its properties

#include "instrumentmodel.h"
#include <vector>


//Struct to model a single instrument string
//Can probably also be used with non-string instruments, but this is
//supposed to be a guitar tuner anyway.
struct instrumentString
{
    char *stringName;
    char note;
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
