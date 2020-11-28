#include "graphsuggest.h"
#include "ui_graphsuggest.h"

GraphSuggest::GraphSuggest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphSuggest)
{
    ui->setupUi(this);
}

GraphSuggest::~GraphSuggest()
{
    delete ui;
}

void GraphSuggest::showGraphs(){
    ShowGraphs *sg = new ShowGraphs();
    sg->show();
}

void GraphSuggest::suggestions(){
    Suggestions *s = new Suggestions();
    s->show();
}
