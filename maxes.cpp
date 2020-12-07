#include "maxes.h"
#include "ui_maxes.h"
#include "liftprogram.h"

Maxes::Maxes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Maxes)
{
    ui->setupUi(this);
}

Maxes::~Maxes()
{
    delete ui;
}

void Maxes::setCurrentUser(QString user){
    currentUser = user;
}

void Maxes::updateMaxes(){
    int squat = ui->squatMax->text().toInt();
    int bench = ui->benchMax->text().toInt();
    int deadlift = ui->deadliftMax->text().toInt();
    qDebug() <<"Passing new maxes";
    qDebug() << squat;
    qDebug() << bench;
    qDebug() << deadlift;
    inputOutput::updateMaxes(currentUser,squat,bench,deadlift);
}

void Maxes::back(){
    this->hide();
    LiftProgram *lp = new LiftProgram();
    lp->setCurrentUser(currentUser);
    lp->show();
}
