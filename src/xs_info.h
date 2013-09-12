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
