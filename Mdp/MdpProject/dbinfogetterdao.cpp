#include "dbinfogetterdao.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>



DBInfoGetterDAO::DBInfoGetterDAO()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mdpschema");
    db.setUserName("root");
    db.setPassword("password");
    bool ok = db.open();
    qDebug() << "db connection status = " << ok;
    QSqlError error = db.lastError();
    if (ok == false){
        qDebug() << "error text = " + error.text();
    }
}


void DBInfoGetterDAO::printAllCountries(){

    QSqlQuery query;
    query.exec("SELECT * FROM countries");
    while (query.next()) {
        QString name = query.value(0).toString();
        qDebug() << name;
    }
}

QList<QString> DBInfoGetterDAO::getAppropriateCountriesFromDB(){
    QList<QString>* list = new QList<QString>();
    QSqlQuery query;
    query.exec("SELECT * FROM countries");
    while (query.next()) {
        QString name = query.value(0).toString();
        list->push_back(name);
    }

    QList<QString>::iterator it = list->begin();
    while (it != list->end()) {
         qDebug() << "Element:" << *it;
         ++it;
    }
    return *list;
}
