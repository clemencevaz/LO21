#ifndef PROJECTVIEWER_H
#define PROJECTVIEWER_H

#include <QDialog>

namespace Ui {
class ProjectViewer;
}

class ProjectViewer : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectViewer(QWidget *parent = 0);
    ~ProjectViewer();

private:
    Ui::ProjectViewer *ui;
};

#endif // PROJECTVIEWER_H
