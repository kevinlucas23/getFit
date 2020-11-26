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
    ~ShowGraphs();

private:
    Ui::ShowGraphs *ui;
};

#endif // SHOWGRAPHS_H

