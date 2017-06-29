#include "instrumentmodel.h"
#include <vector>

struct instrumentString
{
    char *stringName;
    char note;
    int frequency;
};

std::vector<instrumentString> *stringSet;
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
