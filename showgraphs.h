#ifndef SHOWGRAPHS_H
#define SHOWGRAPHS_H

#include <QMainWindow>
#include <QtCharts>
#include "inputoutput.h"

namespace Ui {
class ShowGraphs;
}

class ShowGraphs : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    explicit ShowGraphs(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    void plot();
    void plotWeight();
    void plotSleep();
    void plotExercise();
    void plotCals();
    ~ShowGraphs();

private:
    Ui::ShowGraphs *ui;
    QString currentUser;
    QMap<QString, int> map;
    QMap<QString, QVector<int>> food_map;
};

#endif // SHOWGRAPHS_H

