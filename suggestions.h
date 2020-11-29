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
    void setCurrentUser(QString user);
    ~Suggestions();

private:
    Ui::Suggestions *ui;
    QString currentUser;
};

#endif // SUGGESTIONS_H

