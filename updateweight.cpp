#include "updateweight.h"
#include "ui_updateweight.h"

UpdateWeight::UpdateWeight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWeight)
{
    ui->setupUi(this);
}

UpdateWeight::~UpdateWeight()
{
    delete ui;
}
