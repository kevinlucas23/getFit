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
