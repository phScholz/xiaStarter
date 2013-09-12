/**********************************************************************
*                                                                     *
*                            dgfconfig.h                              *
*                                                                     *
*         This file is part of the XiaStarter-source code             *
*            by Philipp Scholz pscholz@ikp.uni-koeln.de               *
*                                                                     *
*                                                                     *
***********************************************************************/

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
