#include "foodintake.h"
#include "ui_foodintake.h"

FoodIntake::FoodIntake(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodIntake)
{
    ui->setupUi(this);
}

FoodIntake::~FoodIntake()
{
    delete ui;
}
