/****************************************************************************
** Meta object code from reading C++ file 'dgfconfig.h'
**
** Created: Fri Sep 13 18:52:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dgfconfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dgfconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dgfConfig[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   11,   10,   10, 0x0a,
      55,   51,   10,   10, 0x0a,
      94,   76,   10,   10, 0x0a,
     130,  120,   10,   10, 0x0a,
     161,  150,   10,   10, 0x0a,
     193,  187,   10,   10, 0x0a,
     215,  187,   10,   10, 0x0a,
     240,   10,   10,   10, 0x0a,
     255,   10,   10,   10, 0x0a,
     265,   10,   10,   10, 0x0a,
     289,  283,   10,   10, 0x0a,
     322,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dgfConfig[] = {
    "dgfConfig\0\0detnames\0loadDets(std::vector<QString>)\0"
    "det\0readSetting(QString)\0detName,detNumber\0"
    "writeSetting(QString,int)\0detNumber\0"
    "displaySetting(int)\0modelIndex\0"
    "indexClicked(QModelIndex)\0value\0"
    "somethingChanged(int)\0somethingChanged(double)\0"
    "saveSettings()\0saveAll()\0showPsaSettings()\0"
    "input\0psaSettingsChanged(QVector<int>)\0"
    "on_pushButton_3_clicked()\0"
};

const QMetaObject dgfConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dgfConfig,
      qt_meta_data_dgfConfig, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dgfConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dgfConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dgfConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dgfConfig))
        return static_cast<void*>(const_cast< dgfConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int dgfConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadDets((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: readSetting((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: writeSetting((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: displaySetting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: indexClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: somethingChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: somethingChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: saveSettings(); break;
        case 8: saveAll(); break;
        case 9: showPsaSettings(); break;
        case 10: psaSettingsChanged((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 11: on_pushButton_3_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
