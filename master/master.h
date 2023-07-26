#ifndef MASTER_H
#define MASTER_H

#include<QMutex>
#include <QSerialPort>
#include<QThread>
#include<QWaitCondition>
#include"newdialog.h"
class Master : public QThread
{
    Q_OBJECT

public:
    explicit Master(QObject *parent = nullptr);
    ~Master();

    void transaction(const QString &portName, int waitTimeout, const QString &request);
    void closeMaster(const QString &portName, int waitTimeout, const QString &request);

    void resquestMsg(const QString &portName, int waitTimeout, const QString &request);
    void setObject(newDialog *s);

signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
    void close();
    void update();


private:
    QSerialPort serial;
    newDialog newDialogObject;
    void run() override;

    QString m_portName;
    QString m_request;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;
};




#endif // MASTER_H
