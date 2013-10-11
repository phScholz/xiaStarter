/******************************************************************************

    xiastarter.h

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
#ifndef XIASTARTER_H
#define XIASTARTER_H

#include <QObject>
#include <QProcess>
#include <QDir>
#include <QTimer>
#include <QTime>
#include <vector>
#include <QByteArray>
#include <QTextStream>
#include <QTime>
#include <QVector>
#include "xs_det.h"


class XiaStarter : public QObject
{
    Q_OBJECT
public:
    explicit XiaStarter(QObject *parent = 0);

    bool daqbuffer_clear();
    QVector<double> ratestime;
    std::vector< QVector<double> > rates;
    int size;
    std::vector<QString> detnames;

    QTimer *timer;
    QTimer *sleeptimer;
    QTimer *ratetimer;
    QTimer *sizetimer;
    QTimer *mcaTimer;

    bool utimeradio;
    bool ftimeradio;
    bool tvradio;
    bool hdtvradio;

    int mcaCrate;
    int mcaTime;
    int showDets;
    int ratesLoop;

    bool runStopped;

    QString ratesFile;


    std::vector<xs_det> det;
    
signals:
    void newFileName(const QString&);
    void newFileSize(const qint64);
    void statusChanged(const int);
    void textOutput(const QString&);
    void runNumChange(int);
    void subrunNumChange(int);
    void writerIsDone();
    void ratesDataChanged();
    void writerState(QProcess::ProcessState state);
    void collectorState(QProcess::ProcessState state);
    void viewButtons(bool b);
    void newInfo(QString, QString, QString);
    void newMCATime(int);
    void newShowRates(QString);
    void copyingMODFiles(bool);
    void copyingMCAFiles(bool);

    
public slots:

    void copyDGFsetups();

    void startBootProcedure();
    void startSetupProcedure();

    void changeSourceConf();
    void setMCARates(int);

    void setDirname(const QString& string);
    void setDir(const QString& dirname);
    void setProgram(const QString& string);
    void setRunNum(int);
    void setSubrunNum(int);
    void setTime(int);
    void setPrefix(QString);
    void setudefloop(bool);
    void setLoopint(int);
    void setLoopRunint(int);
    void setCrate(QString string);
    void setMCAtime(QString);
    void setUTimeRadio(bool);
    void setFTimeRadio(bool);
    void setTVRadio(bool);
    void setHDTVRadio(bool);

    void startCollector();
    void startWriter();
    void createRunFolders();
    void newWriterRun();
    void writerTimeOut();
    void killWriter();
    void killCollector();

    void mca_viewlatest();
    void mca_stop();
    void mca_start();
    void mca_readout();
    void mca_saveSpectra(QString directory);
    int showRates();

    void getRates();
    void getFileSize();

    void collectorError(QProcess::ProcessError error);
    void collectorStateChanged(QProcess::ProcessState newState);

    void writerStarted();
    void writerError(QProcess::ProcessError error);
    void writerStateChanged(QProcess::ProcessState newState);

    void lmViewLatest();
    void lmViewAll();
    void lmViewLastTwo();

    void copyMCAFiles();

    void readCalList();
    void changeDets(std::vector<xs_det>);
    void loadDetSettings(QString);
	void mcaClock();

    void getMCARates(QString);




private:
    void readSourceConf();
    void writeSourceConf();
    int boot_dgf();
    int setup_dgf();

    void copyStatFiles();
    void mb_request_mca_readout();

    void copyMODStats();
    void writeModuleStats();

    
    int mcaRates;


    QProcess *boot;
    QProcess *setup;
    QProcess *collector;
    QProcess *writer;
    QProcess *readout;
    QProcess *copymca;
    QProcess *dgfshow;
    QProcess *mcastart;
    QProcess *mcareadout;
    QProcess *mcastop;

    QString dirname;
    QString lm_root;
    QString mca_root;
    QString stat_root;
    QString mod_root;
    QString run_root;
    QString dgf_root;
    QString filename;
   // QString sourceconf;
    QString prefix;
    QString folder;
    QString program;
    QString mcatime;
    QString crate;
    QString sourceConfPath;
    QString hwHistDir;

    QDir dir;

    int subrunnum;
    int runnum;
    int time;
    int loopint;
    int lRunint;


    bool udefloop;

    //std::vector<xs_det> det;

    QTime t;

};

#endif // XIASTARTER_H
