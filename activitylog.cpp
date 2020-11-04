#include "activitylog.h"
#include "ui_activitylog.h"
#include "selectionmenu.h"

ActivityLog::ActivityLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityLog)
{
    ui->setupUi(this);
    QObject::connect(ui->back,SIGNAL(clicked()),this,SLOT(back()));
}

void ActivityLog::back(){
    this->hide();
    selectionmenu sm;
    sm.setModal(true);
    sm.exec();

}

ActivityLog::~ActivityLog()
{
    delete ui;
}
