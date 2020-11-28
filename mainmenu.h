#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

#include "caloriegoal.h"
#include "dailyexercise.h"
#include "foodintake.h"
#include "graphsuggest.h"
#include "updateweight.h"
#include "weightlifting.h"
#include "sleep.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    QString currentUser;

private slots:
    void calorieGoal();
    void dailyExercise();
    void foodIntake();
    void updateWeight();
    void weightlifting();
    void sleep();
    void graphSuggest();
};

#endif // MAINMENU_H

