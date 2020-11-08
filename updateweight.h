#ifndef UPDATEWEIGHT_H
#define UPDATEWEIGHT_H

#include <QDialog>

namespace Ui {
class UpdateWeight;
}

class UpdateWeight : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateWeight(QWidget *parent = nullptr);
    ~UpdateWeight();

private:
    Ui::UpdateWeight *ui;
};

#endif // UPDATEWEIGHT_H
