#include "printer.h"

Printer::Printer(const QString& path)
    : _path(path)
{
    _docName = new QFont("Helvetica", 18);
    _docName->setBold(true);

    _header = new QFont("Helvetica", 14);
    _header->setBold(true);

    _body = new QFont("Helvetica", 10);
}

Printer::~Printer()
{
    delete _docName;
    delete _header;
    delete _body;
}

void Printer::setFontFamily(const QString &fontFamily)
{
    _header->setFamily(fontFamily);
    _body->setFamily(fontFamily);
}

void Printer::_appendVIndentation(int multiplier)
{
    _y += _lineSpacing * multiplier;
}

void Printer::_appendHIndentation(int multiplier)
{
    _x += _lineSpacing * multiplier;
}

void Printer::_defaultHIndentation()
{
    _x = 100;
}

void Printer::print(Data data)
{
    Q_UNUSED(data);

    QPrinter printer(QPrinter::HighResolution);

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(_path);
    printer.setPaperSize(QPrinter::A4);

    // Поля вручную
    printer.setPageMargins(15, 15, 15, 15, QPrinter::Millimeter);

    QPainter painter(&printer);

    painter.setFont(*_docName);
    painter.drawText(_x, _y, QString::fromUtf8("Отчёт"));
    _appendVIndentation(3);

    _printObj(painter);

    _appendVIndentation(1);

    _printObj(painter);

    painter.end();
}

void Printer::_printObj(QPainter &painter)
{
    painter.setFont(*_header);
    painter.drawText(_x, _y, QString::fromUtf8("Заголовок"));
    _appendVIndentation(2);

    _appendHIndentation(2);

    QStringList lines = {
        QString::fromUtf8("Первая строка текста."),
        QString::fromUtf8("Вторая строка текста."),
        QString::fromUtf8("Третья строка текста."),
        QString::fromUtf8("Четвертая строка текста."),
        QString::fromUtf8("Пятая строка текста.")
    };

    painter.setFont(*_body);

    for (const QString &line : lines) {
        painter.drawText(_x, _y, line);
        _appendVIndentation(1);
    }

    _defaultHIndentation();
}
