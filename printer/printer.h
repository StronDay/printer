#ifndef PRINTER_H
#define PRINTER_H

#include <QApplication>
#include <QPainter>
#include <QPrinter>
#include <QString>

#include "fm_base.h"
#include "poppler/cpp/poppler-global.h"

class Printer
{
public:
    Printer(const QString& path);
    ~Printer();

    void setFontFamily(const QString &font);

    void print(Data data);

protected:
    void _appendVIndentation(int multiplier);
    void _appendHIndentation(int multiplier);

    void _defaultHIndentation();

    void _printObj(QPainter &painter);

private:
    QString _path;

    QFont *_docName = nullptr;
    QFont *_header = nullptr;
    QFont *_body = nullptr;

    int _x = 100;
    int _y = 100;

    int _lineSpacing = 250;
};

#endif // PRINTER_H
