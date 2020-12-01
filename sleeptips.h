#ifndef SLEEPTIPS_H
#define SLEEPTIPS_H

#include <QMainWindow>

namespace Ui {
class SleepTips;
}

class SleepTips : public QMainWindow
{
    Q_OBJECT

public:
    explicit SleepTips(QWidget *parent = nullptr,QString user = "");
    ~SleepTips();

private:
    Ui::SleepTips *ui;
    QString currentUser;
private slots:
    void liftPage();
    void foodPage();

};

#endif // SLEEPTIPS_H
