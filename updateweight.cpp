#include "updateweight.h"
#include "ui_updateweight.h"

UpdateWeight::UpdateWeight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWeight)
{
    ui->setupUi(this);
    ui->currentWeight->setRange(50, 500);
}

UpdateWeight::~UpdateWeight()
{
    delete ui;
}
