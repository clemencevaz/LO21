#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>

namespace Ui {
class NewProject;
}

class NewProject : public QDialog
{
    Q_OBJECT

public:
    explicit NewProject(QWidget *parent = 0);
    ~NewProject();

private slots:
    void on_saveNewProj_clicked();

private:
    Ui::NewProject *ui;
};

#endif // NEWPROJECT_H
