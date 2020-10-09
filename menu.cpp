#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

inputOutput Menu::getInOut(){
    return inout;
}

void Menu::setUserString(QString userStr){
    ui->welcome_label->setText("Welcome " + userStr + "!");
}

void Menu::setNewData(){
    Data data;
    data.age = ui->age->text().toInt();
    data.height = ui->height->text().toDouble();
    data.weight = ui->weight->text().toDouble();
    data.sex = ui->sex->currentText();
    auto name = ui->welcome_label->text().split(QLatin1Char(' '))[1].split(QLatin1Char('!'))[0];
    data.username = name;
    read_users();
    setData(data);
}
