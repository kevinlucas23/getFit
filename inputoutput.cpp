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

void inputOutput::getallgraph(QString user, QMap<QString, int>* op, QMap<QString, QVector<int>>* po, QString what)
{
//    user = "kevin";
    QMap<QString, int> map;
    QMap<QString, QVector<int>> map2;
    read_users();
    auto obj =  book.value(user).toObject();
    if(what == "weight"){
        auto b = obj.value("sign_in").toString();
        auto c = obj.value("Weight").toInt();
        map[b] = c;
    }

    auto temp = obj.value("Dates").toObject();
    QStringList keys = temp.keys();
    for(auto key : keys){
        auto data = temp.value(key).toObject();
        QStringList inside = data.keys();
        for(auto a : inside){
            if(a == what && a != "food"){
                auto value = data.value(a).toInt();
                map[key] = value;
                qDebug() << value;
            }
            if(a == what && a == "food"){
                auto k = data.value(a).toObject();
                QStringList l = k.keys();
                QVector<int> q;
                for(auto u : l){
                    auto t = k.value(u).toInt();
                    q.push_back(t);
                }
                map2[key] = q;
            }
        }
    }
    *op = map;
    *po = map2;
//    updateFile(book);
}

bool inputOutput::isGL(QString user)
{
    read_users();
    auto obj =  book.value(user).toObject();
    auto temp = obj["G/L"];
    //qDebug() << temp;

    return (temp == "Gain") ? true : false;
}

int inputOutput::getSquatMax(QString user){
    read_users();
    auto obj =  book.value(user).toObject();
    auto temp = obj["squatMax"];
    qDebug() << "Bench max is:";
    qDebug() << temp.toInt();
    return temp.toInt();
}

int inputOutput::getBenchMax(QString user){
    read_users();
    auto obj =  book.value(user).toObject();
    qDebug() << "Bench max is:";
    qDebug() << obj["benchMax"].toString();
    return obj["benchMax"].toInt();
}

int inputOutput::getDeadliftMax(QString user){
    read_users();
    auto obj =  book.value(user).toObject();
    qDebug() << "Deadlift max is:";
    qDebug() << obj["deadliftMax"].toString();
    return obj["deadliftMax"].toInt();
}

void inputOutput::updateMaxes(QString user,qint32 squat, qint32 bench, qint32 deadlift){
    read_users();
    auto obj = book.value(user).toObject();
    QJsonObject statsObject;
    qDebug() << "Adding new maxes to JSON\n";
    qDebug() << user;
    qDebug() << squat;
    qDebug() << bench;
    qDebug() << deadlift;
    if(squat != 0){
        obj["squatMax"] = squat;
    }
    if(bench != 0 ){
        obj["benchMax"] = bench;
    }
    if(deadlift != 0){
        obj["deadliftMax"] = deadlift;
    }
    book[user] = obj;
    updateFile(book);
}

void inputOutput::addData(QString user, QDate date, int weight, int cals, int sleep, int carbs, int proteins, int fv, int dairy, double bench, double row, double squat, double dead, double press){
    // "Dates": {"11/28/20": {"weight": weight, "sleep": sleep, "cals": cals, "lifting": {"ex": ex, "reps": reps, "w": w}, "food": {"carbs": carbs, "proteins": proteins, "fv": fv, "dairy": dairy}}}
    read_users();
    auto obj =  book.value(user).toObject();
    auto a = obj.value("Weight").toInt();
    if(weight == 0 || weight == -1)
        weight = a;
    QJsonObject statsObject;
    statsObject.insert("weight", QJsonValue::fromVariant(weight));
    statsObject.insert("cals", QJsonValue::fromVariant(cals));
    statsObject.insert("sleep", QJsonValue::fromVariant(sleep));

    if(bench > 0 && bench < 2000){
        statsObject.insert("bench", QJsonValue::fromVariant(bench));
    }
    if(row > 0 && row < 2000){
        statsObject.insert("row", QJsonValue::fromVariant(row));
    }
    if(squat > 0 && squat < 2000){
        statsObject.insert("squat", QJsonValue::fromVariant(squat));
    }
    if(dead > 0 && dead < 2000){
        statsObject.insert("dead", QJsonValue::fromVariant(dead));
    }
    if(bench > 0 && bench < 2000){
        statsObject.insert("press", QJsonValue::fromVariant(press));
    }

    QJsonObject foodObject;
    foodObject.insert("carbs", carbs);
    foodObject.insert("proteins", proteins);
    foodObject.insert("fv", fv);
    foodObject.insert("dairy", dairy);

    statsObject.insert("food", foodObject);

    QString ds = QString::number(date.year()*1000 + date.month()*100 + date.day());
    //QString ds = QString::number(date.year()) + "/" + QString::number(date.month()) + "/" + QString::number(date.day());
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
    all.insert("Phone number", k.getnumber());
    all.insert("Question", k.getQuestion());
    all.insert("Answer", k.getAns());
    all.insert("squatMax",k.getSquat());
    all.insert("benchMax",k.getBench());
    all.insert("deadliftMax",k.getDeadlift());
    auto date = QDate::currentDate();
    QString ds = QString::number(date.year()) + "/" + QString::number(date.month()) + "/" + QString::number(date.day());
    all.insert("sign_in", ds);
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

std::pair<bool, QString> inputOutput::user_recovery(QString user, QString question, QString ans)
{
    bool a = false, b = false;
    read_users();
    auto obj =  book.value(user).toObject();
    if(book.contains(user)){
        auto obj =  book.value(user).toObject();
        QStringList keys = obj.keys();
        for(auto key : keys){
            if (key == "Question"){
                auto value = obj.take(key);
                if(value.toString() == question){
                    a = true;
                }
            }
            if (key == "Answer"){
                auto value = obj.take(key);
                if(value.toString() == ans){
                    b = true;
                }
            }
        }
        if(!a && b)
            return {false, "wrong question"};
        else if(a && !b)
            return {false, "wrong ans"};
        else if(!a && !b)
            return {false, "wrong everything"};
        else
            return {true, ""};
    }
    return {false,"wrong user"};
}

void inputOutput::update_pass(QString kev, QString pass)
{
    read_users();
    auto obj =  book.value(kev).toObject();
    obj["Password"] = pass;
    book[kev] = obj;

    updateFile(book);
}

void inputOutput::getQ(QString kev, QString *temp)
{
    read_users();
    auto obj =  book.value(kev).toObject();
    auto k = obj["Question"];
    *temp = k.toString();
}
