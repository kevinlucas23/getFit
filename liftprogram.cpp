#include "liftprogram.h"
#include "ui_liftprogram.h"
#include "rpe.h"

LiftProgram::LiftProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LiftProgram)
{
    ui->setupUi(this);
    QPixmap pic1("../getFit/tsa.png");
    int w = ui->logo->width();
    int h = ui->logo->height();
    ui->logo->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
}

LiftProgram::~LiftProgram()
{
    delete ui;
}

void LiftProgram::rpe(){
    this->hide();
    Rpe *r = new Rpe();
    r->show();
}
