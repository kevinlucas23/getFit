#include "sleep.h"
#include "ui_sleep.h"

Sleep::Sleep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sleep)
{
    ui->setupUi(this);
    this->setWindowTitle("Sleep");
}

Sleep::~Sleep()
{
    delete ui;
}

void Sleep::on_pushButton_clicked()
{
    emit(end(ui->sleep->value()));
}
