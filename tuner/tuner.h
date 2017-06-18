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

private slots:

//    void on_comboBox_3_activated(const QString &arg1);

private:
    Ui::Tuner *ui;
    QAction *actionAbout;
};

#endif // TUNER_H
