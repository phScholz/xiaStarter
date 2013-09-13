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
