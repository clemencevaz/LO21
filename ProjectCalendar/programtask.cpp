#include "programtask.h"
#include "ui_programtask.h"

programTask::programTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::programTask)
{
    ui->setupUi(this);
}

programTask::~programTask()
{
    delete ui;
}

void programTask::on_saveTaskProg_clicked()
{

}
