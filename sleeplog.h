#ifndef SLEEPLOG_H
#define SLEEPLOG_H

#include <QDialog>

namespace Ui {
class SleepLog;
}

class SleepLog : public QDialog
{
    Q_OBJECT

public:
    explicit SleepLog(QWidget *parent = nullptr);
    ~SleepLog();
private slots:
    void back();

private:
    Ui::SleepLog *ui;
};

#endif // SLEEPLOG_H
