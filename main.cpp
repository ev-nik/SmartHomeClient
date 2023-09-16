#include "Widget.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
//----------------------------------------------------------------------------

//     -p=E:/File
// --path=E:/File
//     -p=E:/prog.txt
// --path=E:/prog.txt

//     -p=E:/File -d
// --path=E:/File --delete
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

        if( arg_split.count() == 2)
        {
            QString key   = arg_split[0];
            QString value = arg_split[1];

            key = key.toLower(); // Перезаписываем в нижний регистр

            if(key == "-p" || key == "--path")
            {
                path = value;

                if(QDir(path).exists() == false)
                {
                    qWarning() << Q_FUNC_INFO << path << "Folder not found";
                }
            }
        }

        if(arg_split.count() == 1)
        {
            QString value = arg_split[0];
            value = value.toLower();

            if(value == "-d" || value == "--delete")
            {
                w.setDeleteFile(true);
            }
        }
    }

    if(path.isEmpty() == false)
    {
        w.setFileAdress(path);
    }

    return a.exec();
}
//----------------------------------------------------------------------------


