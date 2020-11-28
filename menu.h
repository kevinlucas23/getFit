#ifndef MENU_H
#define MENU_H

#include "inputoutput.h"
#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog, public inputOutput
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    inputOutput getInOut();
    void setCurrentUser(QString user);
    ~Menu();

public slots:
    void setNewData();

private:
    Ui::Menu *ui;
    inputOutput inout;
    QString currentUser;
};

#endif // MENU_H

