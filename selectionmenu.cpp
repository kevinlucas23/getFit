#include "selectionmenu.h"
#include "ui_selectionmenu.h"
#include "sleeplog.h"
#include "foodlog.h"
#include "activitylog.h"

selectionmenu::selectionmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectionmenu)
{
    ui->setupUi(this);
    QObject::connect(ui->food,SIGNAL(clicked()),this,SLOT(foodPushed()));
    QObject::connect(ui->sleep,SIGNAL(clicked()),this,SLOT(sleepPushed()));
    QObject::connect(ui->activity,SIGNAL(clicked()),this,SLOT(activityPushed()));
}

void selectionmenu::activityPushed(){
    this->hide();
    ActivityLog al;
    al.setModal(true);
    al.exec();
}

void selectionmenu::sleepPushed(){
    this->hide();
    SleepLog sl;
    sl.setModal(true);
    sl.exec();
}

void selectionmenu::foodPushed(){
    this->hide();
    FoodLog fl;
    fl.setModal(true);
    fl.exec();
}

selectionmenu::~selectionmenu()
{
    delete ui;
}
