#ifndef DIALOG_H
#define DIALOG_H

#include"master.h"
#include<newdialog.h>

#include<QDialog>
#include <QSpinBox>

QT_BEGIN_NAMESPACE

class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QComboBox;

QT_END_NAMESPACE

class Dialog:public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

private slots:
    void transaction();
    void closeMaster();
    void requestMsg();     
    void showResponse(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void openNewWindow();
    void setParameters();

private:
    void setControlsEnabled(bool enable);

private:
    int m_transactionCount = 0;
    QLabel *m_serialPortLabel = nullptr;
    QComboBox *m_serialPortComboBox = nullptr;
    QLabel *m_waitResponseLabel = nullptr;
    QSpinBox *m_waitResponseSpinBox = nullptr;
    QLabel *m_requestLabel = nullptr;
    QLineEdit *m_requestLineEdit = nullptr;
    QLabel *m_trafficLabel = nullptr;
    QLabel *m_statusLabel = nullptr;
    QPushButton *m_runButton = nullptr;
    QPushButton *m_closeButton = nullptr;
    QPushButton *m_requestButton = nullptr;
    QPushButton *m_openWindow = nullptr;








    Master m_thread;
    newDialog *form;
};




#endif // DIALOG_H
