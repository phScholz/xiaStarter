/******************************************************************************

    about.cpp

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
