#ifndef DATABASEWRAPPER_H
#define DATABASEWRAPPER_H

#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlField>

#include <QDebug>

#include "fm_base.h"

class DataBaseWrapper
{
public:
    DataBaseWrapper();

    Data getObjsData();

private:
    QSqlDatabase _dataBase;

    bool _connect(/*QSqlDatabase *dataBase*/);
    void _close(/*QSqlDatabase *dataBase*/);
};

#endif // DATABASEWRAPPER_H
