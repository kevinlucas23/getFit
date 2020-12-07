#ifndef PASSWORD_RECOVERY_H
#define PASSWORD_RECOVERY_H

#include <QDialog>
#include <QMessageBox>
#include "mainmenu.h"
#include "inputoutput.h"
#include "updatepassword.h"

namespace Ui {
class Password_recovery;
}

class Password_recovery : public QDialog, public inputOutput
{
    Q_OBJECT

public:
    explicit Password_recovery(QWidget *parent = nullptr);
    ~Password_recovery();
    void setQ(QString temp);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Password_recovery *ui;
};

#endif // PASSWORD_RECOVERY_H
