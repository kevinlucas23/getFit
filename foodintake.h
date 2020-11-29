#ifndef FOODINTAKE_H
#define FOODINTAKE_H

#include <QDialog>

namespace Ui {
class FoodIntake;
}

class FoodIntake : public QDialog
{
    Q_OBJECT

public:
    explicit FoodIntake(QWidget *parent = nullptr);
    ~FoodIntake();

private:
    Ui::FoodIntake *ui;

signals:
    void end(int, int, int, int);
private slots:
    void on_pushButton_clicked();
};

#endif // FOODINTAKE_H


