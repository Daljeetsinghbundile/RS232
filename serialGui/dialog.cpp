#include "dialog.h"
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSerialPortInfo>
#include <QSpinBox>
#include<QDebug>
#include<newdialog.h>
#include"mainwindow.h"

Dialog::Dialog(QWidget *parent):
    QDialog (parent),
    m_serialPortLabel(new QLabel(tr("Choose Serial Port:" ))),
    m_serialPortComboBox(new QComboBox),
    m_waitRequestLabel(new QLabel(tr("Wait Request, msec:"))),
    m_waitRequestSpinBox(new QSpinBox),
    m_responseLabel(new QLabel(tr("Response :"))),
    m_responseLineEdit(new QLineEdit(tr("Hello Daljeet here!!!"))),
    m_trafficLabel(new QLabel(tr("No Traffic availabel !!!"))),
    m_statusLabel(new QLabel(tr("Status: Not Running."))),
    m_runButton(new QPushButton(tr("Start"))),
    m_closeButton(new QPushButton(tr("Close"))),
    m_sendButton(new QPushButton(tr("Send Msg"))),
    m_openWindow(new QPushButton(tr("Settings")))
{
    m_waitRequestSpinBox->setRange(0,10000);
    m_waitRequestSpinBox->setValue(10000);

    const auto m_portInfos= QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &portInfo :m_portInfos)
        m_serialPortComboBox->addItem(portInfo.portName());

       form=new newDialog();
    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(m_serialPortLabel,0,0);
    mainLayout->addWidget(m_serialPortComboBox,0,1);
    mainLayout->addWidget(m_waitRequestLabel,1,0);
    mainLayout->addWidget(m_waitRequestSpinBox,1,1);
    mainLayout->addWidget(m_runButton,0,2,1,1);
    mainLayout->addWidget(m_closeButton,0,2,3,1);
    mainLayout->addWidget(m_responseLabel,2,0);
    mainLayout->addWidget(m_responseLineEdit,2,1,1,3);
    mainLayout->addWidget(m_trafficLabel,3,0,1,4);
    mainLayout->addWidget(m_statusLabel,4,0,1,5);
    mainLayout->addWidget(m_sendButton,5,2,1,2);
    mainLayout->addWidget(m_openWindow,5,1,1,1);
    setLayout(mainLayout);

    setWindowTitle("* Serial Communication client side *");
   // m_serialPortComboBox->setFocus();

    connect(m_runButton,&QPushButton::clicked,this, &Dialog::startClient);
    connect(m_closeButton,&QPushButton::clicked,this,&Dialog::closeClient);
    connect(m_sendButton,&QPushButton::clicked,this, &Dialog::sendMsg);
    connect(m_openWindow,&QPushButton::clicked,this,&Dialog::openNewWindow);




    connect(&m_thread, &MainWindow::request,this, &Dialog::showRequest);
    connect(&m_thread, &MainWindow::error,this, &Dialog::processError);
    connect(&m_thread, &MainWindow::timeout,this, &Dialog::processTimeout);
    connect(&m_thread,&MainWindow::close,this,&Dialog::closeClient);

//new
    connect(&m_thread,&MainWindow::update,this,&Dialog::setParameters);

    connect(m_serialPortComboBox,QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
                                        this,&Dialog::activateRunButton);
    connect(m_waitRequestSpinBox,QOverload<const QString &>::of(&QSpinBox::valueChanged),
                                        this, &Dialog::activateRunButton);
    connect(m_responseLineEdit,&QLineEdit::textChanged,this,&Dialog::activateRunButton);


    m_serialPortComboBox->setEnabled(false);

}

void Dialog::startClient()
{
     m_thread.setObject(form);
     qDebug()<<"form->settings().name"<<form->settings().name;
m_runButton->setEnabled(false);
m_statusLabel->setText(tr("Status: Running, Connected to port %1.")
                        .arg(form->settings().name));

m_serialPortComboBox->setCurrentText(form->settings().name);

m_thread.startClient(form->settings().name,
               m_waitRequestSpinBox->value(),
               m_responseLineEdit->text());
//m_thread.startClient(m_serialPortComboBox->currentText(),
//               m_waitRequestSpinBox->value(),
//               m_responseLineEdit->text());

}

void Dialog::openNewWindow()
{
    //Dialog mDialog;
    //mDialog.setModal(true);
  //  mDialog.exec();
    form->show();
    //form->settings();
   // m_thread.setObject(form);


}
void Dialog::setParameters()
{
    /*newDialog objnD;
    Dialog objD;
    objD.baudRate=objnD.settings().baudRate;
    */
  const newDialog::Settings s =form->settings();
    qDebug()<<s.name;



}

void Dialog::sendMsg()
{
    m_runButton->setEnabled(false);
    m_statusLabel->setText(tr("Status: Running, Connected to port %1.")
                            .arg(form->settings().name));

    m_thread.sendMsg(form->settings().name,
                   m_waitRequestSpinBox->value(),
                   m_responseLineEdit->text());



}

void Dialog::closeClient()
{
    m_runButton->setEnabled(true);
    m_statusLabel->setText(tr("Status: Disconnected to port %1.")
                            .arg(form->settings().name));
    m_thread.closeClient(form->settings().name,
                         m_waitRequestSpinBox->value(),
                         m_responseLineEdit->text());




}

void Dialog:: showRequest(const QString &s)
{
    m_trafficLabel->setText(tr("Traffic, Transaction #%1:"
                               "\n\r-request: %2"
                               "\n\r-response: %3")
                            .arg(++m_transactionCount)
                            .arg(s)
                            .arg(m_responseLineEdit->text()));

}

void Dialog:: processError(const QString &s)
{
    activateRunButton();
    m_statusLabel->setText(tr("Status : Not Running,%1.").arg(s));
    m_trafficLabel->setText(tr("No Traffic.!!!"));

}

void Dialog::processTimeout(const QString &s)
{
    m_statusLabel->setText(tr("Status: Running, %1.").arg(s));
    m_trafficLabel->setText(tr("No Traffic. "));
}

void Dialog:: activateRunButton()
{
    m_runButton->setEnabled(true);
}



