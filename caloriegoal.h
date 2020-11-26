#ifndef CALORIEGOAL_H
#define CALORIEGOAL_H

#include <QDialog>

namespace Ui {
class CalorieGoal;
}

class CalorieGoal : public QDialog
{
    Q_OBJECT

public:
    explicit CalorieGoal(QWidget *parent = nullptr);
    ~CalorieGoal();

private:
    Ui::CalorieGoal *ui;
};

#endif // CALORIEGOAL_H
