#include "sleeplog.h"
#include "ui_sleeplog.h"
#include "selectionmenu.h"

SleepLog::SleepLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SleepLog)
{
    ui->setupUi(this);
    QObject::connect(ui->back,SIGNAL(clicked()),this,SLOT(back()));
}

void SleepLog::back(){
    this->hide();
    selectionmenu sm;
    sm.setModal(true);
    sm.exec();
}

SleepLog::~SleepLog()
{
    delete ui;
}
