#include "getfit.h"
#include "ui_getfit.h"

getFit::getFit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::getFit)
{
    ui->setupUi(this);
    ui->label_3->setText("Welcome...");
    setStyleSheet( "background-image:url(pic.jpg);" ); //this works
}

getFit::~getFit()
{
    delete ui;
}


void getFit::on_push_signin_clicked()
{
    QString username = ui->user_sign->text();
    QString password = ui->passw_sign->text();
    read_users();
    if(!check_user(username, password)){
        QMessageBox::information(this, "Login","wrong Password or Username");
        return;
    }
    QMessageBox::information(this, "Login","Correct");
    return;
}

void getFit::on_pushcreate_sign_clicked()
{
    this->hide();
    userCreation userc;
    userc.setModal(true);
    userc.exec();
}

void getFit::on_button_s_clicked()
{
    if(ui->passw_sign->echoMode() == QLineEdit::Normal){
        ui->passw_sign->setEchoMode(QLineEdit::Password);
        return;
    }
    ui->passw_sign->setEchoMode(QLineEdit::Normal);
    return;
}
