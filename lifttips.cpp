#include "lifttips.h"
#include "ui_lifttips.h"
#include "sleeptips.h"
#include "suggestions.h"

LiftTips::LiftTips(QWidget *parent,QString user) :
    QMainWindow(parent),
    ui(new Ui::LiftTips)
{
    ui->setupUi(this);
    currentUser = user;
    QPixmap pic1("../getFit/bench.png");
    int w = ui->bench->width();
    int h = ui->bench->height();
    ui->bench->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pic2("../getFit/squat.png");
    w = ui->squat->width();
    h = ui->squat->height();
    ui->squat->setPixmap(pic2.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pic3("../getFit/deadlift.png");
    w = ui->deadlift->width();
    h = ui->deadlift->height();
    ui->deadlift->setPixmap(pic3.scaled(w,h,Qt::KeepAspectRatio));

    //hyperlinks
    ui->closeGrip->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->closeGrip->setOpenExternalLinks(true);
    ui->closeGrip->setTextFormat(Qt::RichText);
    ui->closeGrip->setText("<a href=\"https://www.youtube.com/watch?v=nEF0bv2FW94\"> Close Grip Bench </a>");
    ui->pausedBench->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->pausedBench->setOpenExternalLinks(true);
    ui->pausedBench->setTextFormat(Qt::RichText);
    ui->pausedBench->setText("<a href=\"https://www.youtube.com/watch?v=dVM-rN5cd4E4\"> Paused Bench </a>");

    ui->gm->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->gm->setOpenExternalLinks(true);
    ui->gm->setTextFormat(Qt::RichText);
    ui->gm->setText("<a href=\"https://www.youtube.com/watch?v=vKPGe8zb2S4\"> Good Mornings </a>");

    ui->pausedSquat->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->pausedSquat->setOpenExternalLinks(true);
    ui->pausedSquat->setTextFormat(Qt::RichText);
    ui->pausedSquat->setText("<a href=\"https://www.youtube.com/watch?v=HV711kwdeQw\"> Paused Squats </a>");

    ui->rdl->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->rdl->setOpenExternalLinks(true);
    ui->rdl->setTextFormat(Qt::RichText);
    ui->rdl->setText("<a href=\"https://www.youtube.com/watch?v=JCXUYuzwNrM\"> Romainian Deadlifts </a>");

    ui->deficit->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->deficit->setOpenExternalLinks(true);
    ui->deficit->setTextFormat(Qt::RichText);
    ui->deficit->setText("<a href=\"https://www.youtube.com/watch?v=CpWsUsqBtN8\"> Deficit Deadlifts </a>");


}

LiftTips::~LiftTips()
{
    delete ui;
}

void LiftTips::foodPage(){
    this->hide();
    Suggestions *s = new Suggestions();
    s->setCurrentUser(currentUser);
    s->show();
}

void LiftTips::sleepPage(){
    this->hide();
    SleepTips* st = new SleepTips(nullptr,currentUser);
    st->show();
}
