#include "Widget.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
//----------------------------------------------------------------------------

//     -p=E:/prog.txt
// --path=E:/prog.txt
//----------------------------------------------------------------------------

class BaseClass
{
    BaseClass()
    {
    }

public:
    void writeInFiles(QString qs);


};
//----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QString path;

    for(int i = 1; i < argc; i++)
    {
        QString arg = argv[i];

        QStringList arg_split = arg.split("=");

        QString key   = arg_split[0];
        QString value = arg_split[1];

        key = key.toLower(); // Перезаписываем в нижний регистр

        if(key == "-p" || key == "--path")
        {
            path = value;
        }
    }

    if(path.isEmpty() == false)
    {
        w.setFileAdress(path);
    }

//        w.setSave(true);

    return a.exec();
}
//----------------------------------------------------------------------------

void writeInFiles(QString qs)
{
    QFile file(fileAdress);

    if(file.open(QIODevice::Append))
    {
        QTextStream prog(&file); // С помощью такой конструкции
        prog << qs;  // передаем данные в файл

        file.close();
    }
}


