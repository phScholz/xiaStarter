#ifndef XIASTARTERWINDOW_H
#define XIASTARTERWINDOW_H

#include <QMainWindow>
#include "xiastarter.h"
#include <QString>
#include <QThread>
#include <iostream>
#include <vector>
#include <QAction>
#include <QMenu>
#include "preferencedialog.h"
#include <vector>
#include <QVector>



namespace Ui {
class XiaStarterWindow;
}

class XiaStarterWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QPalette green1;
    QPalette green2;
    QPalette yellow1;
    QPalette yellow2;
    QPalette red1;
    QPalette red2;
    explicit XiaStarterWindow(QWidget *parent = 0);
    ~XiaStarterWindow();

signals:
    void saveFileNameIsNotEmpty(bool);

public slots:
    void changeStatus(const int num);
    void writeOutput(const QString& msg);
    void changeRunNum(int nummer);
    void changeSubrunNum(int number);
    void plotRates();
    void writerStatus(QProcess::ProcessState state);
    void collectorStatus(QProcess::ProcessState state);
    void setFileName(const QString&);
    void newFileSize(const qint64 filesize);
    void viewButtons(bool b);
    void prefTabChanged(int);
    void ratesContextMenuRequest(QPoint);




    
private slots:
    void removeFile();

    void sourceconf_clicked();

    void dgfconf_clicked();

    void about_clicked();

    void on_bootButton_clicked();

    void on_closeButton_clicked();

    void on_browseButton_clicked();

    void on_runButton_clicked();

    void runCollector();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_mcaStartButton_clicked();

    void on_mcaStopButton_clicked();

    void on_mcaViewlatestButton_clicked();

    void on_mcaReadoutButton_clicked();

    void on_pushButton_clicked();

    void on_setupButton_clicked();

    void on_killButton_clicked();

    void showPreferences();
    
    void loadDefaultSettings();
    
    void loadLastSettings();

    void saveLastSettings();

    void loadSettingsFile();

    void showInfo();

    void writeInfoBox(QString dataFile, QString runNum, QString subRunNum);

    void on_mcaSaveButton_clicked();

    void readMCAFiles();

    void plotMCAFiles();

    void saveSettings();

    void saveAsSettings();

    void showAll();
    void showGe();
    void showSi();

    void showSubrunPopup();

    void detComboBox(int);

private:
    QString filename;
    Ui::XiaStarterWindow *ui;
    XiaStarter *xs;
    
    QMenu *loadMenu;
    QMenu *saveMenu;

    preferencedialog *p;
    
    QAction *defaultAction;
    QAction *lastAction;
    QAction *loadFileAction;
    QAction *saveAction;
    QAction *saveAsAction;

    QString saveFileName;

	int mcaTimeNumber;


    QString hwHistDir;
    QString sourceConfPath;

    std::vector<QVector<double> > mcaCounts;
    std::vector<QVector<double> > mcaChannels;

    int showRatesFor;    

};

#endif // XIASTARTERWINDOW_H
