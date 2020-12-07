#ifndef UPDATEWEIGHT_H
#define UPDATEWEIGHT_H

#include <QDialog>
#include <QMainWindow>

#include "inputoutput.h"

namespace Ui {
class UpdateWeight;
}

class UpdateWeight : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateWeight(QWidget *parent = nullptr);
    ~UpdateWeight();

private:
    Ui::UpdateWeight *ui;

signals:
    void end(int);

private slots:
    void on_pushButton_clicked();
};

#endif // UPDATEWEIGHT_H

