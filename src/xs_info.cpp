/******************************************************************************

    xs_info.cpp

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
#include "xs_info.h"

xs_info::xs_info()
{

}

//----------------------------Setter Functions --------------------------
void xs_info::setInfoFileName(const QString filename){
    infoFileName=filename;
}

void xs_info::setInfoRunPath(const QString path){
    infoRunPath=path;
}

void xs_info::setInfoDetNames(QVector<QString> *detNames){

}

void xs_info::setInfoPrefix(const QString prefix){
    infoPrefix=prefix;
}

void xs_info::setInfoRunNumber(int num){
    infoRunNumber=num;
}

void xs_info::setInfoSubrunNumber(int num){
    infoSubrunNumber=num;
}

//----------------------------Getter Functions --------------------------
QString xs_info::getInfoRunPath(){
    return infoRunPath;
}

QString xs_info::getInfoFileName(){
    return infoFileName;
}

void xs_info::getInfoDetNames(QVector<QString> *targetVector){

    for(int i=0; i<targetVector->size(); i++){
        targetVector->pop_back();
    }

    for(int i=0; i<infoDetNames->size(); i++){
        targetVector->push_back(infoDetNames->at(i));
    }
}

int xs_info::getInfoRunNumber(){
    return infoRunNumber;
}

int xs_info::getInfoSubrunNumber(){
    return infoSubrunNumber;
}

QString xs_info::getInfoPrefix(){
    return infoPrefix;
}
