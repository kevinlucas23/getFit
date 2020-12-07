#include "weightlifting.h"
#include "ui_weightlifting.h"

Weightlifting::Weightlifting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weightlifting)
{
    ui->setupUi(this);
    this->setWindowTitle("Weightlifting");
    ui->rbench->setRange(0,12);
    ui->wbench->setRange(0,2000);
    ui->rsquat->setRange(0,12);
    ui->wsquat->setRange(0,2000);
    ui->rdead->setRange(0,12);
    ui->wdead->setRange(0,2000);
    ui->rrow->setRange(0,12);
    ui->wrow->setRange(0,2000);
    ui->rpress->setRange(0,12);
    ui->wpress->setRange(0,2000);
}

Weightlifting::~Weightlifting()
{
    delete ui;
}

void Weightlifting::on_pushButton_clicked()
{
    emit(end(ui->rbench->value(), ui->wbench->value(), ui->rsquat->value(), ui->wsquat->value(), ui->rrow->value(), ui->wrow->value(), ui->rpress->value(), ui->wpress->value(), ui->rdead->value(), ui->wdead->value()));
}
