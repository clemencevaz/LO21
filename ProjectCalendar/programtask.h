#ifndef PROGRAMTASK_H
#define PROGRAMTASK_H

#include <QDialog>

namespace Ui {
class programTask;
}

class programTask : public QDialog
{
    Q_OBJECT

public:
    explicit programTask(QWidget *parent = 0);
    ~programTask();

private slots:
    void on_saveTaskProg_clicked();

private:
    Ui::programTask *ui;
};

#endif // PROGRAMTASK_H
