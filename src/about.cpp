/**********************************************************************
*                                                                     *
*                            about.cpp                                *
*                                                                     *
*         This file is part of the XiaStarter-source code             *
*            by Philipp Scholz pscholz@ikp.uni-koeln.de               *
*                                                                     *
*                                                                     *
***********************************************************************/

#include "about.h"
#include "ui_about.h"
#include <QFile>
#include <QString>
#include <QTextStream>



about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    //ui->aboutBox->



    //QFile text("./about.txt");

    /*if(text.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&text);
                while (!in.atEnd()) {
                QString line = in.readLine();
                ui->aboutBox->appendPlainText(line);
            }

    }
    else ui->aboutBox->setPlainText("Help could not be found!");*/

    //text.close();
}

about::~about()
{
    delete ui;
}




void about::on_closeButton_clicked()
{
    close();
}
