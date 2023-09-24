#include "LeakInfo.h"
#include "ui_LeakInfo.h"

#include <QFile>
#include <QDebug>
//----------------------------------------------------------------------------

LeakInfo::LeakInfo(QString path, QWidget *parent) :
    Device(parent),
    ui(new Ui::LeakInfo)
{
    ui->setupUi(this);

    QString pathLeak = path + "/" + nameSensor() + ".csv";

    if(QFile::exists(pathLeak))
    {
        if(QFile::remove(pathLeak) == false)
        {
            qWarning() << Q_FUNC_INFO << pathLeak << "File is not delete";
        }
    }

    m_Timer = new QTimer(this);

    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateLeakInfo()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteClick()));

    m_Timer->start(1000);
}
//----------------------------------------------------------------------------

LeakInfo::~LeakInfo()
{
    delete ui;
}
//----------------------------------------------------------------------------

void LeakInfo::updateLeakInfo()
{
    QPalette pal = ui->leakInfoLabel->palette();

    QTime time = QTime::currentTime();
    int iTime = time.second();

    if(iTime >=10 && iTime <= 30)
    {
        pal.setColor(QPalette::WindowText, Qt::red);
        ui->leakInfoLabel->setPalette(pal);
        ui->leakInfoLabel->setText("Leak YES");

        writeInFile("Leak YES", CSV);
    }
    else
    {
        pal.setColor(QPalette::WindowText, Qt::green);
        ui->leakInfoLabel->setPalette(pal);
        ui->leakInfoLabel->setText("Leak NO");

        writeInFile("Leak NO", CSV);
    }
}
//----------------------------------------------------------------------------

void LeakInfo::deleteClick()
{
    emit deleteMe();
}
//----------------------------------------------------------------------------

QString LeakInfo::nameSensor()
{
    return "leakeInfo";
}
//----------------------------------------------------------------------------
