#ifndef RPE_H
#define RPE_H

#include <QMainWindow>

namespace Ui {
class Rpe;
}

class Rpe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rpe(QWidget *parent = nullptr);
    ~Rpe();
    void setCurrentUser(QString user);

private:
    Ui::Rpe *ui;
    QString currentUser;
private slots:
    void back();
};

#endif // RPE_H
