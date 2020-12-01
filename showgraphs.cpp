#include "showgraphs.h"
#include "ui_showgraphs.h"

ShowGraphs::ShowGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowGraphs)
{
    ui->setupUi(this);
}

ShowGraphs::~ShowGraphs()
{
    delete ui;
}

void ShowGraphs::setCurrentUser(QString user){
    currentUser = user;
    plot();
}

void ShowGraphs::plot()
{
//     user, QMap<QString, int> map, QString what);
    getallgraph(currentUser, &map, &food_map, "cals");
    plotExercise();
    map.clear();
    getallgraph(currentUser, &map, &food_map, "weight");
    plotWeight();
    map.clear();
    getallgraph(currentUser, &map, &food_map, "sleep");
    plotSleep();
    map.clear();
    getallgraph(currentUser, &map, &food_map, "food");
    plotCals();
    food_map.clear();

}

void ShowGraphs::plotWeight(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("lbs");
    QMap<QString, int>::iterator it;

    int x = 0;
    int max = 0;
    for (it = map.begin(); it != map.end(); it++ ){
        *series << QPointF(x, it.value());
        if(it.value() > max){
            max = it.value();
        }
        x++;
    }
    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Weight(lb)");
    axisY->setRange(0, max + 20);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0, map.size() - 1);
    c->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    c->legend()->setVisible(true);
    c->legend()->setAlignment(Qt::AlignBottom);
    ui->weightPlot->setChart(c);
    ui->weightPlot->setRenderHint(QPainter::Antialiasing);
    ui->weightPlot->update();
}

void ShowGraphs::plotSleep(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("hours");
    QMap<QString, int>::iterator it;

    int x = 0;
    int max = 0;
    for (it = map.begin(); it != map.end(); it++ ){
        *series << QPointF(x, it.value());
        if(it.value() > max){
            max = it.value();
        }
        x++;
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Sleep(hrs)");
    axisY->setRange(0,24);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0, map.size() - 1);
    c->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    c->legend()->setVisible(true);
    c->legend()->setAlignment(Qt::AlignBottom);
    ui->sleepPlot->setChart(c);
    ui->sleepPlot->setRenderHint(QPainter::Antialiasing);
    ui->sleepPlot->update();
}

void ShowGraphs::plotExercise(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Calories");
    QMap<QString, int>::iterator it;

    int x = 0;
    int max = 0;
    for (it = map.begin(); it != map.end(); it++ ){
        *series << QPointF(x, it.value());
        if(it.value() > max){
            max = it.value();
        }
        x++;
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Calories Burned");
    axisY->setRange(0, max + 20);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0, map.size() - 1);
    c->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    c->legend()->setVisible(true);
    c->legend()->setAlignment(Qt::AlignBottom);
    ui->exercisePlot->setChart(c);
    ui->exercisePlot->setRenderHint(QPainter::Antialiasing);
    ui->exercisePlot->update();
}

void ShowGraphs::plotCals(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Calories");
    QMap<QString, int>::iterator it;

    int x = 0;
    int max = 0;
    for (it = map.begin(); it != map.end(); it++ ){
        *series << QPointF(x, it.value());
        if(it.value() > max){
            max = it.value();
        }
        x++;
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Calories Consumed");
    axisY->setRange(0, max + 20);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0, map.size() - 1);
    c->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    c->legend()->setVisible(true);
    c->legend()->setAlignment(Qt::AlignBottom);
    ui->caloriePlot->setChart(c);
    ui->caloriePlot->setRenderHint(QPainter::Antialiasing);
    ui->caloriePlot->update();
}
