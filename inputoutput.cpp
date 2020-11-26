#include "inputoutput.h"

inputOutput::inputOutput()
{

}

Data inputOutput::getData(){
    return user;
}

bool inputOutput::setData(Data k)
{
    auto obj =  book.value(k.getuname()).toObject();
    obj["Age"] = k.getage();
    obj["Height"] = k.getheight();
    obj["Sex"] = k.getsex();
    obj["Weight"] = k.getweight();
    book[k.getuname()] = obj;

    QJsonDocument content;
    content.setObject(book);
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
    return true;
}

bool inputOutput::create_user(Data k)
{
    if(book.contains(k.getuname())){
        return false;
    }
    QJsonObject all;
    all.insert("Email", k.getemail());
    all.insert("Age", k.getage());
    all.insert("Height", k.getheight());
    all.insert("Sex", k.getsex());
    all.insert("Phone Number", k.getphone());
    all.insert("Weight", k.getweight());
    all.insert("Password", k.getpasswd());
    book[k.getuname()] = all;
    QJsonDocument content;
    content.setObject(book);
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
