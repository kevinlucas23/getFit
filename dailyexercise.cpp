#include "dailyexercise.h"
#include "ui_dailyexercise.h"

DailyExercise::DailyExercise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailyExercise)
{
    ui->setupUi(this);
}

DailyExercise::~DailyExercise()
{
    delete ui;
}
