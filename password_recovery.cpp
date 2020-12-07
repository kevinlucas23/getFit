#include "password_recovery.h"
#include "ui_password_recovery.h"

Password_recovery::Password_recovery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password_recovery)
{
    ui->setupUi(this);
}

Password_recovery::~Password_recovery()
{
    delete ui;
}

void Password_recovery::setQ(QString temp)
{
    if(temp != "")
        ui->question_l->setText(temp);
}

void Password_recovery::on_pushButton_clicked()
{
    auto temp = user_recovery(ui->username_l->text(),ui->question_l->text(), ui->ans->text());
    if(temp.first){
        this->hide();
        UpdatePassword userc;
        userc.setCurrentUser(ui->username_l->text());
        userc.setModal(true);
        userc.exec();
    }
    else{
        if(temp.second == "wrong user")
            QMessageBox::critical(this, "Warning", "wrong User");
        else if(temp.second == "wrong question")
            QMessageBox::critical(this, "Warning", "Wrong Question link to User");
        else if(temp.second == "wrong ans")
            QMessageBox::critical(this, "Warning", "Wrong Answer to Question");
        else
            QMessageBox::critical(this, "Warning", "None of those matches our record");
    }
}
