#ifndef LIFTPROGRAM_H
#define LIFTPROGRAM_H

#include <QMainWindow>
#include "inputoutput.h"

namespace Ui {
class LiftProgram;
}

class LiftProgram : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    explicit LiftProgram(QWidget *parent = nullptr);
    ~LiftProgram();
    void setCurrentUser(QString user);
    void setWeights();
    int getWeek();

private:
    Ui::LiftProgram *ui;
    QString currentUser;

private slots:
    void rpe();
    void updateMaxes();
    void changeWeek();
};

#endif // LIFTPROGRAM_H
