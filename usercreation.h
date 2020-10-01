#ifndef USERCREATION_H
#define USERCREATION_H

#include <QDialog>
#include "inputoutput.h"

namespace Ui {
class userCreation;
}

class userCreation : public QDialog, public inputOutput
{
    Q_OBJECT

public:
    explicit userCreation(QWidget *parent = nullptr);
    ~userCreation();

private slots:
    void on_push_createa_clicked();

    void on_passw_radio_clicked();

private:
    Ui::userCreation *ui;
};

#endif // USERCREATION_H
