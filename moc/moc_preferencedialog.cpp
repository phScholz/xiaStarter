/****************************************************************************
** Meta object code from reading C++ file 'preferencedialog.h'
**
** Created: Fri Sep 13 18:52:16 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/preferencedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferencedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_preferencedialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      51,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   17,   17,   17, 0x0a,
     105,   17,   17,   17, 0x08,
     128,   17,   17,   17, 0x08,
     154,   17,   17,   17, 0x08,
     178,   17,   17,   17, 0x08,
     204,   17,   17,   17, 0x08,
     223,   17,   17,   17, 0x08,
     249,   17,   17,   17, 0x08,
     273,   17,   17,   17, 0x08,
     300,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_preferencedialog[] = {
    "preferencedialog\0\0detsChanged(std::vector<xs_det>)\0"
    "tabChanged(int)\0detectorsChanged(std::vector<xs_det>)\0"
    "on_addButton_clicked()\0on_cancelButton_clicked()\0"
    "on_saveButton_clicked()\0"
    "on_removeButton_clicked()\0tabWasChanged(int)\0"
    "calStringChanged(QString)\0"
    "detTypeChanged(QString)\0"
    "ratesLimitChanged(QString)\0setupDetTable()\0"
};

const QMetaObject preferencedialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_preferencedialog,
      qt_meta_data_preferencedialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &preferencedialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *preferencedialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *preferencedialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_preferencedialog))
        return static_cast<void*>(const_cast< preferencedialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int preferencedialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: detsChanged((*reinterpret_cast< std::vector<xs_det>(*)>(_a[1]))); break;
        case 1: tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: detectorsChanged((*reinterpret_cast< std::vector<xs_det>(*)>(_a[1]))); break;
        case 3: on_addButton_clicked(); break;
        case 4: on_cancelButton_clicked(); break;
        case 5: on_saveButton_clicked(); break;
        case 6: on_removeButton_clicked(); break;
        case 7: tabWasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: calStringChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: detTypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: ratesLimitChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: setupDetTable(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void preferencedialog::detsChanged(std::vector<xs_det> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void preferencedialog::tabChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
