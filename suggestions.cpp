#include "suggestions.h"
#include "ui_suggestions.h"

Suggestions::Suggestions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Suggestions)
{
    ui->setupUi(this);
    ui->title->setText("Weight Loss Food Tips");
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
