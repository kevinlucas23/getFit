#include "showgraphs.h"
#include "ui_showgraphs.h"

ShowGraphs::ShowGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowGraphs)
{
    ui->setupUi(this);
//    plot();
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
    getallgraph(currentUser);
    std::cout<< 7;
}
