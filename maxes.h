#ifndef MAXES_H
#define MAXES_H

#include <QMainWindow>
#include "inputoutput.h"

namespace Ui {
class Maxes;
}

class Maxes : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    explicit Maxes(QWidget *parent = nullptr);
    ~Maxes();
    void setCurrentUser(QString user);

private:
    Ui::Maxes *ui;
    QString currentUser;
private slots:
    void updateMaxes();
    void back();
};

#endif // MAXES_H
