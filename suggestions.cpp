#include "suggestions.h"
#include "ui_suggestions.h"

Suggestions::Suggestions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Suggestions)
{
    ui->setupUi(this);
}

Suggestions::~Suggestions()
{
    delete ui;
}
