#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H


class InstrumentModel
{
public:
    InstrumentModel();
    ~InstrumentModel();

    char *getInstrumentName();
    int getNumberOfStrings();

    char *getStringName(int stringNumber);
    int getStringNumber(char *stringName);

    int getStringFrequency(char *stringName);
    char *getStringNote(char *stringName);

    int deleteStringByName(char *stringName);
    int deleteStringByNumber(int stringNumber);

    int addString(char *stringName, int frequency);

    int reorderString(char *stringName, int newPosition);
};

#endif // INSTRUMENTMODEL_H
