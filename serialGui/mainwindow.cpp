#include "mainwindow.h"
#include"newdialog.h"
#include"dialog.h"

#include<QSerialPort>
#include<QTime>
#include <QDebug>

MainWindow::MainWindow(QObject *parent):
    QThread (parent)
{

}

MainWindow:: ~MainWindow()
{
    m_mutex.lock();
    m_quit= true;
    m_mutex.unlock();
    wait();

}

void MainWindow::startClient(const QString &portName, int waitTimeout, const QString &response)
{
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_response = response;

    qDebug()<<"Response"<<response <<"portName: "<<portName;

    if(!isRunning())
        start();

}

void MainWindow:: setObject(newDialog *s)
{
    //MainWindow newObject; //declared privately in .h
   // newDialogObject = new newDialog(s);
    qDebug()<<"s->settings().name"<<s->settings().name;
   QString beforeSettingPort= s->settings().name;

    QString newSetPort= newDialogObject.settings().name;

    qDebug()<<"newDialogObject->settings().name"<<newSetPort;

    newDialogObject.settings().name= beforeSettingPort;
    newSetPort=beforeSettingPort;
  //  newDialogObject.settings().baudRate= s->settings().baudRate;
qDebug()<<"newDialogObject.settings().name"<<newDialogObject.settings().name;

    //s->settings().

}


void MainWindow::sendMsg(const QString &portName, int waitTimeout, const QString &response)
{

    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_response = response;

    if(!isRunning())
        start();

}
void MainWindow::closeClient(const QString &portName, int waitTimeout, const QString &response)
{
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;    
    m_response = " ";
    qDebug()<<"closing serial connection";

    if(isRunning()){
        serial.close();
    }

}

void MainWindow::run()
{


    bool currentPortNameChanged = false;

    m_mutex.lock();

    QString currentPortName;

qDebug()<<"currentPortName"<<currentPortName;
  qDebug()<<"currentPortName after setting"<<m_portName;  //
  if(currentPortName != m_portName){

      currentPortName = m_portName;

      currentPortNameChanged = true;
  }
/*
  if(currentPortName != newDialogObject.settings().name){

        currentPortName = newDialogObject.settings().name;

        currentPortNameChanged = true;
    }

*/
    int currentWaitTimeout = m_waitTimeout;
    QString currentResponse = m_response;
    m_mutex.unlock();


    QSerialPort serial;

    while(!m_quit){
        if(currentPortNameChanged){
            serial.close();
            serial.setPortName(currentPortName);

            if(!serial.open(QIODevice::ReadWrite)){
                emit error(tr("Can't Open %1, error code %2 ")
                           .arg(m_portName).arg(serial.error()));
            return;
            }
        }

    if(serial.waitForReadyRead(currentWaitTimeout)){

        //readRequest
        QByteArray requestData = serial.readAll();
        qDebug()<<"requestData"<<requestData;
        while(serial.waitForReadyRead(10))
            requestData += serial.readAll();

        //writeResponse
        const QByteArray responseData = currentResponse.toUtf8();
        serial.write(responseData);
        qDebug()<<"Response Data"<<responseData;
        if(serial.waitForBytesWritten(m_waitTimeout)){
            const QString request = QString:: fromUtf8(requestData);

            emit this->request(request);

        }else{
            emit timeout(tr("Wait Write Response timeout %1")
                         .arg(QTime::currentTime().toString()));

        }
    } else {
        emit timeout(tr("Wait read Request timeout %1")
                     .arg(QTime::currentTime().toString()));
    }



    m_mutex.lock(); //m_portName
    if(currentPortName !=m_portName){
        currentPortName = m_portName;
        currentPortNameChanged = true;
    } else {
        currentPortNameChanged = false;
            }
    /*if(currentPortName != newDialogObject.settings().name){
        currentPortName = newDialogObject.settings().name;
        currentPortNameChanged = true;
    } else {
        currentPortNameChanged = false;
            }
            */
    currentWaitTimeout = m_waitTimeout;
    currentResponse = m_response;
    m_mutex.unlock();

}

}









