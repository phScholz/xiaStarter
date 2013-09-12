/**********************************************************************
*                                                                     *
*                           main.cpp                                  *
*                                                                     *
*         This file is part of the XiaStarter-source code             *
*            by Philipp Scholz pscholz@ikp.uni-koeln.de               *
*                                                                     *
*                                                                     *
***********************************************************************/

#include <QtGui/QApplication>
#include "xiastarterwindow.h"
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString home=getenv("HOME");
    QString xsFile=home+"/.xs";
    QFile temp(xsFile);
    QString check;

    if(argc>1){
        QString parameter(argv[1]);
        check=parameter;
    }

    if(temp.exists() && check!="-fs"){
        qDebug() << "XiaStarter could not be started!\nThere is still another instance of XiaStarter running.\nPlease stop the running process and then try to restart XiaStarter.";
        QMessageBox msgBox;
        msgBox.setText("There is still another instance of XiaStarter running! Please stop the running process and then try to restart XiaStarter.");
        msgBox.setWindowTitle("XiaStarter could not be started!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        exit(1);
    }
    else{
        XiaStarterWindow w;
        w.setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
        w.show();
    
        return a.exec();
    }
}
