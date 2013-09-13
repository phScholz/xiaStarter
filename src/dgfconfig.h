/******************************************************************************

    dgfconfig.h

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

#ifndef DGFCONFIG_H
#define DGFCONFIG_H

#include <QDialog>
#include <QString>
#include <vector>
#include <QStringListModel>

class dgfSettings{

public:

    dgfSettings();

    int positivePolarity;
    double tau;
    double gain;
    double offset;
    double slowLength;
    double slowGap;
    int baselineAveraging;
    int fastLength;
    int fastGap;
    int threshold;
    int traceLength;
    int psaLength;
    int userDelay;
    int psaOffset;
    int mcaBining;
    double mcaThreshold;
    int cfdTriggerDelay;
    int cfdDelay;
    int cfdThreshold;
    double cfdFraction;
    int cfdGroupTrigger;
    int baselineCut;
    int integrator;
    int channelGateRequired;
    int gfltPolarity;
    int gateAcceptancePolarity;
    int useGfltForGate;
    int gateEdgePolarityInversion;
    int gateWindow;
    int gateDelayWindow;
    int disablePileUpRejector;
    int invertPileUpRejector;
    int pausePileUprejector;
    int disableOutOfRangeSuppression;
    int estimateEnergy;
    int allowNegativeEnergies;
    int localTime;

};

namespace Ui {
class dgfConfig;
}

class dgfConfig: public QDialog
{
    Q_OBJECT
    
public:
    explicit dgfConfig(QWidget *parent = 0);
    ~dgfConfig();
    bool check;
    int currentIndex;

public slots:
    void loadDets(std::vector<QString> detnames);
    void readSetting(QString det);
    void writeSetting(QString detName, int detNumber);
    void displaySetting(int detNumber);
    void indexClicked(QModelIndex modelIndex);
    void somethingChanged(int value);
    void somethingChanged(double value);
    void saveSettings();
    void saveAll();
    void showPsaSettings();
    void psaSettingsChanged(QVector<int> input);

    
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::dgfConfig *ui;
    QString configDir;
    QStringListModel * bla;
    QStringList *detList;
    std::vector<dgfSettings> detSettings;
    dgfSettings working;
};



#endif // DGFCONFIG_H
