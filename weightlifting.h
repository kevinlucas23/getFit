#ifndef WEIGHTLIFTING_H
#define WEIGHTLIFTING_H

#include <QDialog>

namespace Ui {
class Weightlifting;
}

class Weightlifting : public QDialog
{
    Q_OBJECT

public:
    explicit Weightlifting(QWidget *parent = nullptr);
    ~Weightlifting();

private:
    Ui::Weightlifting *ui;
};

#endif // WEIGHTLIFTING_H
