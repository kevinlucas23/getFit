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


struct Data{
    QString email;
    QString sex;
    qreal weight;
    qreal height;
    qint32 age;
    qint32 phone_n;
    QString username;
    QString password;
    Data(){
        weight = 0;
        height = 0;
        age = 0;
        phone_n = 0;
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
    qint32 getphone(){
        return phone_n;
    }
    QString getuname(){
        return username;
    }
    QString getpasswd(){
        return password;
    }
};

class inputOutput
{
public:
    inputOutput();
    bool create_user(Data k);
    bool setData(Data k);
    void read_users();
    Data getData();
    bool check_user(QString kev, QString pass);
    QJsonObject getBook();

protected:
    QJsonObject book;
    Data user;
};

#endif // INPUTOUTPUT_H

