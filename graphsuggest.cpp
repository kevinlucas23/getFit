#include "graphsuggest.h"
#include "ui_graphsuggest.h"
#include "mainmenu.h"

GraphSuggest::GraphSuggest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphSuggest)
{
    ui->setupUi(this);
    //QObject::connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(back()));
}

void GraphSuggest::back(){
    this->hide();
    MainMenu* mainMenu = new MainMenu();
    mainMenu->setCurrentUser(currentUser);
    mainMenu->show();
}
GraphSuggest::~GraphSuggest()
{
    delete ui;
}

void GraphSuggest::setCurrentUser(QString user){
    currentUser = user;
}

void GraphSuggest::showGraphs(){
    ShowGraphs *sg = new ShowGraphs();
    sg->show();
    sg->setCurrentUser(currentUser);
    qDebug() << currentUser;
}

void GraphSuggest::suggestions(){
    Suggestions *s = new Suggestions();
    s->show();
    s->setCurrentUser(currentUser);
}
