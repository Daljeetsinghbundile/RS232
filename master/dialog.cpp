#include"dialog.h"
#include<QComboBox>
#include<QGridLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QSerialPortInfo>
#include<QSpinBox>
#include<QDebug>
#include<newdialog.h>
#include<master.h>

Dialog::Dialog(QWidget *parent):
    QDialog (parent),
    m_serialPortLabel(new QLabel(tr("Choose Serial Port:"))),
    m_serialPortComboBox(new QComboBox),
    m_waitResponseLabel(new QLabel(tr("Wait Response, msec:"))),
    m_waitResponseSpinBox(new QSpinBox),
    m_requestLabel(new QLabel(tr("Request :"))),
    m_requestLineEdit(new QLineEdit(tr("Who are you ?"))),
    m_trafficLabel(new QLabel(tr("No traffic."))),
    m_statusLabel(new QLabel(tr("Status: Not Running."))),
    m_runButton(new QPushButton(tr("Start"))),
    m_closeButton(new QPushButton(tr("Close"))),
    m_requestButton(new QPushButton(tr("Reqest msg"))),
    m_openWindow(new QPushButton(tr("Settings")))
{
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
        m_serialPortComboBox->addItem(info.portName());

      form=new newDialog();

    m_waitResponseSpinBox->setRange(0,10000);
    m_waitResponseSpinBox->setValue(1000);

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(m_serialPortLabel,0,0);
    mainLayout->addWidget(m_serialPortComboBox,0,1);
    mainLayout->addWidget(m_waitResponseLabel,1,0);
    mainLayout->addWidget(m_waitResponseSpinBox,1,1);
    mainLayout->addWidget(m_runButton,0,2,1,1);
    mainLayout->addWidget(m_closeButton,0,2,3,1);
    mainLayout->addWidget(m_requestLabel,2,0);
    mainLayout->addWidget(m_requestLineEdit,2,1,1,3);
    mainLayout->addWidget(m_trafficLabel,3,0,1,4);
    mainLayout->addWidget(m_statusLabel,4,0,1,5);
    mainLayout->addWidget(m_requestButton,5,2,1,2);
    mainLayout->addWidget(m_openWindow,5,1,1,1);
    setLayout(mainLayout);

    setWindowTitle(tr("* Master Serial communication Side *"));
   // m_serialPortComboBox->setFocus();

    connect(m_runButton, &QPushButton::clicked,this,&Dialog::transaction);
    connect(m_requestButton, &QPushButton::clicked,this,&Dialog::requestMsg);
    connect(m_closeButton,&QPushButton::clicked,this,&Dialog::closeMaster);
    connect(m_openWindow,&QPushButton::clicked,this,&Dialog::openNewWindow);

    connect(&m_thread,&Master::update,this,&Dialog::setParameters);


    connect(&m_thread,&Master::response,this,&Dialog::showResponse);
    connect(&m_thread,&Master::error,this,&Dialog::processError);
    connect(&m_thread,&Master::timeout,this,&Dialog::processTimeout);
    connect(&m_thread,&Master::close,this,&Dialog::closeMaster);

    m_serialPortComboBox->setEnabled(false);


}

void Dialog::transaction()
{
    //setControlsEnabled(false);

    m_thread.setObject(form);
    m_runButton->setEnabled(false);
    m_statusLabel->setText(tr("Status: Running , connected to port %1.")
                           .arg(form->settings().name));
    m_serialPortComboBox->setCurrentText(form->settings().name);
    m_thread.transaction(form->settings().name,
                         m_waitResponseSpinBox->value(),
                         m_requestLineEdit->text());

}

void Dialog::openNewWindow()
{
    form->show();

}

void Dialog::setParameters()
{
    const newDialog::Settings s=form->settings();
    qDebug()<<s.name;
}

void Dialog::requestMsg()
{
    setControlsEnabled(true);
    m_statusLabel->setText(tr("Status: Running , connected to port %1.")
                           .arg(form->settings().name));
    m_thread.transaction(form->settings().name,
                         m_waitResponseSpinBox->value(),
                         m_requestLineEdit->text());

}
void Dialog::closeMaster()
{
    //qDebug()<<"hello";
    m_runButton->setEnabled(true);
    m_statusLabel->setText(tr("Status: Disconnected from port %1.")
                            .arg(form->settings().name));
    m_thread.closeMaster(form->settings().name,
                         m_waitResponseSpinBox->value(),
                         m_requestLineEdit->text());


}


void Dialog:: showResponse(const QString &s)
{
    setControlsEnabled(true);
    m_trafficLabel->setText(tr("Traffic, Transaction %1:"
                               "\n\r-request: %2"
                               "\n\r-response: %3")
                            .arg(++m_transactionCount)
                            .arg(m_requestLineEdit->text())
                            .arg(s));

}

void Dialog::processError(const QString &s)
{
    setControlsEnabled(true);
    m_statusLabel->setText(tr("Status : Not running, %1").arg(s));
    m_trafficLabel->setText(tr("No Traffic."));

}


void Dialog::processTimeout(const QString &s)
{
    setControlsEnabled(true);
    m_statusLabel->setText(tr("Status : Not running, %1").arg(s));
    m_trafficLabel->setText(tr("No Traffic."));

}

void Dialog::setControlsEnabled(bool enable)
{
    m_runButton->setEnabled(false);
    m_serialPortComboBox->setEnabled(enable);
    m_waitResponseSpinBox->setEnabled(enable);
    m_requestLineEdit->setEnabled(enable);

}


























