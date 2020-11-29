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

void FoodIntake::on_pushButton_clicked()
{
    emit(end(ui->carbs->value(), ui->proteins->value(), ui->fruits_veg->value(), ui->dairy->value()));
}
