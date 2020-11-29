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
    ~ShowGraphs();

private:
    Ui::ShowGraphs *ui;
    QString currentUser;
};

#endif // SHOWGRAPHS_H

