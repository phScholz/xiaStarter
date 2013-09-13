/******************************************************************************

    preferencedialog.h

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
