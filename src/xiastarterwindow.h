/******************************************************************************

    xiastarterwindow.h

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
    bool collectorTerminal;
    QString version;
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
    void radioChanged(bool check);
    void scope(bool scopeIsOn);




    
private slots:
    void setTerminalCheck(bool);

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
