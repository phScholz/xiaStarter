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
