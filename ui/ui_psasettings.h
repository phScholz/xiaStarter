/********************************************************************************
** Form generated from reading UI file 'psasettings.ui'
**
** Created: Fri Sep 13 18:51:33 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSASETTINGS_H
#define UI_PSASETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_psaSettings
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *psaLength;
    QLabel *label_3;
    QSpinBox *userDelay;
    QLabel *label_4;
    QSpinBox *psaOffset;
    QLabel *label;
    QSpinBox *traceLength;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *psaSettings)
    {
        if (psaSettings->objectName().isEmpty())
            psaSettings->setObjectName(QString::fromUtf8("psaSettings"));
        psaSettings->resize(207, 171);
        widget = new QWidget(psaSettings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 181, 111));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(4);
        formLayout->setVerticalSpacing(2);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        psaLength = new QSpinBox(widget);
        psaLength->setObjectName(QString::fromUtf8("psaLength"));

        formLayout->setWidget(0, QFormLayout::FieldRole, psaLength);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        userDelay = new QSpinBox(widget);
        userDelay->setObjectName(QString::fromUtf8("userDelay"));

        formLayout->setWidget(1, QFormLayout::FieldRole, userDelay);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        psaOffset = new QSpinBox(widget);
        psaOffset->setObjectName(QString::fromUtf8("psaOffset"));

        formLayout->setWidget(2, QFormLayout::FieldRole, psaOffset);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        traceLength = new QSpinBox(widget);
        traceLength->setObjectName(QString::fromUtf8("traceLength"));

        formLayout->setWidget(3, QFormLayout::FieldRole, traceLength);

        buttonBox = new QDialogButtonBox(psaSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 130, 192, 33));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(psaSettings);

        QMetaObject::connectSlotsByName(psaSettings);
    } // setupUi

    void retranslateUi(QDialog *psaSettings)
    {
        psaSettings->setWindowTitle(QApplication::translate("psaSettings", "PSA Settings", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("psaSettings", "PSA length [ticks]", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("psaSettings", "User delay [ticks]", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("psaSettings", "PSA offset [ticks]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("psaSettings", "Trace length [ticks]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class psaSettings: public Ui_psaSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSASETTINGS_H
