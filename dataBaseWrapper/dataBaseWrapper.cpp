#include "dataBaseWrapper.h"

DataBaseWrapper::DataBaseWrapper()
{
}

bool DataBaseWrapper::_connect(/*QSqlDatabase *dataBase*/)
{
    _dataBase = QSqlDatabase::addDatabase("QPSQL");

    _dataBase.setHostName("localhost");
    _dataBase.setDatabaseName("oto");
    _dataBase.setUserName("postgres");
    _dataBase.setPassword("postgres");

    if (_dataBase.open()) {
        return true;
    } else {
        return false;
    }
}

void DataBaseWrapper::_close(/*QSqlDatabase &dataBase*/)
{
    _dataBase.close();
}

Data DataBaseWrapper::getObjsData()
{
    if (!_connect()) {
        qDebug() << "Data base not open";
    }

    QString dataString;
    QSqlQuery query;

    Data dataObjs;
    Data tempData;

    if (!query.exec("SELECT info FROM situation;")) {
        qDebug() << query.lastError().text();
        return dataObjs;
    }

    JsonConverter converter;

    int i = 1;

    while (query.next()) {
        dataString = query.value(0).toString();
        converter.getData(dataString, tempData);

        dataObjs[QString::number(i)] = tempData["info"];
        i++;
    }

    _close();

    return dataObjs;
}
