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
    int getStringFrequency(int stringNumber);
    char *getStringNote(int stringNumber);
};

#endif // INSTRUMENTMODEL_H
