/********************************************************************************
** Form generated from reading UI file 'newdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIALOG_H
#define UI_NEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newDialog
{
public:
    QGroupBox *additionalOptionsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *localEchoCheckBox;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_3;
    QLabel *dataBitsLabel;
    QComboBox *stopBitsBox;
    QComboBox *dataBitsBox;
    QComboBox *parityBox;
    QComboBox *baudRateBox;
    QLabel *stopBitsLabel;
    QLabel *baudRateLabel;
    QComboBox *flowControlBox;
    QLabel *flowControlLabel;
    QLabel *parityLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *applyButton;
    QGroupBox *selectBox;
    QGridLayout *gridLayout_4;
    QLabel *descriptionLabel;
    QLabel *serialNumberLabel;
    QLabel *pidLabel;
    QComboBox *serialPortInfoListBox;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *manufacturerLabel;

    void setupUi(QDialog *newDialog)
    {
        if (newDialog->objectName().isEmpty())
            newDialog->setObjectName(QString::fromUtf8("newDialog"));
        newDialog->resize(400, 300);
        additionalOptionsGroupBox = new QGroupBox(newDialog);
        additionalOptionsGroupBox->setObjectName(QString::fromUtf8("additionalOptionsGroupBox"));
        additionalOptionsGroupBox->setGeometry(QRect(0, 200, 263, 50));
        verticalLayout_2 = new QVBoxLayout(additionalOptionsGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        localEchoCheckBox = new QCheckBox(additionalOptionsGroupBox);
        localEchoCheckBox->setObjectName(QString::fromUtf8("localEchoCheckBox"));
        localEchoCheckBox->setChecked(true);

        verticalLayout_2->addWidget(localEchoCheckBox);

        parametersBox = new QGroupBox(newDialog);
        parametersBox->setObjectName(QString::fromUtf8("parametersBox"));
        parametersBox->setGeometry(QRect(230, 10, 151, 181));
        gridLayout_3 = new QGridLayout(parametersBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        gridLayout_3->addWidget(dataBitsLabel, 1, 0, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout_3->addWidget(stopBitsBox, 3, 1, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout_3->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        gridLayout_3->addWidget(parityBox, 2, 1, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));

        gridLayout_3->addWidget(baudRateBox, 0, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        gridLayout_3->addWidget(stopBitsLabel, 3, 0, 1, 1);

        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));

        gridLayout_3->addWidget(baudRateLabel, 0, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout_3->addWidget(flowControlBox, 4, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        gridLayout_3->addWidget(flowControlLabel, 4, 0, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        gridLayout_3->addWidget(parityLabel, 2, 0, 1, 1);

        layoutWidget = new QWidget(newDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 250, 111, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        applyButton = new QPushButton(layoutWidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_2->addWidget(applyButton);

        selectBox = new QGroupBox(newDialog);
        selectBox->setObjectName(QString::fromUtf8("selectBox"));
        selectBox->setGeometry(QRect(0, 10, 211, 181));
        gridLayout_4 = new QGridLayout(selectBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        gridLayout_4->addWidget(descriptionLabel, 1, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QString::fromUtf8("serialNumberLabel"));

        gridLayout_4->addWidget(serialNumberLabel, 3, 0, 1, 1);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QString::fromUtf8("pidLabel"));

        gridLayout_4->addWidget(pidLabel, 6, 0, 1, 1);

        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout_4->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        gridLayout_4->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QString::fromUtf8("vidLabel"));

        gridLayout_4->addWidget(vidLabel, 5, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QString::fromUtf8("manufacturerLabel"));

        gridLayout_4->addWidget(manufacturerLabel, 2, 0, 1, 1);


        retranslateUi(newDialog);

        QMetaObject::connectSlotsByName(newDialog);
    } // setupUi

    void retranslateUi(QDialog *newDialog)
    {
        newDialog->setWindowTitle(QApplication::translate("newDialog", "Dialog", nullptr));
        additionalOptionsGroupBox->setTitle(QApplication::translate("newDialog", "Additional options", nullptr));
        localEchoCheckBox->setText(QApplication::translate("newDialog", "Local echo", nullptr));
        parametersBox->setTitle(QApplication::translate("newDialog", "Select Parameters", nullptr));
        dataBitsLabel->setText(QApplication::translate("newDialog", "Data bits:", nullptr));
        stopBitsLabel->setText(QApplication::translate("newDialog", "Stop bits:", nullptr));
        baudRateLabel->setText(QApplication::translate("newDialog", "BaudRate:", nullptr));
        flowControlLabel->setText(QApplication::translate("newDialog", "Flow control:", nullptr));
        parityLabel->setText(QApplication::translate("newDialog", "Parity:", nullptr));
        applyButton->setText(QApplication::translate("newDialog", "Apply", nullptr));
        selectBox->setTitle(QApplication::translate("newDialog", "Select Serial Port", nullptr));
        descriptionLabel->setText(QApplication::translate("newDialog", "Description:", nullptr));
        serialNumberLabel->setText(QApplication::translate("newDialog", "Serial number:", nullptr));
        pidLabel->setText(QApplication::translate("newDialog", "Product ID:", nullptr));
        locationLabel->setText(QApplication::translate("newDialog", "Location:", nullptr));
        vidLabel->setText(QApplication::translate("newDialog", "Vendor ID:", nullptr));
        manufacturerLabel->setText(QApplication::translate("newDialog", "Manufacturer:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newDialog: public Ui_newDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIALOG_H
