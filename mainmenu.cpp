#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::setCurrentUser(QString user){
    currentUser = user;
    ui->welcomelabel->setText("Welcome " + user + "!");
}

void MainMenu::showGraphs(){
    ShowGraphs *sg = new ShowGraphs();
    sg->show();
}

void MainMenu::suggestions(){
    Suggestions *s = new Suggestions();
    s->show();
}

void MainMenu::calorieGoal(){
    CalorieGoal cg;
    cg.setModal(true);
    cg.exec();
}

void MainMenu::dailyExercise(){
    DailyExercise de;
    de.setModal(true);
    de.exec();
}

void MainMenu::foodIntake(){
    FoodIntake fi;
    fi.setModal(true);
    fi.exec();
}

void MainMenu::updateWeight(){
    UpdateWeight uw;
    uw.setModal(true);
    uw.exec();
}

void MainMenu::weightlifting(){
    Weightlifting w;
    w.setModal(true);
    w.exec();
}

void MainMenu::sleep(){
    Sleep s;
    s.setModal(true);
    s.exec();
}
