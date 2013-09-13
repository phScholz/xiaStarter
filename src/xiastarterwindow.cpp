/******************************************************************************

    xiastarterwindow.cpp

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
#include "xiastarterwindow.h"
#include "ui_xiastarterwindow.h"
#include "xiastarter.h"
#include "sourceconfdialog.h"
#include "about.h"
#include "preferencedialog.h"
#include <QDebug>
#include <QTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QPalette>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include </usr/local/include/mfile.h>
#include <QPen>
#include "dgfconfig.h"

XiaStarterWindow::XiaStarterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XiaStarterWindow)
{
    version="0.3.5";
    QString home, xsFile;
    home=getenv("HOME");
    xsFile=home+"/.xs/.xs";
    QFile file(xsFile);
    file.open(QIODevice::WriteOnly);
    QString content="XiaStarter Temporary File";
    file.write(content.toAscii());
    file.close();


    QString configDir(getenv("MB_CONFIG_DIR"));
    sourceConfPath = configDir+"/source.conf";

    QString histDir(getenv("HW_HIST_DIR"));
    hwHistDir=histDir+"/";

    //Some UI-Stuff
    ui->setupUi(this);    
    ui->tabWidget->setCurrentIndex(0);
    ui->outputBox->setReadOnly(1);
    ui->outputBox->setCenterOnScroll(1);
    ui->collectorLabel->setAutoFillBackground(true);
    ui->writerLabel->setAutoFillBackground(true);
    ui->infoBox->setFont(QFont("Helvetica [Cronyx]", 10));
    ui->latestButton->setEnabled(1);
    ui->allButton->setEnabled(1);
    ui->scalerTab->setEnabled(1);
    ui->scalerPlot->setColor(QColor(230,230,230,255));
    ui->killButton->setEnabled(0);
    ui->stopButton->setEnabled(0);
    ui->fixedloppRadio->setEnabled(0);
    ui->loopBox->setEnabled(0);
    ui->sizeCheck->setEnabled(0);
    ui->timeBox->setEnabled(1);
    ui->sizeBox->setEnabled(0);
    ui->detCombo->addItem("Germaniums");
    ui->detCombo->addItem("Silicons");
    ui->plotRatesCheck->setEnabled(0);
    ui->scopeButton->setEnabled(0);

    //mcaPlot Settings
    ui->mcaPlot->setRangeDrag(Qt::Vertical| Qt::Horizontal);
    ui->mcaPlot->setRangeZoom(Qt::Vertical| Qt::Horizontal);
    ui->mcaPlot->xAxis->setLabel("Channels");
    ui->mcaPlot->yAxis->setLabel("Counts");
    QFont sansFont("Helvetica [Cronyx]", 8);
    ui->mcaPlot->legend->setFont(sansFont);
    ui->mcaPlot->legend->setVisible(1);
    ui->mcaPlot->legend->setPositionStyle(QCPLegend::psTopRight);

    showRatesFor=0;

    //ratesPlot settings
    ui->ratesPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->ratesPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ratesContextMenuRequest(QPoint)));
    ui->ratesPlot->setRangeDrag(Qt::Vertical);
    ui->ratesPlot->setRangeZoom(Qt::Vertical);
    ui->ratesPlot->xAxis->setLabel("Time elapsed [s]");
    ui->ratesPlot->yAxis->setLabel("Current rate [Hz]");
    ui->ratesPlot->legend->setFont(sansFont);
    ui->ratesPlot->legend->setVisible(1);
    ui->ratesPlot->legend->setPositionStyle(QCPLegend::psTopLeft);
    ui->ratesPlot->legend->setItemSpacing(0);
    ui->ratesPlot->legend->setMargin(10,10,0,1);


    //setting up LoadMenu manually
    defaultAction = new QAction(tr("Default Settings"), this);
    defaultAction->setShortcut(Qt::CTRL + Qt::Key_D);
    lastAction = new QAction(tr("Last Settings"), this);
    lastAction->setShortcut(Qt::CTRL + Qt::Key_Z);
    loadFileAction = new QAction(tr("Settings File"), this);
    loadFileAction->setShortcut(Qt::CTRL + Qt::Key_L);
    connect(defaultAction, SIGNAL(triggered()), this, SLOT(loadDefaultSettings()));
    connect(lastAction, SIGNAL(triggered()), this, SLOT(loadLastSettings()));
    connect(loadFileAction, SIGNAL(triggered()), this, SLOT(loadSettingsFile()));
    loadMenu=new QMenu(tr("&Load"), this);
    menuBar()->insertMenu(ui->menu_Settings->menuAction(), loadMenu);
    loadMenu->addAction(defaultAction);
    loadMenu->addAction(lastAction);
    loadMenu->addAction(loadFileAction);

    //setting up SaveMenue
    saveAction = new QAction(tr("Save ..."), this);
    saveAction->setShortcut(Qt::CTRL + Qt::Key_S);
    saveAsAction = new QAction(tr("Save As..."), this);
    saveAsAction->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveSettings()));
    connect(this, SIGNAL(saveFileNameIsNotEmpty(bool)), saveAction, SLOT(setEnabled(bool)));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsSettings()));
    saveMenu=new QMenu(tr("S&ave"), this);
    menuBar()->insertMenu(ui->menu_Settings->menuAction(), saveMenu);
    saveMenu->addAction(saveAction);
    saveMenu->addAction(saveAsAction);
    saveAction->setEnabled(0);

    
    //connect menu entries with functions
    connect(ui->actionSource_conf,SIGNAL (triggered()), this, SLOT(sourceconf_clicked()));
    connect(ui->actionDgf_config,SIGNAL (triggered()), this, SLOT(dgfconf_clicked()));
    connect(ui->sourceconfButton, SIGNAL(clicked()), this, SLOT(sourceconf_clicked()));
    connect(ui->dgfconfButton, SIGNAL(clicked()), this, SLOT(dgfconf_clicked()));
    connect(ui->actionAbout, SIGNAL (triggered()), this, SLOT(about_clicked()));
    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(showPreferences()));
    connect(ui->actionInfo, SIGNAL(triggered()), this, SLOT(showInfo()));
    connect(ui->ftimeRadio, SIGNAL(toggled(bool)), ui->mcaTimeBox, SLOT(setEnabled(bool)));
    connect(ui->detCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(detComboBox(int)));

    xs = new XiaStarter(this);
    changeStatus(2);

    //Connections between SIGNALS and SLOTS with the xiastarter class
    connect(ui->runBox, SIGNAL(valueChanged(int)), xs, SLOT(setRunNum(int)));
    connect(ui->subrunBox, SIGNAL(valueChanged(int)), xs, SLOT(setSubrunNum(int)));
    connect(ui->prefixLine, SIGNAL(textChanged(QString)), xs, SLOT(setPrefix(QString)));
    connect(ui->pathLine, SIGNAL(textChanged(QString)), xs, SLOT(setDirname(QString)));
    connect(ui->undefinedloopRadio, SIGNAL(toggled(bool)), xs, SLOT(setudefloop(bool)));
    connect(ui->timeBox, SIGNAL(valueChanged(int)), xs, SLOT(setTime(int)));	
    connect(ui->loopBox, SIGNAL(valueChanged(int)), xs, SLOT(setLoopint(int)));
    connect(ui->utimeRadio, SIGNAL(toggled(bool)),xs, SLOT(setUTimeRadio(bool)));
    connect(ui->ftimeRadio, SIGNAL(toggled(bool)), xs, SLOT(setFTimeRadio(bool)));
    connect(xs, SIGNAL(ratesDataChanged()), this, SLOT(plotRates()));
    connect(xs, SIGNAL(collectorState(QProcess::ProcessState)), this, SLOT(collectorStatus(QProcess::ProcessState)));
    connect(xs, SIGNAL(writerState(QProcess::ProcessState)), this, SLOT(writerStatus(QProcess::ProcessState)));
    connect(xs, SIGNAL(newFileName(QString)), this, SLOT(setFileName(QString)));
    connect(xs, SIGNAL(newFileSize(qint64)), this, SLOT(newFileSize(qint64)));
    connect(xs, SIGNAL(writerIsDone()), this, SLOT(on_stopButton_clicked()));
    connect(ui->allButton,SIGNAL(clicked()), xs, SLOT(lmViewAll()));
    connect(ui->latestButton,SIGNAL(clicked()), xs, SLOT(lmViewLatest()));
    connect(ui->bootButton, SIGNAL(clicked()), xs, SLOT(startBootProcedure()));
    connect(ui->setupButton, SIGNAL(clicked()), xs, SLOT(startSetupProcedure()));
    connect(xs, SIGNAL(statusChanged(int)), this, SLOT(changeStatus(int)));
    connect(xs, SIGNAL(textOutput(QString)), this, SLOT(writeOutput(QString)));
    connect(xs, SIGNAL(runNumChange(int)), this, SLOT(changeRunNum(int)));
    connect(xs, SIGNAL(subrunNumChange(int)), this, SLOT(changeSubrunNum(int)));
    connect(xs, SIGNAL(viewButtons(bool)), this, SLOT(viewButtons(bool)));
    connect(xs, SIGNAL(newInfo(QString,QString,QString)), this, SLOT(writeInfoBox(QString,QString,QString)));
    connect(xs, SIGNAL(newMCATime(int)), ui->mcaTimeBox, SLOT(setValue(int)));
    connect(ui->plotRatesCheck, SIGNAL(stateChanged(int)), xs, SLOT(setMCARates(int)));
    connect(xs, SIGNAL(copyingMODFiles(bool)), ui->killButton, SLOT(setDisabled(bool)));
    connect(xs, SIGNAL(copyingMODFiles(bool)), ui->stopButton, SLOT(setDisabled(bool)));
    connect(xs, SIGNAL(copyingMCAFiles(bool)), ui->killButton, SLOT(setDisabled(bool)));
    connect(xs, SIGNAL(copyingMCAFiles(bool)), ui->stopButton, SLOT(setDisabled(bool)));
    connect(ui->subrunsButton, SIGNAL(clicked()), xs, SLOT(lmViewLastTwo()));

    setWindowTitle("xiaStarter " + version);

    writeOutput("XiaStarter has been started!");
}

XiaStarterWindow::~XiaStarterWindow()
{
    delete ui;
    delete xs;
}

/*-----------------------------------changeStatus()--------------------------------
The Function changeStatusLabel() should setup the UI according to the programs current status.
It need a integer number to setup the status.

    1: Booting
    2: Not Booted
    3: Failed to boot DGF
    4: Failed to setup DGF
    5: Booted

At the moment it only changes the color and the textmessage of the statuslabel above the bootButton.
*/
void XiaStarterWindow::changeStatus(const int num){

    QString msg;
    QPalette palette= ui->statusLabel->palette();

    switch(num){
    case 1:
        palette.setColor(ui->statusLabel->backgroundRole(), Qt::yellow);
        palette.setColor(ui->statusLabel->foregroundRole(), Qt::black);
        ui->statusLabel->setPalette(palette);
        msg ="Booted!";
        ui->statusLabel->setText(msg);
        break;

    case 2:
        loadDefaultSettings();
        ui->tabWidget->setEnabled(0);
        ui->mcaStopButton->setEnabled(0);
        ui->statusLabel->setAutoFillBackground(true);
        ui->mcaTimeBox->setEnabled(0);

        palette.setColor(ui->statusLabel->backgroundRole(), Qt::red);
        palette.setColor(ui->statusLabel->foregroundRole(), Qt::black);
        ui->statusLabel->setPalette(palette);
        msg="Not Booted";
        ui->statusLabel->setText(msg);
        break;

    case 3:
        palette.setColor(ui->statusLabel->backgroundRole(), Qt::yellow);
        palette.setColor(ui->statusLabel->foregroundRole(), Qt::black);
        ui->statusLabel->setPalette(palette);
        ui->statusLabel->setText("Failed to boot DGF");
        break;

    case 4:
        palette.setColor(ui->statusLabel->backgroundRole(), Qt::yellow);
        palette.setColor(ui->statusLabel->foregroundRole(), Qt::black);
        ui->statusLabel->setPalette(palette);
        ui->statusLabel->setText("Failed to setup DGF");
        break;

    case 5:
        palette.setColor(ui->statusLabel->backgroundRole(), Qt::green);
        palette.setColor(ui->statusLabel->foregroundRole(), Qt::black);
        ui->statusLabel->setPalette(palette);
        ui->statusLabel->setText("Ready");
        ui->tabWidget->setEnabled(1);
        break;


    }
}

void XiaStarterWindow::writeOutput(const QString& msg){

        QDate date;
        date = QDate::currentDate();
        QTime t;
        t.start();
        QString output="[";
        output.append(date.toString());
        output.append(" | ");
        output.append(t.toString());
        output.append("] ");
        output.append(msg);
        ui->outputBox->appendPlainText(output);
        qDebug() << output;
}

void XiaStarterWindow::sourceconf_clicked(){
    sourceconfDialog *b = new sourceconfDialog(this);
    connect(b, SIGNAL(sourceConfChanged()), xs, SLOT(changeSourceConf()));
    b->exec();
}

void XiaStarterWindow::dgfconf_clicked(){

    QEventLoop dgfLoop;
    dgfConfig dgf;
    dgf.show();
    if(dgf.isVisible()){
        dgf.loadDets(xs->detnames);
    }
    dgfLoop.exec();
}

void XiaStarterWindow::on_bootButton_clicked(){    
}

void XiaStarterWindow::removeFile(){
    QString home, xsFile;
    home=getenv("HOME");
    xsFile=home+"/.xs/.xs";
    QDir temp(home);
    temp.remove(xsFile);
}

void XiaStarterWindow::on_closeButton_clicked()
{
    if(xs->runStopped){

        //Open log file and writing the header with the current date
        QString xsFolder=getenv("HOME");
        xsFolder+="/.xs/";
        QFile file(xsFolder+"xs.log");
        QString log=ui->outputBox->toPlainText();
        log+="\n\n\n";

        if(file.open(QIODevice::Append| QIODevice::Text)){
            file.write(log.toLatin1());
            file.close();
        }
    
        saveLastSettings();
        removeFile();
        close();
        }
        else{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Error: There is still a collector/writer running!");
            msgBox.exec();
        }
}

void XiaStarterWindow::about_clicked(){
    about a;
    a.exec();
}


void XiaStarterWindow::on_browseButton_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    xs->setDirname(dirname);
    ui->pathLine->setText(dirname);
    xs->setDir(dirname);

}

void XiaStarterWindow::on_runButton_clicked(){
    runCollector();
    //ui->collectorBox->setEnabled(0);
	xs->runStopped=false;
    ui->psaCheck->setEnabled(0);
    ui->runButton->setEnabled(0);
    ui->acheck->setEnabled(0);
    ui->gfltcheck->setEnabled(0);
    ui->ftpwidthcheck->setEnabled(0);
    ui->killButton->setEnabled(1);
    ui->ftpBox->setEnabled(0);
    ui->longcheck->setEnabled(0);
    ui->eventCheck->setEnabled(0);
    ui->eventBox->setEnabled(0);
    ui->coincBox->setEnabled(0);
    ui->coinccheck->setEnabled(0);
    ui->buffercheck->setEnabled(0);
}

void XiaStarterWindow::changeRunNum(int nummer){
    ui->runBox->setValue(nummer);
}
void XiaStarterWindow::changeSubrunNum(int number){
    ui->subrunBox->setValue(number);
}

void XiaStarterWindow::runCollector(){
#ifdef unbuffer
    QString program = "unbuffer mb_collector";
#endif
#ifndef unbuffer
    QString program = "mb_collector";
#endif

    //setup arguments

    if(ui->psaCheck->checkState()==Qt::Checked){
        program.append(" -x");
    }

    if(ui->buffercheck->checkState()==Qt::Checked){
        program.append(" -r");
    }

    if(ui->coinccheck->checkState()==Qt::Checked){
        QString num;

        num.setNum(ui->coincBox->value(),10);

        program.append(" -w ");
        program.append(num);
    }

    if(ui->eventCheck->checkState()==Qt::Checked){
        QString num;

        num.setNum(ui->eventBox->value());

        program.append(" -e ");
        program.append(num);
    }

    if(ui->ftpwidthcheck->checkState()==Qt::Checked){
        QString num;

        num.setNum(ui->ftpBox->value(),10);
        program.append(" -f ");
        program.append(num);
    }

    if(ui->gfltcheck->checkState()==Qt::Checked){
        program.append(" -g");
    }

    if(ui->acheck->checkState()==Qt::Checked){
        program.append(" -a");
    }

    if(ui->longcheck->checkState()==Qt::Checked){
        program.append(" -l");
    }

    xs->setProgram(program);
    ui->killButton->setEnabled(1);
    xs->startCollector();
}


void XiaStarterWindow::on_startButton_clicked()
{
    QApplication::beep();
    //check if Prefix-Box is empty or not
    //if empty, a messagebox will appear
        if(ui->pathLine->text()=="" || ui->prefixLine->text()==""){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Please choose a path AND a prefix for your runfiles!!!");
            msgBox.exec();
        }

        //if not empty, the folders will be created in the choosen path
        else{

			xs->setDirname(ui->pathLine->text());
			xs->setDir(ui->pathLine->text());
            xs->createRunFolders();
            xs->copyDGFsetups();

            for(unsigned int i=0; i<xs->rates.size(); i++){
                xs->rates.at(i).clear();
            }

            xs->ratestime.clear();
            xs->ratesLoop=0;


            if(xs->daqbuffer_clear()){

	

                ui->prefixLine->setEnabled(0);
                ui->runBox->setEnabled(0);
                ui->subrunBox->setEnabled(0);
                ui->timeBox->setEnabled(0);
                ui->timeCheck->setEnabled(0);
                ui->startButton->setEnabled(0);
                ui->pathBox->setEnabled(0);
                ui->undefinedloopRadio->setEnabled(0);
                ui->fixedloppRadio->setEnabled(0);
                ui->loopBox->setEnabled(0);
                ui->stopButton->setEnabled(1);
                ui->bootButton->setEnabled(0);
                ui->setupButton->setEnabled(0);
                ui->dgfconfButton->setEnabled(1);
                ui->sourceconfButton->setEnabled(1);
                ui->actionDgf_config->setEnabled(1);
                ui->actionSource_conf->setEnabled(1);
                ui->tab_2->setEnabled(0);
                ui->subrunBox->setValue(1);                
                xs->runStopped=false;
                xs->newWriterRun();
             }
        }
}

void XiaStarterWindow::on_stopButton_clicked(){

    qDebug()<< "Stopping Writer and Collector!";
    xs->runStopped=true;
    xs->killWriter();
    xs->killCollector();

    qDebug() << "Trying to stop the timer ...";
    xs->timer->deleteLater();

    qDebug() << "Enabling and disabling UI-objects";

    //Enable all disabled Objects at the UI and disables stopButton
    ui->tab_2->setEnabled(1);
    ui->prefixLine->setEnabled(1);
    ui->runBox->setEnabled(1);
    ui->subrunBox->setEnabled(1);
    ui->timeBox->setEnabled(1);
    ui->timeCheck->setEnabled(1);
    ui->startButton->setEnabled(1);
    ui->pathBox->setEnabled(1);
    ui->psaCheck->setEnabled(1);
    ui->stopButton->setEnabled(0);
    ui->bootButton->setEnabled(1);
    ui->setupButton->setEnabled(1);
    ui->dgfconfButton->setEnabled(1);
    ui->sourceconfButton->setEnabled(1);
    ui->actionDgf_config->setEnabled(1);
    ui->actionSource_conf->setEnabled(1);
    ui->tab_2->setEnabled(1);
    ui->runButton->setEnabled(1);
    ui->acheck->setEnabled(1);
    ui->gfltcheck->setEnabled(1);
    ui->ftpwidthcheck->setEnabled(1);
    ui->killButton->setEnabled(0);
    ui->ftpBox->setEnabled(1);
    ui->longcheck->setEnabled(1);
    ui->eventCheck->setEnabled(1);
    ui->eventBox->setEnabled(1);
    ui->coincBox->setEnabled(1);
    ui->coinccheck->setEnabled(1);
    ui->buffercheck->setEnabled(1);    
}

void XiaStarterWindow::on_mcaStartButton_clicked(){
    ui->tab->setEnabled(0);
	ui->mcaStartButton->setEnabled(0);
	ui->mcaTimeBox->setEnabled(0);
	ui->mcaSaveButton->setEnabled(0);

    if(ui->utimeRadio->isChecked()){
        xs->utimeradio=true;
        xs->ftimeradio=false;
        ui->mcaSaveButton->setEnabled(0);
		ui->mcaStopButton->setEnabled(1);
    }
    if(ui->ftimeRadio->isChecked()){
        xs->ftimeradio=true;
        xs->utimeradio=false;
        ui->mcaSaveButton->setEnabled(1);
		ui->mcaStopButton->setEnabled(1);

    }
    int num;
    num=ui->crateBox->value();
	mcaTimeNumber=num;
    xs->mcaCrate=num;
    mcaTimeNumber=ui->mcaTimeBox->value();
    xs->mcaTime=mcaTimeNumber;
    xs->mca_start();
    ui->tab->setEnabled(0);
    ui->tab_3->setEnabled(0);

}

void XiaStarterWindow::on_mcaStopButton_clicked()
{
    xs->mca_stop();
    ui->mcaStopButton->setEnabled(0);
    ui->mcaStartButton->setEnabled(1);
    ui->tab->setEnabled(1);
    ui->tab_3->setEnabled(1);
    ui->mcaTimeBox->setValue(mcaTimeNumber);
    ui->mcaTimeBox->setEnabled(1);
}

void XiaStarterWindow::on_mcaViewlatestButton_clicked()
{
    xs->mca_viewlatest();
}

void XiaStarterWindow::on_mcaReadoutButton_clicked()
{
    xs->mca_readout();
    readMCAFiles();
    plotMCAFiles();
	ui->mcaTimeBox->setValue(mcaTimeNumber);
	ui->mcaTimeBox->setEnabled(1);
	ui->mcaStartButton->setEnabled(1);
    ui->mcaSaveButton->setEnabled(1);
    ui->tab->setEnabled(1);
    ui->tab_3->setEnabled(1);

}

void XiaStarterWindow::plotRates(){

    if(xs->ratestime.size()>2){

        ui->ratesPlot->clearGraphs();
        ui->ratesPlot->setRangeDrag(Qt::Vertical);
        ui->ratesPlot->setRangeZoom(Qt::Vertical);

        if(xs->ratestime.size()>2){
            ui->ratesPlot->xAxis->setRange(xs->ratestime.at(0), xs->ratestime.at(xs->ratestime.size()-1));
        }
        else{
            qDebug() << "ERROR: ratestime.size() is too small to adjust xAxis of ratesPlot! (XiaStarterWindow::plotRates)";
        }

        ui->ratesPlot->xAxis->setLabel("Time elapsed [s]");
        ui->ratesPlot->yAxis->setLabel("Current rate [Hz]");

        QFont sansFont("Helvetica [Cronyx]", 8);
        ui->ratesPlot->legend->setFont(sansFont);
        ui->ratesPlot->legend->setVisible(1);
        ui->ratesPlot->legend->setPositionStyle(QCPLegend::psTopLeft);
        ui->ratesPlot->legend->setItemSpacing(0);
        ui->ratesPlot->legend->setMargin(10,10,0,1);

        int i=0;
        for(int j=0; j<xs->size; j++){
            if((int) xs->det.size()>j){
                if((showRatesFor==0) || (showRatesFor==1 && xs->det.at(j).getDetType()=="Germanium") || (showRatesFor==2 && xs->det.at(j).getDetType()=="Silicon")){
                    ui->ratesPlot->addGraph();
                    if((int) xs->detnames.size()>j){
                        switch(i){
                        case 0:
                            ui->ratesPlot->graph(0)->setPen(QPen(Qt::red));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 1:
                            ui->ratesPlot->graph(1)->setPen(QPen(Qt::green));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 2:
                            ui->ratesPlot->graph(2)->setPen(QPen(Qt::blue));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 3:
                            ui->ratesPlot->graph(3)->setPen(QPen(Qt::cyan));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 4:
                            ui->ratesPlot->graph(4)->setPen(QPen(Qt::darkCyan));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 5:
                            ui->ratesPlot->graph(5)->setPen(QPen(Qt::magenta));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 6:
                            ui->ratesPlot->graph(6)->setPen(QPen(Qt::darkMagenta));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 7:
                            ui->ratesPlot->graph(7)->setPen(QPen(Qt::black));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 8:
                            ui->ratesPlot->graph(8)->setPen(QPen(Qt::darkYellow));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 9:
                            ui->ratesPlot->graph(9)->setPen(QPen(Qt::gray));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 10:
                            ui->ratesPlot->graph(10)->setPen(QPen(Qt::darkBlue));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 11:
                            ui->ratesPlot->graph(11)->setPen(QPen(Qt::darkRed));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 12:
                            ui->ratesPlot->graph(12)->setPen(QPen(Qt::yellow));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 13:
                            ui->ratesPlot->graph(13)->setPen(QPen(Qt::darkGreen));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 14:
                            ui->ratesPlot->graph(14)->setPen(QPen(Qt::darkGray));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 15:
                            ui->ratesPlot->graph(15)->setPen(QPen(Qt::lightGray));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 16:
                            ui->ratesPlot->graph(16)->setPen(QPen(Qt::red));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 17:
                            ui->ratesPlot->graph(17)->setPen(QPen(Qt::red));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        case 18:
                            ui->ratesPlot->graph(18)->setPen(QPen(Qt::red));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        default:
                            ui->ratesPlot->graph(i)->setPen(QPen(Qt::red));
                            ui->ratesPlot->graph(i)->setName(xs->detnames.at(j));
                            break;
                        }
                    }
                    else{
                        qDebug() << "ERROR: detnames.at(j) does not exist! j=" << j << " (XiaStarterWindow::plotRates())";
                        continue;
                    }

                    ui->ratesPlot->graph(i)->setData(xs->ratestime, xs->rates.at(j));
                    i++;
                }
            }
            else{
                qDebug() << "ERROR: det.at(j) does not exist! j=" << j << " (XiaStarterWindow::plotRates())";
            }
        }

        ui->ratesPlot->rescaleAxes();
        ui->ratesPlot->legend->reArrange();
        ui->ratesPlot->replot();

        //scalerPlot
        ui->scalerPlot->clearPlottables();
        ui->scalerPlot->clearItems();
        //blueBars
        QCPBars *blueBars = new QCPBars(ui->scalerPlot->xAxis, ui->scalerPlot->yAxis);
        ui->scalerPlot->addPlottable(blueBars);
        //yellowBars
        QCPBars *yellowBars = new QCPBars(ui->scalerPlot->xAxis, ui->scalerPlot->yAxis);
        ui->scalerPlot->addPlottable(yellowBars);
        //redBars
        QCPBars *redBars = new QCPBars(ui->scalerPlot->xAxis, ui->scalerPlot->yAxis);
        ui->scalerPlot->addPlottable(redBars);

        QPen pen;
        pen.setColor(QColor(255, 131, 0));
        yellowBars->setPen(pen);
        yellowBars->setBrush(QColor(255, 131, 0, 50));

        pen.setColor(QColor(255,0,0));
        redBars->setPen(pen);
        redBars->setBrush(QColor(255,0,0,50));


        QVector<double> ticks;
        QVector<QString> labels;
        QVector<double> data_b, data_y, data_r;
        QVector<QCPItemText *> ratelabels;
        QString s_rate;
        double d_rate;

        for(unsigned int i=0; i<xs->rates.size(); i++){

           ticks << i+1;

           if(xs->detnames.size()>i){
            labels << xs->detnames.at(i);
           }
           else{
               qDebug() << "ERROR: detnames.at(i) does not exist! i="<<i<<" (XiaStarterWindow::plotRates()";
           }

            d_rate=xs->rates.at(i).at(xs->rates.at(i).size()-1);

            if(xs->det.size()>i){

                if(d_rate < xs->det.at(i).getIratesLimit()*0.67){
                    data_b.push_back(d_rate);
                    data_y.push_back(0);
                    data_r.push_back(0);
                }

                if(d_rate >= xs->det.at(i).getIratesLimit()*0.67 && d_rate < xs->det.at(i).getIratesLimit()){
                    data_b.push_back(0);
                    data_y.push_back(d_rate);
                    data_r.push_back(0);
                }

                if(d_rate >= xs->det.at(i).getIratesLimit()){
                    data_b.push_back(0);
                    data_y.push_back(0);
                    data_r.push_back(d_rate);
                }
            }
            else{
                qDebug() << "ERROR: det.at(i) does not exist! i="<<i<<" (XiaStarterWindow::plotRates)";
            }

            s_rate.setNum(d_rate);

            QCPItemText *labeldummy = new QCPItemText(ui->scalerPlot);
            ratelabels.push_back(labeldummy);
            if(ratelabels.size()>i){
                ui->scalerPlot->addItem(ratelabels.at(i));
            }
            else{
                qDebug() << "ERROR: ratelabels.at(i) does not exist! i="<<i<<" (XiaStarterWindow::plotRates())";
            }

            ratelabels.at(i)->setText(s_rate);
            ratelabels.at(i)->setFont(QFont(font().family(), 7));
            ratelabels.at(i)->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
            ratelabels.at(i)->position->setType(QCPItemPosition::ptPlotCoords);
            ratelabels.at(i)->position->setAxes(ui->scalerPlot->xAxis, ui->scalerPlot->yAxis);
            ratelabels.at(i)->position->setCoords(ticks.at(i), xs->rates.at(i).at(xs->rates.at(i).size()-1));
        }

        //configure xAxis
        ui->scalerPlot->xAxis->setAutoTicks(false);
        ui->scalerPlot->xAxis->setAutoTickLabels(false);
        ui->scalerPlot->xAxis->setTickVector(ticks);
        ui->scalerPlot->xAxis->setTickVectorLabels(labels);
        ui->scalerPlot->xAxis->setTickLabelRotation(-60);
        ui->scalerPlot->xAxis->setSubTickCount(0);
        ui->scalerPlot->xAxis->setTickLength(0, 1);
        ui->scalerPlot->xAxis->setGrid(false);
        ui->scalerPlot->xAxis->setRange(0, xs->detnames.size()+1);

        //configure yAxis
        ui->scalerPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
        ui->scalerPlot->yAxis->setScaleLogBase(10);
        ui->scalerPlot->yAxis->setPadding(2); // a bit more space to the left border
        ui->scalerPlot->yAxis->setLabel("Detector Rates\n[Hz]");
        ui->scalerPlot->yAxis->setSubGrid(true);
        ui->scalerPlot->yAxis->setRangeUpper(100000);
        ui->scalerPlot->yAxis->setRangeLower(1);

        blueBars->setData(ticks,data_b);
        yellowBars->setData(ticks,data_y);
        redBars->setData(ticks,data_r);
        ui->scalerPlot->replot();
    }
}

void XiaStarterWindow::on_pushButton_clicked(){}

void XiaStarterWindow::on_setupButton_clicked(){}

void XiaStarterWindow::collectorStatus(QProcess::ProcessState state){
    switch(state){
    case QProcess::Running:
        green1.setColor(ui->collectorLabel->backgroundRole(), Qt::green);
        green1.setColor(ui->collectorLabel->foregroundRole(), Qt::black);
        ui->collectorLabel->setPalette(green1);
        ui->collectorLabel->setText("Running");
        break;
    case QProcess::Starting:        
        yellow1.setColor(ui->collectorLabel->backgroundRole(), Qt::yellow);
        yellow1.setColor(ui->collectorLabel->foregroundRole(), Qt::black);
        ui->collectorLabel->setPalette(yellow1);
        ui->collectorLabel->setText("Starting");
        break;
    case QProcess::NotRunning:
        red1.setColor(ui->collectorLabel->backgroundRole(), Qt::red);
        red1.setColor(ui->collectorLabel->foregroundRole(), Qt::black);
        ui->collectorLabel->setPalette(red1);
        ui->collectorLabel->setText("Not Running");        
        break;
    }

}

void XiaStarterWindow::writerStatus(QProcess::ProcessState state){
    switch(state){
    case QProcess::Running:
        green2.setColor(ui->writerLabel->backgroundRole(), Qt::green);
        green2.setColor(ui->writerLabel->foregroundRole(), Qt::black);
        ui->writerLabel->setPalette(green2);
        ui->writerLabel->setText("Running");
        writeOutput("Writer is running.");
        break;
    case QProcess::Starting:
        yellow2.setColor(ui->writerLabel->backgroundRole(), Qt::yellow);
        yellow2.setColor(ui->writerLabel->foregroundRole(), Qt::black);
        ui->writerLabel->setPalette(yellow2);
        ui->writerLabel->setText("Starting");
        writeOutput("Writer is Starting.");
        break;
    case QProcess::NotRunning:
        red2.setColor(ui->writerLabel->backgroundRole(), Qt::red);
        red2.setColor(ui->writerLabel->foregroundRole(), Qt::black);
        ui->writerLabel->setPalette(red2);
        ui->writerLabel->setText("Not Running");
        writeOutput("Writer is NOT running.");
        break;
    }

}

void XiaStarterWindow::on_killButton_clicked()
{
    xs->killCollector();
    xs->runStopped=true;

    ui->runButton->setEnabled(1);
    ui->acheck->setEnabled(1);
    ui->gfltcheck->setEnabled(1);
    ui->ftpwidthcheck->setEnabled(1);
    ui->killButton->setEnabled(0);
    ui->ftpBox->setEnabled(1);
    ui->longcheck->setEnabled(1);
    ui->eventCheck->setEnabled(1);
    ui->eventBox->setEnabled(1);
    ui->coincBox->setEnabled(1);
    ui->coinccheck->setEnabled(1);
    ui->buffercheck->setEnabled(1);
    ui->psaCheck->setEnabled(1);

}

void XiaStarterWindow::setFileName(const QString &name){
    filename=name;
}

void XiaStarterWindow::newFileSize(const qint64 filesize){
    QString datasize;
    double s;
    s =(double) filesize/1000000;
    datasize.setNum(s);
    ui->sizeLabel->setText(datasize + " MB");
}

void XiaStarterWindow::showPreferences(){
    QEventLoop loop;
    p = new preferencedialog(this);
    connect(p, SIGNAL(detsChanged(std::vector<xs_det>)), xs, SLOT(changeDets(std::vector<xs_det>)));
    connect(p, SIGNAL(tabChanged(int)), this, SLOT(prefTabChanged(int)));    
    p->show();
    p->detectorsChanged(xs->det);
    loop.exec();
    xs->readCalList();
}

void XiaStarterWindow::prefTabChanged(int tab){
    switch(tab){
      case 0:
	 break;
      case 1:
    p->detectorsChanged(xs->det);
	break;
    }
}

void XiaStarterWindow::loadDefaultSettings(){
    xs->setRunNum(1);
    xs->setSubrunNum(1);
    xs->setudefloop(1);
    xs->setTime(10);
    xs->setPrefix("");
    xs->runStopped=true;

    ui->pathLine->setText("");

    //setup Checkbox default settings - LISTMODETAB
    ui->buffercheck->setChecked(1);
    ui->coinccheck->setChecked(1);
    ui->ftpwidthcheck->setChecked(1);
    ui->gfltcheck->setChecked(0);
    ui->acheck->setChecked(0);
    ui->longcheck->setChecked(0);
    ui->timeCheck->setChecked(1);
    ui->sizeCheck->setChecked(0);
    ui->fixedloppRadio->setChecked(0);
    ui->undefinedloopRadio->setChecked(1);


    //setup spinbox default values - LISTMODETAB
    ui->coincBox->setValue(55);
    ui->ftpBox->setValue(66);
    ui->timeBox->setValue(10);
    ui->sizeBox->setValue(1000);
    ui->loopBox->setValue(1);
    ui->runBox->setValue(1);
    ui->subrunBox->setValue(1);

    //setup checkbox default settings - MCATAB

    ui->crateBox->setValue(0);
    ui->utimeRadio->setChecked(1);
    ui->ftimeRadio->setChecked(0);
    ui->mcaSaveButton->setEnabled(0);

}

void XiaStarterWindow::loadLastSettings(){
    xs->loadDetSettings("./last.xss");
    QFile file("./last.xss");

    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,
                              "Load last settings",
                              "Couldn't open last.xss",
                              QMessageBox::Ok);
    }else{



    QXmlStreamReader xml(&file);

    while(!xml.atEnd()){
        /* Read next element.*/
        xml.readNext();

        if(xml.isStartDocument()){
            continue;
        }

        if(xml.isStartElement()){
            if(xml.name()=="pathLine"){
                xml.readNext();
				QString lol;
				lol = xml.text().toString();
                ui->pathLine->setText(lol);
				xs->setDirname(lol);
				xs->setDir(lol);
		
            }
            if(xml.name()=="prefixLine"){
                xml.readNext();
                ui->prefixLine->setText(xml.text().toString());
            }
 	    if(xml.name()=="psaCheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->psaCheck->setChecked(value.toInt());
            }
            if(xml.name()=="buffercheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->buffercheck->setChecked(value.toInt());
            }
            if(xml.name()=="eventCheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->eventCheck->setChecked(value.toInt());
            }
            if(xml.name()=="coinccheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->coinccheck->setChecked(value.toInt());
            }
            if(xml.name()=="ftpwidthcheck"){
                xml.readNext();
                QString value;
                value=(xml.text().toString());
                ui->ftpwidthcheck->setChecked(value.toInt());
            }
            if(xml.name()=="gfltcheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->gfltcheck->setChecked(value.toInt());
            }
            if(xml.name()=="acheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->acheck->setChecked(value.toInt());
            }
            if(xml.name()=="longcheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->longcheck->setChecked(value.toInt());
            }
            if(xml.name()=="sizeCheck"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->sizeCheck->setChecked(value.toInt());
            }
            if(xml.name()=="fixedloppRadio"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->fixedloppRadio->setChecked(value.toInt());
            }
            if(xml.name()=="undefinedloopRadio"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->undefinedloopRadio->setEnabled(value.toInt());
            }
            if(xml.name()=="eventBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->eventBox->setValue(value.toInt());
            }
            if(xml.name()=="coincBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->coincBox->setValue(value.toInt());
            }
            if(xml.name()=="ftpBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->ftpBox->setValue(value.toInt());
            }
            if(xml.name()=="timeBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->timeBox->setValue(value.toInt());
            }
            if(xml.name()=="sizeBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->sizeBox->setValue(value.toInt());
            }
            if(xml.name()=="loopBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->loopBox->setValue(value.toInt());
            }
            if(xml.name()=="runBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->runBox->setValue(value.toInt());
            }
            if(xml.name()=="subrunBox"){
                xml.readNext();
                QString value;
                value=xml.text().toString();
                ui->subrunBox->setValue(value.toInt());
            }
        }
    }
}
}

void XiaStarterWindow::saveLastSettings(){

    //storing path to xiaStarter folder into xsFolder
    QString xsFolder=getenv("HOME");
    xsFolder+="/.xs/";

    //Writing Settings into last.xss
    QFile settings(xsFolder+"last.xss");

    if(settings.open(QIODevice::WriteOnly)){
        QDate date;
        date=QDate::currentDate();

        QTime time;
        time=QTime::currentTime();

        QString value;

        QXmlStreamWriter xmlwriter(&settings);

        xmlwriter.setAutoFormatting(1);
        xmlwriter.writeStartDocument();
        xmlwriter.writeStartElement("XiaStarterSettings");
        xmlwriter.writeAttribute("date", date.toString());
        xmlwriter.writeAttribute("time", time.toString());

        //begin LISTMODE Settings
        xmlwriter.writeStartElement("ListmodeSettings");

        value=ui->pathLine->text();
        xmlwriter.writeTextElement("pathLine", value);

        value=ui->prefixLine->text();
        xmlwriter.writeTextElement("prefixLine", value);

        if(ui->psaCheck->isChecked()){
            xmlwriter.writeTextElement("psaCheck", "1");
        }else{
            xmlwriter.writeTextElement("psaCheck", "0");
        }

        if(ui->buffercheck->isChecked()){
            xmlwriter.writeTextElement("buffercheck", "1");
        }else{
            xmlwriter.writeTextElement("buffercheck", "0");
        }

        if(ui->eventCheck->isChecked()){
            xmlwriter.writeTextElement("eventCheck", "1");
        }else{
            xmlwriter.writeTextElement("eventCheck", "0");
        }

        if(ui->coinccheck->isChecked()){
            xmlwriter.writeTextElement("coinccheck", "1");
        }else{
            xmlwriter.writeTextElement("coinccheck", "0");
        }

        if(ui->ftpwidthcheck->isChecked()){
            xmlwriter.writeTextElement("ftpwidthcheck", "1");
        }else{
            xmlwriter.writeTextElement("ftpwidthcheck", "0");
        }

        if(ui->gfltcheck->isChecked()){
            xmlwriter.writeTextElement("gfltcheck", "1");
        }else{
            xmlwriter.writeTextElement("gfltcheck", "0");
        }

        if(ui->acheck->isChecked()){
            xmlwriter.writeTextElement("acheck", "1");
        }else{
            xmlwriter.writeTextElement("acheck", "0");
        }

        if(ui->longcheck->isChecked()){
            xmlwriter.writeTextElement("longcheck", "1");
        }else{
            xmlwriter.writeTextElement("longcheck", "0");
        }

        if(ui->timeCheck->isChecked()){
            xmlwriter.writeTextElement("timeCheck", "1");
        }else{
            xmlwriter.writeTextElement("timeCheck", "0");
        }

        if(ui->sizeCheck->isChecked()){
            xmlwriter.writeTextElement("sizeCheck", "1");
        }else{
            xmlwriter.writeTextElement("sizeCheck", "0");
        }

        if(ui->fixedloppRadio->isChecked()){
            xmlwriter.writeTextElement("fixedloppRadio", "1");
        }else{
            xmlwriter.writeTextElement("fixedloppRadio", "0");
        }

        if(ui->undefinedloopRadio->isChecked()){
            xmlwriter.writeTextElement("undefinedloopRadio", "1");
        }else{
            xmlwriter.writeTextElement("undefinedloopRadio", "0");
        }

        value.setNum(ui->eventBox->value());
        xmlwriter.writeTextElement("eventBox", value);

        value.setNum(ui->coincBox->value());
        xmlwriter.writeTextElement("coincBox", value);

        value.setNum(ui->ftpBox->value());
        xmlwriter.writeTextElement("ftpBox", value);

        value.setNum(ui->timeBox->value());
        xmlwriter.writeTextElement("timeBox", value);

        value.setNum(ui->sizeBox->value());
        xmlwriter.writeTextElement("sizeBox", value);

        value.setNum(ui->loopBox->value());
        xmlwriter.writeTextElement("loopBox", value);

        value.setNum(ui->runBox->value());
        xmlwriter.writeTextElement("runBox", value);

        value.setNum(ui->subrunBox->value());
        xmlwriter.writeTextElement("subrunBox", value);

        xmlwriter.writeEndElement();
        //end LISTMODE Settings

        //begin MCA Settings
        xmlwriter.writeStartElement("MCASettings");

        value.setNum(ui->crateBox->value());
        xmlwriter.writeTextElement("crateBox",value);

        value.setNum(ui->mcaTimeBox->value());
        xmlwriter.writeTextElement("mcaTimeBox",value);

        if(ui->utimeRadio->isChecked()){
            xmlwriter.writeTextElement("utimeRadio","1");
        }else{
            xmlwriter.writeTextElement("utimeRadio","0");
        }

        if(ui->ftimeRadio->isChecked()){
            xmlwriter.writeTextElement("ftimeRadio","1");
        }else{
            xmlwriter.writeTextElement("ftimeRadio","0");
        }

        xmlwriter.writeEndElement();
        //end MCA Settings

        //begin detector settings
        xmlwriter.writeStartElement("detectorSettings");
        xmlwriter.writeStartElement("calibrationFiles");
        for(unsigned int i=0; i< xs->det.size(); i++){
            xmlwriter.writeTextElement(xs->det.at(i).getName(), xs->det.at(i).getCalFilePath());
        }
        xmlwriter.writeEndElement();
        xmlwriter.writeStartElement("detectorTypes");
        for(unsigned int i=0; i< xs->det.size(); i++){
            xmlwriter.writeTextElement(xs->det.at(i).getName(), xs->det.at(i).getDetType());
        }
        xmlwriter.writeEndElement();
        xmlwriter.writeStartElement("ratesLimit");
        for(unsigned int i=0; i< xs->det.size(); i++){
            xmlwriter.writeTextElement(xs->det.at(i).getName(), xs->det.at(i).getRatesLimit());
        }
        xmlwriter.writeEndElement();
        xmlwriter.writeEndElement();
	//end detector settings

        xmlwriter.writeEndElement();
        xmlwriter.writeEndDocument();

        settings.close();
    }

    //Storing calibration File list into xs.cal in the xsFolder
    QFile calFile(xsFolder+"xs.cal");

    if(calFile.open(QIODevice::WriteOnly)){
        QString text="";
        for(unsigned int i=0; i<xs->det.size(); i++){
            text+=xs->det.at(i).getCalFilePath();
            text+="\n";
        }
        calFile.write(text.toAscii());
    }
    calFile.close();
}

void XiaStarterWindow::showInfo(){
    QMessageBox info(QMessageBox::Information, "xiaStarter Info", "xiaStarter " + version + "\n\nxiaStarter is a Graphical User Interface-Program for the digital data aquisition with the Miniball Acquisition Code by Nigel Warr.\n\n2012-2013 Philipp Scholz");
    info.exec();
}

void XiaStarterWindow::viewButtons(bool b){
    ui->latestButton->setEnabled(b);
    ui->allButton->setEnabled(b);
}

void XiaStarterWindow::on_mcaSaveButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    xs->mca_saveSpectra(directory);    
    writeOutput("MCA Spectra were saved to "+directory);
}

void XiaStarterWindow::writeInfoBox(QString dataFile, QString runNum, QString subRunNum){
    QString info="";
    info+="   Current Listmode-file: ..."+dataFile.right(50)+"\n";
    info+="   Current Run Number: "+runNum+"\n";
    info+="   Current Subrun Number: "+subRunNum+"\n";
    info+="\n   Rates:\n";

    switch(ui->detCombo->currentIndex()){
        case 0:
            for(unsigned int i=0; i<xs->det.size(); i++){
                if(xs->rates.size()>i){
                    if(xs->detnames.size()>i){
                        info+="\t"+xs->detnames.at(i) + ":\t" + QString::number(xs->rates.at(i).last())+"\n";
                    }
                    else{
                        qDebug() << "ERROR: detnames.at(i) does not exist! i="<<i<<" (XiaStarterWindow::writeInfoBox())";
                    }
                }
                else{
                    qDebug() << "ERROR: rates.at(i) does not exist! i="<<i<<" (XiaStarterWindow::writeInfoBox())";
                }
            }
            break;

        case 1:
            for(unsigned int i=0; i<xs->det.size(); i++){
                if(xs->det.at(i).getDetType()=="Germanium"){
                    if(xs->rates.size()>i){
                        if(xs->detnames.size()>i){
                            info+="\t"+xs->detnames.at(i) + ":\t" + QString::number(xs->rates.at(i).last())+"\n";
                        }
                        else{
                            qDebug() << "ERROR: detnames.at(i) does not exist! i="<<i<<" (XiaStarterWindow::writeInfoBox())";
                        }
                    }
                    else{
                        qDebug() << "ERROR: rates.at(i) does not exist! i="<<i<<" (XiaStarterWindow::writeInfoBox())";
                    }
                }
            }
            break;

        case 2:
            for(unsigned int i=0; i<xs->det.size(); i++){
                if(xs->det.at(i).getDetType()=="Silicon"){
                    if(xs->rates.size()>i){
                        if(xs->detnames.size()>i){
                            info+="\t"+xs->detnames.at(i) + ":\t" + QString::number(xs->rates.at(i).last())+"\n";
                        }
                        else{
                            qDebug() << "ERROR: detnames.at(i) does not exist! i="<<i<<" (XiaStarterWindow::writeInfoBox())";
                        }
                    }
                    else{
                        qDebug() << "ERROR: rates.at(i) does not exist! i="<<i<<" (XiaStarterWindow::writeInfoBox())";
                    }
                }
            }
            break;
    }

    ui->infoBox->setPlainText(info);
}

void XiaStarterWindow::readMCAFiles(){
    mcaCounts.clear();
    mcaChannels.clear();

    for(unsigned int i=0; i<xs->det.size(); i++){
        QString source;
        QVector<double> dummyCounts;
        QVector<double> dummyChannels;

        source=hwHistDir+"DGF_";
        source+= xs->det.at(i).getCrate();
        int m=xs->det.at(i).getIslot();

        if(m <= 9){
            source+="_0";
        }
        else{
            source+="_";
        }
        source+= xs->det.at(i).getSlot();
        source+="_";
        source+= xs->det.at(i).getAddress();
        source+=".spc";

        //converting QString to char*
        QByteArray ba = source.toLatin1();
        char *c_source = ba.data();

        MFILE *in_spc = mopen(c_source,"r");
        if (!in_spc) {
                qDebug() << "cannot open inputfile for reading!";
        }else{
            minfo info;
            mgetinfo(in_spc, &info);
            info.filetype=14; //MAT_TXT

            int buffer[info.columns];
            mgetint(in_spc,buffer,0,0,0,info.columns);
            mclose(in_spc);

            for (int j=0;j<(int)info.columns;j++){
                    dummyCounts.push_back((double) buffer[j]);
                    dummyChannels.push_back((double) j);
            }

            mcaCounts.push_back(dummyCounts);
            mcaChannels.push_back(dummyChannels);
        }
    }

}

void XiaStarterWindow::plotMCAFiles(){
    ui->mcaPlot->clearGraphs();
    //ui->mcaPlot->setRangeDrag(Qt::Vertical| Qt::Horizontal);
    //ui->mcaPlot->setRangeZoom(Qt::Vertical| Qt::Horizontal);
    //ui->mcaPlot->xAxis->setRangeLower(0);
    //ui->mcaPlot->xAxis->setRangeUpper(30000);

    for(unsigned int i=0; i<mcaCounts.size(); i++){
        ui->mcaPlot->addGraph();
        if(xs->detnames.size()>i){
            switch(i){
            case 0:
                ui->mcaPlot->graph(0)->setPen(QPen(Qt::red));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 1:
                ui->mcaPlot->graph(1)->setPen(QPen(Qt::green));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 2:
                ui->mcaPlot->graph(2)->setPen(QPen(Qt::blue));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 3:
                ui->mcaPlot->graph(3)->setPen(QPen(Qt::cyan));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 4:
                ui->mcaPlot->graph(4)->setPen(QPen(Qt::darkCyan));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 5:
                ui->mcaPlot->graph(5)->setPen(QPen(Qt::magenta));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 6:
                ui->mcaPlot->graph(6)->setPen(QPen(Qt::darkMagenta));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 7:
                ui->mcaPlot->graph(7)->setPen(QPen(Qt::black));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 8:
                ui->mcaPlot->graph(8)->setPen(QPen(Qt::darkYellow));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 9:
                ui->mcaPlot->graph(9)->setPen(QPen(Qt::gray));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 10:
                ui->mcaPlot->graph(10)->setPen(QPen(Qt::darkBlue));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 11:
                ui->mcaPlot->graph(11)->setPen(QPen(Qt::darkRed));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 12:
                ui->mcaPlot->graph(12)->setPen(QPen(Qt::yellow));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 13:
                ui->mcaPlot->graph(13)->setPen(QPen(Qt::darkGreen));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 14:
                ui->mcaPlot->graph(14)->setPen(QPen(Qt::darkGray));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 15:
                ui->mcaPlot->graph(15)->setPen(QPen(Qt::lightGray));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 16:
                ui->mcaPlot->graph(16)->setPen(QPen(Qt::red));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 17:
                ui->mcaPlot->graph(17)->setPen(QPen(Qt::red));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            case 18:
                ui->mcaPlot->graph(18)->setPen(QPen(Qt::red));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            default:
                ui->mcaPlot->graph(i)->setPen(QPen(Qt::red));
                ui->mcaPlot->graph(i)->setName(xs->detnames.at(i));
                break;
            }
        }
        else{
            qDebug() << "ERROR: detnames.at(i) does not exist! i=" << i << " (XiaStarterWindow::plotMCAFiles())";
            continue;
        }

        if(mcaChannels.size()>i){
            ui->mcaPlot->graph(i)->setData(mcaChannels.at(i), mcaCounts.at(i));
        }
        else{
            qDebug() << "ERROR: mcaChannels.at(i) does not exist! i=" << i << " (XiaStarterWindow::plotMCAFiles())";
        }
    }

    ui->mcaPlot->rescaleAxes();
    ui->mcaPlot->legend->reArrange();

    ui->mcaPlot->replot();

}

void XiaStarterWindow::saveSettings(){
    QFile settings(saveFileName);

    if(settings.open(QIODevice::WriteOnly)){
        QDate date;
        date=QDate::currentDate();

        QTime time;
        time=QTime::currentTime();

        QString value;

        QXmlStreamWriter xmlwriter(&settings);

        xmlwriter.setAutoFormatting(1);
        xmlwriter.writeStartDocument();
        xmlwriter.writeStartElement("XiaStarterSettings");
        xmlwriter.writeAttribute("date", date.toString());
        xmlwriter.writeAttribute("time", time.toString());

        //begin LISTMODE Settings
        xmlwriter.writeStartElement("ListmodeSettings");

        value=ui->pathLine->text();
        xmlwriter.writeTextElement("pathLine", value);

        value=ui->prefixLine->text();
        xmlwriter.writeTextElement("prefixLine", value);

        if(ui->psaCheck->isChecked()){
            xmlwriter.writeTextElement("psaCheck", "1");
        }else{
            xmlwriter.writeTextElement("psaCheck", "0");
        }

        if(ui->buffercheck->isChecked()){
            xmlwriter.writeTextElement("buffercheck", "1");
        }else{
            xmlwriter.writeTextElement("buffercheck", "0");
        }

        if(ui->eventCheck->isChecked()){
            xmlwriter.writeTextElement("eventCheck", "1");
        }else{
            xmlwriter.writeTextElement("evenCheck", "0");
        }

        if(ui->coinccheck->isChecked()){
            xmlwriter.writeTextElement("coinccheck", "1");
        }else{
            xmlwriter.writeTextElement("coinccheck", "0");
        }

        if(ui->ftpwidthcheck->isChecked()){
            xmlwriter.writeTextElement("ftpwidthcheck", "1");
        }else{
            xmlwriter.writeTextElement("ftpwidthcheck", "0");
        }

        if(ui->gfltcheck->isChecked()){
            xmlwriter.writeTextElement("gfltcheck", "1");
        }else{
            xmlwriter.writeTextElement("gfltcheck", "0");
        }

        if(ui->acheck->isChecked()){
            xmlwriter.writeTextElement("acheck", "1");
        }else{
            xmlwriter.writeTextElement("acheck", "0");
        }

        if(ui->longcheck->isChecked()){
            xmlwriter.writeTextElement("longcheck", "1");
        }else{
            xmlwriter.writeTextElement("longcheck", "0");
        }

        if(ui->timeCheck->isChecked()){
            xmlwriter.writeTextElement("timeCheck", "1");
        }else{
            xmlwriter.writeTextElement("timeCheck", "0");
        }

        if(ui->sizeCheck->isChecked()){
            xmlwriter.writeTextElement("sizeCheck", "1");
        }else{
            xmlwriter.writeTextElement("sizeCheck", "0");
        }

        if(ui->fixedloppRadio->isChecked()){
            xmlwriter.writeTextElement("fixedloppRadio", "1");
        }else{
            xmlwriter.writeTextElement("fixedloppRadio", "0");
        }

        if(ui->undefinedloopRadio->isChecked()){
            xmlwriter.writeTextElement("undefinedloopRadio", "1");
        }else{
            xmlwriter.writeTextElement("undefinedloopRadio", "0");
        }

        value.setNum(ui->eventBox->value());
        xmlwriter.writeTextElement("eventBox", value);

        value.setNum(ui->coincBox->value());
        xmlwriter.writeTextElement("coincBox", value);

        value.setNum(ui->ftpBox->value());
        xmlwriter.writeTextElement("ftpBox", value);

        value.setNum(ui->timeBox->value());
        xmlwriter.writeTextElement("timeBox", value);

        value.setNum(ui->sizeBox->value());
        xmlwriter.writeTextElement("sizeBox", value);

        value.setNum(ui->loopBox->value());
        xmlwriter.writeTextElement("loopBox", value);

        value.setNum(ui->runBox->value());
        xmlwriter.writeTextElement("runBox", value);

        value.setNum(ui->subrunBox->value());
        xmlwriter.writeTextElement("subrunBox", value);

        xmlwriter.writeEndElement();
        //end LISTMODE Settings

        //begin MCA Settings
        xmlwriter.writeStartElement("MCASettings");

        value.setNum(ui->crateBox->value());
        xmlwriter.writeTextElement("crateBox",value);

        value.setNum(ui->mcaTimeBox->value());
        xmlwriter.writeTextElement("mcaTimeBox",value);

        if(ui->utimeRadio->isChecked()){
            xmlwriter.writeTextElement("utimeRadio","1");
        }else{
            xmlwriter.writeTextElement("utimeRadio","0");
        }

        if(ui->ftimeRadio->isChecked()){
            xmlwriter.writeTextElement("ftimeRadio","1");
        }else{
            xmlwriter.writeTextElement("ftimeRadio","0");
        }

        xmlwriter.writeEndElement();
        //end MCA Settings

        //begin detector settings
        xmlwriter.writeStartElement("detectorSettings");
        xmlwriter.writeStartElement("calibrationFiles");
        for(unsigned int i=0; i< xs->det.size(); i++){
            xmlwriter.writeTextElement(xs->det.at(i).getName(), xs->det.at(i).getCalFilePath());
        }
        xmlwriter.writeEndElement();
        xmlwriter.writeStartElement("detectorTypes");
        for(unsigned int i=0; i< xs->det.size(); i++){
            xmlwriter.writeTextElement(xs->det.at(i).getName(), xs->det.at(i).getDetType());
        }
        xmlwriter.writeEndElement();
        xmlwriter.writeStartElement("ratesLimit");
        for(unsigned int i=0; i< xs->det.size(); i++){
            xmlwriter.writeTextElement(xs->det.at(i).getName(), xs->det.at(i).getRatesLimit());
        }
        xmlwriter.writeEndElement();
        xmlwriter.writeEndElement();

        //end detector settings

        xmlwriter.writeEndElement();
        xmlwriter.writeEndDocument();

        settings.close();
    }

}

void XiaStarterWindow::saveAsSettings(){

    saveFileName=QFileDialog::getSaveFileName(this,tr("Save file"), tr("./"), tr("*.xss"));
    if(saveFileName!=""){
        if(saveFileName.right(4)!=".xss") saveFileName.append(".xss");
        emit saveFileNameIsNotEmpty(true);
        saveSettings();
    }
}

void XiaStarterWindow::loadSettingsFile(){
    QString settingsFile;
    settingsFile=QFileDialog::getOpenFileName(this, tr("Open a XiaStarterSettings file"), tr("./"), tr("*.xss"));

    xs->loadDetSettings(settingsFile);

    QFile file(settingsFile);

    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,
                              "Load last settings",
                              "Couldn't open ..."+settingsFile.right(20),
                              QMessageBox::Ok);
    }
    else{



        QXmlStreamReader xml(&file);

        while(!xml.atEnd()){
            /* Read next element.*/
            xml.readNext();

            if(xml.isStartDocument()){
                continue;
            }

            if(xml.isStartElement()){
                if(xml.name()=="pathLine"){
                    xml.readNext();
					QString lol;
					lol= xml.text().toString();
                    ui->pathLine->setText(lol);
					xs->setDirname(lol);
					xs->setDir(lol);
                }
                if(xml.name()=="prefixLine"){
                    xml.readNext();
                    ui->prefixLine->setText(xml.text().toString());
                }
		if(xml.name()=="psaCheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->psaCheck->setChecked(value.toInt());
                }
                if(xml.name()=="buffercheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->buffercheck->setChecked(value.toInt());
                }
                if(xml.name()=="coinccheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->coinccheck->setChecked(value.toInt());
                }
                if(xml.name()=="ftpwidthcheck"){
                    xml.readNext();
                    QString value;
                    value=(xml.text().toString());
                    ui->ftpwidthcheck->setChecked(value.toInt());
                }
                if(xml.name()=="gfltcheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->gfltcheck->setChecked(value.toInt());
                }
                if(xml.name()=="acheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->acheck->setChecked(value.toInt());
                }
                if(xml.name()=="longcheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->longcheck->setChecked(value.toInt());
                }
                if(xml.name()=="sizeCheck"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->sizeCheck->setChecked(value.toInt());
                }
                if(xml.name()=="fixedloppRadio"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->fixedloppRadio->setChecked(value.toInt());
                }
                if(xml.name()=="undefinedloopRadio"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->undefinedloopRadio->setEnabled(value.toInt());
                }
                if(xml.name()=="coincBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->coincBox->setValue(value.toInt());
                }
                if(xml.name()=="ftpBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->ftpBox->setValue(value.toInt());
                }
                if(xml.name()=="timeBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->timeBox->setValue(value.toInt());
                }
                if(xml.name()=="sizeBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->sizeBox->setValue(value.toInt());
                }
                if(xml.name()=="loopBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->loopBox->setValue(value.toInt());
                }
                if(xml.name()=="runBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->runBox->setValue(value.toInt());
                }
                if(xml.name()=="subrunBox"){
                    xml.readNext();
                    QString value;
                    value=xml.text().toString();
                    ui->subrunBox->setValue(value.toInt());
                }
            }
        }
    }
}

void XiaStarterWindow::ratesContextMenuRequest(QPoint pos){
    QMenu *menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);

    menu->addAction("show All", this, SLOT(showAll()));
    menu->addAction("show Germaniums", this, SLOT(showGe()));
    menu->addAction("show Silicons", this, SLOT(showSi()));

    menu->popup(ui->ratesPlot->mapToGlobal(pos));
}

void XiaStarterWindow::showAll(){
    showRatesFor=0;
    plotRates();
}

void XiaStarterWindow::showGe(){
    showRatesFor=1;
    plotRates();
}

void XiaStarterWindow::showSi(){
    showRatesFor=2;
    plotRates();
}

void XiaStarterWindow::showSubrunPopup(){

}

void XiaStarterWindow::detComboBox(int choice){
    switch(choice){
        case 0: xs->showDets=0;
                break;
        case 1: xs->showDets=1;
                break;
        case 2: xs->showDets=2;
                break;
    }
}
