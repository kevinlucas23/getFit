#include "rpe.h"
#include "ui_rpe.h"
#include "liftprogram.h"

Rpe::Rpe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rpe)
{
    ui->setupUi(this);
    QPixmap pic1("../getFit/rpe.png");
    int w = ui->rpePic->width();
    int h = ui->rpePic->height();
    ui->rpePic->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
}

Rpe::~Rpe()
{
    delete ui;
}

void Rpe::back(){
    this->hide();
    LiftProgram *lp = new LiftProgram();
    lp->show();
}
