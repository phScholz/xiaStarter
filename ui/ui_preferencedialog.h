/********************************************************************************
** Form generated from reading UI file 'preferencedialog.ui'
**
** Created: Fri Sep 13 18:51:33 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCEDIALOG_H
#define UI_PREFERENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_preferencedialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *calTab;
    QWidget *tab;
    QListView *listView;
    QLabel *label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addButton;
    QPushButton *removeButton;
    QWidget *detTab;
    QTableWidget *detTable;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *preferencedialog)
    {
        if (preferencedialog->objectName().isEmpty())
            preferencedialog->setObjectName(QString::fromUtf8("preferencedialog"));
        preferencedialog->resize(787, 480);
        preferencedialog->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget = new QWidget(preferencedialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 771, 461));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calTab = new QTabWidget(layoutWidget);
        calTab->setObjectName(QString::fromUtf8("calTab"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listView = new QListView(tab);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(310, 10, 441, 371));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 281, 261));
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label->setWordWrap(true);
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 311, 291, 62));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(layoutWidget1);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);

        removeButton = new QPushButton(layoutWidget1);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout_2->addWidget(removeButton);

        calTab->addTab(tab, QString());
        detTab = new QWidget();
        detTab->setObjectName(QString::fromUtf8("detTab"));
        detTable = new QTableWidget(detTab);
        if (detTable->columnCount() < 9)
            detTable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setForeground(brush);
        detTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        detTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (detTable->rowCount() < 35)
            detTable->setRowCount(35);
        detTable->setObjectName(QString::fromUtf8("detTable"));
        detTable->setGeometry(QRect(0, 10, 751, 371));
        detTable->setMinimumSize(QSize(751, 371));
        detTable->setMaximumSize(QSize(751, 16777215));
        detTable->setLayoutDirection(Qt::LeftToRight);
        detTable->setTextElideMode(Qt::ElideMiddle);
        detTable->setRowCount(35);
        detTable->setColumnCount(9);
        detTable->horizontalHeader()->setDefaultSectionSize(94);
        detTable->horizontalHeader()->setMinimumSectionSize(20);
        detTable->verticalHeader()->setDefaultSectionSize(20);
        detTable->verticalHeader()->setMinimumSectionSize(20);
        calTab->addTab(detTab, QString());

        verticalLayout->addWidget(calTab);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        buttonLayout->addWidget(cancelButton);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        buttonLayout->addWidget(saveButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(preferencedialog);

        calTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(preferencedialog);
    } // setupUi

    void retranslateUi(QDialog *preferencedialog)
    {
        preferencedialog->setWindowTitle(QApplication::translate("preferencedialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("preferencedialog", "In this tab you can either add or remove calibrations files from the calibration file-list by simply clicking the \"Add File\"- or \"Remove File\"-button. \n"
"After you are finished you can either save the list into a standard file named \"xs.cal\" by pressing the \"Save\"-button or you can ignore the changes by pressing the \"cancel\"-button.\n"
"If there was already a calibration file-list saved in the running directory the box on the right side won't be empty. \n"
"It doesn't make any differences if you change the \"xs.cal\"-file via this preference dialog or a via another editor program.", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("preferencedialog", "&Add File", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("preferencedialog", "&Remove File", 0, QApplication::UnicodeUTF8));
        calTab->setTabText(calTab->indexOf(tab), QApplication::translate("preferencedialog", "Calibration &Files", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = detTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("preferencedialog", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = detTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("preferencedialog", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = detTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("preferencedialog", "DGF Module", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = detTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("preferencedialog", "Crate", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = detTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("preferencedialog", "Slot", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = detTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("preferencedialog", "Subadress", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = detTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("preferencedialog", "Calibration", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = detTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("preferencedialog", "Detector Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = detTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("preferencedialog", "Rate limit", 0, QApplication::UnicodeUTF8));
        calTab->setTabText(calTab->indexOf(detTab), QApplication::translate("preferencedialog", "&Detector Settings", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("preferencedialog", "&Cancel", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("preferencedialog", "&Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class preferencedialog: public Ui_preferencedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCEDIALOG_H
