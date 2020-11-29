#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    uw = new UpdateWeight();
    de = new DailyExercise();
    s = new Sleep();
    fi = new FoodIntake();
    w = new Weightlifting();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::setCurrentUser(QString user){
    currentUser = user;
    ui->welcomelabel->setText("Welcome " + user + "!");
}

void MainMenu::graphSuggest(){
    // Format should be like this
    // "Dates": {"11/28/20": {"weight": 171, "sleep": 8, "cals": 3000, "food": {"carbs": 900, "proteins": 400, "fv": 300, "dairy": 500}}}
    addData(weight, cals, sleepTime, carbs, proteins, fruits_veg, dairy);
    this->hide();
    GraphSuggest *sg = new GraphSuggest();
    sg->show();
}

void MainMenu::dailyExercise(){
    connect(de, SIGNAL(end(int)), this, SLOT(setDailyExercise(int)));
    de->show();
}

void MainMenu::updateWeight(){
    connect(uw, SIGNAL(end(int)), this, SLOT(setWeight(int)));
    uw->show();
}

void MainMenu::sleep(){
    connect(s, SIGNAL(end(int)), this, SLOT(setSleep(int)));
    s->show();
}

void MainMenu::foodIntake(){
    connect(fi, SIGNAL(end(int, int, int, int)), this, SLOT(setFoodIntake(int, int, int, int)));
    fi->show();
}

void MainMenu::weightlifting(){
    connect(w, SIGNAL(end(int)), this, SLOT(setWeightLifting(int)));
    w->show();
}

void MainMenu::setWeight(int w){
    weight = w;
    uw->hide();
    qDebug() << weight;
}

void MainMenu::setDailyExercise(int e){
    cals = e;
    de->hide();
    qDebug() << cals;
}

void MainMenu::setSleep(int sl){
    sleepTime = sl;
    s->hide();
    qDebug() << sleepTime;
}

void MainMenu::setFoodIntake(int c, int p, int fv, int d){
    carbs = c;
    proteins = p;
    fruits_veg = fv;
    dairy = d;
    qDebug() << c;
    qDebug() << p;
    qDebug() << fv;
    qDebug() << d;
    fi->hide();
}
