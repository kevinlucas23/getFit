#ifndef LIFTTIPS_H
#define LIFTTIPS_H

#include <QMainWindow>

namespace Ui {
class LiftTips;
}

class LiftTips : public QMainWindow
{
    Q_OBJECT

public:
    explicit LiftTips(QWidget *parent = nullptr,QString user = "");
    ~LiftTips();

private:
    Ui::LiftTips *ui;
    QString currentUser;
private slots:
    void foodPage();
    void sleepPage();
};

#endif // LIFTTIPS_H
