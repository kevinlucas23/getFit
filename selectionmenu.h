#ifndef SELECTIONMENU_H
#define SELECTIONMENU_H

#include <QDialog>

namespace Ui {
class selectionmenu;
}

class selectionmenu : public QDialog
{
    Q_OBJECT

public:
    explicit selectionmenu(QWidget *parent = nullptr);
    ~selectionmenu();
private slots:
    void foodPushed();
    void sleepPushed();
    void activityPushed();


private:
    Ui::selectionmenu *ui;
};

#endif // SELECTIONMENU_H
