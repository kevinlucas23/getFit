#ifndef MENU_H
#define MENU_H

#include "inputoutput.h"
#include <QDialog>
#include "selectionmenu.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog, public inputOutput
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    inputOutput getInOut();
    ~Menu();

public slots:
    void setUserString(QString userStr);
    void setNewData();

private:
    Ui::Menu *ui;
    inputOutput inout;
    QString userStr;
};

#endif // MENU_H
