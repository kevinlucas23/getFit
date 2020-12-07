#ifndef LIFTPROGRAM_H
#define LIFTPROGRAM_H

#include <QMainWindow>

namespace Ui {
class LiftProgram;
}

class LiftProgram : public QMainWindow
{
    Q_OBJECT

public:
    explicit LiftProgram(QWidget *parent = nullptr);
    ~LiftProgram();

private:
    Ui::LiftProgram *ui;

private slots:
    void rpe();
};

#endif // LIFTPROGRAM_H
