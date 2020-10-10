#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap bkgnd("pic3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background, bkgnd);
    this->setPalette(pal);
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
    if(ui->age->text().toInt() <= 3 || ui->height->text().toDouble() <= 0 || ui->weight->text().toDouble() <= 40){
        QMessageBox::information(this, "Error", "wrong inputs entered");
        return;
    }
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
