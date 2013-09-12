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

    int mcaCrate;
    int mcaTime;
    int showDets;


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
