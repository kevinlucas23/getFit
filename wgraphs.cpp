#include "wgraphs.h"
#include "ui_wgraphs.h"

WGraphs::WGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WGraphs)
{
    // https://strengthlevel.com/one-rep-max-calculator
    ui->setupUi(this);
    this->setWindowTitle("Graphs");
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
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
}

WGraphs::~WGraphs()
{
    delete ui;
}

void WGraphs::setCurrentUser(QString user){
    currentUser = user;
    plot();
}

void WGraphs::plot()
{
    // user, QMap<QString, int> map, QString what);
    // "lifting": {"ex": ex, "reps": reps, "w": w},
    QMap<QString, QVector<int>> m;
    getallgraph(currentUser, &map, &m, "bench");
    plotBench();
    map.clear();
    getallgraph(currentUser, &map, &m, "row");
    plotRow();
    map.clear();
    getallgraph(currentUser, &map, &m, "squat");
    plotSquat();
    map.clear();
    getallgraph(currentUser, &map, &m, "dead");
    plotDeadlift();
    map.clear();
    getallgraph(currentUser, &map, &m, "press");
    plotPress();
    map.clear();
}

void WGraphs::plotSquat(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Squat");
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
    axisY->setTitleText("1 rep max (lbs)");
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
    ui->squat->setChart(c);
    ui->squat->setRenderHint(QPainter::Antialiasing);
    ui->squat->update();
}

void WGraphs::plotDeadlift(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Deadlift");
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
    axisY->setTitleText("1 rep max (lbs)");
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
    ui->dead->setChart(c);
    ui->dead->setRenderHint(QPainter::Antialiasing);
    ui->dead->update();
}

void WGraphs::plotPress(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Overhead Press");
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
    axisY->setTitleText("1 rep max (lbs)");
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
    ui->opress->setChart(c);
    ui->opress->setRenderHint(QPainter::Antialiasing);
    ui->opress->update();
}

void WGraphs::plotBench(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Bench Press");
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
    axisY->setTitleText("1 rep max (lbs)");
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
    ui->bench->setChart(c);
    ui->bench->setRenderHint(QPainter::Antialiasing);
    ui->bench->update();
}

void WGraphs::plotRow(){
    QChart *c = new QChart();
    QLineSeries *series = new QLineSeries();
    series->setName("Barbell Row");
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
    axisY->setTitleText("1 rep max (lbs)");
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
    ui->row->setChart(c);
    ui->row->setRenderHint(QPainter::Antialiasing);
    ui->row->update();
}
