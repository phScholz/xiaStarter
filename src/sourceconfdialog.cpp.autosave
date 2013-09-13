/******************************************************************************

    sourceconfdialog.cpp

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
