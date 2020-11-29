#ifndef SLEEP_H
#define SLEEP_H

#include <QDialog>

namespace Ui {
class Sleep;
}

class Sleep : public QDialog
{
    Q_OBJECT

public:
    explicit Sleep(QWidget *parent = nullptr);
    ~Sleep();

private:
    Ui::Sleep *ui;

signals:
    void end(int);
private slots:
    void on_pushButton_clicked();
};

#endif // SLEEP_H
