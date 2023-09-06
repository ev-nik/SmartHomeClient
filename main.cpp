#include "Widget.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
//----------------------------------------------------------------------------

//     -p=E:/File
// --path=E:/File
//     -p=E:/prog.txt
// --path=E:/prog.txt
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

//    qWarning() << Q_FUNC_INFO <<

    if(path.isEmpty() == false)
    {
        w.setFileAdress(path);
    }

    return a.exec();
}
//----------------------------------------------------------------------------


