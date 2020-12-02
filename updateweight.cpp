#include "updateweight.h"
#include "ui_updateweight.h"

UpdateWeight::UpdateWeight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWeight)
{
    ui->setupUi(this);
    ui->currentWeight->setRange(50, 500);
    this->setWindowTitle("Update Weight");
}

UpdateWeight::~UpdateWeight()
{
    delete ui;
}

void UpdateWeight::on_pushButton_clicked()
{
    emit(end(ui->currentWeight->value()));
}
