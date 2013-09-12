#ifndef PSASETTINGS_H
#define PSASETTINGS_H

#include <QDialog>
#include <QVector>

namespace Ui {
class psaSettings;
}

class psaSettings : public QDialog
{
    Q_OBJECT
    
public:

    explicit psaSettings(QWidget *parent = 0);
    ~psaSettings();

    QVector<int> values;

public slots:
    void setInput(QVector<int> );
    void somethingChanged(int value);
    void buttonBoxOk();
    void buttonBoxCancel();

signals:
    void sendValues(QVector<int>);
    
private:
    Ui::psaSettings *ui;
};

#endif // PSASETTINGS_H
