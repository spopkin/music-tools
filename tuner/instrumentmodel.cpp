//Models an instrument and its properties

#include "instrumentmodel.h"
#include <vector>
#include <cstdlib>
#include <cstring>
#include <tgmath.h>

//Define constant baseline notes
//used to compute a note for a given frequency
#define a1 55.00
#define b1 61.74
#define c1 32.70
#define d1 36.71
#define e1 41.20
#define f1 43.65
#define g1 49.00
//used to provide half-steps for sharp/flat notes at octave edges
//#define b0 = 30.87;
//#define c2 = 65.41;

//Struct to model a single instrument string
//Can probably also be used with non-string instruments, but this is
//supposed to be a guitar tuner anyway.
struct instrumentString
{
    char *stringName;
    //char *note;   //this can probably just be computed on the fly
    double frequency;
};

//Holds the set of string structs
std::vector<instrumentString *> *stringSet;

//The name of the current instrument
char *instrumentName;


InstrumentModel::InstrumentModel()
{
    stringSet = new std::vector<instrumentString *>();
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

    while(stringSet->size() > 0) {
        deleteStringByNumber(0);
    }
    delete stringSet;
}

//returns the number of strings in this instrument model
int InstrumentModel::getNumberOfStrings()
{
    return stringSet->size();
}

//returns the name of a given string
char *InstrumentModel::getStringName(int stringNumber)
{
    if (stringNumber >= stringSet->size() || stringNumber < 0) {
        return 0;
    }
    return stringSet->at(stringNumber)->stringName;
}

//returns the zero-indexed numeric position of a given string
int InstrumentModel::getStringNumber(char *stringName)
{
    for (int i = 0; i < stringSet->size(); i++) {
        char *c = stringSet->at(i)->stringName;
        if (strlen(c) == strlen(stringName) && !strncmp(stringName, c, strlen(c))) {
            return i;
        }
    }
    return -1;
}

//returns the correct frequency in Hz of a given string
double InstrumentModel::getStringFrequency(char *stringName)
{
    int stringNo = getStringNumber(stringName);
    if (stringNo == -1) {
        return -1.0;
    }
    return stringSet->at(stringNo)->frequency;
}

//returns the note of a given string
char InstrumentModel::getStringNote(char *stringName)
{
    //basically, just use mod math to find the one with
    //the smallest remainder.
    char note = 0;
    double minDiff = 10000000000000;
    double current = getStringFrequency(stringName);

    double aNoteDiff = fmod(current, a1);
    double bNoteDiff = fmod(current, b1);
    double cNoteDiff = fmod(current, c1);
    double dNoteDiff = fmod(current, d1);
    double eNoteDiff = fmod(current, e1);
    double fNoteDiff = fmod(current, f1);
    double gNoteDiff = fmod(current, g1);

    if (aNoteDiff < minDiff) {
        minDiff = aNoteDiff;
        note = 'a';
    }
    if (bNoteDiff < minDiff) {
        minDiff = bNoteDiff;
        note = 'b';
    }
    if (cNoteDiff < minDiff) {
        minDiff = cNoteDiff;
        note = 'c';
    }
    if (dNoteDiff < minDiff) {
        minDiff = dNoteDiff;
        note = 'd';
    }
    if (eNoteDiff < minDiff) {
        minDiff = eNoteDiff;
        note = 'e';
    }
    if (fNoteDiff < minDiff) {
        minDiff = fNoteDiff;
        note = 'f';
    }
    if (gNoteDiff < minDiff) {
        minDiff = gNoteDiff;
        note = 'g';
    }

    return note;
}

//deletes the first string found with the matching string name
int InstrumentModel::deleteStringByName(char *stringName)
{
    return deleteStringByNumber(getStringNumber(stringName));
}

//deletes the string in the given vector position
int InstrumentModel::deleteStringByNumber(int stringNumber)
{
    if (stringNumber >= stringSet->size() || stringNumber < 0) {
        return -1;
    }
    instrumentString *strn = stringSet->at(stringNumber);
    free(strn->stringName);
    free(strn);
    stringSet->erase(stringSet->begin() + stringNumber);
    return 0;
}

//adds a new string
int InstrumentModel::addString(char *stringName, float frequency)
{
    //first, check if the name is not taken
    //int number = getStringNumber(stringName);

    //if so, then fail
    //if (number != -1) {
    //    return -1;
    //}
    //otherwise, create the string and add it to the array

    //create the string
    instrumentString *newString = (instrumentString *) malloc(sizeof(instrumentString));

    //duplicate the string name to the heap so it won't go out of scope
    int len = strlen(stringName) + 1;
    char *duplicate = (char *) malloc(len * sizeof(char));
    strcpy(duplicate, stringName);

    //assign the name and frequency to the new string
    newString->frequency = frequency;
    newString->stringName = duplicate;

    //add the string to the set
    stringSet->push_back(newString);

    return 0;
}

//moves a string to a different position.  Meant for use if the
//user created the strings out of order.
int InstrumentModel::reorderString(char *stringName, int newPosition)
{
    int currentStringNo = getStringNumber(stringName);
    if (currentStringNo < 0 || currentStringNo >= stringSet->size()
            || newPosition < 0 || newPosition >= stringSet-> size()) {
        return -1;
    }
    instrumentString *instStr = stringSet->at(currentStringNo);
    stringSet->erase(stringSet->begin() + currentStringNo);
    stringSet->insert(stringSet->begin() + newPosition, instStr);

    return 0;
}
