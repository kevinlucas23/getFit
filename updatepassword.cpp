#include "updatepassword.h"
#include "ui_updatepassword.h"

UpdatePassword::UpdatePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatePassword)
{
    ui->setupUi(this);
}

UpdatePassword::~UpdatePassword()
{
    delete ui;
}

void UpdatePassword::setCurrentUser(QString user)
{
    userC = user;
    ui->label_3->setText("Welcome " + user + "!");
}

void UpdatePassword::on_radioButton_clicked()
{
    if(ui->pass1->echoMode() == QLineEdit::Normal){
        ui->pass1->setEchoMode(QLineEdit::Password);
        ui->pass2->setEchoMode(QLineEdit::Password);
        return;
    }
    ui->pass1->setEchoMode(QLineEdit::Normal);
    ui->pass2->setEchoMode(QLineEdit::Normal);
    return;
}

void UpdatePassword::on_pushButton_clicked()
{
    if(ui->pass1->text() == ui->pass2->text()){
        update_pass(userC, ui->pass1->text());
        this->hide();
        //Menu menu;
        MainMenu* mainMenu = new MainMenu();
        //menu.setUserString(ui->user_sign->text());
        //menu.setModal(true);
        mainMenu->setCurrentUser(userC);
        mainMenu->show();
        //menu.exec();
        return;
    }
    QMessageBox::critical(this, "Warning", "those passwords doesn't match");
}
