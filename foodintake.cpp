#include "foodintake.h"
#include "ui_foodintake.h"

FoodIntake::FoodIntake(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodIntake)
{
    ui->setupUi(this);
    ui->carbs->setRange(0,5000);
    ui->proteins->setRange(0,5000);
    ui->dairy->setRange(0,5000);
    ui->fruits_veg->setRange(0,1000);

}

FoodIntake::~FoodIntake()
{
    delete ui;
}

void FoodIntake::on_pushButton_clicked()
{
    emit(end(ui->carbs->value(), ui->proteins->value(), ui->fruits_veg->value(), ui->dairy->value()));
}
