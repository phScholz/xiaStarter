/********************************************************************************
** Form generated from reading UI file 'sourceconfdialog.ui'
**
** Created: Fri Sep 13 18:51:33 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCECONFDIALOG_H
#define UI_SOURCECONFDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_sourceconfDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *sourceconfBox;

    void setupUi(QDialog *sourceconfDialog)
    {
        if (sourceconfDialog->objectName().isEmpty())
            sourceconfDialog->setObjectName(QString::fromUtf8("sourceconfDialog"));
        sourceconfDialog->resize(540, 568);
        buttonBox = new QDialogButtonBox(sourceconfDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(180, 520, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        sourceconfBox = new QPlainTextEdit(sourceconfDialog);
        sourceconfBox->setObjectName(QString::fromUtf8("sourceconfBox"));
        sourceconfBox->setGeometry(QRect(20, 20, 501, 481));

        retranslateUi(sourceconfDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), sourceconfDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), sourceconfDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(sourceconfDialog);
    } // setupUi

    void retranslateUi(QDialog *sourceconfDialog)
    {
        sourceconfDialog->setWindowTitle(QApplication::translate("sourceconfDialog", "Edit Source.Conf", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sourceconfDialog: public Ui_sourceconfDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCECONFDIALOG_H
