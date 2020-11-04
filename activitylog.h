#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <QDialog>

namespace Ui {
class ActivityLog;
}

class ActivityLog : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityLog(QWidget *parent = nullptr);
    ~ActivityLog();
private slots:
    void back();

private:
    Ui::ActivityLog *ui;
};

#endif // ACTIVITYLOG_H
