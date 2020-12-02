#include "usercreation.h"
#include "ui_usercreation.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

userCreation::userCreation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userCreation)
{
    ui->setupUi(this);
    ui->weightbox->setRange(50, 500);
    this->setWindowTitle("Create User");
    /*
    QPixmap bkgnd("../getFit/pic2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background, bkgnd);
    this->setWindowTitle("getFit");
    this->setPalette(pal);
    QPalette readOnlyPalette;
    readOnlyPalette.setColor(QPalette::Base, Qt::transparent);
    readOnlyPalette.setColor(QPalette::Text,Qt::white);
    ui->uname_create->setPalette(readOnlyPalette);
    ui->passw1_create->setPalette(readOnlyPalette);
    ui->passw2_create->setPalette(readOnlyPalette);
    ui->email_create->setPalette(readOnlyPalette);
    QPalette ko;
    ko.setColor(QPalette::WindowText,Qt::white);
    ui->label->setPalette(ko);
    ui->label_2->setPalette(ko);
    ui->label_3->setPalette(ko);
    ui->label_4->setPalette(ko);
    ui->label_5->setPalette(ko);
    ui->label_6->setPalette(ko);
    ui->passw_radio->setPalette(ko);
    QPalette kok;
    kok.setColor(QPalette::WindowText,Qt::darkGray);
    ui->groupBox->setPalette(kok);
    */
}

userCreation::~userCreation()
{
    delete ui;
}

void userCreation::on_push_createa_clicked()
{
    if(!ui->uname_create->text().isEmpty() && !ui->email_create->text().isEmpty() && !ui->passw1_create->text().isEmpty() && !ui->passw2_create->text().isEmpty()){
        if(ui->passw1_create->text() == ui->passw2_create->text()){
            QString pass1 = ui->passw1_create->text();
            if(pass1.size() > 5){
                Data us;
                us.email = ui->email_create->text();
                us.password = pass1;
                us.username = ui->uname_create->text();
                us.age = ui->agebox->text().toInt();
                us.weight = ui->weightbox->text().toInt();
                us.height = ui->heightbox->text().toInt();
                us.sex = ui->sexbox->currentText();
                QString temp = ui->comboBox->currentText();
                us.gain_lose = (temp == "Gain Weight") ? true : false;
                if(!ui->email_create->text().contains("@")){
                    QLabel* lab = ui->label_6;
                    lab->setStyleSheet("QLabel { background-color : transparent; color : blue; }");
                    lab->setText("wrong email format");
                    return;
                }
                read_users();
                if(!create_user(us)){
                    QLabel* lab = ui->label_6;
                    lab->setStyleSheet("QLabel { background-color : transparent; color : blue; }");
                    lab->setText("username already exist, try something else");
                    return;
                }

                // QMessageBox::information(this, "Create", "Created successfully");
                this->hide();
                MainMenu* mainMenu = new MainMenu();
                mainMenu->setCurrentUser(ui->uname_create->text());
                mainMenu->show();
                //Menu menu;
                //menu.setUserString(ui->uname_create->text());
                //menu.setModal(true);
                //menu.exec();
                return;
            }

            QLabel* lab = ui->label_6;
            lab->setStyleSheet("QLabel { background-color : transparent; color : blue; }");
            lab->setText("password size is less than 6 characters");
            return;
        }
        QMessageBox::information(this, "Create", "the two passwords doesn't match");
        return;
    }

    QLabel* lab = ui->label_6;
    lab->setStyleSheet("QLabel { background-color : transparent; color : blue; }");
    lab->setText("some boxes above are empty");
    return;
}

void userCreation::on_passw_radio_clicked()
{
    if(ui->passw1_create->echoMode() == QLineEdit::Normal){
        ui->passw1_create->setEchoMode(QLineEdit::Password);
        ui->passw2_create->setEchoMode(QLineEdit::Password);
        return;
    }
    ui->passw1_create->setEchoMode(QLineEdit::Normal);
    ui->passw2_create->setEchoMode(QLineEdit::Normal);
    return;
}
