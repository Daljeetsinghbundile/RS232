#ifndef DIALOG_H
#define DIALOG_H

#include "mainwindow.h"
#include<newdialog.h>
#include <QDialog>

QT_BEGIN_NAMESPACE

class QLabel;
class QLineEdit;
class QComboBox;
class QSpinBox;
class QPushButton;

QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    //variable declaration

        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;

public slots:
    void startClient();
    void closeClient();
    void sendMsg();
    void showRequest(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void activateRunButton();
    void openNewWindow();
    void setParameters();

private:
    int m_transactionCount = 0;
    QLabel *m_serialPortLabel = nullptr;
    QComboBox *m_serialPortComboBox = nullptr;
    QLabel *m_waitRequestLabel = nullptr;
    QSpinBox *m_waitRequestSpinBox = nullptr;
    QLabel *m_responseLabel = nullptr;
    QLineEdit *m_responseLineEdit = nullptr;
    QLabel *m_trafficLabel = nullptr;
    QLabel *m_statusLabel = nullptr;
    QPushButton *m_runButton = nullptr;
    QPushButton *m_closeButton = nullptr;  
    QPushButton *m_sendButton = nullptr;
    QPushButton *m_openWindow = nullptr;





    MainWindow m_thread;
    newDialog *form;




};

#endif // DIALOG_H
