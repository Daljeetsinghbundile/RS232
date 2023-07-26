#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include <QSerialPort>

QT_BEGIN_NAMESPACE

namespace Ui {
class newDialog;
}

class QIntValidator;

QT_END_NAMESPACE
class newDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings{
      QString name;
      qint32 baudRate;
      QString stringBaudRate;
      QSerialPort::DataBits dataBits;
      QString stringDataBits;
      QSerialPort::Parity parity;
      QString stringParity;
      QSerialPort::StopBits stopBits;
      QString stringsStopBits;
      QSerialPort::FlowControl flowcontrol;
      QString stringFlowControl;

      bool localEchoEnabled;

    };


    explicit newDialog(QWidget *parent = nullptr);
    ~newDialog();

    Settings settings() const;
public:
    void updateSettings();
private slots:

    void showPortInfo(int idx);
    void apply();
    void checkCustomBaudratePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);

private:
    void fillPortsParameters();
    void fillPortsInfo();

private:

    Ui::newDialog *m_ui = nullptr;
   Settings m_currentSettings;
    QIntValidator *m_intValidator = nullptr;





};


#endif // NEWDIALOG_H
