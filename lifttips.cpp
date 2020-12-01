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
