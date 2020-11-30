#include "suggestions.h"
#include "ui_suggestions.h"

Suggestions::Suggestions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Suggestions)
{
    ui->setupUi(this);
    if(inputOutput::isGL(currentUser)){
        ui->title->setText("Weight Gain Food Suggestions");
    }
    else{
        ui->title->setText("Weight Loss Food Suggestions");
    }

    QPixmap theScale("../getFit/scale.png");
    int w = ui->scalePic->width();
    int h = ui->scalePic->height();
    ui->scalePic->setPixmap(theScale.scaled(w,h,Qt::KeepAspectRatio));

}

Suggestions::~Suggestions()
{
    delete ui;
}

void Suggestions::setCurrentUser(QString user){
    currentUser = user;
}
