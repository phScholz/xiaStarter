/******************************************************************************

    psasettings.cpp

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

#include "psasettings.h"
#include "ui_psasettings.h"
#include <QDebug>

psaSettings::psaSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::psaSettings)
{
    ui->setupUi(this);

    connect(ui->psaLength, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->userDelay, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->psaOffset, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->traceLength, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(buttonBoxOk()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(buttonBoxCancel()));

}

psaSettings::~psaSettings()
{
    delete ui;
}

void psaSettings::somethingChanged(int value){
    QObject *s=sender();
    QString sendername;

    if(s){
        sendername=s->objectName();

        //qDebug() << "Sendername: " << sendername;

        if(sendername=="psaLength") values.replace(0,value);
        if(sendername=="userDelay") values.replace(1,value);
        if(sendername=="psaOffset") values.replace(2,value);
        if(sendername=="traceLength") values.replace(3,value);
    }

}

void psaSettings::setInput(QVector<int> input){
    if(input.size()==4){
        for(int i=0; i<input.size(); i++){
            values.push_back(input.at(i));
        }
        //0:psa length; 1:user delay; 2:psa offset; 3: trace length
	if(values.size()>3){
	  ui->psaLength->setValue(values.at(0));
	  ui->userDelay->setValue(values.at(1));
	  ui->psaOffset->setValue(values.at(2));
	  ui->traceLength->setValue(values.at(3));
	}
	else{
	  qDebug() << "ERROR: vector values is too small! (psaSettings::setInput())";
	}
    }
    else{
        qDebug() << "ERROR: Too less input values! (psaSettings::setInput())";
    }
}

void psaSettings::buttonBoxOk(){
    emit sendValues(values);
    close();
}

void psaSettings::buttonBoxCancel(){
    close();
}
