//Models an instrument and its properties

#include "instrumentmodel.h"
#include <vector>
#include <cstdlib>

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

    //for instrumentString in stringSet:
        //instrumentString = stringSet[i]
        //free instrumentString
    //delete stringSet
    //done
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

int InstrumentModel::getStringNumber(char *stringName)
{
    return 0;
}

//returns the correct frequency in Hz of a given string
int InstrumentModel::getStringFrequency(char *stringName)
{
    return 0;
}

//returns the note of a given string
char *InstrumentModel::getStringNote(char *stringName)
{
    return "";
}

//deletes the first string found with the matching string name
int InstrumentModel::deleteStringByName(char *stringName)
{
    return 0;
}

//deletes the string in the given vector position
int InstrumentModel::deleteStringByNumber(int stringNumber)
{
    return 0;
}

//adds a new string
int addString(char *stringName, int frequency)
{
    //first, check if the name is not taken
    int number = getStringNumber(stringName);

    //if so, then fail
    if (number != -1) {
        return -1;
    }

    //otherwise, create the string and add it to the array
    instrumentString *newString = (instrumentString *) malloc(sizeof(instrumentString));
    newString->frequency = frequency;



    return 0;
}

//moves a string to a different position.  Meant for use if the
//user created the strings out of order.
int reorderString(char *stringName, int newPosition)
{
    return 0;
}
