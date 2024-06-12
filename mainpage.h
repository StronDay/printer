#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

#include "dataBaseWrapper/dataBaseWrapper.h"
#include "printer/printer.h"

class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();

    void createPDF(Data data);
};
#endif // MAINPAGE_H
