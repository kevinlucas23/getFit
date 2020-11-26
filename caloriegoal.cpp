#include "caloriegoal.h"
#include "ui_caloriegoal.h"

CalorieGoal::CalorieGoal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalorieGoal)
{
    ui->setupUi(this);
}

CalorieGoal::~CalorieGoal()
{
    delete ui;
}
