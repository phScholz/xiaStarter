/******************************************************************************

    xs_info.h

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
#ifndef XS_INFO_H
#define XS_INFO_H
#include <QString>
#include <QVector>

class xs_info
{
public:
    xs_info();

    void setInfoRunPath(const QString);
    void setInfoFileName(const QString);
    void setInfoPrefix(const QString);
    void setInfoDetNames(QVector<QString> * );
    void setInfoRunNumber(int);
    void setInfoSubrunNumber(int);

    QString getInfoRunPath();
    QString getInfoFileName();
    QString getInfoPrefix();
    int getInfoRunNumber();
    int getInfoSubrunNumber();
    void getInfoDetNames(QVector<QString> *);


private:
    QString infoRunPath;
    QString infoFileName;
    QString infoPrefix;

    QVector<QString> *infoDetNames;

    int infoRunNumber;
    int infoSubrunNumber;


};

#endif // XS_INFO_H
