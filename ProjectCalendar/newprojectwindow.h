#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H

#include <QDialog>

namespace Ui {
class NewProjectWindow;
}

class NewProjectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectWindow(QWidget *parent = 0);
    ~NewProjectWindow();
//poulet
private slots:
    void on_saveNewProjButton_clicked();

private:
    Ui::NewProjectWindow *ui;
};

#endif // NEWPROJECTWINDOW_H
