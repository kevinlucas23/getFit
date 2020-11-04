#include "foodlog.h"
#include "ui_foodlog.h"
#include "selectionmenu.h"

FoodLog::FoodLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodLog)
{
    ui->setupUi(this);
    QObject::connect(ui->back,SIGNAL(clicked()),this,SLOT(back()));
}

void FoodLog::back(){
    this->hide();
    selectionmenu sm;
    sm.setModal(true);
    sm.exec();
}

FoodLog::~FoodLog()
{
    delete ui;
}
