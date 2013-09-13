/********************************************************************************
** Form generated from reading UI file 'xiastarterwindow.ui'
**
** Created: Fri Sep 13 18:51:33 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XIASTARTERWINDOW_H
#define UI_XIASTARTERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "src/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_XiaStarterWindow
{
public:
    QAction *actionSource_conf;
    QAction *actionDgf_config;
    QAction *actionPreferences;
    QAction *actionAbout;
    QAction *actionInfo;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *infoTab;
    QLabel *infoLabel;
    QWidget *tab;
    QGroupBox *pathBox;
    QLineEdit *pathLine;
    QPushButton *browseButton;
    QGroupBox *collectorBox;
    QFrame *line;
    QWidget *layoutWidget1;
    QGridLayout *collectorLayout;
    QCheckBox *buffercheck;
    QCheckBox *longcheck;
    QCheckBox *gfltcheck;
    QCheckBox *coinccheck;
    QSpinBox *coincBox;
    QCheckBox *acheck;
    QCheckBox *ftpwidthcheck;
    QSpinBox *ftpBox;
    QPushButton *runButton;
    QSpinBox *eventBox;
    QCheckBox *eventCheck;
    QPushButton *killButton;
    QLabel *collectorLabel;
    QCheckBox *psaCheck;
    QGroupBox *writerBox;
    QWidget *layoutWidget2;
    QGridLayout *writerLayout;
    QLabel *runLabel;
    QSpinBox *runBox;
    QLabel *prefixLabel;
    QLineEdit *prefixLine;
    QCheckBox *timeCheck;
    QSpinBox *timeBox;
    QRadioButton *undefinedloopRadio;
    QCheckBox *sizeCheck;
    QSpinBox *sizeBox;
    QRadioButton *fixedloppRadio;
    QSpinBox *loopBox;
    QSpinBox *subrunBox;
    QLabel *subrunLabel;
    QPushButton *startButton;
    QLabel *fileLabel;
    QLabel *sizeLabel;
    QPushButton *stopButton;
    QLabel *writerLabel;
    QWidget *tab_2;
    QWidget *layoutWidget3;
    QVBoxLayout *mcaSettingsLayout;
    QRadioButton *utimeRadio;
    QRadioButton *ftimeRadio;
    QFormLayout *formLayout;
    QLabel *crateLabel;
    QLabel *timeLabel;
    QSpinBox *crateBox;
    QSpinBox *mcaTimeBox;
    QWidget *layoutWidget4;
    QVBoxLayout *mcaButtonLayout;
    QCheckBox *plotRatesCheck;
    QPushButton *mcaStartButton;
    QPushButton *mcaStopButton;
    QPushButton *mcaReadoutButton;
    QPushButton *mcaViewlatestButton;
    QPushButton *mcaSaveButton;
    QCustomPlot *mcaPlot;
    QWidget *viewTab;
    QGroupBox *infoGroup;
    QPlainTextEdit *infoBox;
    QWidget *layoutWidget;
    QVBoxLayout *viewLayout;
    QComboBox *detCombo;
    QSpacerItem *verticalSpacer;
    QPushButton *subrunsButton;
    QPushButton *latestButton;
    QPushButton *allButton;
    QWidget *tab_3;
    QCustomPlot *ratesPlot;
    QWidget *scalerTab;
    QCustomPlot *scalerPlot;
    QPlainTextEdit *outputBox;
    QWidget *layoutWidget5;
    QVBoxLayout *buttonsLayout;
    QLabel *statusLabel;
    QPushButton *bootButton;
    QPushButton *setupButton;
    QPushButton *sourceconfButton;
    QPushButton *dgfconfButton;
    QPushButton *scopeButton;
    QPushButton *closeButton;
    QMenuBar *menuBar;
    QMenu *menu_Settings;
    QMenu *menu_Help;

    void setupUi(QMainWindow *XiaStarterWindow)
    {
        if (XiaStarterWindow->objectName().isEmpty())
            XiaStarterWindow->setObjectName(QString::fromUtf8("XiaStarterWindow"));
        XiaStarterWindow->resize(850, 600);
        XiaStarterWindow->setMinimumSize(QSize(850, 600));
        XiaStarterWindow->setMaximumSize(QSize(850, 600));
        actionSource_conf = new QAction(XiaStarterWindow);
        actionSource_conf->setObjectName(QString::fromUtf8("actionSource_conf"));
        actionDgf_config = new QAction(XiaStarterWindow);
        actionDgf_config->setObjectName(QString::fromUtf8("actionDgf_config"));
        actionPreferences = new QAction(XiaStarterWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionAbout = new QAction(XiaStarterWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionInfo = new QAction(XiaStarterWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        centralWidget = new QWidget(XiaStarterWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(5, 5, 840, 350));
        tabWidget->setMinimumSize(QSize(840, 350));
        tabWidget->setMaximumSize(QSize(840, 350));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        infoTab = new QWidget();
        infoTab->setObjectName(QString::fromUtf8("infoTab"));
        infoLabel = new QLabel(infoTab);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(10, 20, 811, 281));
        tabWidget->addTab(infoTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pathBox = new QGroupBox(tab);
        pathBox->setObjectName(QString::fromUtf8("pathBox"));
        pathBox->setGeometry(QRect(50, 10, 771, 61));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pathBox->sizePolicy().hasHeightForWidth());
        pathBox->setSizePolicy(sizePolicy);
        pathBox->setFont(font);
        pathLine = new QLineEdit(pathBox);
        pathLine->setObjectName(QString::fromUtf8("pathLine"));
        pathLine->setGeometry(QRect(40, 20, 500, 30));
        sizePolicy.setHeightForWidth(pathLine->sizePolicy().hasHeightForWidth());
        pathLine->setSizePolicy(sizePolicy);
        pathLine->setMinimumSize(QSize(500, 30));
        pathLine->setMaximumSize(QSize(500, 30));
        browseButton = new QPushButton(pathBox);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(560, 20, 85, 27));
        collectorBox = new QGroupBox(tab);
        collectorBox->setObjectName(QString::fromUtf8("collectorBox"));
        collectorBox->setGeometry(QRect(30, 80, 361, 231));
        sizePolicy.setHeightForWidth(collectorBox->sizePolicy().hasHeightForWidth());
        collectorBox->setSizePolicy(sizePolicy);
        collectorBox->setFont(font);
        collectorBox->setStyleSheet(QString::fromUtf8(""));
        collectorBox->setAlignment(Qt::AlignCenter);
        collectorBox->setFlat(false);
        collectorBox->setCheckable(false);
        line = new QFrame(collectorBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-620, 230, 951, 41));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget1 = new QWidget(collectorBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 341, 191));
        collectorLayout = new QGridLayout(layoutWidget1);
        collectorLayout->setSpacing(6);
        collectorLayout->setContentsMargins(11, 11, 11, 11);
        collectorLayout->setObjectName(QString::fromUtf8("collectorLayout"));
        collectorLayout->setContentsMargins(0, 0, 0, 0);
        buffercheck = new QCheckBox(layoutWidget1);
        buffercheck->setObjectName(QString::fromUtf8("buffercheck"));

        collectorLayout->addWidget(buffercheck, 0, 0, 1, 1);

        longcheck = new QCheckBox(layoutWidget1);
        longcheck->setObjectName(QString::fromUtf8("longcheck"));

        collectorLayout->addWidget(longcheck, 0, 1, 1, 2);

        gfltcheck = new QCheckBox(layoutWidget1);
        gfltcheck->setObjectName(QString::fromUtf8("gfltcheck"));

        collectorLayout->addWidget(gfltcheck, 1, 0, 1, 1);

        coinccheck = new QCheckBox(layoutWidget1);
        coinccheck->setObjectName(QString::fromUtf8("coinccheck"));

        collectorLayout->addWidget(coinccheck, 1, 1, 1, 1);

        coincBox = new QSpinBox(layoutWidget1);
        coincBox->setObjectName(QString::fromUtf8("coincBox"));
        coincBox->setMaximum(999);

        collectorLayout->addWidget(coincBox, 1, 2, 1, 1);

        acheck = new QCheckBox(layoutWidget1);
        acheck->setObjectName(QString::fromUtf8("acheck"));

        collectorLayout->addWidget(acheck, 2, 0, 1, 1);

        ftpwidthcheck = new QCheckBox(layoutWidget1);
        ftpwidthcheck->setObjectName(QString::fromUtf8("ftpwidthcheck"));

        collectorLayout->addWidget(ftpwidthcheck, 2, 1, 1, 1);

        ftpBox = new QSpinBox(layoutWidget1);
        ftpBox->setObjectName(QString::fromUtf8("ftpBox"));
        ftpBox->setMaximum(999);

        collectorLayout->addWidget(ftpBox, 2, 2, 1, 1);

        runButton = new QPushButton(layoutWidget1);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        collectorLayout->addWidget(runButton, 4, 0, 1, 1);

        eventBox = new QSpinBox(layoutWidget1);
        eventBox->setObjectName(QString::fromUtf8("eventBox"));
        eventBox->setMaximum(9999);

        collectorLayout->addWidget(eventBox, 3, 2, 1, 1);

        eventCheck = new QCheckBox(layoutWidget1);
        eventCheck->setObjectName(QString::fromUtf8("eventCheck"));

        collectorLayout->addWidget(eventCheck, 3, 1, 1, 1);

        killButton = new QPushButton(layoutWidget1);
        killButton->setObjectName(QString::fromUtf8("killButton"));

        collectorLayout->addWidget(killButton, 5, 0, 1, 1);

        collectorLabel = new QLabel(layoutWidget1);
        collectorLabel->setObjectName(QString::fromUtf8("collectorLabel"));
        collectorLabel->setMinimumSize(QSize(0, 27));
        collectorLabel->setMaximumSize(QSize(16777215, 27));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        collectorLabel->setFont(font1);
        collectorLabel->setAlignment(Qt::AlignCenter);

        collectorLayout->addWidget(collectorLabel, 5, 2, 1, 1);

        psaCheck = new QCheckBox(layoutWidget1);
        psaCheck->setObjectName(QString::fromUtf8("psaCheck"));

        collectorLayout->addWidget(psaCheck, 3, 0, 1, 1);

        layoutWidget1->raise();
        line->raise();
        writerBox = new QGroupBox(tab);
        writerBox->setObjectName(QString::fromUtf8("writerBox"));
        writerBox->setGeometry(QRect(410, 80, 411, 231));
        sizePolicy.setHeightForWidth(writerBox->sizePolicy().hasHeightForWidth());
        writerBox->setSizePolicy(sizePolicy);
        writerBox->setFont(font);
        writerBox->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(writerBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 391, 194));
        writerLayout = new QGridLayout(layoutWidget2);
        writerLayout->setSpacing(6);
        writerLayout->setContentsMargins(11, 11, 11, 11);
        writerLayout->setObjectName(QString::fromUtf8("writerLayout"));
        writerLayout->setContentsMargins(0, 0, 0, 0);
        runLabel = new QLabel(layoutWidget2);
        runLabel->setObjectName(QString::fromUtf8("runLabel"));

        writerLayout->addWidget(runLabel, 0, 0, 1, 1);

        runBox = new QSpinBox(layoutWidget2);
        runBox->setObjectName(QString::fromUtf8("runBox"));

        writerLayout->addWidget(runBox, 0, 1, 1, 1);

        prefixLabel = new QLabel(layoutWidget2);
        prefixLabel->setObjectName(QString::fromUtf8("prefixLabel"));

        writerLayout->addWidget(prefixLabel, 1, 0, 1, 1);

        prefixLine = new QLineEdit(layoutWidget2);
        prefixLine->setObjectName(QString::fromUtf8("prefixLine"));

        writerLayout->addWidget(prefixLine, 1, 1, 1, 2);

        timeCheck = new QCheckBox(layoutWidget2);
        timeCheck->setObjectName(QString::fromUtf8("timeCheck"));

        writerLayout->addWidget(timeCheck, 2, 0, 1, 1);

        timeBox = new QSpinBox(layoutWidget2);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setMaximum(999);

        writerLayout->addWidget(timeBox, 2, 1, 1, 1);

        undefinedloopRadio = new QRadioButton(layoutWidget2);
        undefinedloopRadio->setObjectName(QString::fromUtf8("undefinedloopRadio"));

        writerLayout->addWidget(undefinedloopRadio, 2, 2, 1, 2);

        sizeCheck = new QCheckBox(layoutWidget2);
        sizeCheck->setObjectName(QString::fromUtf8("sizeCheck"));

        writerLayout->addWidget(sizeCheck, 3, 0, 1, 1);

        sizeBox = new QSpinBox(layoutWidget2);
        sizeBox->setObjectName(QString::fromUtf8("sizeBox"));
        sizeBox->setMaximum(9999);

        writerLayout->addWidget(sizeBox, 3, 1, 1, 1);

        fixedloppRadio = new QRadioButton(layoutWidget2);
        fixedloppRadio->setObjectName(QString::fromUtf8("fixedloppRadio"));

        writerLayout->addWidget(fixedloppRadio, 3, 2, 1, 1);

        loopBox = new QSpinBox(layoutWidget2);
        loopBox->setObjectName(QString::fromUtf8("loopBox"));

        writerLayout->addWidget(loopBox, 3, 3, 1, 1);

        subrunBox = new QSpinBox(layoutWidget2);
        subrunBox->setObjectName(QString::fromUtf8("subrunBox"));
        subrunBox->setMaximum(999);

        writerLayout->addWidget(subrunBox, 0, 3, 1, 1);

        subrunLabel = new QLabel(layoutWidget2);
        subrunLabel->setObjectName(QString::fromUtf8("subrunLabel"));
        subrunLabel->setAlignment(Qt::AlignCenter);

        writerLayout->addWidget(subrunLabel, 0, 2, 1, 1);

        startButton = new QPushButton(layoutWidget2);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        writerLayout->addWidget(startButton, 4, 0, 1, 1);

        fileLabel = new QLabel(layoutWidget2);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        fileLabel->setFont(font1);
        fileLabel->setAlignment(Qt::AlignCenter);

        writerLayout->addWidget(fileLabel, 4, 2, 1, 1);

        sizeLabel = new QLabel(layoutWidget2);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

        writerLayout->addWidget(sizeLabel, 4, 3, 1, 1);

        stopButton = new QPushButton(layoutWidget2);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        writerLayout->addWidget(stopButton, 5, 0, 1, 1);

        writerLabel = new QLabel(layoutWidget2);
        writerLabel->setObjectName(QString::fromUtf8("writerLabel"));
        writerLabel->setMinimumSize(QSize(0, 27));
        writerLabel->setMaximumSize(QSize(16777215, 27));
        writerLabel->setFont(font1);
        writerLabel->setAlignment(Qt::AlignCenter);

        writerLayout->addWidget(writerLabel, 5, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 20, 181, 114));
        mcaSettingsLayout = new QVBoxLayout(layoutWidget3);
        mcaSettingsLayout->setSpacing(6);
        mcaSettingsLayout->setContentsMargins(11, 11, 11, 11);
        mcaSettingsLayout->setObjectName(QString::fromUtf8("mcaSettingsLayout"));
        mcaSettingsLayout->setContentsMargins(0, 0, 0, 0);
        utimeRadio = new QRadioButton(layoutWidget3);
        utimeRadio->setObjectName(QString::fromUtf8("utimeRadio"));

        mcaSettingsLayout->addWidget(utimeRadio);

        ftimeRadio = new QRadioButton(layoutWidget3);
        ftimeRadio->setObjectName(QString::fromUtf8("ftimeRadio"));

        mcaSettingsLayout->addWidget(ftimeRadio);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        crateLabel = new QLabel(layoutWidget3);
        crateLabel->setObjectName(QString::fromUtf8("crateLabel"));
        crateLabel->setMinimumSize(QSize(100, 0));
        crateLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, crateLabel);

        timeLabel = new QLabel(layoutWidget3);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setMinimumSize(QSize(100, 0));
        timeLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, timeLabel);

        crateBox = new QSpinBox(layoutWidget3);
        crateBox->setObjectName(QString::fromUtf8("crateBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, crateBox);

        mcaTimeBox = new QSpinBox(layoutWidget3);
        mcaTimeBox->setObjectName(QString::fromUtf8("mcaTimeBox"));
        mcaTimeBox->setMaximum(9999);

        formLayout->setWidget(1, QFormLayout::FieldRole, mcaTimeBox);


        mcaSettingsLayout->addLayout(formLayout);

        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(40, 140, 141, 183));
        mcaButtonLayout = new QVBoxLayout(layoutWidget4);
        mcaButtonLayout->setSpacing(6);
        mcaButtonLayout->setContentsMargins(11, 11, 11, 11);
        mcaButtonLayout->setObjectName(QString::fromUtf8("mcaButtonLayout"));
        mcaButtonLayout->setContentsMargins(0, 0, 0, 0);
        plotRatesCheck = new QCheckBox(layoutWidget4);
        plotRatesCheck->setObjectName(QString::fromUtf8("plotRatesCheck"));

        mcaButtonLayout->addWidget(plotRatesCheck);

        mcaStartButton = new QPushButton(layoutWidget4);
        mcaStartButton->setObjectName(QString::fromUtf8("mcaStartButton"));
        mcaStartButton->setMinimumSize(QSize(100, 0));

        mcaButtonLayout->addWidget(mcaStartButton);

        mcaStopButton = new QPushButton(layoutWidget4);
        mcaStopButton->setObjectName(QString::fromUtf8("mcaStopButton"));

        mcaButtonLayout->addWidget(mcaStopButton);

        mcaReadoutButton = new QPushButton(layoutWidget4);
        mcaReadoutButton->setObjectName(QString::fromUtf8("mcaReadoutButton"));

        mcaButtonLayout->addWidget(mcaReadoutButton);

        mcaViewlatestButton = new QPushButton(layoutWidget4);
        mcaViewlatestButton->setObjectName(QString::fromUtf8("mcaViewlatestButton"));

        mcaButtonLayout->addWidget(mcaViewlatestButton);

        mcaSaveButton = new QPushButton(layoutWidget4);
        mcaSaveButton->setObjectName(QString::fromUtf8("mcaSaveButton"));

        mcaButtonLayout->addWidget(mcaSaveButton);

        mcaPlot = new QCustomPlot(tab_2);
        mcaPlot->setObjectName(QString::fromUtf8("mcaPlot"));
        mcaPlot->setGeometry(QRect(240, 10, 581, 291));
        tabWidget->addTab(tab_2, QString());
        viewTab = new QWidget();
        viewTab->setObjectName(QString::fromUtf8("viewTab"));
        infoGroup = new QGroupBox(viewTab);
        infoGroup->setObjectName(QString::fromUtf8("infoGroup"));
        infoGroup->setGeometry(QRect(270, 10, 551, 291));
        infoGroup->setFont(font);
        infoBox = new QPlainTextEdit(infoGroup);
        infoBox->setObjectName(QString::fromUtf8("infoBox"));
        infoBox->setGeometry(QRect(20, 30, 521, 241));
        QFont font2;
        font2.setPointSize(9);
        infoBox->setFont(font2);
        layoutWidget = new QWidget(viewTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 241, 261));
        viewLayout = new QVBoxLayout(layoutWidget);
        viewLayout->setSpacing(6);
        viewLayout->setContentsMargins(11, 11, 11, 11);
        viewLayout->setObjectName(QString::fromUtf8("viewLayout"));
        viewLayout->setContentsMargins(0, 0, 0, 0);
        detCombo = new QComboBox(layoutWidget);
        detCombo->setObjectName(QString::fromUtf8("detCombo"));

        viewLayout->addWidget(detCombo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        viewLayout->addItem(verticalSpacer);

        subrunsButton = new QPushButton(layoutWidget);
        subrunsButton->setObjectName(QString::fromUtf8("subrunsButton"));

        viewLayout->addWidget(subrunsButton);

        latestButton = new QPushButton(layoutWidget);
        latestButton->setObjectName(QString::fromUtf8("latestButton"));

        viewLayout->addWidget(latestButton);

        allButton = new QPushButton(layoutWidget);
        allButton->setObjectName(QString::fromUtf8("allButton"));

        viewLayout->addWidget(allButton);

        tabWidget->addTab(viewTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        ratesPlot = new QCustomPlot(tab_3);
        ratesPlot->setObjectName(QString::fromUtf8("ratesPlot"));
        ratesPlot->setGeometry(QRect(10, 10, 811, 301));
        tabWidget->addTab(tab_3, QString());
        scalerTab = new QWidget();
        scalerTab->setObjectName(QString::fromUtf8("scalerTab"));
        scalerTab->setEnabled(false);
        scalerPlot = new QCustomPlot(scalerTab);
        scalerPlot->setObjectName(QString::fromUtf8("scalerPlot"));
        scalerPlot->setGeometry(QRect(10, 10, 811, 301));
        tabWidget->addTab(scalerTab, QString());
        outputBox = new QPlainTextEdit(centralWidget);
        outputBox->setObjectName(QString::fromUtf8("outputBox"));
        outputBox->setGeometry(QRect(5, 360, 620, 210));
        outputBox->setMinimumSize(QSize(600, 210));
        outputBox->setMaximumSize(QSize(620, 210));
        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(660, 360, 177, 211));
        buttonsLayout = new QVBoxLayout(layoutWidget5);
        buttonsLayout->setSpacing(6);
        buttonsLayout->setContentsMargins(11, 11, 11, 11);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(layoutWidget5);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(130, 30));
        statusLabel->setMaximumSize(QSize(175, 30));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        statusLabel->setFont(font3);
        statusLabel->setAlignment(Qt::AlignCenter);

        buttonsLayout->addWidget(statusLabel);

        bootButton = new QPushButton(layoutWidget5);
        bootButton->setObjectName(QString::fromUtf8("bootButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(23);
        sizePolicy1.setHeightForWidth(bootButton->sizePolicy().hasHeightForWidth());
        bootButton->setSizePolicy(sizePolicy1);
        bootButton->setMinimumSize(QSize(0, 23));
        bootButton->setMaximumSize(QSize(16777215, 23));

        buttonsLayout->addWidget(bootButton);

        setupButton = new QPushButton(layoutWidget5);
        setupButton->setObjectName(QString::fromUtf8("setupButton"));
        setupButton->setMinimumSize(QSize(175, 23));
        setupButton->setMaximumSize(QSize(175, 23));

        buttonsLayout->addWidget(setupButton);

        sourceconfButton = new QPushButton(layoutWidget5);
        sourceconfButton->setObjectName(QString::fromUtf8("sourceconfButton"));
        sourceconfButton->setMinimumSize(QSize(175, 23));
        sourceconfButton->setMaximumSize(QSize(175, 23));

        buttonsLayout->addWidget(sourceconfButton);

        dgfconfButton = new QPushButton(layoutWidget5);
        dgfconfButton->setObjectName(QString::fromUtf8("dgfconfButton"));
        dgfconfButton->setMinimumSize(QSize(175, 23));
        dgfconfButton->setMaximumSize(QSize(175, 23));

        buttonsLayout->addWidget(dgfconfButton);

        scopeButton = new QPushButton(layoutWidget5);
        scopeButton->setObjectName(QString::fromUtf8("scopeButton"));
        scopeButton->setMinimumSize(QSize(0, 23));
        scopeButton->setMaximumSize(QSize(16777215, 23));

        buttonsLayout->addWidget(scopeButton);

        closeButton = new QPushButton(layoutWidget5);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(175, 25));
        closeButton->setMaximumSize(QSize(175, 23));

        buttonsLayout->addWidget(closeButton);

        XiaStarterWindow->setCentralWidget(centralWidget);
        outputBox->raise();
        layoutWidget5->raise();
        tabWidget->raise();
        menuBar = new QMenuBar(XiaStarterWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 21));
        menu_Settings = new QMenu(menuBar);
        menu_Settings->setObjectName(QString::fromUtf8("menu_Settings"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        XiaStarterWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_Settings->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_Settings->addAction(actionSource_conf);
        menu_Settings->addAction(actionDgf_config);
        menu_Settings->addAction(actionPreferences);
        menu_Help->addAction(actionAbout);
        menu_Help->addAction(actionInfo);

        retranslateUi(XiaStarterWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(XiaStarterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *XiaStarterWindow)
    {
        XiaStarterWindow->setWindowTitle(QApplication::translate("XiaStarterWindow", "XiaStarter", 0, QApplication::UnicodeUTF8));
        actionSource_conf->setText(QApplication::translate("XiaStarterWindow", "Edit source.conf", 0, QApplication::UnicodeUTF8));
        actionDgf_config->setText(QApplication::translate("XiaStarterWindow", "Edit DGF Configuration", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("XiaStarterWindow", "Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("XiaStarterWindow", "About", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("XiaStarterWindow", "Info", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:16pt;\">xiaStarter</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'DejaVu Sans';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">How to get started:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Boot the setup by pressing the &quot;Boot&quot;-button below </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Edit the source configuration and the configuration of your DGF modules via &quot;Edit source.conf&quot; or &quot;Edit DGF Configuration&quot; </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans';\">   either by pressing the buttons below or via the entries in the &quot;Settings&quot;-menu in the menubar</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Press the &quot;Setup&quot;-Button below </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">Starting a Listmode Run:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">* </span><span style=\" font-family:'Sans';\">Go to the &quot;Listmode Run&quot;-tab</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style"
                        "=\" font-family:'Sans';\"> Enter or Browse to the directory where your run folders should be created</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Enter a Prefix for your Run, e.g. 12C(p,g)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Check the parameters of the collector and the writer, e.g. subrun time, run number ...</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Press the &quot;Start&quot;-button to start the writer</span></p>\n"
"<p style=\" marg"
                        "in-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-weight:600;\">*</span><span style=\" font-family:'Sans';\"> Press the &quot;Run&quot;-button to start the collector</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans';\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(infoTab), QApplication::translate("XiaStarterWindow", "Info", 0, QApplication::UnicodeUTF8));
        pathBox->setTitle(QApplication::translate("XiaStarterWindow", "Run-Path", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        pathLine->setWhatsThis(QApplication::translate("XiaStarterWindow", "This is the Box, where the path of your run-path shoudl appear after you have choosen one by pressing the Browse-Button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        browseButton->setText(QApplication::translate("XiaStarterWindow", "Browse", 0, QApplication::UnicodeUTF8));
        collectorBox->setTitle(QApplication::translate("XiaStarterWindow", "Collector", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buffercheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If set, the data acquisition will be started in the 32-bu\357\254\200er mode. This means, if the bu\357\254\200er on the DGF is full, it is not read out by the writer directly to the host computer, but stored in an external memory on the DGF board. If there are \357\254\201nally 32 \357\254\201lled bu\357\254\200ers in the external memory, they are read out in one piece. This option highly reduces the read-out deadtime and should be always set.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buffercheck->setText(QApplication::translate("XiaStarterWindow", "32 buffer mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        longcheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If set, the data acquisition will take data in long listmode format. This includes sampled traces.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        longcheck->setText(QApplication::translate("XiaStarterWindow", "long listmode format", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gfltcheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If set, the global \357\254\201rst level trigger (GFLT) is turned o\357\254\200. The GFLT serves as late event validation.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        gfltcheck->setText(QApplication::translate("XiaStarterWindow", "Ignore GFLT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        coinccheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This option sets a value for COINCWAIT in ticks. This is the amount of time, the DSP waits for other channels to contribute to an event, if there was a valid event in another channel before.  Therefore, this value de\357\254\201nes the length of the coincidence window for channels within one module.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Important:</span> The value of coincwait is additional to a minimum value of about 250 ns. In additio"
                        "n, note that the e\357\254\200ective coincidence window is twice this amount because either channel can come \357\254\201rst.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        coinccheck->setText(QApplication::translate("XiaStarterWindow", "Coincwait", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        acheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This option should only be used in combination with &quot;Ignore GFLT&quot;. If this option is set, an event which comes with a GFLT will be stored in listmode data as well as in the onboard MCA spectra. Instead of this, if there is no GFLT together with the event, it will be stored only in the MCA spectra but not in the listmode data. In particular, this option is used if you create a GFLT for events with multiplicity m of two or higher. In this case, the m &gt; 1 events are stored in listmode data and MCA spectra, and events with m = 1 are stored only in th"
                        "e MCA spectra.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        acheck->setText(QApplication::translate("XiaStarterWindow", "-a", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ftpwidthcheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This option sets a value for FTPWIDTH. This value determines the length of the signal on the Mult-out on the front panel and can be used to de\357\254\201ne a coincidence window between two channels in di\357\254\200erent modules. </p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ftpwidthcheck->setText(QApplication::translate("XiaStarterWindow", "FTPWIDTH", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        runButton->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">THis button will start the collector (calls mb_collector with the set parameter flags).</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        runButton->setText(QApplication::translate("XiaStarterWindow", "&Run", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        eventCheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">With the &quot;max Event&quot;-option one can adjust a number of events in the buffer. After the number is reached the buffer is going to be read out.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        eventCheck->setText(QApplication::translate("XiaStarterWindow", "max. Events", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        killButton->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This button will <span style=\" font-weight:600;\">only</span> kill the collector.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        killButton->setText(QApplication::translate("XiaStarterWindow", "Kill", 0, QApplication::UnicodeUTF8));
        collectorLabel->setText(QApplication::translate("XiaStarterWindow", "Not Running", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        psaCheck->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This will start the collector in compression mode 2.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        psaCheck->setText(QApplication::translate("XiaStarterWindow", "PSA mode", 0, QApplication::UnicodeUTF8));
        writerBox->setTitle(QApplication::translate("XiaStarterWindow", "Writer", 0, QApplication::UnicodeUTF8));
        runLabel->setText(QApplication::translate("XiaStarterWindow", "Run", 0, QApplication::UnicodeUTF8));
        prefixLabel->setText(QApplication::translate("XiaStarterWindow", "Prefix", 0, QApplication::UnicodeUTF8));
        timeCheck->setText(QApplication::translate("XiaStarterWindow", "set Time [min]", 0, QApplication::UnicodeUTF8));
        undefinedloopRadio->setText(QApplication::translate("XiaStarterWindow", "undefined Loop", 0, QApplication::UnicodeUTF8));
        sizeCheck->setText(QApplication::translate("XiaStarterWindow", "set Filesize", 0, QApplication::UnicodeUTF8));
        fixedloppRadio->setText(QApplication::translate("XiaStarterWindow", "fixed Loop", 0, QApplication::UnicodeUTF8));
        subrunLabel->setText(QApplication::translate("XiaStarterWindow", "SubRun", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QApplication::translate("XiaStarterWindow", "This button will start the writer (calls mb_writer).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        startButton->setText(QApplication::translate("XiaStarterWindow", "St&art", 0, QApplication::UnicodeUTF8));
        fileLabel->setText(QApplication::translate("XiaStarterWindow", "File Size:", 0, QApplication::UnicodeUTF8));
        sizeLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        stopButton->setToolTip(QApplication::translate("XiaStarterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">This button will stop the whole data acquisition!!!</span><span style=\" font-size:10pt; font-weight:600;\"> </span><span style=\" font-size:10pt;\">This means, that it will kill the writer AND the collector and therefore stops the current run!</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        stopButton->setText(QApplication::translate("XiaStarterWindow", "St&op", 0, QApplication::UnicodeUTF8));
        writerLabel->setText(QApplication::translate("XiaStarterWindow", "Not Running", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("XiaStarterWindow", "Listmode Run", 0, QApplication::UnicodeUTF8));
        utimeRadio->setText(QApplication::translate("XiaStarterWindow", "&Undefined Time", 0, QApplication::UnicodeUTF8));
        ftimeRadio->setText(QApplication::translate("XiaStarterWindow", "&Fixed Time", 0, QApplication::UnicodeUTF8));
        crateLabel->setText(QApplication::translate("XiaStarterWindow", "Crate", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("XiaStarterWindow", "Time [s]", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        plotRatesCheck->setToolTip(QApplication::translate("XiaStarterWindow", "This will activate the \"Rates Plot\" and the \"Scaler\" for the MCA Run, i.e. the rates of the detectors will be plotted in the corresponing tab. This will increase the deadtime of your meassurement!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        plotRatesCheck->setWhatsThis(QApplication::translate("XiaStarterWindow", "This will activate the \"Rates Plot\" and the \"Scaler\" for the MCA Run, i.e. the rates of the detectors will be plotted in the corresponing tab. This will increase the deadtime of your meassurement!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        plotRatesCheck->setText(QApplication::translate("XiaStarterWindow", "plot Rates", 0, QApplication::UnicodeUTF8));
        mcaStartButton->setText(QApplication::translate("XiaStarterWindow", "St&art", 0, QApplication::UnicodeUTF8));
        mcaStopButton->setText(QApplication::translate("XiaStarterWindow", "St&op ", 0, QApplication::UnicodeUTF8));
        mcaReadoutButton->setText(QApplication::translate("XiaStarterWindow", "&Read out", 0, QApplication::UnicodeUTF8));
        mcaViewlatestButton->setText(QApplication::translate("XiaStarterWindow", "View &latest", 0, QApplication::UnicodeUTF8));
        mcaSaveButton->setText(QApplication::translate("XiaStarterWindow", "Save spectra", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("XiaStarterWindow", "MCA Run", 0, QApplication::UnicodeUTF8));
        infoGroup->setTitle(QApplication::translate("XiaStarterWindow", "Info Box", 0, QApplication::UnicodeUTF8));
        detCombo->clear();
        detCombo->insertItems(0, QStringList()
         << QApplication::translate("XiaStarterWindow", "All", 0, QApplication::UnicodeUTF8)
        );
        subrunsButton->setText(QApplication::translate("XiaStarterWindow", "View last two subruns", 0, QApplication::UnicodeUTF8));
        latestButton->setText(QApplication::translate("XiaStarterWindow", "View Latest", 0, QApplication::UnicodeUTF8));
        allButton->setText(QApplication::translate("XiaStarterWindow", "View All", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(viewTab), QApplication::translate("XiaStarterWindow", "Listmode View", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("XiaStarterWindow", "Rates Plot", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(scalerTab), QApplication::translate("XiaStarterWindow", "Scaler", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("XiaStarterWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        bootButton->setText(QApplication::translate("XiaStarterWindow", "&Boot", 0, QApplication::UnicodeUTF8));
        setupButton->setText(QApplication::translate("XiaStarterWindow", "&Setup", 0, QApplication::UnicodeUTF8));
        sourceconfButton->setText(QApplication::translate("XiaStarterWindow", "Edit source.conf", 0, QApplication::UnicodeUTF8));
        dgfconfButton->setText(QApplication::translate("XiaStarterWindow", "Edit DGF Configuration", 0, QApplication::UnicodeUTF8));
        scopeButton->setText(QApplication::translate("XiaStarterWindow", "Scope", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("XiaStarterWindow", "&Close", 0, QApplication::UnicodeUTF8));
        menu_Settings->setTitle(QApplication::translate("XiaStarterWindow", "S&ettings", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("XiaStarterWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XiaStarterWindow: public Ui_XiaStarterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XIASTARTERWINDOW_H
