#include"master.h"
#include<QSerialPort>
#include<QTime>
#include<QDebug>

Master::Master(QObject *parent):
    QThread(parent)
{

}
//0

Master::~Master()
{
    m_mutex.lock();
    m_quit = true;
    m_cond.wakeOne();
    m_mutex.unlock();
    wait();

}
//!0

//1
void Master::transaction(const QString &portName,int waitTimeout, const QString &request)
{
    const QMutexLocker locker(&m_mutex);
    m_portName= portName;
    m_waitTimeout=waitTimeout;
    m_request = request;


    if(!isRunning())
        start();
    else
        m_cond.wakeOne();

}

void Master::setObject(newDialog *s)
{
    newDialogObject.settings().name = s->settings().name;
    qDebug()<<"newDialogObject.settings().name"<<newDialogObject.settings().name;

}


void Master:: resquestMsg(const QString &portName, int waitTimeout, const QString &request)
{
    const QMutexLocker locker(&m_mutex);
    m_portName= portName;
    m_waitTimeout=waitTimeout;
    m_request = request;


    if(!isRunning())
        start();
    else
        m_cond.wakeOne();

}
void Master::closeMaster(const QString &portName, int waitTimeout, const QString &request)
{
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_request = " ";

   qDebug()<<"closing serial connection";

    if(isRunning()){
        serial.close();
    }

}



// !1

//2
void Master:: run()
{ //3
    bool currentPortNameChanged =false;

    m_mutex.lock();

   QString currentPortName;
   if(currentPortName != m_portName){
       currentPortName = m_portName;
       currentPortNameChanged = true;

   }

   int currentWaitTimeout = m_waitTimeout;
   QString currentRequest = m_request;
   m_mutex.unlock();

   QSerialPort serial;

   if(currentPortName.isEmpty()){
       emit error(tr("No Port name Specified"));
       return;
   }

   //2-1
   while(!m_quit){ //while start
       if(currentPortNameChanged)
       {
           serial.close();
           serial.setPortName(currentPortName);

           if(!serial.open(QIODevice::ReadWrite)){
               emit error(tr("Can't open %1, error code%2")
                             .arg(m_portName).arg(serial.error()));
                       return;
          }
       }

 // 2-1-1

   //writeRequest

    const QByteArray requestData = currentRequest.toUtf8();
    serial.write(requestData);
    if(serial.waitForBytesWritten(m_waitTimeout)){

        //read response
        if(serial.waitForReadyRead(currentWaitTimeout)){
            QByteArray responseData =serial.readAll();
            while(serial.waitForReadyRead(10))
                responseData+= serial.readAll();

            const QString response = QString :: fromUtf8(responseData);

            emit this->response(response);

        }else{
            emit timeout(tr("Wait read Response timeout %1")
                            .arg(QTime::currentTime().toString()));
        }

      }else{
        emit timeout(tr("Wait write request Timeout %1")
                        .arg(QTime::currentTime().toString()));
        }

        m_mutex.lock();
        m_cond.wait(&m_mutex);
        if(currentPortName !=m_portName){
            currentPortName = m_portName;
            currentPortNameChanged = true;
        }else{
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
        currentRequest = m_request;
        m_mutex.unlock();

    } //while close

} //3close


