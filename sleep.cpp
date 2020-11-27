#include "sleep.h"
#include "ui_sleep.h"

Sleep::Sleep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sleep)
{
    ui->setupUi(this);
}

Sleep::~Sleep()
{
    delete ui;
}
