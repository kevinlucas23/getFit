#include "showgraphs.h"
#include "ui_showgraphs.h"

ShowGraphs::ShowGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowGraphs)
{
    ui->setupUi(this);
    this->setWindowTitle("Graphs");
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
    int min = 500;
    for (it = map.begin(); it != map.end(); it++ ){
        *series << QPointF(x, it.value());
        if(it.value() > max){
            max = it.value();
        }
        if(it.value() < min){
            min = it.value();
        }
        x++;
    }
    if(min == 500){
        min = 0;
    }
    c->addSeries(series);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Weight(lb)");
    axisY->setRange(min, max);
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
    QLineSeries *seriesC = new QLineSeries();
    QLineSeries *seriesD = new QLineSeries();
    QLineSeries *seriesFV = new QLineSeries();
    QLineSeries *seriesP = new QLineSeries();
    seriesC->setName("carbs");
    seriesD->setName("dairy");
    seriesFV->setName("fruits & vegetables");
    seriesP->setName("proteins");
    QMap<QString, QVector<int>>::iterator it;

    int x = 0;
    int max = 0;
    for (it = food_map.begin(); it != food_map.end(); it++ ){
        *seriesC << QPointF(x, it.value()[0]);
        *seriesD << QPointF(x, it.value()[1]);
        *seriesFV << QPointF(x, it.value()[2]);
        *seriesP << QPointF(x, it.value()[3]);
        if(it.value()[0] > max){
            max = it.value()[0];
        }
        if(it.value()[1] > max){
            max = it.value()[0];
        }
        if(it.value()[2] > max){
            max = it.value()[0];
        }
        if(it.value()[3] > max){
            max = it.value()[0];
        }
        x++;
    }

    c->addSeries(seriesC);
    c->addSeries(seriesD);
    c->addSeries(seriesFV);
    c->addSeries(seriesP);
    c->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Calories Consumed");
    axisY->setRange(0, max + 20);
    c->addAxis(axisY, Qt::AlignLeft);
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time");
    axisX->setRange(0, map.size() - 1);
    c->addAxis(axisX, Qt::AlignBottom);

    seriesC->attachAxis(axisX);
    seriesC->attachAxis(axisY);
    seriesD->attachAxis(axisX);
    seriesD->attachAxis(axisY);
    seriesFV->attachAxis(axisX);
    seriesFV->attachAxis(axisY);
    seriesP->attachAxis(axisX);
    seriesP->attachAxis(axisY);

    c->legend()->setVisible(true);
    c->legend()->setAlignment(Qt::AlignBottom);
    ui->caloriePlot->setChart(c);
    ui->caloriePlot->setRenderHint(QPainter::Antialiasing);
    ui->caloriePlot->update();
}
