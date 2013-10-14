/******************************************************************************

    xiastarter.cpp

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

#include "xiastarter.h"
#include <QProcess>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include "xs_det.h"
#include <QDebug>
#include <QTimer>
#include <QByteArray>
#include <QStringList>
#include <QVector>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QInputDialog>

//If you uncomment the next line, there will be some additional output to the qDebug() Stream
//#define debug
//#define debugNWR
//#define debugrates

XiaStarter::XiaStarter(QObject *parent) :
    QObject(parent)
{
	//Getting environment variables
    QString configDir(getenv("MB_CONFIG_DIR"));
    sourceConfPath = configDir+"/source.conf";

    QString histDir(getenv("HW_HIST_DIR"));
    hwHistDir=histDir+"/";

    readSourceConf();    

#ifdef debug
	writeSourceConf();
#endif

    t.start();
	//setup the arrays for the rates and the detector names
	QVector<double> dummy;

    for(unsigned int i=0; i<det.size(); i++){
        rates.push_back(dummy);
    }

    for(unsigned int i=0; i<det.size(); i++){
        if(i<det.size()){
            detnames.push_back(det.at(i).getName());
        }
        else{
            qDebug() << "ERROR: det.at(i) does not exist! i="<< i <<" (XiaStarter::XiaStarter())";
            continue;
        }
    }

	//There is no running run
    runStopped=false;

    mcaRates=0;
	showDets=0;

	//reading xs.cal
    readCalList();

    connect(this, SIGNAL(newShowRates(QString)), this, SLOT(getMCARates(QString)));

}

/*--------------------------------changeSourceConf()---------------------------*/
/*This function is called if the source.conf file has been changed. It deletes 
all entries of the det-vector and calls readSourceConf() again.*/
void XiaStarter::changeSourceConf(){
    for(int i=0; i<size; i++){
        det.pop_back();
    }
    readSourceConf();
}

/*--------------------------------readSourceConf()---------------------------*/
/*This function will be called if one will construct a XiaStarter-Object. It 
reads the all information stored in the source.conf file into a class called 
xs_det. The information is now available in a vektor of type xs_det called "det".*/
void XiaStarter::readSourceConf(){
    QStringList lines;
    QString text, line;

    QFile file(sourceConfPath);

    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
            QTextStream in(&file);

            while(!in.atEnd()){
                /*Here the reading of the file starts line by line.
                  Every line will be append with a linebreak flag
                  before it is going to be added to a string, which
                  contains the whole file. Lines which contain "#"
                  will be ignored.*/
                line=in.readLine().append("\n");
                if(!line.contains("#")){
                    text.append(line);
                }
            }
            file.close();
            lines = text.split("\n");
            QStringList values[lines.size()]; //Array of QStringlists of size of the number of lines

            for(int i=0; i<lines.size()-1; i++){
                if(i<lines.size()){
                    if(lines.at(i).size()>0){
                        values[i] = lines.at(i).split(QRegExp( "[ \\t]+"), QString::SkipEmptyParts);
                    }
                }
                else{
                    qDebug() << "ERROR: lines.at(i) does not exist! i="<< i <<" (XiaStarter::readSourceConf())";
                    continue;
                }
            }

            for(int i=0; i<lines.size()-1; i++){
                xs_det dummy;

                if(!values[i].size()) continue;

                if(values[i].size()>=6){
                    dummy.setType(values[i].at(0));
                    dummy.setName(values[i].at(1));
                    dummy.setDgfmodule(values[i].at(2));
                    dummy.setCrate(values[i].at(3));
                    dummy.setSlot(values[i].at(4));
                    dummy.setIslot(values[i].at(4).toInt());
                    dummy.setAddress(values[i].at(5));
                }
                else{
                    qDebug() << "ERROR: values[i].at(5) does not exist! i="<< i <<" (XiaStarter::readSourceConf())";
                    continue;
                }

                    det.push_back(dummy);
            }

        }
        else{
            emit textOutput("ERROR: Could not open source.conf!");
            qDebug() << "ERROR: Could not open source.conf!";

        }

    }
    else{
        emit textOutput("ERROR:Could not read source.conf!");
        qDebug() << "ERROR: Could not read source.conf!";
    }

    size=det.size();
}
/*------------------------------------writeSourceConf()-------------------------------------*/
void XiaStarter::writeSourceConf(){
    for(unsigned int i=0; i<det.size(); i++){
        QString msg;
        msg = det.at(i).getType();
        msg += "\t";
        msg += det.at(i).getName();
        msg += "\t";
        msg += det.at(i).getDgfmodule();
        msg += "\t";
        msg += det.at(i).getCrate();
        msg += "\t";
        msg += det.at(i).getSlot();
        msg += "\t";
        msg += det.at(i).getAddress();

        qDebug() << msg << endl;
    }
}

/*------------------------------------startBootProcedure()-------------------------------------*/
void XiaStarter::startBootProcedure(){

    emit statusChanged(1);
    emit textOutput("Trying to boot ...");

    if(boot_dgf()){
        emit textOutput("Error: Failed to boot DGF");
        emit statusChanged(3);
    }
    else{
        emit textOutput("Success: DGF booted!");
    }
}
/*------------------------------------startSetupProcedure()-------------------------------------*/
void XiaStarter::startSetupProcedure(){
    if(setup_dgf()){
        emit textOutput("Error: Failed to setup DGF");
    }
    else{
    emit textOutput("Success: Setup DGF!");
        emit statusChanged(5);
        emit textOutput("XiaStarter is ready!");
    }
}

/*-----------------------------------boot_dgf()--------------------------------------------*/
/*This function will start the mb_boot_dgf program to boot the DGF modules. 
It returns the Exitcode of the mb_boot_dgf program as an interger.*/
int XiaStarter::boot_dgf(){
    QString bootprogram = "mb_boot_dgf";
    int exit;
    boot = new QProcess(this);
    exit= boot->execute(bootprogram);
    return exit;
}


/*-----------------------------------setup_dgf()--------------------------------*/
/*This function will start the mb_setup_dgf program to boot the DGF modules. 
It returns the Exitcode of the mb_setup_dgf program as an interger.*/

int XiaStarter::setup_dgf(){
    QString setupprogram = "mb_setup_dgf";
    int exit;
    setup= new QProcess(this);
    exit= setup->execute(setupprogram);
    return exit;
}

/*------------------------------The "set"-functions------------------------------*/
/*The following public member functions are used to set the private variables of 
the XiaStarter-Class.*/

void XiaStarter::setDirname(const QString& string){
    dirname=string;
}

void XiaStarter::setDir(const QString& dirname){
    dir.setPath(dirname);
}

void XiaStarter::setProgram(const QString &string){
    program=string;
}

void XiaStarter::setSubrunNum(int number){
    subrunnum=number;
}

void XiaStarter::setRunNum(int number){
    runnum=number;
}

void XiaStarter::setTime(int number){
    time=number;
}

void XiaStarter::setPrefix(QString string){
    prefix=string;
}

void XiaStarter::setudefloop(bool check){
    udefloop=check;
}

void XiaStarter::setLoopint(int number){
    loopint=number;
}

void XiaStarter::setLoopRunint(int number){
    lRunint=number;
}

void XiaStarter::setMCAtime(QString number){
    mcatime = number;
}

void XiaStarter::setUTimeRadio(bool check){
    utimeradio=check;
}

void XiaStarter::setFTimeRadio(bool check){
    ftimeradio=check;
}

void XiaStarter::setTVRadio(bool check){
    tvradio=check;
}

void XiaStarter::setHDTVRadio(bool check){
    hdtvradio=check;
}

void XiaStarter::setCrate(QString string){
    crate=string;
}


/*----------------------------startCollector()-----------------------------------*/
void XiaStarter::startCollector(){

    collector = new QProcess(this);

    connect(collector, SIGNAL(started()), this, SLOT(getRates()));
    connect(collector, SIGNAL(error(QProcess::ProcessError)), this, SLOT(collectorError(QProcess::ProcessError)));
    connect(collector, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(collectorStateChanged(QProcess::ProcessState)));
    connect(collector, SIGNAL(readyReadStandardError()), this, SLOT(showStdtErrorBox()));


    collector->start(program);
    t.restart();

}

void XiaStarter::collectorError(QProcess::ProcessError error){
    switch(error){
    case QProcess::FailedToStart:
        emit textOutput("Collector ERROR CODE 0: Failed to start!");
        break;
    case QProcess::Crashed:
        qDebug() << "Collector ERROR CODE 1: Crashed!";
        break;
    case QProcess::Timedout:
        emit textOutput("Collector ERROR CODE 2: Timed Out!");
        break;
    case QProcess::WriteError:
        emit textOutput("Collector ERROR CODE 3: Writing Error!");
        break;
    case QProcess::ReadError:
        emit textOutput("Collector ERROR CODE 4: Reading Error!");
        break;
    case QProcess::UnknownError:
        emit textOutput("Collector ERROR CODE 5: Unknown Error!");
        break;
    }

}

void XiaStarter::collectorStateChanged(QProcess::ProcessState newState){
    emit collectorState(newState);

}

/*----------------------------startWriter()--------------------------------------*/
void XiaStarter::startWriter(){

#ifdef debug
    qDebug() << time << endl;
#endif
    qDebug()<< "Trying to start Writer ...";
#ifdef debugNWR
        qDebug() << "Writer->state()!=Running";
#endif
        writer = new QProcess(this);
        connect(writer, SIGNAL(started()), this, SLOT(writerStarted()));
        connect(writer, SIGNAL(error(QProcess::ProcessError)), this, SLOT(writerError(QProcess::ProcessError)));
        connect(writer, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(writerStateChanged(QProcess::ProcessState)));
        connect(writer, SIGNAL(readyReadStandardError()), this, SLOT(showStdtErrorBox()));

        writer->start(program);
        qDebug() <<"Wait for Writer to be started ...";
}

void XiaStarter::writerStarted(){
#ifdef debugNWR
    qDebug() <<"writer.started() signal was emitted";
#endif
    timer=new QTimer(this);
    timer->setInterval(time*60*1000);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),SLOT(writerTimeOut()));
    timer->start();
}

void XiaStarter::writerError(QProcess::ProcessError error){
    switch(error){
    case QProcess::FailedToStart:
        emit textOutput("Writer ERROR CODE 0: Failed to start!");
        break;
    case QProcess::Crashed:
        qDebug() << "Writer ERROR CODE 1: Crashed!";
        break;
    case QProcess::Timedout:
        emit textOutput("Writer ERROR CODE 2: Timed Out!");
        break;
    case QProcess::WriteError:
        emit textOutput("Writer ERROR CODE 3: Writing Error!");
        break;
    case QProcess::ReadError:
        emit textOutput("Writer ERROR CODE 4: Reading Error!");
        break;
    case QProcess::UnknownError:
        emit textOutput("Writer ERROR CODE 5: Unknown Error!");
        break;
    }
}
void XiaStarter::writerStateChanged(QProcess::ProcessState newState){
    emit writerState(newState);

}


/*-----------------------------request_mca_readout()---------------------------*/
void XiaStarter::mb_request_mca_readout(){
    readout= new QProcess(this);
    emit textOutput("Reading Out MCA files ...");
    readout->start("mb_request_mca_readout");
    sleeptimer =new QTimer(this);
    sleeptimer->singleShot(20*1000, this, SLOT(copyMCAFiles()));
    emit viewButtons(0);
}

/*--------------------------copyMODStats()---------------------------------------*/
void XiaStarter::copyMODStats(){
    emit copyingMODFiles(true);
    int s[25], slot;
  
    for(int i=0; i<25; i++){
        s[i]=0;
    }

    #ifdef debug
        qDebug() << "Checking which slots are occupied ..." << endl;
    #endif

     for(unsigned int i=0; i<det.size(); i++){
        int j=det.at(i).getIslot();
        if(s[j]!=1){
            s[j]=1;
        }
    }

    #ifdef debug
        qDebug() << "Starting with Mainloop of copyMODStats() ..." << endl;
    #endif

    emit textOutput("Copy MOD files ...");

    for(int i=0; i<25; i++){
        if(s[i]){
            slot=i;
            #ifdef debug
                qDebug() << "Trying to get dgf_show data ..." << endl;
            #endif
            if(collector->state()==QProcess::Running){
                dgfshow = new QProcess(this);
                QString prog="dgf_show ",sl;
                sl.setNum(slot);
                prog.append("0:"+sl);

                #ifdef debug
                    qDebug() << "Nein?" << endl;
                #endif


                #ifdef debug
                    qDebug() << "Trying to read in data..." << endl;
                #endif

                dir.setPath(mod_root);

                QString subrun, folder="", path, pos;

                subrun.setNum(subrunnum-1);

                if(subrunnum-1<10){
                    folder.append("000");
                }

                if(subrunnum-1>=10 && subrunnum-1<100){
                    folder.append("00");
                }

                if(subrunnum-1>=100 && subrunnum-1<1000){
                    folder.append("0");
                }
                folder.append(subrun);
                dir.mkdir(folder);
                dir.cd(folder);

                path=dir.path();
                pos.setNum(slot);
                path.append("/mod"+pos+".stat");

                dgfshow->setStandardOutputFile(path);
                  #ifdef debug
                        emit textOutput(prog + " started!");
                  #endif
                  dgfshow->start(prog);
                  if(dgfshow->waitForFinished(-1)){
                  #ifdef debug
                      emit textOutput(prog+" successfull finished!");
                  #endif
                  }
                  else{
                      emit textOutput(prog+" don't finished ...");
                  }
	    

                  #ifdef debug
                      qDebug() << "Trying to write MOD_STATS to "<<path << endl;
                  #endif
            }
        }
    }

    dir.setPath(dirname);
    emit copyingMODFiles(false);
}

/*--------------------------copyMCAFiles()--------------------------------------*/
void XiaStarter::copyMCAFiles(){
    emit copyingMCAFiles(true);
    copymca = new QProcess(this);
    QString script, source, target, folder="";
    emit textOutput("Copy MCA files ...");

    dir.setPath(mca_root);

    QString subrun;

    subrun.setNum(subrunnum-1);

    if(subrunnum-1<10){
        folder.append("000");
    }
    if(subrunnum-1>=10 && subrunnum-1<100){
        folder.append("00");
    }
    if(subrunnum-1>=100 && subrunnum-1<1000){
        folder.append("0");
    }

    folder.append(subrun);
    dir.mkdir(folder);

    for(unsigned int i=0; i<det.size(); i++){
        target =mca_root+"/"+folder+"/";
        target+=det.at(i).getName()+".spc";
        source=hwHistDir+"DGF_";
        source+= det.at(i).getCrate();
        int m=det.at(i).getIslot();

        if(m <= 9){
            source+="_0";
        }
        else{
            source+="_";
        }
        source+= det.at(i).getSlot();
        source+="_";
        source+= det.at(i).getAddress();
        source+=".spc";

        script="cp ";
        script+=source;
        script+=" ";
        script+=target;
#ifdef debug
	qDebug() << script << endl;
#endif
        copymca->execute(script);
    }
    dir.setPath(dirname);
    emit viewButtons(1);
    emit copyingMCAFiles(false);
}

/*-------------------------------createRunFolders()-------------------------*/
/*For everybody who knows the old writer.sh script, the following will not be
 very difficult to understand. As the name of this method already says, it is 
used to create all folders, which will store the listmode, mca and statistics
files.*/
void XiaStarter::createRunFolders(){

    emit textOutput("Trying to create Runfolders ...");

    QString run="Run";
    int nummer = runnum;

    if(nummer<10){
        run.append("0");
    }

    QString zahl;
    zahl.setNum(nummer);
    run.append(zahl);

    QString test=dirname;

    test.append("/");
    test.append(prefix);

    if(dir.exists(prefix)){

        emit textOutput("WARNING: Prefixfolder already exist! The Runnumber has been changed!");

        test.append("/Run");
        QString test2=test;
        QString test3=test;
		
		if(runnum<10){
			test2+="0"+QString::number(runnum);
            test3+="0"+QString::number(runnum+1);
		}

		if(runnum>=10){
			test2+=QString::number(runnum);
            test3+=QString::number(runnum+1);
		}

        if(dir.exists(test2)){
            if(dir.exists(test3)){

                bool chkrun=true;
                int i=1;
		
                while(chkrun){
		  		    QString runpath=test;
                    QString rn;
                    rn.setNum(i);

                    if(i<10){
                        runpath.append("0"+rn);
                    }

                    if(i>=10){
                        runpath.append(rn);
                    }

                    if(dir.exists(runpath)){
                        i++;
                    }
                    else{
                        chkrun=false;
                        nummer=i;
                        emit runNumChange(nummer);
                        run="Run";
                        zahl.setNum(nummer);

                        if(nummer<10){
                            run.append("0");
                        }

                        run.append(zahl);

                        dir.setPath(dirname);
                        dir.cd(prefix);

                        if(dir.mkdir(run)){
                            #ifdef debug
                                qDebug() << "Runfolder created!" << endl;
                            #endif
                        }
                        else {
                            #ifdef debug
                                qDebug() << "Could not create Runfolder!" << endl;
                            #endif
                        }
                    }
                }
            }
            else{
                nummer=runnum+1;
                emit runNumChange(nummer);
                run="Run";
                zahl.setNum(nummer);

                if(nummer<10){
                  run.append("0");
                }

                run.append(zahl);

                dir.setPath(dirname);
                dir.cd(prefix);

                if(dir.mkdir(run)){
                  #ifdef debug
                      qDebug() << "Runfolder created!" << endl;
                  #endif
                }
                else {
                  #ifdef debug
                      qDebug() << "Could not create Runfolder!" << endl;
                  #endif
                }
            }
	    }
	    else{
	      nummer=runnum;
	      emit runNumChange(nummer);
	      run="Run";
	      zahl.setNum(nummer);
	      
	      if(nummer<10){
            run.append("0");
	      }

	      run.append(zahl);

	      dir.setPath(dirname);
	      dir.cd(prefix);
	      
	      if(dir.mkdir(run)){
            #ifdef debug
                qDebug() << "Runfolder created!" << endl;
            #endif
	      }
	      else {
            #ifdef debug
                qDebug() << "Could not create Runfolder!" << endl;
            #endif
	      }
	    }
    }
    else{
        if(dir.mkdir(prefix)){
            dir.cd(prefix);
            if(dir.mkdir(run)){
                #ifdef debug
                    qDebug() << "Runfolder created!" << endl;
                #endif
            }
            else {
                #ifdef debug
                    qDebug() << "Could not create Runfolder!" << endl;
                #endif
            }
        }
        else{
            #ifdef debug
                qDebug() << "Could not create Runfolder!" << endl;
            #endif
        }
    }

    dir.cd(run);
    if(dir.mkdir("listmode")){
        #ifdef debug
            qDebug() << "Listmode folder created!" << endl;
        #endif
    }
    else {
        #ifdef debug
            qDebug() << "Could not create Listmode folder!" << endl;
        #endif
    }

    if(dir.mkdir("MCA")){
        #ifdef debug
            qDebug() << "MCAfolder created!" << endl;
        #endif
    }
    else {
        #ifdef debug
            qDebug() << "Could not create MCAfolder!" << endl;
        #endif
    }

    if(dir.mkdir("statistics")){
        #ifdef debug
            qDebug() << "Statistics folder created!" << endl;
        #endif
    }
    else{
        #ifdef debug
            qDebug() << "Could not create Statistics folder!" << endl;
        #endif
    }

    if(dir.mkdir("mod_statistics")){
        #ifdef debug
            qDebug() << "MOD folder created!" << endl;
        #endif
    }
    else {
        #ifdef debug
            qDebug() << "Could not create MOD folder!" << endl;
        #endif
    }

    if(dir.mkdir("dgf_setups")){
        #ifdef debug
            qDebug() << "MOD folder created!" << endl;
        #endif
    }
    else {
        #ifdef debug
            qDebug() << "Could not create MOD folder!" << endl;
        #endif
    }

    dir.cd("listmode");
    lm_root=dir.absolutePath();
    dir.cd("../MCA");
    mca_root=dir.absolutePath();
    dir.cd("../statistics");
    stat_root=dir.absolutePath();
    dir.cd("../mod_statistics");
    mod_root=dir.absolutePath();
    dir.cd("../dgf_setups");
    dgf_root=dir.absolutePath();
    dir.cd("../");
    run_root=dir.absolutePath();
    dir.setPath(dirname);


    ratesFile=run_root+"/"+QString::number(runnum)+".rates";
    QString header="#TIME\t";

    for(unsigned int i=0; i<detnames.size(); i++){
        header+=detnames.at(i)+"\t";
    }
    header+="\n";

    QFile output(ratesFile);

    if(output.exists()){
        output.open(QIODevice::Append);
    }
    else{
        output.open(QIODevice::WriteOnly);
    }
    output.write(header.toLatin1());
    output.close();


    #ifdef debug
        qDebug() << "Rates are going to be stored in " << ratesFile;
    #endif

    emit textOutput("All Runfolders created!");
}

/*---------------------------------daqbuffer_clear()------------------------*/
/*This function just starts the daqbuffer_clear program of the miniball
dataquisition code.It returns a bool value, which should say, if the program
was executed successfully or not.*/
bool XiaStarter::daqbuffer_clear(){

    QProcess dclear;
    if(dclear.execute("daqbuffer_clear")){
     emit textOutput("Es läuft etwas mit dem daqbuffer_clear falsch!");
     return 0;
    }
    else{
        emit textOutput("Buffer cleared!");
        return 1;
    }
}

/*++++++++++++++++++++++++++++++++++++++newWriterRun()++++++++++++++++++++++++++++++++++++++++++
This is the function which sets up a new writer run. When it's called a new QProcess writer will
 be declared. Before this Process starts, this function also appends sets the arguments of the
writer according to the UI-input of the user. The time limit is provided by a QTimer widget. It's
 singleshot-signal is directly connected to the writerTimeOut() function. */

void XiaStarter::newWriterRun(){
#ifdef debugNWR
    qDebug() << "newWriterRun()";
#endif
    if(!runStopped){
        //defines the name of the program

        program="mb_writer";

        QString run; //string for the run number
        QString subrun; //string for subrun number

        //transforming subrun number into a QString
        subrun.setNum(subrunnum);

        //transforming the run number into a QString
        run.setNum(runnum);

        //setting up the filename
        filename=lm_root;
        filename.append("/");
        filename.append(prefix);
        filename.append(".");

        //Here some leading zeroes will be append. I'm pretty sure that there's a nicer way to do that
        if(runnum<10){
            filename.append("0");
        }

        filename.append(run);
        filename.append(".");

        if(subrunnum<10){
            filename.append("000");
        }
        if(subrunnum>=10 && subrunnum<100){
            filename.append("00");
        }
        if(subrunnum>=100 && subrunnum<1000){
            filename.append("0");
        }

        filename.append(subrun);
        filename.append(".lst");

        //Some Outputs to the writerOutput
        emit textOutput("Starting new Run: "+filename);

        program.append(" ");
        program.append(filename);
        emit newFileName(filename);
        sizetimer = new QTimer(this);
        sizetimer->singleShot(1000, this, SLOT(getFileSize()));

#ifdef debugNWR
        qDebug() << "startWriter() beginnt.";
#endif
        startWriter();
    }

}

void XiaStarter::copyDGFsetups(){
    QString setupDir = getenv("HOME");
    setupDir+="/mb/dgf_setups/";
    QString targetDir = dgf_root+"/";

    QProcess copy;
    QString script="cp ";

    for(unsigned int i=0; i<detnames.size(); i++){
        script+=setupDir+"dgf_config_"+detnames.at(i)+".setup ";
    }

    script+= targetDir;

#ifdef debug
    qDebug() << script;
#endif

    copy.startDetached(script);
    emit textOutput("Copying dgf_configs...");
}

/*----------------------------------writerTimeOut()---------------------------*/
void XiaStarter::writerTimeOut(){
    if(!runStopped){
        timer->stop();
        timer->~QTimer();
        writer->kill();
        writer->waitForFinished(1000);


        emit textOutput("Subrun stopped after writer timed out!");
        lRunint++;

        copyStatFiles();
        mb_request_mca_readout();

        if(udefloop){
            subrunnum++;
            emit subrunNumChange(subrunnum);
            newWriterRun();
            copyMODStats();

#ifdef debug
            qDebug() << "copyMODStats beendet.";
#endif
        }

        /*if(!udefloop){
            if(lRunint<loopint){
                subrunnum++;
                emit subrunNumChange(subrunnum);
                newWriterRun();
                copyMODStats();
            }
            else{
                emit writerIsDone();
            }
        }*/
    }
}

/*+++++++++++++++++++++++++++++++++++++copyStatFiles()++++++++++++++++++++++++++++++++++++++++++*/
/*This function calls a QProcess which copies the statistics_0.txt file in the mb/hw_hist folder to
 the statistics folder of the current run using the cp program of linux shell*/
void XiaStarter::copyStatFiles(){

    QProcess *cp=new QProcess(this);
    QString cpstring="cp "+ hwHistDir + "statistics_0.txt ";
    cpstring.append(stat_root);
    cpstring.append("/");
    cpstring.append(prefix);
    cpstring.append(".");

    QString run;
    QString subrun;

    subrun.setNum(subrunnum);
    run.setNum(runnum);

    if(runnum<10){
        cpstring.append("0");
    }

    cpstring.append(run);
    cpstring.append(".");

    if(subrunnum<10){
        cpstring.append("000");
    }
    if(subrunnum>=10 && subrunnum<100){
        cpstring.append("00");
    }
    if(subrunnum>=100 && subrunnum<1000){
        cpstring.append("0");
    }

    cpstring.append(subrun);
    cpstring.append(".stat");

    QString msg="Copy statistics file ... ";
    textOutput(msg);
#ifdef debug    
    qDebug() << cpstring;
#endif
    cp->execute(cpstring);
    cp->waitForFinished(1000);
}

/*-----------------killWriter()------------------------------*/
void XiaStarter::killWriter(){

#ifdef debug
    qDebug() << "Killing Writer!";
#endif
	
    //call kill slot of QProcess::writer
	if(writer->state() == QProcess::Running){
        writer->kill();
    //wait for the writer to shutdown
        writer->waitForFinished(1000);
	}

    emit textOutput("Writer is dead!");

}
/*------------------------killCollector()----------------------*/
void XiaStarter::killCollector(){
#ifdef debug
    qDebug() << "Killing Collector!";
#endif
    //call kill slot of QProcess::writer
    if(collector->state() == QProcess::Running){
        collector->kill();
	    //wait for the writer to shutdown
        collector->waitForFinished(1000);
    }

    emit textOutput("Collector is dead!");

}
/*------------------------------------The MCA-Programs----------------------------*/
void XiaStarter::mca_viewlatest(){
    QProcess viewlatest;
    program="tv";
    program+=" -e \"";

    for(unsigned int i=0; i<det.size(); i++){
        QString source;
        source=hwHistDir+"/DGF_";
        source+= det.at(i).getCrate();
        int m=det.at(i).getIslot();

        if(m <= 9){
            source+="_0";
        }
        else{
            source+="_";
        }
        source+= det.at(i).getSlot();
        source+="_";
        source+= det.at(i).getAddress();
        source+=".spc";

        program+="s g "+source +"; ";
    }


    for(unsigned int i=0; i<det.size(); i++){
        QString num;
        num.setNum(i);
        program+="c p r "+ det.at(i).getCalFilePath() + " " + num +"; ";
    }
    program+="\"";

    viewlatest.startDetached(program);
}

void XiaStarter::mca_stop(){
    if(ftimeradio){
        mcaTimer->stop();
    }
    QString c;
    c.setNum(mcaCrate);

    mcastop = new QProcess(this);
        program = "mb_mca_stop";

        program.append(" ");
        program.append(c);

        mcastop->start(program);

        emit textOutput("MCA Run has been stopped!");
}

void XiaStarter::mca_start(){
    QString c;
    c.setNum(mcaCrate); 

    mcastart = new QProcess(this);
    emit textOutput("Starting MCA Run!");

    if(utimeradio){
        program = "mb_mca_start -z ";
        program.append(c);
    }

    if(ftimeradio){
        program = "mb_mca_start -z ";
        program.append(c);


        mcaTimer = new QTimer(this);
        mcaTimer->setInterval(1000);
        mcaTimer->setSingleShot(true);
        connect(mcaTimer,SIGNAL(timeout()),SLOT(mcaClock()));
        mcaTimer->start();
    }
    mcastart->start(program);

}

void XiaStarter::mcaClock(){
	if(mcaTime){
		mcaTime--;
		emit newMCATime(mcaTime);
		mcaTimer->start();

        if(mcaRates){ showRates();}
	}
	else{
		mca_stop();
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("MCA Run Stopped: MCA timed out!");
        msgBox.exec();
	}
	
}

void XiaStarter::mca_readout(){
    QString c, t;
    c.setNum(mcaCrate); t.setNum(mcaTime);
    mcareadout = new QProcess(this);
    emit textOutput("MCA is going to be readout!");
    program = "mb_mca_readout ";
    program.append(c);
    mcareadout->execute(program);
}

void XiaStarter::mca_saveSpectra(QString directory){
    QProcess saveSpectra;
    QString script, target, target2, source, source2;

    for(unsigned int i=0; i<det.size(); i++){
        target =directory+"/";
        target+=det.at(i).getName()+".spc";

        target2 =directory+"/";
        target2+=det.at(i).getName()+".dat";

        source=hwHistDir + "DGF_";
        source+= det.at(i).getCrate();
        int m=det.at(i).getIslot();

        if(m <= 9){
            source+="_0";
        }
        else{
            source+="_";
        }
        source+= det.at(i).getSlot();
        source+="_";
        source+= det.at(i).getAddress();

        source2=source;
        source+=".spc";
        source2+=".dat";

        script="cp ";
        script+=source;
        script+=" ";
        script+=target;
#ifdef debug
    qDebug() << script << endl;
#endif
        saveSpectra.execute(script);

        script="cp ";
        script+=source2;
        script+=" ";
        script+=target2;
#ifdef debug
    qDebug() << script << endl;
#endif
        saveSpectra.execute(script);
    }

}

/*-------------------------------getRates()------------------------------*/
void XiaStarter::getRates(){
    if(!runStopped || collector->state()==QProcess::Running){
        QString path=hwHistDir+"statistics_0.txt";
        QFile statfile(path);
        QString line;
        QString name, current;
        QStringList names, currents;


        if(statfile.open(QIODevice::ReadOnly)){

            QTextStream in(&statfile);

            while(!in.atEnd()){

                line=in.readLine().append("\n");

                if(line.contains("Name:")){
                    name.append(line);
                }

                if(line.contains("Current rate:")){
                    current.append(line);
                }
            }
        }

        statfile.close();
        names = name.split("\n");
        currents = current.split("\n");

        std::vector<QStringList> lname;
        std::vector<QStringList> lcurrent;

        for(int i=0; i<names.size()-1; i++){

            #ifdef debugrates
                qDebug() << names.at(i) << endl;
            #endif
            lname.push_back(names.at(i).split(QRegExp( "[ \\t]+"), QString::SkipEmptyParts));
        }

        for(int i=0; i<currents.size()-1; i++){
            #ifdef debugrates
                qDebug() << currents.at(i) << endl;
            #endif
            lcurrent.push_back(currents.at(i).split(QRegExp( "[ \\t]+"), QString::SkipEmptyParts));
        }

        #ifdef debugrates
            qDebug()<<"lname:"<<endl;
            for(unsigned int i =0; i<lname.size(); i++){
                for(unsigned int n=0; n<lname.at(i).size(); n++){
                    qDebug() << lname.at(i).at(n) << endl;
                }
            }

            qDebug()<< "\n" << "lcurrent:"<<endl;
            for(unsigned int i =0; i<lcurrent.size(); i++){
                for(unsigned int n=0; n<lcurrent.at(i).size(); n++){
                    qDebug() << lcurrent.at(i).at(n) << endl;
                }
            }

            for(unsigned int i=0; i<det.size(); i++){
                qDebug() << i << det.at(i).getName();
            }
        #endif

        for(unsigned int i=0; i<det.size(); i++){
            for(unsigned int j=0; j < lname.size(); j++){
                for(int k=0; k < lname.at(j).size(); k++){

                    if(lname.at(j).at(k) == det.at(i).getName()){

                        int a=det.at(i).getIaddress();
                        #ifdef debugrates
                            qDebug() << i << j << k << a;
                        #endif
                        double rate;

                        if(lcurrent.size()>j){
                            if(lcurrent.at(j).size()>a+2){
                                rate=lcurrent.at(j).at(a+2).toDouble();
                            }
                            else{
                                qDebug() << "ERROR: lcurrent.at("<< j <<").at(a+2) does not exist! a+2="<< a+2 <<" (XiaStarter::getRates())";
                                continue;
                            }
                        }
                        else{
                            qDebug() << "ERROR: lcurrent.at(j) does not exist! j="<< j <<" (XiaStarter::getRates())";
                            continue;
                        }

                        if(rates.size()>i){
                            rates.at(i).append(rate);
                        }
                        else{
                            qDebug() << "ERROR: rates.at(i) does not exist! i="<< j <<" (XiaStarter::getRates())";
                            continue;
                        }
                    }
                }
            }
        }

        double zeit=(double) t.elapsed()/1000;
        ratestime.push_back(zeit);
        int datasize=ratestime.size();
        ratesLoop++;

        if(ratesLoop>=1000){
            QString content="";
            for(unsigned int i=0; i<ratestime.size()-1; i++){
                content+=QString::number(ratestime.at(i))+"\t";
                for(unsigned int j=0; j<rates.size(); j++){
                    if(rates.at(j).size()>i){
                        content+=QString::number(rates.at(j).at(i))+"\t";
                    }
                    else{
                        qDebug() << "ERROR: rates.at("<<j<<").at(i) does not exist! i="<<i<<" (XiaStarter::getRates())";
                        continue;
                    }
                }
                content+="\n";
            }

            QFile output(ratesFile);

            if(output.exists()){
                output.open(QIODevice::Append);
            }
            else{
                output.open(QIODevice::WriteOnly);
            }
            output.write(content.toLatin1());
            output.close();
            ratesLoop=0;
        }

        if(datasize>1000){
            if(ratestime.size()>=1){
                ratestime.pop_front();
            }
            else{
                qDebug() << "ERROR: ratestime.at(0) does not exist! (XiaStarter::getRates())";
            }

            for(unsigned int i=0; i< rates.size(); i++){
                if(rates.at(i).size()>=1){
                    rates.at(i).pop_front();
                }
                else{
                    qDebug() << "ERROR: rates.at("<<i<<").at(0) does not exist! (XiaStarter::getRates())";
                    continue;
                }
            }
        }

        ratetimer = new QTimer(this);
        ratetimer->singleShot(1000, this, SLOT(getRates()));
        emit ratesDataChanged();
        QString runNum=QString::number(runnum);
        QString subRunNum=QString::number(subrunnum);

        emit newInfo(filename, runNum, subRunNum);
   }

}

void XiaStarter::getFileSize(){

    QFile listmode(filename);
    if(listmode.exists()){
        listmode.open(QIODevice::ReadOnly);
        qint64 filesize=listmode.size();
        emit newFileSize(filesize);
        listmode.close();
        if(!runStopped){
            sizetimer->singleShot(1000, this, SLOT(getFileSize()));
        }
    }
    else{
        qDebug() << "ERROR: Listmode-flie does not exist. Could not get file size! (XiaStarter::getFileSize())";
    }
}

void XiaStarter::lmViewAll(){

    if(tvradio){

        if(subrunnum>1){
            QString mcaSpectrum, prog="tv -e \"", sSubrun1=QString::number(subrunnum-1);
            QProcess *viewall = new QProcess(this);

            if(subrunnum-1 <10){
                sSubrun1.prepend("000");
            }

            if(subrunnum-1 <100 && subrunnum-1>=10){
                sSubrun1.prepend("00");
            }

            if(subrunnum-1 <1000 && subrunnum-1>=100){
                sSubrun1.prepend("0");
            }

            int j=0;

            for(unsigned int i=0; i<det.size(); i++){
                if((showDets==0) || (showDets==1 && det.at(i).getDetType()=="Germanium") || (showDets==2 && det.at(i).getDetType()=="Silicon")){
                    QString num=QString::number(j);
                    mcaSpectrum =mca_root+"/"+sSubrun1+"/";
                    mcaSpectrum+=det.at(i).getName()+".spc";
                    prog+="s g "+ mcaSpectrum + "; ";
                    prog+="c p r "+ det.at(i).getCalFilePath() + " " + num +"; ";
                    j++;
                }
            }
            prog+="\"";

            #ifdef debug
                qDebug() << "XiaStarter::lmViewAll() script ...";
                qDebug() << prog;
            #endif

            viewall->startDetached(prog);
        }
        else{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Sorry, the MCA spectra are not yet available. Please try again after the first subrun!");
            msgBox.exec();
        }
    }

    if(hdtvradio){
        if(subrunnum>1){
            QString mcaSpectrum, prog="hdtv -b ", sSubrun1=QString::number(subrunnum-1), fileContent="";
            QProcess *viewall = new QProcess(this);

            if(subrunnum-1 <10){
                sSubrun1.prepend("000");
            }

            if(subrunnum-1 <100 && subrunnum-1>=10){
                sSubrun1.prepend("00");
            }

            if(subrunnum-1 <1000 && subrunnum-1>=100){
                sSubrun1.prepend("0");
            }

            int j=0;

            for(unsigned int i=0; i<det.size(); i++){
                if((showDets==0) || (showDets==1 && det.at(i).getDetType()=="Germanium") || (showDets==2 && det.at(i).getDetType()=="Silicon")){
                    QString num=QString::number(j);
                    mcaSpectrum =mca_root+"/"+sSubrun1+"/";
                    mcaSpectrum+=det.at(i).getName()+".spc";
                    fileContent+="spectrum get "+ mcaSpectrum + "; ";
                    fileContent="calibration position read -s "+ num +" "+ det.at(i).getCalFilePath() + "; ";
                    j++;
                }
            }

            QFile file("./viewTemp");
            if(file.open(QIODevice::WriteOnly)){
                file.write(fileContent.toLatin1());
                file.close();
            }
            else{
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setText("Could not open temporary file with hdtv-commands. Please use tv instead!");
                msgBox.exec();
            }

            prog+="./viewTemp";

            #ifdef debug
                qDebug() << "XiaStarter::lmViewAll() script ...";
                qDebug() << prog;
            #endif

            viewall->startDetached(prog);
        }
        else{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Sorry, the MCA spectra are not yet available. Please try again after the first subrun!");
            msgBox.exec();
        }

    }
}

void XiaStarter::lmViewLastTwo(){

    if(subrunnum>2){

        QInputDialog *dialog=new QInputDialog;
        QStringList items;

        for(unsigned int i=0; i < detnames.size(); i++){
            items.push_back(detnames.at(i));
        }

        dialog->setComboBoxItems(items);
        dialog->setWindowTitle("View two latest subruns!");
        dialog->setLabelText("Choose the detector for which you want to compare the last two subruns.");
        int ret=dialog->exec();

        if(ret == QDialog::Accepted){
            if(tvradio){

                QString mcaSpectrum, prog="tv -e \"", sSubrun1=QString::number(subrunnum-1), sSubrun2=QString::number(subrunnum-2), cmd, num1, num2;
                QVector <QString> mcaSpectra;
                QProcess *viewlatest = new QProcess(this);

                if(subrunnum-1 <10){
                    sSubrun1.prepend("000");
                }

                if(subrunnum-1 <100 && subrunnum-1>=10){
                    sSubrun1.prepend("00");
                }

                if(subrunnum-1 <1000 && subrunnum-1>=100){
                    sSubrun1.prepend("0");
                }

                if(subrunnum-2 <10){
                    sSubrun2.prepend("000");
                }

                if(subrunnum-2 <100 && subrunnum-1>=10){
                    sSubrun2.prepend("00");
                }

                if(subrunnum-2 <1000 && subrunnum-1>=100){
                    sSubrun2.prepend("0");
                }

                int j=0;

                for(unsigned int i=0; i<det.size(); i++){
                    if(det.at(i).getName()==dialog->textValue()){

                        num1.setNum(j);
                        num2.setNum(j+1);
                        mcaSpectrum = mca_root+"/"+sSubrun1+"/";
                        mcaSpectrum+= det.at(i).getName()+".spc ";
                        prog+="s r "+ mcaSpectrum + num1 + "; ";

                        mcaSpectrum = mca_root+"/"+sSubrun2+"/";
                        mcaSpectrum+= det.at(i).getName()+".spc ";
                        prog+="s r "+ mcaSpectrum + num2 + "; ";

                        prog+="c p r "+ det.at(i).getCalFilePath() + " " + num1 +" " + num2+"; ";

                        j++;
                    }
                }

                prog+="\"";

                #ifdef debug
                    qDebug() << "XiaStarter::lmViewLastTwo() script ...";
                    qDebug() << prog;
                #endif

                viewlatest->startDetached(prog);
            }

            if(hdtvradio){

                QString mcaSpectrum, prog="hdtv -b ", sSubrun1=QString::number(subrunnum-1), sSubrun2=QString::number(subrunnum-2), cmd, num1, num2, fileContent;
                QVector <QString> mcaSpectra;
                QProcess *viewlatest = new QProcess(this);

                if(subrunnum-1 <10){
                    sSubrun1.prepend("000");
                }

                if(subrunnum-1 <100 && subrunnum-1>=10){
                    sSubrun1.prepend("00");
                }

                if(subrunnum-1 <1000 && subrunnum-1>=100){
                    sSubrun1.prepend("0");
                }

                if(subrunnum-2 <10){
                    sSubrun2.prepend("000");
                }

                if(subrunnum-2 <100 && subrunnum-1>=10){
                    sSubrun2.prepend("00");
                }

                if(subrunnum-2 <1000 && subrunnum-1>=100){
                    sSubrun2.prepend("0");
                }

                int j=0;

                for(unsigned int i=0; i<det.size(); i++){
                    if(det.at(i).getName()==dialog->textValue()){

                        num1.setNum(j);
                        num2.setNum(j+1);
                        mcaSpectrum = mca_root+"/"+sSubrun1+"/";
                        mcaSpectrum+= det.at(i).getName()+".spc ";
                        fileContent+="spectrum get -s "+ num1 + mcaSpectrum +"; ";

                        mcaSpectrum = mca_root+"/"+sSubrun2+"/";
                        mcaSpectrum+= det.at(i).getName()+".spc ";
                        fileContent+="spectrum get -s "+ num2 + mcaSpectrum +"; ";

                        fileContent+="calibration position read -s "+ num1 + " " + det.at(i).getCalFilePath()+"; ";
                        fileContent+="calibration position read -s "+ num2 + " " + det.at(i).getCalFilePath()+"; ";

                        j++;
                    }
                }

                QFile file("./viewTemp");
                if(file.open(QIODevice::WriteOnly)){
                    file.write(fileContent.toLatin1());
                    file.close();
                }
                else{
                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.setText("Could not open temporary file with hdtv-commands. Please use tv instead!");
                    msgBox.exec();
                }

                prog+="./viewTemp";

                #ifdef debug
                    qDebug() << "XiaStarter::lmViewLastTwo() script ...";
                    qDebug() << prog;
                #endif

                viewlatest->startDetached(prog);
            }
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Sorry, the MCA spectra are not yet available. Please try again after the second subrun!");
        msgBox.exec();
    }
}

void XiaStarter::lmViewLatest(){
    if(tvradio){
        if(subrunnum>2){
            QString mcaSpectrum, prog="tv -e \"", sSubrun1=QString::number(subrunnum-1), sSubrun2=QString::number(subrunnum-2), cmd, num1, num2;
            QVector <QString> mcaSpectra;
            QProcess *viewlatest = new QProcess(this);

            if(subrunnum-1 <10){
                sSubrun1.prepend("000");
            }

            if(subrunnum-1 <100 && subrunnum-1>=10){
                sSubrun1.prepend("00");
            }

            if(subrunnum-1 <1000 && subrunnum-1>=100){
                sSubrun1.prepend("0");
            }

            if(subrunnum-2 <10){
                sSubrun2.prepend("000");
            }

            if(subrunnum-2 <100 && subrunnum-1>=10){
                sSubrun2.prepend("00");
            }

            if(subrunnum-2 <1000 && subrunnum-1>=100){
                sSubrun2.prepend("0");
            }


            int j=0;

            for(unsigned int i=0; i<det.size(); i++){
                if((showDets==0) || (showDets==1 && det.at(i).getDetType()=="Germanium") || (showDets==2 && det.at(i).getDetType()=="Silicon")){

                    num1.setNum(j);
                    num2.setNum(j+1);
                    mcaSpectrum = mca_root+"/"+sSubrun1+"/";
                    mcaSpectrum+= det.at(i).getName()+".spc ";
                    prog+="s r "+ mcaSpectrum + num1 + "; ";

                    mcaSpectrum = mca_root+"/"+sSubrun2+"/";
                    mcaSpectrum+= det.at(i).getName()+".spc ";
                    prog+="s r "+ mcaSpectrum + num2 + "; ";

                    prog+="spectrum sub "+ num1 + " " + num2 + "; ";
                    prog+="spectrum delete "+ num2 + "; ";
                    prog+="c p r "+ det.at(i).getCalFilePath() + " " + num1 +"; ";

                    j++;
                }
            }

            prog+="\"";

            #ifdef debug
                qDebug() << "XiaStarter::lmViewLatest() script ...";
                qDebug() << prog;
            #endif

            viewlatest->startDetached(prog);
        }
        else{
            if(subrunnum>1){
                lmViewAll();
            }
            else{
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText("Sorry, the MCA spectra are not yet available. Please try again after the first subrun!");
                msgBox.exec();
            }
        }
    }

    if(hdtvradio){
        if(subrunnum>2){
            QString mcaSpectrum, prog="hdtv -b ", sSubrun1=QString::number(subrunnum-1), sSubrun2=QString::number(subrunnum-2), cmd, num1, num2, fileContent;
            QVector <QString> mcaSpectra;
            QProcess *viewlatest = new QProcess(this);

            if(subrunnum-1 <10){
                sSubrun1.prepend("000");
            }

            if(subrunnum-1 <100 && subrunnum-1>=10){
                sSubrun1.prepend("00");
            }

            if(subrunnum-1 <1000 && subrunnum-1>=100){
                sSubrun1.prepend("0");
            }

            if(subrunnum-2 <10){
                sSubrun2.prepend("000");
            }

            if(subrunnum-2 <100 && subrunnum-1>=10){
                sSubrun2.prepend("00");
            }

            if(subrunnum-2 <1000 && subrunnum-1>=100){
                sSubrun2.prepend("0");
            }


            int j=0;

            for(unsigned int i=0; i<det.size(); i++){
                if((showDets==0) || (showDets==1 && det.at(i).getDetType()=="Germanium") || (showDets==2 && det.at(i).getDetType()=="Silicon")){

                    num1.setNum(j);
                    num2.setNum(j+1);
                    mcaSpectrum = mca_root+"/"+sSubrun1+"/";
                    mcaSpectrum+= det.at(i).getName()+".spc ";
                    fileContent+="spectrum get -s "+ num1 +" " + mcaSpectrum+"; ";

                    mcaSpectrum = mca_root+"/"+sSubrun2+"/";
                    mcaSpectrum+= det.at(i).getName()+".spc ";
                    fileContent+="spectrum get -s " + num2 + " "+ mcaSpectrum+"; ";

                    fileContent+="spectrum substract "+ num1 + " " + num2 + "; ";
                    fileContent="spectrum delete "+ num2 + "; ";
                    fileContent+="calibration position read -s "+ num1 + " "+ det.at(i).getCalFilePath() + "; ";

                    j++;
                }
            }

            QFile file("./viewTemp");
            if(file.open(QIODevice::WriteOnly)){
                file.write(fileContent.toLatin1());
                file.close();
            }
            else{
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setText("Could not open temporary file with hdtv-commands. Please use tv instead!");
                msgBox.exec();
            }

            prog+="./viewTemp";


            #ifdef debug
                qDebug() << "XiaStarter::lmViewLatest() script ...";
                qDebug() << prog;
            #endif

            viewlatest->startDetached(prog);
        }
        else{
            if(subrunnum>1){
                lmViewAll();
            }
            else{
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText("Sorry, the MCA spectra are not yet available. Please try again after the first subrun!");
                msgBox.exec();
            }
        }

    }
}

void XiaStarter::readCalList(){
    QString xsFolder=getenv("HOME");
    xsFolder+="/.xs/";

    QFile file(xsFolder+"xs.cal");

    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
            QTextStream in(&file);
            QStringList calNames;

            while(!in.atEnd()){
                calNames.push_back(in.readLine());
            }

            file.close();

	    
            if(calNames.size()==(int) det.size()){
                for(int i=0; i<calNames.size(); i++){
                    det.at(i).setCalFilePath(calNames.at(i));
                }
            }
            else{
                   qDebug() << "WARNING: Too less caliration files in list or wrong source configuration!";
                }
        }
        else{            
            qDebug() << "WARNING: Can not open xs.cal. Check calibration file list!" ;
        }
    }
    else{
        qDebug() << "WARNING: File xs.cal does not exist. Check calibration file list!";
    }
}

void XiaStarter::changeDets(std::vector<xs_det> newDets){
    det.clear();

    for(unsigned int i=0; i<newDets.size(); i++){
        det.push_back(newDets.at(i));
    }

    size=det.size();
}

void XiaStarter::loadDetSettings(QString settingsFile){
    qDebug() << "Loading Detector Settings...";
    QFile file(settingsFile);

    if(file.open(QIODevice::ReadOnly)){

        QXmlStreamReader xml(&file);

        while(!xml.atEnd()){
            /* Read next element.*/
            xml.readNext();

            if(xml.isStartDocument()){
                continue;
            }

            if(xml.isStartElement()){
                if(xml.name()=="calibrationFiles"){
               //qDebug() << "CalFiles";
                for(unsigned int i=0; i<det.size(); i++){
                    xml.readNextStartElement();
                    //qDebug() << xml.name();
                    if(det.at(i).getName()==xml.name()){
                        //qDebug() << det.at(i).getName();
                        det.at(i).setCalFilePath(xml.readElementText());
                        //qDebug() << "CalFilePath" << i << xml.readElementText();
                        }
                    }
                }
            }

            if(xml.isStartElement()){
                if(xml.name()=="detectorTypes"){
                    //qDebug() << "DetTypes";
                    for(unsigned int i=0; i<det.size(); i++){
                        xml.readNextStartElement();
                        //qDebug() << xml.name();
                        if(det.at(i).getName()==xml.name()){
                            //qDebug() << det.at(i).getName();
                            det.at(i).setDetType(xml.readElementText());
                            //qDebug() << "Detectortype" << i << xml.readElementText();
                        }
                    }
                }
            }

            if(xml.isStartElement()){
                if(xml.name()=="ratesLimit"){
                //qDebug() << "RateLimit";
                for(unsigned int i=0; i<det.size(); i++){
                    xml.readNextStartElement();
                    //qDebug() << xml.name();
                    if(det.at(i).getName()==xml.name()){
                        //qDebug() << det.at(i).getName();
                        det.at(i).setRatesLimit(xml.readElementText());
                        //qDebug() << "Rateslimit" << i << xml.readElementText();
                    }
                }
                }
            }
        }
    }
    else qDebug() << "couldn't open file" << settingsFile;
   file.close();

   QString xsFolder=getenv("HOME");
   xsFolder+="/.xs/";
   QFile calFile(xsFolder+"xs.cal");
   QString text="";

   for(unsigned int i=0; i<det.size(); i++){
       text+=det.at(i).getCalFilePath() + "\n";
   }

   if(calFile.open(QIODevice::WriteOnly)){
      calFile.write(text.toAscii());
   }
   else{
       qDebug() << "WARNING: couldn't write to xs.cal! (XiaStarter::loadDetSettings())";
   }

   calFile.close();
   qDebug() <<"..done!";
}

int XiaStarter::showRates(){
    QProcess * showRates= new QProcess(this);
    QString program="mb_show_rates";

    QByteArray stdOut;
    int status=1;

    showRates->start(program);
    showRates->waitForFinished(-1);
    stdOut = showRates->readAllStandardOutput();

    QString text(stdOut);
    emit newShowRates(text);
    return status;
}

void XiaStarter::setMCARates(int num){
    mcaRates=num;
}

void XiaStarter::getMCARates(QString text){
    text+="lol";
}

void XiaStarter::showStdtErrorBox(){
    //Getting sendername
    QObject *s=sender();
    QString sendername;
    if(s){
        sendername=s->objectName();

        //Differ between collector and writer

        if(sendername=="collector"){
            collector->setReadChannel(QProcess::StandardError);
            QByteArray errorMsg;
            //reading all Standard Error
            errorMsg= collector->readAllStandardError();
            QString message(errorMsg);
            //Showing Messagebox with stderror!
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText(message);
            msgBox.exec();
        }

        if(sendername=="writer"){
            writer->setReadChannel(QProcess::StandardError);
            QByteArray errorMsg;
            //reading all Standard Error
            errorMsg= writer->readAllStandardError();
            QString message(errorMsg);
            //Showing Messagebox with stderror!
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText(message);
            msgBox.exec();
        }
    }
}

