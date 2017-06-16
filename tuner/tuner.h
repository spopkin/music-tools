#ifndef TUNER_H
#define TUNER_H

#include <QMainWindow>

namespace Ui {
class Tuner;
}

class Tuner : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tuner(QWidget *parent = 0);
    ~Tuner();

private:
    Ui::Tuner *ui;
};

#endif // TUNER_H
