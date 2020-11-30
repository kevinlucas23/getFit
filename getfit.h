#ifndef GETFIT_H
#define GETFIT_H

#include <QMainWindow>

// files included
#include "inputoutput.h"
#include "usercreation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class getFit; }
QT_END_NAMESPACE

class getFit : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    getFit(QWidget *parent = nullptr);
    ~getFit();

private slots:
    void on_push_signin_clicked();

    void on_pushcreate_sign_clicked();

    void on_button_s_clicked();

    void on_passw_sign_returnPressed();

private:
    Ui::getFit *ui;
};
#endif // GETFIT_H
