/****************************************************************************
** Meta object code from reading C++ file 'sourceconfdialog.h'
**
** Created: Fri Sep 13 18:52:13 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/sourceconfdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sourceconfdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sourceconfDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   17,   17,   17, 0x08,
      62,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_sourceconfDialog[] = {
    "sourceconfDialog\0\0sourceConfChanged()\0"
    "on_buttonBox_accepted()\0on_buttonBox_rejected()\0"
};

const QMetaObject sourceconfDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_sourceconfDialog,
      qt_meta_data_sourceconfDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sourceconfDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sourceconfDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sourceconfDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sourceconfDialog))
        return static_cast<void*>(const_cast< sourceconfDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int sourceconfDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sourceConfChanged(); break;
        case 1: on_buttonBox_accepted(); break;
        case 2: on_buttonBox_rejected(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void sourceconfDialog::sourceConfChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
