/**********************************************************************
*                                                                     *
*                      preferencedialog.cpp                           *
*                                                                     *
*         This file is part of the XiaStarter-source code             *
*            by Philipp Scholz pscholz@ikp.uni-koeln.de               *
*                                                                     *
*                                                                     *
***********************************************************************/


#include "preferencedialog.h"
#include "ui_preferencedialog.h"
#include <QFileDialog>
#include <QListWidget>
#include <QStringListModel>
#include <QTextStream>
#include <QDebug>
#include <QSpinBox>



preferencedialog::preferencedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preferencedialog)
{
    ui->setupUi(this);

    check = true;

    bla = new QStringListModel;
    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setMovement(QListView::Static);
    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->detTable->setSelectionMode(QAbstractItemView::NoSelection);
    readCal();
    setWindowTitle("Preferences");
    ui->calTab->setCurrentIndex(0);
    connect(ui->calTab, SIGNAL(currentChanged(int)), this, SLOT(tabWasChanged(int)));    
}


preferencedialog::~preferencedialog()
{
    delete ui;
}

void preferencedialog::tabWasChanged(int tab){
  emit tabChanged(tab);
}

void preferencedialog::addCal(){
    QFileDialog caldialog;
    caldialog.setFileMode(QFileDialog::ExistingFiles);
    caldialog.setNameFilter("*.cal");
    caldialog.setViewMode(QFileDialog::Detail);
    caldialog.setDirectory("./");

    QStringList stringlist;
    QStringList reducedCalNames;

    for(int i=0; i<calNames.size(); i++){
        QString zahl;
        zahl.setNum(i);
        reducedCalNames.push_back("  "+zahl+":   ..."+calNames.at(i).right(50));
    }

    if (caldialog.exec())
        stringlist = caldialog.selectedFiles();

    for(int i=0; i<stringlist.size(); i++){
        QString zahl;
        zahl.setNum(i);
        calNames.push_back(stringlist.at(i));
        reducedCalNames.push_back("  "+zahl+":   ..."+stringlist.at(i).right(50));
    }

    bla->setStringList(reducedCalNames);
    ui->listView->setModel(bla);



}

void preferencedialog::removeCal(){
    QStringList one, reducedCalNames;

    for(int j=0; j<calNames.size(); j++){
        bool check=true;
        for(int i=0; i<ui->listView->selectionModel()->selectedRows().size(); i++){
            if(ui->listView->selectionModel()->currentIndex().row()==j) check=false;
        }
        if(check){
            one.push_back(calNames.at(j));
        }
    }

    calNames.clear();

    for(int i=0; i<one.size(); i++){
        QString zahl;
        zahl.setNum(i);
        calNames.push_back(one.at(i));
        reducedCalNames.push_back("  "+zahl+":   ..."+one.at(i).right(50));
    }

    bla->setStringList(reducedCalNames);
    ui->listView->setModel(bla);
}

void preferencedialog::on_addButton_clicked()
{
    addCal();
}

void preferencedialog::writeCal(){
    QFile file("./xs.cal");
    QString content="";
    for(int i=0; i<calNames.size(); i++){
        content+=calNames.at(i)+"\n";
    }


    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        file.write(content.toAscii());
        file.close();
    }
}


void preferencedialog::readCal(){
    QFile file("./xs.cal");

    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
	  if(calNames.size()>=1){
            calNames.clear();
	  }
            QTextStream in(&file);
            QStringList reducedCalNames;

            while(!in.atEnd()){
                calNames.push_back(in.readLine());
            }

            for(int i=0; i<calNames.size(); i++){
                QString zahl;
                zahl.setNum(i);
                reducedCalNames.push_back("  "+zahl+":   ..."+calNames.at(i).right(50));
            }

            file.close();
            bla->setStringList(reducedCalNames);
            ui->listView->setModel(bla);
        }
    }
}


void preferencedialog::on_cancelButton_clicked()
{
    close();
}

void preferencedialog::on_saveButton_clicked()
{
    writeCal();
    getDets();
    check=false;
    close();
}

void preferencedialog::on_removeButton_clicked()
{
    removeCal();
}

void preferencedialog::detectorsChanged(std::vector<xs_det> dets){
    detectors.clear();
    for(unsigned int i=0; i<dets.size(); i++){
        detectors.push_back(dets.at(i));
    }
    setupDetTable();
}

void preferencedialog::setupDetTable(){

    ui->detTable->setRowCount(detectors.size());

    calList.clear();

    for(unsigned int i=0; i<detectors.size(); i++){
        calList.push_back("");
        calNum.push_back(0);
    }

    //Setup all items
    for (unsigned int j=0; j<detectors.size(); j++){
        for(int i=0; i<8; i++){
            ui->detTable->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(unsigned int i=0; i<detectors.size(); i++){
        ui->detTable->item(i,0)->setText(detectors.at(i).getType());
        ui->detTable->item(i,1)->setText(detectors.at(i).getName());
        ui->detTable->item(i,2)->setText(detectors.at(i).getDgfmodule());
        ui->detTable->item(i,3)->setText(detectors.at(i).getCrate());
        ui->detTable->item(i,4)->setText(detectors.at(i).getSlot());
        ui->detTable->item(i,5)->setText(detectors.at(i).getAddress());
        calList.replace(i, detectors.at(i).getCalFilePath());

        for(int j=0; j<calNames.size(); j++){
            if(calNames.at(j)==detectors.at(i).getCalFilePath()){
                if((int)detectors.size()<=calNum.size()){
                    calNum.replace(i,j+1);
                }
            }
        }
    }

    for(unsigned int i=0; i<detectors.size(); i++){
        QComboBox* calCombo = new QComboBox(this);
        calCombo->addItem("");
        for(int j=0; j<calNames.size(); j++){
            if(calNames.at(j).size()!=0) {calCombo->addItem("..."+calNames.at(j).right(20));}
        }
        calCombo->setCurrentIndex(calNum.at(i));
        calCombo->setObjectName(QString::number(i));
        connect(calCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(calStringChanged(QString)));

        ui->detTable->setCellWidget(i,6,calCombo);
    }

    for(unsigned int i=0; i<detectors.size(); i++){
        QComboBox* detCombo = new QComboBox(this);
        detCombo->addItem("");
        detCombo->addItem("Germanium");
        detCombo->addItem("Silicon");
        if(detectors.at(i).getDetType()=="Germanium")
            detCombo->setCurrentIndex(1);
        if(detectors.at(i).getDetType()=="Silicon")
            detCombo->setCurrentIndex(2);

        detCombo->setObjectName("detCombo"+QString::number(i));
        connect(detCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(detTypeChanged(QString)));

        ui->detTable->setCellWidget(i,7,detCombo);
    }

    for(unsigned int i=0; i<detectors.size(); i++){
        QSpinBox* ratesBox = new QSpinBox(this);
	ratesBox->setObjectName("ratesBox"+QString::number(i));
        connect(ratesBox, SIGNAL(valueChanged(QString)), this, SLOT(ratesLimitChanged(QString)));
        ratesBox->setRange(0,100000);
        ratesBox->setValue(detectors.at(i).getIratesLimit());
        ui->detTable->setCellWidget(i,8,ratesBox);
    }



    ui->detTable->resizeColumnsToContents();
    ui->detTable->setSelectionMode(QAbstractItemView::SingleSelection);
}

void preferencedialog::getDets(){
    emit detsChanged(detectors);
}

void preferencedialog::calStringChanged(QString calString){
    QObject *s=sender();
    QString sendername;

    if(s){
        sendername=s->objectName();
        int row=sendername.toInt();
        QString compare;

        for(int j=0; j<calNames.size(); j++){
            compare="..."+calNames.at(j).right(20);
            if(calString==compare){
                calNum.replace(row,j);
                calList.replace(row, calNames.at(j));
                detectors.at(row).setCalFilePath(calNames.at(j));
            }
        }
    }

    emit detsChanged(detectors);
}

void preferencedialog::detTypeChanged(QString detType){
    QObject *s=sender();
    QString sendername;
	int row;

    if(s && check){
        sendername=s->objectName();
        
	switch(sendername.size()){
		
		case 9:
			row=sendername.right(1).toInt();
			break;	
		case 10:
			row=sendername.right(2).toInt();
			break;
	}

        detectors.at(row).setDetType(detType);
    }

    emit detsChanged(detectors);
}

void preferencedialog::ratesLimitChanged(QString ratesLimit){
    QObject *s=sender();
    QString sendername;
	int row;

    if(s && check){
        sendername=s->objectName();
        switch(sendername.size()){
            case 9:
                row=sendername.right(1).toInt();
                break;
            case 10:
                row=sendername.right(2).toInt();
                break;
        }
        detectors.at(row).setRatesLimit(ratesLimit);

    }
    emit detsChanged(detectors);
}
