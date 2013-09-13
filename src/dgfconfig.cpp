/******************************************************************************

    dgfconfig.cpp

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
#include "dgfconfig.h"
#include "ui_dgfconfig.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include "psasettings.h"

dgfConfig::dgfConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dgfConfig)
{
    ui->setupUi(this);
    check=false;
    configDir = getenv("HOME");
    configDir+="/mb/dgf_setups/";

    bla = new QStringListModel;
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setMovement(QListView::Static);
    ui->listView->setLayoutMode(QListView::SinglePass);
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(indexClicked(QModelIndex)));
    setWindowTitle("DGF Configuration");
    detList = new QStringList;

    connect(ui->baselineAveraging, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->baselineCut, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->channelGateRequired, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->fastGap, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->fastLength, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->gain, SIGNAL(valueChanged(double)), this, SLOT(somethingChanged(double)));
    connect(ui->gateAcceptancePolarity, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->gateDelayWindow, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->gateEdgePolarityInversion, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->gateWindow, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->gfltPolarity, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->offset, SIGNAL(valueChanged(double)), this, SLOT(somethingChanged(double)));
    connect(ui->pausePileUpRejector, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->polarity, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->slowGap, SIGNAL(valueChanged(double)), this, SLOT(somethingChanged(double)));
    connect(ui->slowLength, SIGNAL(valueChanged(double)), this, SLOT(somethingChanged(double)));
    connect(ui->tau, SIGNAL(valueChanged(double)), this, SLOT(somethingChanged(double)));
    connect(ui->threshold, SIGNAL(valueChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->useGfltForGate, SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));
    connect(ui->disablePileUpRejector,SIGNAL(currentIndexChanged(int)), this, SLOT(somethingChanged(int)));

    connect(ui->saveAllButton,SIGNAL(clicked()), this, SLOT(saveAll()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveSettings()));

    connect(ui->psaButton, SIGNAL(clicked()), this, SLOT(showPsaSettings()));

    currentIndex=0;

    ui->saveButton->setEnabled(0);
    ui->saveAllButton->setEnabled(0);

    //qDebug() << "Current index: " << ui->listView->currentIndex().row();

}

dgfConfig::~dgfConfig()
{
    delete ui;
}

void dgfConfig::showPsaSettings(){

    QVector<int> input;
    if(detSettings.size()>currentIndex){
      input.push_back(detSettings.at(currentIndex).psaLength);
      input.push_back(detSettings.at(currentIndex).userDelay);
      input.push_back(detSettings.at(currentIndex).psaOffset);
      input.push_back(detSettings.at(currentIndex).traceLength);
    }
    else{ 
      qDebug() << "ERROR: detSettings.at(currentIndex) does not exist! currentIndex="<<currentIndex<<" (dgfConfig::showPsaSettings())";
    }

    QEventLoop b;
    psaSettings psaDialog;
    connect(&psaDialog, SIGNAL(sendValues(QVector<int>)), this, SLOT(psaSettingsChanged(QVector<int>)));
    psaDialog.setModal(1);
    psaDialog.show();
    psaDialog.setInput(input);
    b.exec();

}

void dgfConfig::psaSettingsChanged(QVector<int> values){
    if(detSettings.size()>currentIndex){
      detSettings.at(currentIndex).psaLength=values.at(0);
      detSettings.at(currentIndex).userDelay=values.at(1);
      detSettings.at(currentIndex).psaOffset=values.at(2);
      detSettings.at(currentIndex).traceLength=values.at(3);
    }
    else{ 
      qDebug() << "ERROR: detSettings.at(currentIndex) does not exist! currentIndex="<<currentIndex<<" (dgfConfig::psaSettingsChanged())";
    }

    if(detList->at(currentIndex).right(1)!=("*")){
        QString blub=detList->at(currentIndex)+"*";
        detList->replace(currentIndex,blub);
        bla->setStringList(*detList);
        ui->listView->setModel(bla);
        ui->listView->setCurrentIndex(bla->index(currentIndex));
        ui->saveButton->setEnabled(1);
        ui->saveAllButton->setEnabled(1);
    }
}

void dgfConfig::indexClicked(QModelIndex modelIndex){
    currentIndex=modelIndex.row();
    displaySetting(currentIndex);

    if(detList->at(currentIndex).right(1)=="*"){
        ui->saveButton->setEnabled(1);
        ui->saveAllButton->setEnabled(1);
    }
    else{
        ui->saveButton->setEnabled(0);
    }

    //qDebug() << "Row clicked " << modelIndex.row();
}

void dgfConfig::loadDets(std::vector<QString> detnames){
    //qDebug() << "Checking setup files ...";
    QString filePath;

    for(unsigned int i=0; i<detnames.size(); i++){
        filePath=configDir+"dgf_config_"+detnames.at(i)+".setup";
        QFile setupFile(filePath);

        if(setupFile.exists()){
            detList->push_back(detnames.at(i));
            readSetting(detnames.at(i));
            //qDebug() << "Det Number " << i;
            bla->setStringList(*detList);
            ui->listView->setModel(bla);
        }
        else{
            qDebug() << "ERROR: Can not find " << "dgf_config_"+detnames.at(i)+".setup";
            continue;
        }
    }

    if(detList->size()==0){
        detList->push_back("No Detectors");
        bla->setStringList(*detList);
        ui->listView->setModel(bla);        
    }

     ui->listView->setCurrentIndex(bla->index(currentIndex));
     indexClicked(bla->index(currentIndex));
     check=true;
}

void dgfConfig::readSetting(QString det){
    //qDebug() << "Read settings for " << det;

    QFile setupFile(configDir+"dgf_config_"+det+".setup");
    QString content, line;
    if(setupFile.open(QIODevice::ReadOnly)){
        QTextStream in(&setupFile);

        while(!in.atEnd()){
            line=in.readLine().append("\n");
            if(!line.contains("#") && line.size()>2){
                content.append(line);
            }
        }
        setupFile.close();
        //qDebug() << content;

        QStringList lines=content.split("\n");
        QVector<QStringList> values;

        for(int i=0; i< lines.size(); i++){
            values.push_back(lines.at(i).split(QRegExp( "[ \\t]+"), QString::SkipEmptyParts));
        }

        lines.clear();
        content.clear();
        line.clear();

        dgfSettings dummy;
        for(int i=0; i<values.size(); i++){
            if(values.at(i).size()>=2){

                if(values.at(i).at(0)=="POLARITY"){
                    dummy.positivePolarity = values.at(i).at(1).toInt();
                    //qDebug()<< values.at(i).at(0) << values.at(i).at(1) <<dummy.positivePolarity;
                }

                if(values.at(i).at(0)=="TAU"){
                    dummy.tau = values.at(i).at(1).toDouble();
                    //qDebug()<< values.at(i).at(0) << values.at(i).at(1) <<dummy.tau;
                }

                if(values.at(i).at(0)=="GAIN"){
                    dummy.gain = values.at(i).at(1).toDouble();
                    //qDebug()<< values.at(i).at(0) << values.at(i).at(1) <<dummy.gain;
                }

                if(values.at(i).at(0)=="OFFSET"){
                    dummy.offset = values.at(i).at(1).toDouble();
                    //qDebug()<< values.at(i).at(0) << values.at(i).at(1) <<dummy.offset;
                }

                if(values.at(i).at(0)=="SLOWLENGTH"){
                    dummy.slowLength = values.at(i).at(1).toDouble();
                    //qDebug()<< values.at(i).at(0) << values.at(i).at(1) <<dummy.slowLength;
                }

                if(values.at(i).at(0)=="SLOWGAP"){
                    dummy.slowGap = values.at(i).at(1).toDouble();
                    //qDebug()<< values.at(i).at(0) << values.at(i).at(1) <<dummy.slowGap;
                }

                if(values.at(i).at(0)=="MCABASEAV") dummy.baselineAveraging = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="FASTLENGTH") dummy.fastLength = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="FASTGAP") dummy.fastGap = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="THRESHOLD") dummy.threshold = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="TRACELENGTH") dummy.traceLength = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="PSALENGTH") dummy.psaLength = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="USERDELAY") dummy.userDelay = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="PSAOFFSET") dummy.psaOffset = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="MCAENBIN") dummy.mcaBining = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="MCACFDTHR") dummy.mcaThreshold = values.at(i).at(1).toDouble();
                if(values.at(i).at(0)=="CFDTRIGGERDELAY") dummy.cfdTriggerDelay = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="CFDDELAY") dummy.cfdDelay = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="CFDTHRESHOLD") dummy.cfdThreshold = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="CFDFRACTION") dummy.cfdFraction = values.at(i).at(1).toDouble();
                if(values.at(i).at(0)=="CFDGRPTRIGGER") dummy.cfdGroupTrigger = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="BLCUT") dummy.baselineCut = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="INTEGRATOR") dummy.integrator = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GATE") dummy.channelGateRequired = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GFLTPOL") dummy.gfltPolarity = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GATEACCPOL") dummy.gateAcceptancePolarity = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GATEGFLT") dummy.useGfltForGate = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GATEEDGEINV") dummy.gateEdgePolarityInversion = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GATEWINDOW") dummy.gateWindow = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="GATEDELAY") dummy.gateDelayWindow = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="DISPUR") dummy.disablePileUpRejector = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="INVPUR") dummy.invertPileUpRejector = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="PAUSEPUR") dummy.pausePileUprejector = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="DISOOR") dummy.disableOutOfRangeSuppression = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="EST_ENERGY") dummy.estimateEnergy = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="ALLOWNEGEN") dummy.allowNegativeEnergies = values.at(i).at(1).toInt();
                if(values.at(i).at(0)=="USELOCALTIME") dummy.localTime = values.at(i).at(1).toInt();
            }
            else{
                qDebug() << "ERROR: Too less values in Line " << i*3;
                continue;
            }
        }
        detSettings.push_back(dummy);
    }
    else{
        qDebug() << "ERROR: Can not read " << "dgf_config_"+det+".setup";
    }
}

void dgfConfig::writeSetting(QString detName, int detNumber){
    QString content;
    QString filePath=configDir+"dgf_config_"+detName+".setup";
    
    if(detSettings.size() > detNumber){

      content="# DGF setup file " + filePath + "\n\n";
      content+="# Polarity of signal (1 = pos, 0 = neg)\n";
      content+="POLARITY "+ QString::number(detSettings.at(detNumber).positivePolarity) + "\n\n";
      content+="# Tau of preamplifier in us\n";
      content+="TAU " + QString::number(detSettings.at(detNumber).tau) + " \n\n";
      content+="# Gain in V/V\n";
      content+="GAIN "+ QString::number(detSettings.at(detNumber).gain) + "\n\n";
      content+="# DC offset in Volts\n";
      content+="OFFSET " + QString::number(detSettings.at(detNumber).offset) + "\n\n";
      content+="# Length of slow filter in us\n";
      content+="SLOWLENGTH " + QString::number(detSettings.at(detNumber).slowLength) + "\n\n";
      content+="# Gap of slow filter in us\n";
      content+="SLOWGAP " + QString::number(detSettings.at(detNumber).slowGap) + "\n\n";
      content+="# Baseline averaging 2^x\n";
      content+="MCABASEAV "+ QString::number(detSettings.at(detNumber).baselineAveraging) + "\n\n";
      content+="# Length of fast filter in ticks\n";
      content+"FASTLENGTH " + QString::number(detSettings.at(detNumber).fastLength) + "\n\n";
      content+="# Gap of fast filter in ticks\n";
      content+="FASTGAP " + QString::number(detSettings.at(detNumber).fastGap) + "\n\n";
      content+="# Threshold in ADC values\n";
      content+="THRESHOLD " + QString::number(detSettings.at(detNumber).threshold) + "\n\n";
      content+="# Tracelength in ticks\n";
      content+="TRACELENGTH " + QString::number(detSettings.at(detNumber).traceLength) + "\n\n";
      content+="# Pulse shape analysis length in ticks\n";
      content+="PSALENGTH " + QString::number(detSettings.at(detNumber).psaLength) + "\n\n";
      content+="# User delay\n";
      content+="USERDELAY " + QString::number(detSettings.at(detNumber).userDelay) + "\n\n";
      content+="# Pulse shape analysis offset in ticks\n";
      content+="PSAOFFSET " + QString::number(detSettings.at(detNumber).psaOffset) + "\n\n";
      content+="# MCA bining 2^x\n";
      content+="MCAENBIN " + QString::number(detSettings.at(detNumber).mcaBining) + "\n\n";
      content+="# MCA threshold\n";
      content+="MCACFDTHR " + QString::number(detSettings.at(detNumber).mcaThreshold) + "\n\n";
      content+="# CFD trigger delay\n";
      content+="CFDTRIGGERDELAY " + QString::number(detSettings.at(detNumber).cfdTriggerDelay) + "\n\n";
      content+="# CFD delay\n";
      content+="CFDDELAY " + QString::number(detSettings.at(detNumber).cfdDelay) + "\n\n";
      content+="# CFD threshold\n";
      content+="CFDTHRESHOLD " + QString::number(detSettings.at(detNumber).cfdThreshold) + "\n\n";
      content+="# CFD fraction\n";
      content+="CFDFRACTION " + QString::number(detSettings.at(detNumber).cfdFraction) + "\n\n";
      content+="# CFD group trigger\n";
      content+="CFDGRPTRIGGER " + QString::number(detSettings.at(detNumber).cfdGroupTrigger) + "\n\n";
      content+="# Baseline cut\n";
      content+="BLCUT " + QString::number(detSettings.at(detNumber).baselineCut) + "\n\n";
      content+="# Integrator\n";
      content+="INTEGRATOR " + QString::number(detSettings.at(detNumber).integrator) + "\n\n";
      content+="# Channel gate required (0 = normal, 1 = gate required)\n";
      content+="GATE " + QString::number(detSettings.at(detNumber).channelGateRequired) + "\n\n";
      content+="# GFLT polarity (0 = normal, 1 = invert)\n";
      content+="GFLTPOL "+QString::number(detSettings.at(detNumber).gfltPolarity) + "\n\n";
      content+="# Gate acceptance polarity (0 = normal, 1 = invert)\n";
      content+="GATEACCPOL " + QString::number(detSettings.at(detNumber).gateAcceptancePolarity) + "\n\n";
      content+="# Use GFLT for gate (0 = GFLT for slow validation, 1 = GFLT for fast validation)\n";
      content+="GATEGFLT " + QString::number(detSettings.at(detNumber).useGfltForGate) + "\n\n";
      content+="# Gate edge polarity inversion - (0 = normal, 1 = invert)\n";
      content+="GATEEDGEINV " + QString::number(detSettings.at(detNumber).gateEdgePolarityInversion) + "\n\n";
      content+="# Gate window\n";
      content+="GATEWINDOW " + QString::number(detSettings.at(detNumber).gateWindow) + "\n\n";
      content+="# Gate delay\n";
      content+="GATEDELAY " + QString::number(detSettings.at(detNumber).gateDelayWindow) + "\n\n";
      content+="# Disable pile-up rejector flag (0 = do not disable PUR, 1 = disable)\n";
      content+="DISPUR " + QString::number(detSettings.at(detNumber).disablePileUpRejector) + "\n\n";
      content+="# Invert pile-up rejector flag (0 = normal, 1 = accept ONLY pile-up events)\n";
      content+="INVPUR " + QString::number(detSettings.at(detNumber).invertPileUpRejector) + "\n\n";
      content+="# Pause pile-up rejector (0 = normal, 1 = do not reject events within 400 ns - use this if you have ringing).\n";
      content+="PAUSEPUR " + QString::number(detSettings.at(detNumber).pausePileUprejector) + "\n\n";
      content+="# Disable Out-of-range suppression (0 = suppress, 1 = do not suppress)\n";
      content+="DISOOR " + QString::number(detSettings.at(detNumber).disableOutOfRangeSuppression) + "\n\n";
      content+="# Estimage energy if below threshold\n";
      content+="EST_ENERGY " + QString::number(detSettings.at(detNumber).estimateEnergy) + "\n\n";
      content+="# Allow negative energies (0 = disallow, 1 = allow)\n";
      content+="ALLOWNEGEN " + QString::number(detSettings.at(detNumber).allowNegativeEnergies) + "\n\n";
      content+="# Local time (0 = latch channel time on event trigger, 1 = latch on local trigger)\n";
      content+="USELOCALTIME " + QString::number(detSettings.at(detNumber).localTime)+ "\n\n";
    }
    else{
      qDebug() << "ERROR: detSettings.at(detNumber) does not exist! detNumber="<<detNumber<<" (dgfConfig::writeSetting())";
    }
    QFile outputFile(filePath);

    if(!outputFile.open(QIODevice::WriteOnly)){
        qDebug() << "ERROR: Can not write to " << filePath;
    }

    outputFile.write(content.toAscii());
    outputFile.close();
}

void dgfConfig::displaySetting(int detNumber){

  if(detSettings.size()>detNumber){
    ui->baselineAveraging->setValue(detSettings.at(detNumber).baselineAveraging);
    ui->baselineCut->setValue(detSettings.at(detNumber).baselineCut);
    ui->channelGateRequired->setCurrentIndex(detSettings.at(detNumber).channelGateRequired);
    ui->fastGap->setValue(detSettings.at(detNumber).fastGap);
    ui->fastLength->setValue(detSettings.at(detNumber).fastLength);
    ui->gain->setValue(detSettings.at(detNumber).gain);
    ui->gateAcceptancePolarity->setCurrentIndex(detSettings.at(detNumber).gateAcceptancePolarity);
    ui->gateDelayWindow->setValue(detSettings.at(detNumber).gateDelayWindow);
    ui->gateEdgePolarityInversion->setCurrentIndex(detSettings.at(detNumber).gateEdgePolarityInversion);
    ui->gateWindow->setValue(detSettings.at(detNumber).gateWindow);
    ui->gfltPolarity->setCurrentIndex(detSettings.at(detNumber).gfltPolarity);
    ui->offset->setValue(detSettings.at(detNumber).offset);
    ui->pausePileUpRejector->setCurrentIndex(detSettings.at(detNumber).pausePileUprejector);
    ui->polarity->setCurrentIndex(detSettings.at(detNumber).positivePolarity);
    ui->slowGap->setValue(detSettings.at(detNumber).slowGap);
    ui->slowLength->setValue(detSettings.at(detNumber).slowLength);
    ui->tau->setValue(detSettings.at(detNumber).tau);
    ui->threshold->setValue(detSettings.at(detNumber).threshold);
    ui->useGfltForGate->setCurrentIndex(detSettings.at(detNumber).useGfltForGate);
    ui->disablePileUpRejector->setCurrentIndex(detSettings.at(detNumber).disablePileUpRejector);
  }
  else{
    qDebug() << "ERROR: detSettings.at(detNumber) does not exist! detNumber="<<detNumber<<" (dgfConfig::displaySetting)";
  }
}

void dgfConfig::somethingChanged(int value){
    QObject *s=sender();
    QString sendername;

    if(detSettings.size()>ui->listView->currentIndex().row()){
    
      if(s){
        sendername=s->objectName();

        //qDebug() << "Sendername: " << sendername;

        if(sendername=="baselineAveraging") detSettings.at(ui->listView->currentIndex().row()).baselineAveraging=value;

        if(sendername=="baselineCut") detSettings.at(ui->listView->currentIndex().row()).baselineCut=value;

        if(sendername=="channelGateRequired") detSettings.at(ui->listView->currentIndex().row()).channelGateRequired=value;

        if(sendername=="fastGap") detSettings.at(ui->listView->currentIndex().row()).fastGap=value;

        if(sendername=="fastLength") detSettings.at(ui->listView->currentIndex().row()).fastLength=value;

        if(sendername=="gateAcceptancePolarity") detSettings.at(ui->listView->currentIndex().row()).gateAcceptancePolarity=value;

        if(sendername=="gateDelayWindow") detSettings.at(ui->listView->currentIndex().row()).gateDelayWindow=value;

        if(sendername=="gateEdgePolarityInversion") detSettings.at(ui->listView->currentIndex().row()).gateEdgePolarityInversion=value;

        if(sendername=="gateWindow") detSettings.at(ui->listView->currentIndex().row()).gateWindow=value;

        if(sendername=="gfltPolarity") detSettings.at(ui->listView->currentIndex().row()).gfltPolarity=value;

        if(sendername=="pausePileUpRejector") detSettings.at(ui->listView->currentIndex().row()).pausePileUprejector=value;

        if(sendername=="polarity") detSettings.at(ui->listView->currentIndex().row()).positivePolarity=value;

        if(sendername=="threshold") detSettings.at(ui->listView->currentIndex().row()).threshold=value;

        if(sendername=="useGfltForGate") detSettings.at(ui->listView->currentIndex().row()).useGfltForGate=value;

        if(sendername=="disablePileUpRejector") detSettings.at(ui->listView->currentIndex().row()).disablePileUpRejector=value;

        if(check && detList->at(currentIndex).right(1)!="*"){

            QString blub=detList->at(currentIndex)+"*";
            detList->replace(currentIndex,blub);
            bla->setStringList(*detList);
            ui->listView->setModel(bla);
            ui->listView->setCurrentIndex(bla->index(currentIndex));
            ui->saveButton->setEnabled(1);
            ui->saveAllButton->setEnabled(1);
        }
      }
    }
    else{
      qDebug() << "ERROR: detSettings.at(ui->listView->currentIndex().row()) does not exist! ui->listView->currentIndex().row()="<<ui->listView->currentIndex().row()<<" (dgfConfig::somethingChanged())";
    }
    

}

void dgfConfig::somethingChanged(double value){
    QObject *s=sender();
    QString sendername;

    if(detSettings.size()>ui->listView->currentIndex().row()){
      if(s){
        sendername=s->objectName();

        //qDebug() << "Sendername: " << sendername;

        if(sendername=="gain") detSettings.at(ui->listView->currentIndex().row()).gain=value;

        if(sendername=="offset") detSettings.at(ui->listView->currentIndex().row()).offset=value;

        if(sendername=="slowGap") detSettings.at(ui->listView->currentIndex().row()).slowGap=value;

        if(sendername=="slowLength") detSettings.at(ui->listView->currentIndex().row()).slowLength=value;

        if(sendername=="tau") detSettings.at(ui->listView->currentIndex().row()).tau=value;

        if(check && detList->at(currentIndex).right(1)!="*"){
            QString blub=detList->at(currentIndex)+"*";
            detList->replace(ui->listView->currentIndex().row(),blub);
            bla->setStringList(*detList);
            ui->listView->setModel(bla);
            ui->listView->setCurrentIndex(bla->index(currentIndex));
            ui->saveButton->setEnabled(1);
            ui->saveAllButton->setEnabled(1);
        }
      }
    }
    else{
      qDebug() << "ERROR: detSettings.at(ui->listView->currentIndex().row()) does not exist! ui->listView->currentIndex().row()="<<ui->listView->currentIndex().row()<<" (dgfConfig::somethingChanged())";
    }
}

void dgfConfig::on_pushButton_3_clicked()
{
    if(ui->saveButton->isEnabled()){
            QMessageBox msgBox;
            msgBox.setText("DGF Configuration Settings have been modified.");
            msgBox.setInformativeText("Do you want to save your changes?");
            msgBox.setStandardButtons(QMessageBox::SaveAll | QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Cancel);
            int ret = msgBox.exec();

            switch(ret){
            case QMessageBox::Save:
                saveSettings();
                close();
                break;
            case QMessageBox::Discard:
                close();
                break;
            case QMessageBox::SaveAll:
                saveAll();
                close();
                break;
            case QMessageBox::Cancel:
                break;
            }
    }
    else{
        close();
    }
}

dgfSettings::dgfSettings(){

}

void dgfConfig::saveSettings(){
    QString blub=detList->at(currentIndex);
    blub.remove(detList->at(currentIndex).size()-1,1);
    detList->replace(currentIndex,blub);
    writeSetting(detList->at(currentIndex), currentIndex);
    ui->saveButton->setEnabled(0);
    bla->setStringList(*detList);
    ui->listView->setModel(bla);
    ui->listView->setCurrentIndex(bla->index(currentIndex));
}

void dgfConfig::saveAll(){
    for(int i=0; i<detList->size(); i++){
        currentIndex=i;
        saveSettings();
    }
    ui->saveAllButton->setEnabled(0);
}
