#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();


public slots:
    void show_about_dialog();

private:
    void populateIcons();
    QWidget *parentWidget;
//    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
