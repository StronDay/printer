#include "mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
{

    DataBaseWrapper dataBase;
    Data data = dataBase.getObjsData();

    createPDF(data);
}

MainPage::~MainPage()
{
}

void MainPage::createPDF(Data data)
{
    QString path = QString::fromUtf8("/home/master/MainFolder/VEGA/Projects/fm_printer/Отчёт.pdf");
    Printer printer(path);

    printer.print(data);
}



/*if (data.isMap()) {
    auto map = data.toMap();

    for (auto it = map.begin(); it != map.end(); it++) {
        qDebug() << it.key() << it.value();
    }
}*/
