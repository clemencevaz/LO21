#ifndef PROJECTMAIN_H
#define PROJECTMAIN_H

#include <QDialog>

namespace Ui {
class projectMain;
}

class projectMain : public QDialog
{
    Q_OBJECT

public:
    explicit projectMain(QWidget *parent = 0);
    ~projectMain();

private slots:
    void on_pushButton_clicked();

    void on_taskProgram_clicked();

private:
    Ui::projectMain *ui;
};

#endif // PROJECTMAIN_H
