#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include <iostream>
#include <QtDebug>
#include <QFileInfo>
#include <QJsonArray>
#include <QMap>
#include <QDateTime>
#include <QDate>

struct Data{
    QString email;
    QString sex;
    qreal weight;
    qreal height;
    qreal number;
    QString question;
    QString ans;
    qint32 age;
    QString username;
    QString password;
    bool gain_lose;
    qint32 squatMax = 0;
    qint32 benchMax = 0;
    qint32 deadliftMax = 0;
    Data(){
        weight = 0;
        height = 0;
        age = 0;
    }
    QString getemail(){
        return email;
    }
    QString getsex(){
        return sex;
    }
    qreal getweight(){
        return weight;
    }
    qreal getheight(){
        return height;
    }
    qint32 getage(){
        return age;
    }
    QString getuname(){
        return username;
    }
    QString getpasswd(){
        return password;
    }
    bool getgain(){
        return gain_lose;
    }
    QString getQuestion(){
        return question;
    }
    qreal getnumber(){
        return number;
    }
    QString getAns(){
        return ans;
    }
    qint32 getSquat(){
        return squatMax;
    }
    qint32 getBench(){
        return benchMax;
    }
    qint32 getDeadlift(){
        return deadliftMax;
    }
};

class inputOutput
{
public:
    inputOutput();
    bool create_user(Data k);
    void read_users();
    void addData(QString user, QDate, int, int, int, int, int, int, int, double bench, double row, double squat, double dead, double press);
    void addBench(QString user, QDate date, int reps, int weight);
    Data getData();
    void updateFile(QJsonObject Book);
    void getallgraph(QString user, QMap<QString, int>* op, QMap<QString, QVector<int>>* po, QString what);
    bool isGL(QString user);
    bool check_user(QString kev, QString pass);
    QJsonObject getBook();
    std::pair<bool, QString> user_recovery(QString user, QString question, QString ans);
    void update_pass(QString kev, QString pass);
    void getQ(QString kev, QString* temp);
    void updateMaxes(QString user,qint32 squat, qint32 bench, qint32 deadlift);
    int getBenchMax(QString user);
    int getSquatMax(QString user);
    int getDeadliftMax(QString user);


protected:
    QJsonObject book;
    Data user;
};

#endif // INPUTOUTPUT_H

