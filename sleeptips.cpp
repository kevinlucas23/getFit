#include "sleeptips.h"
#include "ui_sleeptips.h"
#include "suggestions.h"
#include "lifttips.h"

SleepTips::SleepTips(QWidget *parent,QString user) :
    QMainWindow(parent),
    ui(new Ui::SleepTips)
{
    ui->setupUi(this);
    currentUser = user;
    QPixmap pic1("../getFit/sleep.png");
    int w = ui->sleepPic->width();
    int h = ui->sleepPic->height();
    ui->sleepPic->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pic2("../getFit/sleep2.png");
    w = ui->sleepPic2->width();
    h = ui->sleepPic2->height();
    ui->sleepPic2->setPixmap(pic2.scaled(w,h,Qt::KeepAspectRatio));
    this->setWindowTitle("Sleep Tips");
}

SleepTips::~SleepTips()
{
    delete ui;
}

void SleepTips::foodPage(){
    this->hide();
    Suggestions *s = new Suggestions();
    s->setCurrentUser(currentUser);
    s->show();
}

void SleepTips::liftPage(){
    this->hide();
    LiftTips* lt = new LiftTips(nullptr,currentUser);
    lt->show();
}
