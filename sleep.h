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
};

#endif // SLEEP_H
