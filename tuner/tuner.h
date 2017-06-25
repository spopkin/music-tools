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

public slots:
    void on_menu_about_activated();
    void on_menu_new_instrument();
    void on_menu_edit_instruments();

private slots:


private:
    Ui::Tuner *ui;
    QAction *actionAbout;
    QAction *actionEditInstruments;
    QAction *actionNewInstrument;
};

#endif // TUNER_H
