#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H


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

    void setInstrumentName(char *newName);
    char *getInstrumentName();

private:
    void deleteNameIfAlloc();

    //The name of the current instrument
    char *instrumentName;
};

#endif // INSTRUMENTMODEL_H
