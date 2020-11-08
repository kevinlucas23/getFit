#ifndef SUGGESTIONS_H
#define SUGGESTIONS_H

#include <QMainWindow>

namespace Ui {
class Suggestions;
}

class Suggestions : public QMainWindow
{
    Q_OBJECT

public:
    explicit Suggestions(QWidget *parent = nullptr);
    ~Suggestions();

private:
    Ui::Suggestions *ui;
};

#endif // SUGGESTIONS_H
