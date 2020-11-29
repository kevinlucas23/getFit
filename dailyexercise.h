#ifndef DAILYEXERCISE_H
#define DAILYEXERCISE_H

#include <QDialog>

namespace Ui {
class DailyExercise;
}

class DailyExercise : public QDialog
{
    Q_OBJECT

public:
    explicit DailyExercise(QWidget *parent = nullptr);
    ~DailyExercise();

private slots:
    void on_pushButton_clicked();

signals:
    void end(int);

private:
    Ui::DailyExercise *ui;
};

#endif // DAILYEXERCISE_H
