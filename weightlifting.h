#ifndef WEIGHTLIFTING_H
#define WEIGHTLIFTING_H

#include <QDialog>
#include "inputoutput.h"

namespace Ui {
class Weightlifting;
}

class Weightlifting : public QDialog
{
    Q_OBJECT

public:
    explicit Weightlifting(QWidget *parent = nullptr);
    ~Weightlifting();

private slots:
    void on_pushButton_clicked();

signals:
    void end(QString, int, int);

private:
    Ui::Weightlifting *ui;
};

#endif // WEIGHTLIFTING_H
