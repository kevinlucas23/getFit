#include "weightlifting.h"
#include "ui_weightlifting.h"

Weightlifting::Weightlifting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weightlifting)
{
    ui->setupUi(this);
    this->setWindowTitle("Weightlifting");
    ui->reps->setRange(1,12);
    ui->weight->setRange(5,5000);
}

Weightlifting::~Weightlifting()
{
    delete ui;
}

void Weightlifting::on_pushButton_clicked()
{
    emit(end(ui->ex->currentText(), ui->reps->value(), ui->weight->value()));
}
