/******************************************************************************

    xs_det.cpp

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
#include "xs_det.h"

xs_det::xs_det()
{
}


/*-----------------------------Set-Functions-----------------------*/
void xs_det::setType(QString string){
    type=string;
}

void xs_det::setDetType(QString string){
    detType=string;
}

void xs_det::setRatesLimit(QString string){
    ratesLimit=string;
    iratesLimit=string.toInt();
}

void xs_det::setiRatesLimit(int num){
    iratesLimit=num;
}

void xs_det::setName(QString string){
    name=string;
}

void xs_det::setDgfmodule(QString string){
    dgfmodule=string;
}

void xs_det::setCrate(QString string){
    crate=string;
}

void xs_det::setSlot(QString string){
    slot=string;
    islot=string.toInt();
}

void xs_det::setAddress(QString string){
    address=string;
	iaddress=string.toInt();
}

void xs_det::setCalFilePath(QString string){
    calFilePath=string;
}

void xs_det::setIdgfmodule(int i){
    idgfmodule=i;
}

void xs_det::setIcrate(int i){
    icrate=i;
}

void xs_det::setIslot(int i){
    islot=i;
}

void xs_det::setIaddress(int i){
    iaddress=i;
}

/*------------------------------Get-Functions-------------------------*/

QString xs_det::getType(){
    return type;
}

QString xs_det::getDetType(){
    return detType;
}

QString xs_det::getRatesLimit(){
    return ratesLimit;
}

QString xs_det::getName(){
    return name;
}

QString xs_det::getDgfmodule(){
    return dgfmodule;
}

QString xs_det::getCrate(){
    return crate;
}

QString xs_det::getSlot(){
    return slot;
}

QString xs_det::getAddress(){
    return address;
}

QString xs_det::getCalFilePath(){
    return calFilePath;
}

int xs_det::getIdgfmodule(){
    return idgfmodule;
}

int xs_det::getIcrate(){
    return icrate;
}

int xs_det::getIslot(){
    return islot;
}

int xs_det::getIaddress(){
    return iaddress;
}

int xs_det::getIratesLimit(){
    return iratesLimit;
}
