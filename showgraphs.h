#ifndef SHOWGRAPHS_H
#define SHOWGRAPHS_H

#include <QMainWindow>

namespace Ui {
class ShowGraphs;
}

class ShowGraphs : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowGraphs(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    ~ShowGraphs();

private:
    Ui::ShowGraphs *ui;
    QString currentUser;
};

#endif // SHOWGRAPHS_H

