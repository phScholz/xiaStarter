/**********************************************************************
*                                                                     *
*                      sourceconfdialog.cpp                           *
*                                                                     *
*         This file is part of the XiaStarter-source code             *
*            by Philipp Scholz pscholz@ikp.uni-koeln.de               *
*                                                                     *
*                                                                     *
***********************************************************************/
#include "sourceconfdialog.h"
#include "ui_sourceconfdialog.h"
#include <QFile>
#include "xiastarterwindow.h"
#include <QTextStream>
#include <QMessageBox>

sourceconfDialog::sourceconfDialog(QWidget *parent) :
    QDialog(parent),
        ui(new Ui::sourceconfDialog)
{
        ui->setupUi(this);

        QString configDir(getenv("MB_CONFIG_DIR"));
        sourceConfPath=configDir+"/source.conf";

        //Readin source conf file
        QFile file(sourceConfPath); // sourceconffile

        if(!file.exists()){
            ui->sourceconfBox->appendPlainText("File could not be found!");
        }

        if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
            ui->sourceconfBox->appendPlainText("File could not be opened!");
        }

        QTextStream in(&file);
                while (!in.atEnd()) {
                    QString line = in.readLine();
                ui->sourceconfBox->appendPlainText(line);
            }
        file.close();


}

sourceconfDialog::~sourceconfDialog()
{
    delete ui;
}

void sourceconfDialog::on_buttonBox_accepted()
{
    QFile file(sourceConfPath);
    QString umbruch="\n";
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        file.write(ui->sourceconfBox->toPlainText().toAscii());
        file.write(umbruch.toAscii());
        file.close();
    }
    close();
}

void sourceconfDialog::on_buttonBox_rejected(){
        close();
}
