/****************************************************************************
** Meta object code from reading C++ file 'xiastarterwindow.h'
**
** Created: Fri Sep 13 18:52:11 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/xiastarterwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xiastarterwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XiaStarterWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   47,   17,   17, 0x0a,
      73,   69,   17,   17, 0x0a,
     101,   94,   17,   17, 0x0a,
     126,  119,   17,   17, 0x0a,
     147,   17,   17,   17, 0x0a,
     165,  159,   17,   17, 0x0a,
     202,  159,   17,   17, 0x0a,
     242,   17,   17,   17, 0x0a,
     272,  263,   17,   17, 0x0a,
     294,  292,   17,   17, 0x0a,
     312,   17,   17,   17, 0x0a,
     332,   17,   17,   17, 0x0a,
     364,   17,   17,   17, 0x08,
     377,   17,   17,   17, 0x08,
     398,   17,   17,   17, 0x08,
     416,   17,   17,   17, 0x08,
     432,   17,   17,   17, 0x08,
     456,   17,   17,   17, 0x08,
     481,   17,   17,   17, 0x08,
     507,   17,   17,   17, 0x08,
     530,   17,   17,   17, 0x08,
     545,   17,   17,   17, 0x08,
     570,   17,   17,   17, 0x08,
     594,   17,   17,   17, 0x08,
     622,   17,   17,   17, 0x08,
     649,   17,   17,   17, 0x08,
     682,   17,   17,   17, 0x08,
     712,   17,   17,   17, 0x08,
     736,   17,   17,   17, 0x08,
     761,   17,   17,   17, 0x08,
     785,   17,   17,   17, 0x08,
     803,   17,   17,   17, 0x08,
     825,   17,   17,   17, 0x08,
     844,   17,   17,   17, 0x08,
     863,   17,   17,   17, 0x08,
     882,   17,   17,   17, 0x08,
     919,  893,   17,   17, 0x08,
     957,   17,   17,   17, 0x08,
     984,   17,   17,   17, 0x08,
     999,   17,   17,   17, 0x08,
    1014,   17,   17,   17, 0x08,
    1029,   17,   17,   17, 0x08,
    1046,   17,   17,   17, 0x08,
    1056,   17,   17,   17, 0x08,
    1065,   17,   17,   17, 0x08,
    1074,   17,   17,   17, 0x08,
    1092,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_XiaStarterWindow[] = {
    "XiaStarterWindow\0\0saveFileNameIsNotEmpty(bool)\0"
    "num\0changeStatus(int)\0msg\0"
    "writeOutput(QString)\0nummer\0"
    "changeRunNum(int)\0number\0changeSubrunNum(int)\0"
    "plotRates()\0state\0"
    "writerStatus(QProcess::ProcessState)\0"
    "collectorStatus(QProcess::ProcessState)\0"
    "setFileName(QString)\0filesize\0"
    "newFileSize(qint64)\0b\0viewButtons(bool)\0"
    "prefTabChanged(int)\0ratesContextMenuRequest(QPoint)\0"
    "removeFile()\0sourceconf_clicked()\0"
    "dgfconf_clicked()\0about_clicked()\0"
    "on_bootButton_clicked()\0"
    "on_closeButton_clicked()\0"
    "on_browseButton_clicked()\0"
    "on_runButton_clicked()\0runCollector()\0"
    "on_startButton_clicked()\0"
    "on_stopButton_clicked()\0"
    "on_mcaStartButton_clicked()\0"
    "on_mcaStopButton_clicked()\0"
    "on_mcaViewlatestButton_clicked()\0"
    "on_mcaReadoutButton_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_setupButton_clicked()\0"
    "on_killButton_clicked()\0showPreferences()\0"
    "loadDefaultSettings()\0loadLastSettings()\0"
    "saveLastSettings()\0loadSettingsFile()\0"
    "showInfo()\0dataFile,runNum,subRunNum\0"
    "writeInfoBox(QString,QString,QString)\0"
    "on_mcaSaveButton_clicked()\0readMCAFiles()\0"
    "plotMCAFiles()\0saveSettings()\0"
    "saveAsSettings()\0showAll()\0showGe()\0"
    "showSi()\0showSubrunPopup()\0detComboBox(int)\0"
};

const QMetaObject XiaStarterWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_XiaStarterWindow,
      qt_meta_data_XiaStarterWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XiaStarterWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XiaStarterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XiaStarterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XiaStarterWindow))
        return static_cast<void*>(const_cast< XiaStarterWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int XiaStarterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: saveFileNameIsNotEmpty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: changeStatus((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: writeOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: changeRunNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: changeSubrunNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: plotRates(); break;
        case 6: writerStatus((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 7: collectorStatus((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 8: setFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: newFileSize((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 10: viewButtons((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: prefTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: ratesContextMenuRequest((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 13: removeFile(); break;
        case 14: sourceconf_clicked(); break;
        case 15: dgfconf_clicked(); break;
        case 16: about_clicked(); break;
        case 17: on_bootButton_clicked(); break;
        case 18: on_closeButton_clicked(); break;
        case 19: on_browseButton_clicked(); break;
        case 20: on_runButton_clicked(); break;
        case 21: runCollector(); break;
        case 22: on_startButton_clicked(); break;
        case 23: on_stopButton_clicked(); break;
        case 24: on_mcaStartButton_clicked(); break;
        case 25: on_mcaStopButton_clicked(); break;
        case 26: on_mcaViewlatestButton_clicked(); break;
        case 27: on_mcaReadoutButton_clicked(); break;
        case 28: on_pushButton_clicked(); break;
        case 29: on_setupButton_clicked(); break;
        case 30: on_killButton_clicked(); break;
        case 31: showPreferences(); break;
        case 32: loadDefaultSettings(); break;
        case 33: loadLastSettings(); break;
        case 34: saveLastSettings(); break;
        case 35: loadSettingsFile(); break;
        case 36: showInfo(); break;
        case 37: writeInfoBox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 38: on_mcaSaveButton_clicked(); break;
        case 39: readMCAFiles(); break;
        case 40: plotMCAFiles(); break;
        case 41: saveSettings(); break;
        case 42: saveAsSettings(); break;
        case 43: showAll(); break;
        case 44: showGe(); break;
        case 45: showSi(); break;
        case 46: showSubrunPopup(); break;
        case 47: detComboBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void XiaStarterWindow::saveFileNameIsNotEmpty(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
