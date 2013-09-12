/**********************************************************************
*                                                                     *
*                            xs_info.cpp                              *
*                                                                     *
*         This file is part of the XiaStarter-source code             *
*            by Philipp Scholz pscholz@ikp.uni-koeln.de               *
*                                                                     *
*                                                                     *
***********************************************************************/
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
