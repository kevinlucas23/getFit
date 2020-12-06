#ifndef WGRAPHS_H
#define WGRAPHS_H

#include <QMainWindow>
#include <QtCharts>
#include "inputoutput.h"

namespace Ui {
class WGraphs;
}

class WGraphs : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    explicit WGraphs(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    void plot();
    void plotBench();
    void plotRow();
    void plotSquat();
    void plotDeadlift();
    void plotPress();
    ~WGraphs();

private:
    Ui::WGraphs *ui;
    QString currentUser;
    QMap<QString, QVector<int>> weight_map;
    QMap<int, double> max_map;
};

#endif // WGRAPHS_H
