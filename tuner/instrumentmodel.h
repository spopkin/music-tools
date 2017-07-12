#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H

#include <vector>
#include <string>

class InstrumentModel
{
public:
    InstrumentModel();
    ~InstrumentModel();

    int getNumberOfStrings();

    char *getStringName(int stringNumber);
    int getStringNumber(char *stringName);

    double getStringFrequency(char *stringName);
    char getStringNote(char *stringName);

    int deleteStringByName(char *stringName);
    int deleteStringByNumber(int stringNumber);

    int addString(char *stringName, float frequency);

    int reorderString(char *stringName, int newPosition);

//    void setInstrumentName(char *newName);
//    char *getInstrumentName();
    void setInstrumentName(std::string newName);
    std::string *getInstrumentName();

private:
    void deleteNameIfAlloc();

    //The name of the current instrument
//    char *instrumentName;
    std::string *instrumentName;

    //Struct to model a single instrument string
    //Can probably also be used with non-string instruments, but this is
    //supposed to be a guitar tuner anyway.
    struct instrumentString
    {
        char *stringName;
        //char *note;   //this can probably just be computed on the fly
        double frequency;
    };

    std::vector<instrumentString *> *stringSet;

};

#endif // INSTRUMENTMODEL_H
