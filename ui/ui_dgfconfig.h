/********************************************************************************
** Form generated from reading UI file 'dgfconfig.ui'
**
** Created: Fri Sep 13 18:51:33 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGFCONFIG_H
#define UI_DGFCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dgfConfig
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *listBox;
    QListView *listView;
    QVBoxLayout *verticalLayout;
    QGroupBox *confBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label;
    QComboBox *polarity;
    QLabel *label_3;
    QDoubleSpinBox *tau;
    QLabel *label_5;
    QDoubleSpinBox *gain;
    QLabel *label_6;
    QDoubleSpinBox *offset;
    QLabel *label_7;
    QDoubleSpinBox *slowLength;
    QLabel *label_4;
    QDoubleSpinBox *slowGap;
    QLabel *label_2;
    QSpinBox *baselineAveraging;
    QLabel *label_8;
    QSpinBox *fastLength;
    QLabel *label_9;
    QSpinBox *fastGap;
    QLabel *label_10;
    QSpinBox *threshold;
    QLabel *label_15;
    QComboBox *useGfltForGate;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *label_11;
    QSpinBox *baselineCut;
    QLabel *label_12;
    QComboBox *channelGateRequired;
    QLabel *label_13;
    QComboBox *gfltPolarity;
    QLabel *label_14;
    QComboBox *gateAcceptancePolarity;
    QLabel *label_16;
    QComboBox *gateEdgePolarityInversion;
    QLabel *label_17;
    QSpinBox *gateWindow;
    QLabel *label_18;
    QSpinBox *gateDelayWindow;
    QLabel *label_19;
    QComboBox *pausePileUpRejector;
    QLabel *label_20;
    QComboBox *disablePileUpRejector;
    QHBoxLayout *horizontalLayout;
    QPushButton *psaButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *saveButton;
    QPushButton *saveAllButton;

    void setupUi(QDialog *dgfConfig)
    {
        if (dgfConfig->objectName().isEmpty())
            dgfConfig->setObjectName(QString::fromUtf8("dgfConfig"));
        dgfConfig->resize(748, 432);
        layoutWidget = new QWidget(dgfConfig);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 731, 401));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        listBox = new QGroupBox(layoutWidget);
        listBox->setObjectName(QString::fromUtf8("listBox"));
        listBox->setMinimumSize(QSize(160, 0));
        listView = new QListView(listBox);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 30, 141, 351));

        horizontalLayout_2->addWidget(listBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        confBox = new QGroupBox(layoutWidget);
        confBox->setObjectName(QString::fromUtf8("confBox"));
        confBox->setMinimumSize(QSize(500, 350));
        confBox->setMaximumSize(QSize(560, 500));
        layoutWidget1 = new QWidget(confBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 531, 311));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        polarity = new QComboBox(layoutWidget1);
        polarity->setObjectName(QString::fromUtf8("polarity"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, polarity);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        tau = new QDoubleSpinBox(layoutWidget1);
        tau->setObjectName(QString::fromUtf8("tau"));
        tau->setDecimals(3);
        tau->setMaximum(999);
        tau->setSingleStep(0.01);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, tau);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_5);

        gain = new QDoubleSpinBox(layoutWidget1);
        gain->setObjectName(QString::fromUtf8("gain"));
        gain->setDecimals(3);
        gain->setSingleStep(0.001);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, gain);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_6);

        offset = new QDoubleSpinBox(layoutWidget1);
        offset->setObjectName(QString::fromUtf8("offset"));
        offset->setDecimals(4);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, offset);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_7);

        slowLength = new QDoubleSpinBox(layoutWidget1);
        slowLength->setObjectName(QString::fromUtf8("slowLength"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, slowLength);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_4);

        slowGap = new QDoubleSpinBox(layoutWidget1);
        slowGap->setObjectName(QString::fromUtf8("slowGap"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, slowGap);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_2);

        baselineAveraging = new QSpinBox(layoutWidget1);
        baselineAveraging->setObjectName(QString::fromUtf8("baselineAveraging"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, baselineAveraging);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_8);

        fastLength = new QSpinBox(layoutWidget1);
        fastLength->setObjectName(QString::fromUtf8("fastLength"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, fastLength);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_9);

        fastGap = new QSpinBox(layoutWidget1);
        fastGap->setObjectName(QString::fromUtf8("fastGap"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, fastGap);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_10);

        threshold = new QSpinBox(layoutWidget1);
        threshold->setObjectName(QString::fromUtf8("threshold"));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, threshold);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_15);

        useGfltForGate = new QComboBox(layoutWidget1);
        useGfltForGate->setObjectName(QString::fromUtf8("useGfltForGate"));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, useGfltForGate);


        horizontalLayout_3->addLayout(formLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_11);

        baselineCut = new QSpinBox(layoutWidget1);
        baselineCut->setObjectName(QString::fromUtf8("baselineCut"));

        formLayout->setWidget(0, QFormLayout::FieldRole, baselineCut);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_12);

        channelGateRequired = new QComboBox(layoutWidget1);
        channelGateRequired->setObjectName(QString::fromUtf8("channelGateRequired"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(channelGateRequired->sizePolicy().hasHeightForWidth());
        channelGateRequired->setSizePolicy(sizePolicy);
        channelGateRequired->setMaximumSize(QSize(90, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, channelGateRequired);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        gfltPolarity = new QComboBox(layoutWidget1);
        gfltPolarity->setObjectName(QString::fromUtf8("gfltPolarity"));
        sizePolicy.setHeightForWidth(gfltPolarity->sizePolicy().hasHeightForWidth());
        gfltPolarity->setSizePolicy(sizePolicy);
        gfltPolarity->setMinimumSize(QSize(80, 0));
        gfltPolarity->setMaximumSize(QSize(90, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, gfltPolarity);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_14);

        gateAcceptancePolarity = new QComboBox(layoutWidget1);
        gateAcceptancePolarity->setObjectName(QString::fromUtf8("gateAcceptancePolarity"));
        sizePolicy.setHeightForWidth(gateAcceptancePolarity->sizePolicy().hasHeightForWidth());
        gateAcceptancePolarity->setSizePolicy(sizePolicy);
        gateAcceptancePolarity->setMaximumSize(QSize(90, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, gateAcceptancePolarity);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_16);

        gateEdgePolarityInversion = new QComboBox(layoutWidget1);
        gateEdgePolarityInversion->setObjectName(QString::fromUtf8("gateEdgePolarityInversion"));
        sizePolicy.setHeightForWidth(gateEdgePolarityInversion->sizePolicy().hasHeightForWidth());
        gateEdgePolarityInversion->setSizePolicy(sizePolicy);
        gateEdgePolarityInversion->setMaximumSize(QSize(16777215, 100));

        formLayout->setWidget(4, QFormLayout::FieldRole, gateEdgePolarityInversion);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_17);

        gateWindow = new QSpinBox(layoutWidget1);
        gateWindow->setObjectName(QString::fromUtf8("gateWindow"));

        formLayout->setWidget(6, QFormLayout::FieldRole, gateWindow);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_18);

        gateDelayWindow = new QSpinBox(layoutWidget1);
        gateDelayWindow->setObjectName(QString::fromUtf8("gateDelayWindow"));

        formLayout->setWidget(7, QFormLayout::FieldRole, gateDelayWindow);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_19);

        pausePileUpRejector = new QComboBox(layoutWidget1);
        pausePileUpRejector->setObjectName(QString::fromUtf8("pausePileUpRejector"));

        formLayout->setWidget(8, QFormLayout::FieldRole, pausePileUpRejector);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_20);

        disablePileUpRejector = new QComboBox(layoutWidget1);
        disablePileUpRejector->setObjectName(QString::fromUtf8("disablePileUpRejector"));

        formLayout->setWidget(9, QFormLayout::FieldRole, disablePileUpRejector);


        horizontalLayout_3->addLayout(formLayout);


        verticalLayout->addWidget(confBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        psaButton = new QPushButton(layoutWidget);
        psaButton->setObjectName(QString::fromUtf8("psaButton"));

        horizontalLayout->addWidget(psaButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);

        saveAllButton = new QPushButton(layoutWidget);
        saveAllButton->setObjectName(QString::fromUtf8("saveAllButton"));

        horizontalLayout->addWidget(saveAllButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(dgfConfig);

        QMetaObject::connectSlotsByName(dgfConfig);
    } // setupUi

    void retranslateUi(QDialog *dgfConfig)
    {
        dgfConfig->setWindowTitle(QApplication::translate("dgfConfig", "Dialog", 0, QApplication::UnicodeUTF8));
        listBox->setTitle(QApplication::translate("dgfConfig", "List of Detectors", 0, QApplication::UnicodeUTF8));
        confBox->setTitle(QApplication::translate("dgfConfig", "Configuration", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dgfConfig", "Polarity", 0, QApplication::UnicodeUTF8));
        polarity->clear();
        polarity->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "negative", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "positive", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("dgfConfig", "Tau [us]", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dgfConfig", "Gain [V/V]", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dgfConfig", "Offset [Volts]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("dgfConfig", "Slow Length [us]", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dgfConfig", "Slow Gap [us]", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dgfConfig", "Baseline averaging", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("dgfConfig", "Fast Length [ticks]", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("dgfConfig", "Fast Gap [ticks]", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("dgfConfig", "Threshold [ADC units]", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("dgfConfig", "Use GFLT for gate", 0, QApplication::UnicodeUTF8));
        useGfltForGate->clear();
        useGfltForGate->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "Yes", 0, QApplication::UnicodeUTF8)
        );
        label_11->setText(QApplication::translate("dgfConfig", "Baseline cut", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("dgfConfig", "Channel gate required", 0, QApplication::UnicodeUTF8));
        channelGateRequired->clear();
        channelGateRequired->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "Yes", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("dgfConfig", "GFLT polarity", 0, QApplication::UnicodeUTF8));
        gfltPolarity->clear();
        gfltPolarity->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "negative", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "positive", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("dgfConfig", "Gate acceptance polarity", 0, QApplication::UnicodeUTF8));
        gateAcceptancePolarity->clear();
        gateAcceptancePolarity->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "negative", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "positive", 0, QApplication::UnicodeUTF8)
        );
        label_16->setText(QApplication::translate("dgfConfig", "Gate edge polarity inversion ", 0, QApplication::UnicodeUTF8));
        gateEdgePolarityInversion->clear();
        gateEdgePolarityInversion->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "Yes", 0, QApplication::UnicodeUTF8)
        );
        label_17->setText(QApplication::translate("dgfConfig", "Gate window [ticks]", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("dgfConfig", "Gate delaywindow [ticks]", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("dgfConfig", "Pause pile-up rejector", 0, QApplication::UnicodeUTF8));
        pausePileUpRejector->clear();
        pausePileUpRejector->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "Yes", 0, QApplication::UnicodeUTF8)
        );
        label_20->setText(QApplication::translate("dgfConfig", "Disable pile-up rejector", 0, QApplication::UnicodeUTF8));
        disablePileUpRejector->clear();
        disablePileUpRejector->insertItems(0, QStringList()
         << QApplication::translate("dgfConfig", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dgfConfig", "Yes", 0, QApplication::UnicodeUTF8)
        );
        psaButton->setText(QApplication::translate("dgfConfig", "PSA Settings", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("dgfConfig", "Close", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("dgfConfig", "Save", 0, QApplication::UnicodeUTF8));
        saveAllButton->setText(QApplication::translate("dgfConfig", "Save All", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dgfConfig: public Ui_dgfConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGFCONFIG_H
