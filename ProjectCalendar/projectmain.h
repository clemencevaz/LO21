#ifndef PROJECTMAIN_H
#define PROJECTMAIN_H
#include "QTreeWidgetItem"
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

    void on_taskProgram_clicked();

    void on_projTreeView_activated(const QModelIndex &index);

    void on_projTreeView_itemActivated(QTreeWidgetItem *item, int column);

    void on_taskProgram_2_clicked();

private:
    Ui::projectMain *ui;
};

#endif // PROJECTMAIN_H
