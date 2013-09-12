#ifndef SOURCECONFDIALOG_H
#define SOURCECONFDIALOG_H

#include <QDialog>

namespace Ui {
class sourceconfDialog;
}

class sourceconfDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sourceconfDialog(QWidget *parent = 0);
    ~sourceconfDialog();

signals:
    void sourceConfChanged();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::sourceconfDialog *ui;
    QString sourceConfPath;
};

#endif // SOURCECONFDIALOG_H
