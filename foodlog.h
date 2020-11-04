#ifndef FOODLOG_H
#define FOODLOG_H

#include <QDialog>

namespace Ui {
class FoodLog;
}

class FoodLog : public QDialog
{
    Q_OBJECT

public:
    explicit FoodLog(QWidget *parent = nullptr);
    ~FoodLog();
private slots:
    void back();

private:
    Ui::FoodLog *ui;
};

#endif // FOODLOG_H
