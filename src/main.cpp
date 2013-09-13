/******************************************************************************

    main.cpp

    This file is part of xiaStarter.

    xiaStarter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    xiaStarter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with xiaStarter.  If not, see <http://www.gnu.org/licenses/>.

    Diese Datei ist Teil von xiaStarter.

    xiaStarter ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

    xiaStarter wird in der Hoffnung, dass es nützlich sein wird, aber
    OHNE JEDE GEWÄHELEISTUNG, bereitgestellt; sogar ohne die implizite
    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Details.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

    (C)2013     Philipp Scholz
                pscholz@ikp.uni-koeln.de

********************************************************************************/

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

    //Checking if "~/.xs"-folder already exists. If not, it will be created.
    QDir xsFolder(home+"/.xs");
    if(!xsFolder.exists()){
        xsFolder.setPath(home);
        xsFolder.mkdir(".xs");
        xsFolder.cd(".xs");
    }

    QString xsFile=xsFolder.path()+"/.xs";
    QFile temp(xsFile);

    bool fs=false;
    bool h=false;

    if(argc>1){
        for(int i=0; i<argc; i++){
            QString parameter(argv[i]);

            if(parameter=="-fs" || parameter=="--force-start") fs=true;
            if(parameter=="-h" || parameter=="--help") h=true;
        }
    }

    if(h){
        qDebug() << "\n\n USAGE:\txiaStarter <para>\n\n\t -h/--help\tDisplays this.\n\t -fs/--force-start\tIgnores that the \".xs\" file exists. Also if there is another of instance of xiaStarter running, the program will start anyway.";
        exit(1);
    }

    if(temp.exists() && !fs){
        qDebug() << "ERROR: XiaStarter could not be started!\nThere is still another instance of XiaStarter running.\nPlease stop the running process and then try to restart XiaStarter.";
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
