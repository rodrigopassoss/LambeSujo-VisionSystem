/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mouseevents_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mouseevents_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mouseevents_t qt_meta_stringdata_mouseevents = {
    {
QT_MOC_LITERAL(0, 0, 11), // "mouseevents"
QT_MOC_LITERAL(1, 12, 9), // "Mouse_pos"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13) // "Mouse_pressed"

    },
    "mouseevents\0Mouse_pos\0\0Mouse_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mouseevents[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mouseevents::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mouseevents *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Mouse_pos(); break;
        case 1: _t->Mouse_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mouseevents::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mouseevents::Mouse_pos)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mouseevents::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mouseevents::Mouse_pressed)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mouseevents::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_mouseevents.data,
    qt_meta_data_mouseevents,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mouseevents::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mouseevents::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mouseevents.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int mouseevents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void mouseevents::Mouse_pos()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void mouseevents::Mouse_pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[91];
    char stringdata0[2104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "Robos"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "Robot"
QT_MOC_LITERAL(4, 24, 3), // "rb1"
QT_MOC_LITERAL(5, 28, 3), // "rb2"
QT_MOC_LITERAL(6, 32, 3), // "rb3"
QT_MOC_LITERAL(7, 36, 17), // "Mouse_current_pos"
QT_MOC_LITERAL(8, 54, 13), // "Mouse_pressed"
QT_MOC_LITERAL(9, 68, 23), // "Refresh_position_robots"
QT_MOC_LITERAL(10, 92, 11), // "calibration"
QT_MOC_LITERAL(11, 104, 25), // "on_actionKmeans_triggered"
QT_MOC_LITERAL(12, 130, 24), // "on_select_azul_triggered"
QT_MOC_LITERAL(13, 155, 27), // "on_select_amarelo_triggered"
QT_MOC_LITERAL(14, 183, 27), // "on_actionComandos_triggered"
QT_MOC_LITERAL(15, 211, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 233, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(17, 257, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(18, 289, 5), // "index"
QT_MOC_LITERAL(19, 295, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(20, 317, 33), // "on_actionAbrir_Settings_trigg..."
QT_MOC_LITERAL(21, 351, 23), // "on_select_RGB_triggered"
QT_MOC_LITERAL(22, 375, 27), // "on_select_New_RGB_triggered"
QT_MOC_LITERAL(23, 403, 23), // "on_select_HSV_triggered"
QT_MOC_LITERAL(24, 427, 7), // "checked"
QT_MOC_LITERAL(25, 435, 25), // "on_contraste_valueChanged"
QT_MOC_LITERAL(26, 461, 5), // "value"
QT_MOC_LITERAL(27, 467, 25), // "on_saturacao_valueChanged"
QT_MOC_LITERAL(28, 493, 22), // "on_brilho_valueChanged"
QT_MOC_LITERAL(29, 516, 25), // "on_exposicao_valueChanged"
QT_MOC_LITERAL(30, 542, 32), // "on_Resolucao_currentIndexChanged"
QT_MOC_LITERAL(31, 575, 19), // "on_hue_valueChanged"
QT_MOC_LITERAL(32, 595, 29), // "on_white_balance_valueChanged"
QT_MOC_LITERAL(33, 625, 21), // "on_Gamma_valueChanged"
QT_MOC_LITERAL(34, 647, 20), // "on_Gain_valueChanged"
QT_MOC_LITERAL(35, 668, 33), // "on_Back_Compensation_valueCha..."
QT_MOC_LITERAL(36, 702, 23), // "on_nitidez_valueChanged"
QT_MOC_LITERAL(37, 726, 21), // "select_Limiar2Segment"
QT_MOC_LITERAL(38, 748, 4), // "Mat*"
QT_MOC_LITERAL(39, 753, 3), // "Mat"
QT_MOC_LITERAL(40, 757, 15), // "change_limiares"
QT_MOC_LITERAL(41, 773, 3), // "row"
QT_MOC_LITERAL(42, 777, 3), // "col"
QT_MOC_LITERAL(43, 781, 20), // "on_bmin_valueChanged"
QT_MOC_LITERAL(44, 802, 20), // "on_gmin_valueChanged"
QT_MOC_LITERAL(45, 823, 20), // "on_rmin_valueChanged"
QT_MOC_LITERAL(46, 844, 20), // "on_bmax_valueChanged"
QT_MOC_LITERAL(47, 865, 20), // "on_gmax_valueChanged"
QT_MOC_LITERAL(48, 886, 20), // "on_rmax_valueChanged"
QT_MOC_LITERAL(49, 907, 38), // "on_comboBox_colors_currentInd..."
QT_MOC_LITERAL(50, 946, 13), // "set_ui_values"
QT_MOC_LITERAL(51, 960, 32), // "on_spinBox_abertura_valueChanged"
QT_MOC_LITERAL(52, 993, 4), // "arg1"
QT_MOC_LITERAL(53, 998, 34), // "on_spinBox_fechamento_valueCh..."
QT_MOC_LITERAL(54, 1033, 40), // "on_comboBox_tipomask_currentI..."
QT_MOC_LITERAL(55, 1074, 12), // "set_mascaras"
QT_MOC_LITERAL(56, 1087, 29), // "on_spinBox_cut_y_valueChanged"
QT_MOC_LITERAL(57, 1117, 29), // "on_spinBox_cut_x_valueChanged"
QT_MOC_LITERAL(58, 1147, 33), // "on_spinBox_cut_width_valueCha..."
QT_MOC_LITERAL(59, 1181, 34), // "on_spinBox_cut_height_valueCh..."
QT_MOC_LITERAL(60, 1216, 29), // "on_checkBox_expo_auto_clicked"
QT_MOC_LITERAL(61, 1246, 27), // "on_checkBox_wb_auto_clicked"
QT_MOC_LITERAL(62, 1274, 34), // "on_pushButton_linhas_campo_cl..."
QT_MOC_LITERAL(63, 1309, 17), // "plotar_principais"
QT_MOC_LITERAL(64, 1327, 18), // "plotar_secundarias"
QT_MOC_LITERAL(65, 1346, 28), // "on_spinBox_ftop_valueChanged"
QT_MOC_LITERAL(66, 1375, 28), // "on_spinBox_fbot_valueChanged"
QT_MOC_LITERAL(67, 1404, 29), // "on_spinBox_gtopy_valueChanged"
QT_MOC_LITERAL(68, 1434, 29), // "on_spinBox_gboty_valueChanged"
QT_MOC_LITERAL(69, 1464, 30), // "on_spinBox_fleftx_valueChanged"
QT_MOC_LITERAL(70, 1495, 31), // "on_spinBox_frightx_valueChanged"
QT_MOC_LITERAL(71, 1527, 29), // "on_spinBox_gleft_valueChanged"
QT_MOC_LITERAL(72, 1557, 30), // "on_spinBox_gright_valueChanged"
QT_MOC_LITERAL(73, 1588, 33), // "on_spinBox_area_left_valueCha..."
QT_MOC_LITERAL(74, 1622, 34), // "on_spinBox_area_right_valueCh..."
QT_MOC_LITERAL(75, 1657, 33), // "on_spinBox_lzagueiro_valueCha..."
QT_MOC_LITERAL(76, 1691, 32), // "on_spinBox_lgoleiro_valueChanged"
QT_MOC_LITERAL(77, 1724, 33), // "on_spinBox_area_topy_valueCha..."
QT_MOC_LITERAL(78, 1758, 33), // "on_spinBox_area_boty_valueCha..."
QT_MOC_LITERAL(79, 1792, 32), // "on_spinBox_p_area_b_valueChanged"
QT_MOC_LITERAL(80, 1825, 32), // "on_spinBox_p_area_t_valueChanged"
QT_MOC_LITERAL(81, 1858, 28), // "on_pushButton_cortar_clicked"
QT_MOC_LITERAL(82, 1887, 30), // "on_checkBox_help_lines_pressed"
QT_MOC_LITERAL(83, 1918, 30), // "on_checkBox_help_lines_clicked"
QT_MOC_LITERAL(84, 1949, 24), // "on_refresh_ports_clicked"
QT_MOC_LITERAL(85, 1974, 10), // "info_ports"
QT_MOC_LITERAL(86, 1985, 20), // "on_read_data_clicked"
QT_MOC_LITERAL(87, 2006, 21), // "on_write_data_clicked"
QT_MOC_LITERAL(88, 2028, 29), // "on_connect_disconnect_clicked"
QT_MOC_LITERAL(89, 2058, 22), // "on_sendvl_valueChanged"
QT_MOC_LITERAL(90, 2081, 22) // "on_sendvr_valueChanged"

    },
    "MainWindow\0Robos\0\0Robot\0rb1\0rb2\0rb3\0"
    "Mouse_current_pos\0Mouse_pressed\0"
    "Refresh_position_robots\0calibration\0"
    "on_actionKmeans_triggered\0"
    "on_select_azul_triggered\0"
    "on_select_amarelo_triggered\0"
    "on_actionComandos_triggered\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_comboBox_activated\0"
    "on_actionAbrir_Settings_triggered\0"
    "on_select_RGB_triggered\0"
    "on_select_New_RGB_triggered\0"
    "on_select_HSV_triggered\0checked\0"
    "on_contraste_valueChanged\0value\0"
    "on_saturacao_valueChanged\0"
    "on_brilho_valueChanged\0on_exposicao_valueChanged\0"
    "on_Resolucao_currentIndexChanged\0"
    "on_hue_valueChanged\0on_white_balance_valueChanged\0"
    "on_Gamma_valueChanged\0on_Gain_valueChanged\0"
    "on_Back_Compensation_valueChanged\0"
    "on_nitidez_valueChanged\0select_Limiar2Segment\0"
    "Mat*\0Mat\0change_limiares\0row\0col\0"
    "on_bmin_valueChanged\0on_gmin_valueChanged\0"
    "on_rmin_valueChanged\0on_bmax_valueChanged\0"
    "on_gmax_valueChanged\0on_rmax_valueChanged\0"
    "on_comboBox_colors_currentIndexChanged\0"
    "set_ui_values\0on_spinBox_abertura_valueChanged\0"
    "arg1\0on_spinBox_fechamento_valueChanged\0"
    "on_comboBox_tipomask_currentIndexChanged\0"
    "set_mascaras\0on_spinBox_cut_y_valueChanged\0"
    "on_spinBox_cut_x_valueChanged\0"
    "on_spinBox_cut_width_valueChanged\0"
    "on_spinBox_cut_height_valueChanged\0"
    "on_checkBox_expo_auto_clicked\0"
    "on_checkBox_wb_auto_clicked\0"
    "on_pushButton_linhas_campo_clicked\0"
    "plotar_principais\0plotar_secundarias\0"
    "on_spinBox_ftop_valueChanged\0"
    "on_spinBox_fbot_valueChanged\0"
    "on_spinBox_gtopy_valueChanged\0"
    "on_spinBox_gboty_valueChanged\0"
    "on_spinBox_fleftx_valueChanged\0"
    "on_spinBox_frightx_valueChanged\0"
    "on_spinBox_gleft_valueChanged\0"
    "on_spinBox_gright_valueChanged\0"
    "on_spinBox_area_left_valueChanged\0"
    "on_spinBox_area_right_valueChanged\0"
    "on_spinBox_lzagueiro_valueChanged\0"
    "on_spinBox_lgoleiro_valueChanged\0"
    "on_spinBox_area_topy_valueChanged\0"
    "on_spinBox_area_boty_valueChanged\0"
    "on_spinBox_p_area_b_valueChanged\0"
    "on_spinBox_p_area_t_valueChanged\0"
    "on_pushButton_cortar_clicked\0"
    "on_checkBox_help_lines_pressed\0"
    "on_checkBox_help_lines_clicked\0"
    "on_refresh_ports_clicked\0info_ports\0"
    "on_read_data_clicked\0on_write_data_clicked\0"
    "on_connect_disconnect_clicked\0"
    "on_sendvl_valueChanged\0on_sendvr_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      78,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  404,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  411,    2, 0x08 /* Private */,
       8,    0,  412,    2, 0x08 /* Private */,
       9,    0,  413,    2, 0x08 /* Private */,
      10,    0,  414,    2, 0x08 /* Private */,
      11,    0,  415,    2, 0x08 /* Private */,
      12,    0,  416,    2, 0x08 /* Private */,
      13,    0,  417,    2, 0x08 /* Private */,
      14,    0,  418,    2, 0x08 /* Private */,
      15,    0,  419,    2, 0x08 /* Private */,
      16,    0,  420,    2, 0x08 /* Private */,
      17,    1,  421,    2, 0x08 /* Private */,
      19,    1,  424,    2, 0x08 /* Private */,
      20,    0,  427,    2, 0x08 /* Private */,
      21,    0,  428,    2, 0x08 /* Private */,
      22,    0,  429,    2, 0x08 /* Private */,
      23,    1,  430,    2, 0x08 /* Private */,
      23,    0,  433,    2, 0x08 /* Private */,
      25,    1,  434,    2, 0x08 /* Private */,
      27,    1,  437,    2, 0x08 /* Private */,
      28,    1,  440,    2, 0x08 /* Private */,
      29,    1,  443,    2, 0x08 /* Private */,
      30,    1,  446,    2, 0x08 /* Private */,
      31,    1,  449,    2, 0x08 /* Private */,
      32,    1,  452,    2, 0x08 /* Private */,
      33,    1,  455,    2, 0x08 /* Private */,
      34,    1,  458,    2, 0x08 /* Private */,
      35,    1,  461,    2, 0x08 /* Private */,
      36,    1,  464,    2, 0x08 /* Private */,
      37,    1,  467,    2, 0x08 /* Private */,
      40,    3,  470,    2, 0x08 /* Private */,
      43,    1,  477,    2, 0x08 /* Private */,
      44,    1,  480,    2, 0x08 /* Private */,
      45,    1,  483,    2, 0x08 /* Private */,
      46,    1,  486,    2, 0x08 /* Private */,
      47,    1,  489,    2, 0x08 /* Private */,
      48,    1,  492,    2, 0x08 /* Private */,
      49,    1,  495,    2, 0x08 /* Private */,
      50,    0,  498,    2, 0x08 /* Private */,
      51,    1,  499,    2, 0x08 /* Private */,
      53,    1,  502,    2, 0x08 /* Private */,
      54,    1,  505,    2, 0x08 /* Private */,
      55,    0,  508,    2, 0x08 /* Private */,
      56,    1,  509,    2, 0x08 /* Private */,
      57,    1,  512,    2, 0x08 /* Private */,
      58,    1,  515,    2, 0x08 /* Private */,
      59,    1,  518,    2, 0x08 /* Private */,
      60,    1,  521,    2, 0x08 /* Private */,
      61,    1,  524,    2, 0x08 /* Private */,
      62,    0,  527,    2, 0x08 /* Private */,
      63,    0,  528,    2, 0x08 /* Private */,
      64,    0,  529,    2, 0x08 /* Private */,
      65,    1,  530,    2, 0x08 /* Private */,
      66,    1,  533,    2, 0x08 /* Private */,
      67,    1,  536,    2, 0x08 /* Private */,
      68,    1,  539,    2, 0x08 /* Private */,
      69,    1,  542,    2, 0x08 /* Private */,
      70,    1,  545,    2, 0x08 /* Private */,
      71,    1,  548,    2, 0x08 /* Private */,
      72,    1,  551,    2, 0x08 /* Private */,
      73,    1,  554,    2, 0x08 /* Private */,
      74,    1,  557,    2, 0x08 /* Private */,
      75,    1,  560,    2, 0x08 /* Private */,
      76,    1,  563,    2, 0x08 /* Private */,
      77,    1,  566,    2, 0x08 /* Private */,
      78,    1,  569,    2, 0x08 /* Private */,
      79,    1,  572,    2, 0x08 /* Private */,
      80,    1,  575,    2, 0x08 /* Private */,
      81,    0,  578,    2, 0x08 /* Private */,
      82,    0,  579,    2, 0x08 /* Private */,
      83,    1,  580,    2, 0x08 /* Private */,
      84,    0,  583,    2, 0x08 /* Private */,
      85,    0,  584,    2, 0x08 /* Private */,
      86,    0,  585,    2, 0x08 /* Private */,
      87,    0,  586,    2, 0x08 /* Private */,
      88,    0,  587,    2, 0x08 /* Private */,
      89,    1,  588,    2, 0x08 /* Private */,
      90,    1,  591,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    0x80000000 | 38, 0x80000000 | 39,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   26,   41,   42,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Robos((*reinterpret_cast< Robot(*)>(_a[1])),(*reinterpret_cast< Robot(*)>(_a[2])),(*reinterpret_cast< Robot(*)>(_a[3]))); break;
        case 1: _t->Mouse_current_pos(); break;
        case 2: _t->Mouse_pressed(); break;
        case 3: _t->Refresh_position_robots(); break;
        case 4: _t->calibration(); break;
        case 5: _t->on_actionKmeans_triggered(); break;
        case 6: _t->on_select_azul_triggered(); break;
        case 7: _t->on_select_amarelo_triggered(); break;
        case 8: _t->on_actionComandos_triggered(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_actionAbrir_Settings_triggered(); break;
        case 14: _t->on_select_RGB_triggered(); break;
        case 15: _t->on_select_New_RGB_triggered(); break;
        case 16: _t->on_select_HSV_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_select_HSV_triggered(); break;
        case 18: _t->on_contraste_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_saturacao_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_brilho_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_exposicao_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_Resolucao_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_hue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_white_balance_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_Gamma_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_Gain_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_Back_Compensation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_nitidez_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: { Mat* _r = _t->select_Limiar2Segment((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Mat**>(_a[0]) = std::move(_r); }  break;
        case 30: _t->change_limiares((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 31: _t->on_bmin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_gmin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_rmin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_bmax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_gmax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_rmax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_comboBox_colors_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->set_ui_values(); break;
        case 39: _t->on_spinBox_abertura_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_spinBox_fechamento_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_comboBox_tipomask_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->set_mascaras(); break;
        case 43: _t->on_spinBox_cut_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_spinBox_cut_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_spinBox_cut_width_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_spinBox_cut_height_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_checkBox_expo_auto_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_checkBox_wb_auto_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_pushButton_linhas_campo_clicked(); break;
        case 50: _t->plotar_principais(); break;
        case 51: _t->plotar_secundarias(); break;
        case 52: _t->on_spinBox_ftop_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->on_spinBox_fbot_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->on_spinBox_gtopy_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->on_spinBox_gboty_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->on_spinBox_fleftx_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->on_spinBox_frightx_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->on_spinBox_gleft_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->on_spinBox_gright_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->on_spinBox_area_left_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->on_spinBox_area_right_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: _t->on_spinBox_lzagueiro_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->on_spinBox_lgoleiro_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: _t->on_spinBox_area_topy_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->on_spinBox_area_boty_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->on_spinBox_p_area_b_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: _t->on_spinBox_p_area_t_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 68: _t->on_pushButton_cortar_clicked(); break;
        case 69: _t->on_checkBox_help_lines_pressed(); break;
        case 70: _t->on_checkBox_help_lines_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 71: _t->on_refresh_ports_clicked(); break;
        case 72: _t->info_ports(); break;
        case 73: _t->on_read_data_clicked(); break;
        case 74: _t->on_write_data_clicked(); break;
        case 75: _t->on_connect_disconnect_clicked(); break;
        case 76: _t->on_sendvl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->on_sendvr_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(Robot , Robot , Robot );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::Robos)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 78)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 78;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::Robos(Robot _t1, Robot _t2, Robot _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
