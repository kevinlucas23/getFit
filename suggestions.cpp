#include "suggestions.h"
#include "ui_suggestions.h"
#include "lifttips.h"
#include "sleeptips.h"

Suggestions::Suggestions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Suggestions)
{
    ui->setupUi(this);
    this->setWindowTitle("Suggestions");
}

void Suggestions::sleepPage(){
    this->hide();
    //Menu menu;
    SleepTips* st = new SleepTips();
    st->show();
}

void Suggestions::liftPage(){
    this->hide();
    LiftTips* lt = new LiftTips();
    lt->show();
}

Suggestions::~Suggestions()
{
    delete ui;
}

void Suggestions::setCurrentUser(QString user){
    currentUser = user;
    bool gain = inputOutput::isGL(currentUser);
    if(gain){
        ui->title->setText("Weight Gain Food Suggestions");
        ui->food1->setText("Milk: Provides a good balance of protein,carbs,and fat");
        ui->food2->setText("Rice: Great source of carbs that are easy to consume/digest");
        ui->food3->setText("Nuts/Nut Butter: High calorie snack with healthy fats");
        ui->food4->setText("Potatoes: A healthy starch that provides nutrients and fiber");
        ui->food5->setText("Salmon: A great source of healthy omega-3 fatty acids");
        QPixmap pic1("../getFit/milk.png");
        int w = ui->foodPic->width();
        int h = ui->foodPic->height();
        ui->foodPic->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic2("../getFit/rice.png");
        w = ui->foodPic_2->width();
        h = ui->foodPic_2->height();
        ui->foodPic_2->setPixmap(pic2.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic3("../getFit/nuts.png");
        w = ui->foodPic_3->width();
        h = ui->foodPic_3->height();
        ui->foodPic_3->setPixmap(pic3.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic4("../getFit/potatoes.png");
        w = ui->foodPic_4->width();
        h = ui->foodPic_4->height();
        ui->foodPic_4->setPixmap(pic4.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic5("../getFit/salmon.png");
        w = ui->foodPic_5->width();
        h = ui->foodPic_5->height();
        ui->foodPic_5->setPixmap(pic5.scaled(w,h,Qt::KeepAspectRatio));
    }
    else{
        ui->title->setText("Weight Loss Food Suggestions");
        ui->food1->setText("Leafy Greens: High in fiber and keeps you feeling full");
        ui->food2->setText("Chicken Breast: High in protein while low in fat");
        ui->food3->setText("Tuna: A lean fish that is a good source of protein");
        ui->food4->setText("Beans: Low calorie food that provide fiber and protein");
        ui->food5->setText("Greek Yogurt: A sweet snack provides calcium and protein");
        QPixmap pic1("../getFit/greens.png");
        int w = ui->foodPic->width();
        int h = ui->foodPic->height();
        ui->foodPic->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic2("../getFit/chicken.png");
        w = ui->foodPic_2->width();
        h = ui->foodPic_2->height();
        ui->foodPic_2->setPixmap(pic2.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic3("../getFit/tuna.png");
        w = ui->foodPic_3->width();
        h = ui->foodPic_3->height();
        ui->foodPic_3->setPixmap(pic3.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic4("../getFit/beans.png");
        w = ui->foodPic_4->width();
        h = ui->foodPic_4->height();
        ui->foodPic_4->setPixmap(pic4.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pic5("../getFit/yogurt.png");
        w = ui->foodPic_5->width();
        h = ui->foodPic_5->height();
        ui->foodPic_5->setPixmap(pic5.scaled(w,h,Qt::KeepAspectRatio));
    }
}
