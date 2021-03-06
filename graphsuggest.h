#ifndef GRAPHSUGGEST_H
#define GRAPHSUGGEST_H

#include <QMainWindow>

#include "showgraphs.h"
#include "wgraphs.h"
#include "suggestions.h"

namespace Ui {
class GraphSuggest;
}

class GraphSuggest : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphSuggest(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    ~GraphSuggest();

private slots:
    void showGraphs();
    void suggestions();
    void back();
    void wgraphs();

private:
    Ui::GraphSuggest *ui;
    QString currentUser;
};

#endif // GRAPHSUGGEST_H
