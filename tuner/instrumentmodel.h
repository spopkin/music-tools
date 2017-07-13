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

    std::string *getStringName(int stringNumber);
    int getStringNumber(std::string stringName);

    double getStringFrequency(std::string stringName);
    char getStringNote(std::string stringName);

    int deleteStringByName(std::string stringName);
    int deleteStringByNumber(int stringNumber);

    int addString(std::string stringName, double frequency);

    int reorderString(std::string stringName, int newPosition);

    void setInstrumentName(std::string newName);
    std::string *getInstrumentName();

private:
    void deleteNameIfAlloc();

    //The name of the current instrument
    std::string *instrumentName;

    //Struct to model a single instrument string
    //Can probably also be used with non-string instruments, but this is
    //supposed to be a guitar tuner anyway.
    struct instrumentString
    {
        std::string *stringName;
//        char *stringName;
        double frequency;
    };

    std::vector<instrumentString *> *stringSet;

};

#endif // INSTRUMENTMODEL_H
