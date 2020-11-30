#include "showgraphs.h"
#include "ui_showgraphs.h"

ShowGraphs::ShowGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowGraphs)
{
    ui->setupUi(this);
    plot();
}

ShowGraphs::~ShowGraphs()
{
    delete ui;
}

void ShowGraphs::setCurrentUser(QString user){
    currentUser = user;
}

void ShowGraphs::plot()
{
//     user, QMap<QString, int> map, QString what);
    getallgraph(currentUser, map, "cals");
    plotWeight();
    plotCals();
    plotExercise();
    plotSleep();
}

void ShowGraphs::plotWeight(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    for(int i = 0; i < 10; i++){
        *series << QPointF(i, 0.5*i);
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Weight");
    axisY->setRange(0,5);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0,9);
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
    for(int i = 0; i < 10; i++){
        *series << QPointF(i, 0.5*i);
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Sleep");
    axisY->setRange(0,5);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0,9);
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
    for(int i = 0; i < 10; i++){
        *series << QPointF(i, 0.5*i);
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Calories Burned");
    axisY->setRange(0,5);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0,9);
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
    for(int i = 0; i < 10; i++){
        *series << QPointF(i, 0.5*i);
    }

    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Calories Consumed");
    axisY->setRange(0,5);
    c->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0,9);
    c->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    c->legend()->setVisible(true);
    c->legend()->setAlignment(Qt::AlignBottom);
    ui->caloriePlot->setChart(c);
    ui->caloriePlot->setRenderHint(QPainter::Antialiasing);
    ui->caloriePlot->update();
}
