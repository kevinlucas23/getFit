#include "getfit.h"
#include "mainmenu.h"
#include "ui_getfit.h"
#include "ui_mainmenu.h"

getFit::getFit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::getFit)
{
    ui->setupUi(this);
    ui->label_3->setText("Welcome...");
    /*
    QPixmap bkgnd("../getFit/pic1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background, bkgnd);
    this->setPalette(pal);
    QPalette readOnlyPalette = ui->user_sign->palette();
    readOnlyPalette.setColor(QPalette::Base, Qt::transparent);
    readOnlyPalette.setColor(QPalette::Text,Qt::white);
    ui->user_sign->setPalette(readOnlyPalette);
    ui->passw_sign->setPalette(readOnlyPalette);

    QPalette ko;
    ko.setColor(QPalette::WindowText,Qt::white);
    ui->label->setPalette(ko);
    ui->label_2->setPalette(ko);
    ui->label_3->setPalette(ko);
    ui->button_s->setPalette(ko);
    ui->groupBox->setPalette(ko);
    */
//    setStyleSheet( "background-image:url(pic.jpg);" ); //this works
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
    // QMessageBox::information(this, "Login","Correct");
    this->hide();
    //Menu menu;
    MainMenu* mainMenu = new MainMenu();
    //menu.setUserString(ui->user_sign->text());
    //menu.setModal(true);
    mainMenu->setCurrentUser(ui->user_sign->text());
    mainMenu->show();
    //menu.exec();
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

void getFit::on_passw_sign_returnPressed()
{
    on_push_signin_clicked();
}
