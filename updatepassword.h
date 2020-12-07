#ifndef UPDATEPASSWORD_H
#define UPDATEPASSWORD_H

#include <QDialog>
#include "mainmenu.h"
#include <QMessageBox>
#include "inputoutput.h"

namespace Ui {
class UpdatePassword;
}

class UpdatePassword : public QDialog, public inputOutput
{
    Q_OBJECT

public:
    explicit UpdatePassword(QWidget *parent = nullptr);
    ~UpdatePassword();
    void setCurrentUser(QString user);

private slots:
    void on_radioButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::UpdatePassword *ui;
    QString userC;
};

#endif // UPDATEPASSWORD_H
