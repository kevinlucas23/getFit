#ifndef GRAPHSUGGEST_H
#define GRAPHSUGGEST_H

#include <QMainWindow>

#include "showgraphs.h"
#include "suggestions.h"

namespace Ui {
class GraphSuggest;
}

class GraphSuggest : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphSuggest(QWidget *parent = nullptr);
    ~GraphSuggest();

private slots:
    void showGraphs();
    void suggestions();

private:
    Ui::GraphSuggest *ui;
};

#endif // GRAPHSUGGEST_H