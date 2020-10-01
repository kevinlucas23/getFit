#include "usercreation.h"
#include "ui_usercreation.h"

userCreation::userCreation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userCreation)
{
    ui->setupUi(this);
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
                read_users();
                if(!create_user(us)){
                    QLabel* lab = ui->label_6;
                    lab->setStyleSheet("QLabel { background-color : red; color : blue; }");
                    lab->setText("username already exist, try something else");
                    return;
                }

                QMessageBox::information(this, "Create", "Created successfully");
                return;
            }
            QLabel* lab = ui->label_6;
            lab->setStyleSheet("QLabel { background-color : red; color : blue; }");
            lab->setText("password size is less than 6 characters");
            return;
        }
        QMessageBox::information(this, "Create", "the two passwords doesn't match");
        return;
    }

    QLabel* lab = ui->label_6;
    lab->setStyleSheet("QLabel { background-color : red; color : blue; }");
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
