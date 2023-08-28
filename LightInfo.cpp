#include "LightInfo.h"
#include "ui_LightInfo.h"

#include <QFile>
#include <QTextStream>
//----------------------------------------------------------------------------

//#define FILE_PATH "E:/prog.txt"
//----------------------------------------------------------------------------

LightInfo::LightInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LightInfo)
{
    ui->setupUi(this);

//    isSave = false;

    m_Timer = new QTimer(this);

    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateLightInfo()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));

    m_Timer->start(1000);
}
//----------------------------------------------------------------------------

LightInfo::~LightInfo()
{
    delete ui;
}
//----------------------------------------------------------------------------

void LightInfo::updateLightInfo()
{
    QPalette pal = ui->lightInfoLabel->palette();

    QTime time = QTime::currentTime();
    int t = time.hour();

    if(t >= 7 && t <= 21)
    {
        pal.setColor(QPalette::WindowText, Qt::black);
        ui->lightInfoLabel->setPalette(pal);
        ui->lightInfoLabel->setText("Switch OFF");

        writeFiles("Switch OFF");
    }

    else
    {
        pal.setColor(QPalette::WindowText, Qt::red);
        ui->lightInfoLabel->setPalette(pal);
        ui->lightInfoLabel->setText("Switch ON");

        writeInFiles("Switch ON");
    }
}
//----------------------------------------------------------------------------

void LightInfo::deleteClick()
{
    emit deleteMe();
}
//----------------------------------------------------------------------------

void LightInfo::writeInFile(QString qs)
{
    QFile file(fileAdress);

    if(file.open(QIODevice::Append))
    {
        QTextStream prog(&file);
        prog << qs << "\n";

        file.close();
    }
}
//----------------------------------------------------------------------------

//void LightInfo::setSave(bool x)
//{
//    isSave = x;
//}
//----------------------------------------------------------------------------

void LightInfo::setFileAdress(QString addres)
{
    fileAdress = addres;
}
//----------------------------------------------------------------------------
