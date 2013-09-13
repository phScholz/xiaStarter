/******************************************************************************

    xs_det.h

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
#ifndef XS_DET_H
#define XS_DET_H
#include <QString>
class xs_det
{
public:
    xs_det();

    void setType(QString);
    void setName(QString);
    void setDgfmodule(QString);
    void setCrate(QString);
    void setSlot(QString);
    void setAddress(QString);
    void setCalFilePath(QString);
    void setDetType(QString);
    void setRatesLimit(QString);

    void setIdgfmodule(int);
    void setIcrate(int);
    void setIslot(int);
    void setIaddress(int);
    void setiRatesLimit(int);

    QString getType();
    QString getName();
    QString getDgfmodule();
    QString getCrate();
    QString getSlot();
    QString getAddress();
    QString getCalFilePath();
    QString getDetType();
    QString getRatesLimit();

    int getIdgfmodule();
    int getIcrate();
    int getIslot();
    int getIaddress();
    int getIratesLimit();


private:
        QString type;
        QString name;
        QString dgfmodule;
        QString crate;
        QString slot;
        QString address;
        QString sort;
        QString limit;
        QString calFilePath;
        QString detType;
        QString ratesLimit;

        int ilimit;
        int idgfmodule;
        int icrate;
        int islot;
        int iaddress;
        int iratesLimit;
};

#endif // XS_DET_H
