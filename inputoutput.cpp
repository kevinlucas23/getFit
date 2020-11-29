#include "inputoutput.h"

#include <inputoutput.h>

inputOutput::inputOutput()
{

}

Data inputOutput::getData(){
    return user;
}

void inputOutput::updateFile(QJsonObject Book){
    QJsonDocument content;
    content.setObject(Book);
    QByteArray bytes = content.toJson(QJsonDocument::Indented);
    QFile file("./UAuth.json");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream istream(&file);
        istream.setCodec("utf-8");
        istream << bytes;
        file.close();
    }
    else{
        qDebug() <<"file open failed\n";
    }
}

void inputOutput::addData(QString user, QDate date, int weight, int cals, int sleep, int carbs, int proteins, int fv, int dairy){
    // "Dates": {"11/28/20": {"weight": weight, "sleep": sleep, "cals": cals, "food": {"carbs": carbs, "proteins": proteins, "fv": fv, "dairy": dairy}}}
    QJsonObject statsObject;
    statsObject.insert("weight", QJsonValue::fromVariant(weight));
    statsObject.insert("cals", QJsonValue::fromVariant(cals));
    statsObject.insert("sleep", QJsonValue::fromVariant(sleep));

    QJsonObject foodObject;
    foodObject.insert("carbs", carbs);
    foodObject.insert("proteins", proteins);
    foodObject.insert("fv", fv);
    foodObject.insert("dairy", dairy);
    statsObject.insert("food", foodObject);

//    QJsonObject dateObject;
    QString ds = QString::number(date.day()) + "/" + QString::number(date.month()) + "/" + QString::number(date.year());

    read_users();
    auto obj =  book.value(user).toObject();
    auto temp = obj.value("Dates").toObject();
    temp[ds] = statsObject;
    obj["Dates"] = temp;
    book[user] = obj;

    updateFile(book);
}

bool inputOutput::create_user(Data k)
{
    if(book.contains(k.getuname())){
        return false;
    }
    QJsonObject all, temp;
    all.insert("Email", k.getemail());
    all.insert("Age", k.getage());
    all.insert("Height", k.getheight());
    all.insert("Sex", k.getsex());
    all.insert("Weight", k.getweight());
    all.insert("Password", k.getpasswd());
    all.insert("G/L", (k.getgain()) ? "Gain" : "Lose");
    all["Dates"] = temp;
    book[k.getuname()] = all;

    updateFile(book);
    return true;
}

void inputOutput::read_users()
{
    QFile file("./UAuth.json");
    if(file.open(QIODevice::ReadOnly)){
        QByteArray bytes = file.readAll();
        file.close();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
        if(jsonError.error != QJsonParseError::NoError){
            qDebug()<<"From json fraille";
            return;
        }
        if(document.isObject()){
            book = document.object();
        }
    }
}

bool inputOutput::check_user(QString kev, QString pass)
{
    if(book.contains(kev)){
        auto obj =  book.value(kev).toObject();
        QStringList keys = obj.keys();
        for(auto key : keys){
            if (key == "Password"){
                auto value = obj.take(key);
                if(value.toString() == pass){
                    return true;
                }

            }
        }
    }
    return false;
}

QJsonObject inputOutput::getBook()
{
    return book;
}
