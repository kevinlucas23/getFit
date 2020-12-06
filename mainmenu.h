#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "dailyexercise.h"
#include "foodintake.h"
#include "graphsuggest.h"
#include "updateweight.h"
#include "weightlifting.h"
#include "sleep.h"
#include "inputoutput.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    QString currentUser;
    double bench;
    double row;
    double squat;
    double dead;
    double press;
    int weight;
    int cals;
    int sleepTime;
    int carbs;
    int proteins;
    int fruits_veg;
    int dairy;
    UpdateWeight *uw;
    DailyExercise *de;
    FoodIntake *fi;
    Weightlifting *w;
    class Sleep *s;
    QMap<int, double> max_map;

private slots:
    void dailyExercise();
    void foodIntake();
    void updateWeight();
    void weightlifting();
    void sleep();
    void graphSuggest();
    void setWeight(int w);
    void setSleep(int sl);
    void setDailyExercise(int e);
    void setFoodIntake(int c, int p, int fv, int d);
    void setWeightLifting(int rbench, int wbench, int rsquat, int wsquat, int rrow, int wrow, int rpress, int wpress, int rdead, int wdead);
    void noData();
};

#endif // MAINMENU_H

