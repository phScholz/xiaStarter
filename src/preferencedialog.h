#ifndef PREFERENCEDIALOG_H
#define PREFERENCEDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QStringListModel>
#include <QString>
#include <QStringList>
#include "xs_det.h"
#include <QComboBox>
#include <QTableWidgetItem>
#include "xs_det.h"

namespace Ui {
class preferencedialog;
}

class preferencedialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit preferencedialog(QWidget *parent = 0);
    ~preferencedialog();

public slots:
    void detectorsChanged(std::vector<xs_det>);

private slots:
    void on_addButton_clicked();

    void on_cancelButton_clicked();

    void on_saveButton_clicked();

    void on_removeButton_clicked();
    
    void tabWasChanged(int);

    void calStringChanged(QString);

    void detTypeChanged(QString);

    void ratesLimitChanged(QString);

    void setupDetTable();



signals:

    void detsChanged(std::vector<xs_det>);

    void tabChanged(int);

private:
    Ui::preferencedialog *ui;

    QStringList calNames;
    QStringListModel *bla;
    QStringList calList;
    QVector<int> calNum;

    QComboBox *calCombo;

    bool check;

    void addCal();
    void removeCal();
    void writeCal();
    void readCal();
    void getDets();

    std::vector<xs_det> detectors;
};

#endif // PREFERENCEDIALOG_H
