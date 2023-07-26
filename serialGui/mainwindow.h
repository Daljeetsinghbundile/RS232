#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include<QMutex>
#include<QThread>
#include<QWaitCondition>
#include<QSerialPort>
#include"newdialog.h"


class MainWindow : public QThread
{
    Q_OBJECT
public:
    explicit MainWindow(QObject*parent =nullptr);
    ~MainWindow();

    void startClient(const QString &portName, int waitTimeout, const QString &response);
    void closeClient(const QString &portName, int waitTimeout, const QString &response);

    void setObject(newDialog *s);
    void sendMsg(const QString &portName, int waitTimeout, const QString &response);


signals:

    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
    void close();
    void update();
    void setsignal();


private:
    QSerialPort serial;
    newDialog newDialogObject;
    void run() override;

    QString m_portName;
    QString m_response;
    int m_waitTimeout=0;
    QMutex m_mutex;
    bool m_quit =  false;

};

#endif      // MAINWINDOW_H
