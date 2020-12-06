#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    uw = new UpdateWeight();
    de = new DailyExercise();
    s = new class Sleep();
    fi = new FoodIntake();
    w = new Weightlifting();
    auto date = QDate::currentDate();
    max_map[1] = 1;
    max_map[2] = 1/0.97;
    max_map[3] = 1/0.94;
    max_map[4] = 1/0.92;
    max_map[5] = 1/0.89;
    max_map[6] = 1/0.86;
    max_map[7] = 1/0.83;
    max_map[8] = 1/0.81;
    max_map[9] = 1/0.78;
    max_map[10] = 1/0.75;
    max_map[11] = 1/0.73;
    max_map[12] = 1/0.71;
    max_map[13] = 1/0.70;
    max_map[14] = 1/0.68;
    max_map[15] = 1/0.67;
    ui->dateEdit->setDate(date);
    this->setWindowTitle("Main Menu");
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
    // "Dates": {"11/28/20": {"weight": 171, "sleep": 8, "cals": 3000, "food": {"carbs": 900, "proteins": 400, "fv": 300, "dairy": 500}}}
    addData(currentUser, ui->dateEdit->date(), weight, cals, sleepTime, carbs, proteins, fruits_veg, dairy, bench, row, squat, dead, press);
    this->hide();
    GraphSuggest *sg = new GraphSuggest();
    sg->show();
    sg->setCurrentUser(currentUser);
}

void MainMenu::noData(){
    this->hide();
    GraphSuggest *sg = new GraphSuggest();
    sg->show();
    sg->setCurrentUser(currentUser);
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
    connect(w, SIGNAL(end(int, int, int, int, int, int, int, int, int, int)), this, SLOT(setWeightLifting(int, int, int, int, int, int, int, int, int, int)));
    w->show();
}

void MainMenu::setWeight(int w){
    weight = w;
    uw->hide();
    qDebug() << weight;
}

void MainMenu::setWeightLifting(int rbench, int wbench, int rsquat, int wsquat, int rrow, int wrow, int rpress, int wpress, int rdead, int wdead){
    bench = max_map[rbench] * wbench;
    row = max_map[rsquat] * wsquat;
    squat = max_map[rrow] * wrow;
    dead = max_map[rpress] * wpress;
    press = max_map[rdead] * wdead;
    w->hide();
}

void MainMenu::setDailyExercise(int e){
    if(e >= 0 && e < 10000){
        cals = e;
    }
    else{
        cals = 0;
    }
    de->hide();
    qDebug() << cals;
}

void MainMenu::setSleep(int sl){
    if(sl >= 0 && sl < 25){
        sleepTime = sl;
    }
    else{
        sleepTime = 0;
    }
    s->hide();
    qDebug() << sleepTime;
}

void MainMenu::setFoodIntake(int c, int p, int fv, int d){
    carbs = 0;
    proteins = 0;
    fruits_veg = 0;
    dairy = 0;
    if(c >= 0 && c < 10000){
        carbs = c;
    }
    if(p >= 0 && p < 10000){
        proteins = p;
    }
    if(fv >= 0 && fv < 10000){
        fruits_veg = fv;
    }
    if(d >= 0 && d < 10000){
        dairy = d;
    }
    qDebug() << c;
    qDebug() << p;
    qDebug() << fv;
    qDebug() << d;
    fi->hide();
}
