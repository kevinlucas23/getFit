#include "weightlifting.h"
#include "ui_weightlifting.h"

Weightlifting::Weightlifting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weightlifting)
{
    ui->setupUi(this);
    this->setWindowTitle("Weightlifting");
}

Weightlifting::~Weightlifting()
{
    delete ui;
}
