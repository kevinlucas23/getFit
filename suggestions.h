#ifndef SUGGESTIONS_H
#define SUGGESTIONS_H

#include <QMainWindow>
#include "inputoutput.h"

namespace Ui {
class Suggestions;
}

class Suggestions : public QMainWindow, public inputOutput
{
    Q_OBJECT

public:
    explicit Suggestions(QWidget *parent = nullptr);
    void setCurrentUser(QString user);
    ~Suggestions();

private:
    Ui::Suggestions *ui;
    QString currentUser;
private slots:
    void liftPage();
    void sleepPage();
};

#endif // SUGGESTIONS_H

