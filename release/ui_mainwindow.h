/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../utils/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionKmeans;
    QAction *actionFind_Contours;
    QAction *actionComandos;
    QAction *actionAzul;
    QAction *actionAmarelo;
    QAction *select_azul;
    QAction *select_amarelo;
    QAction *actionAbrir_Settings;
    QAction *select_RGB;
    QAction *select_New_RGB;
    QAction *select_HSV;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *Tempo;
    QLabel *milesegundos;
    QLabel *Tempoms;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_63;
    QTabWidget *tabWidget;
    QWidget *Principal;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *janela;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *combo_atacante;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QFrame *line_2;
    QComboBox *combo_zagueiro;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *pushButton_2;
    QComboBox *combo_goleiro;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *calibracao;
    QGridLayout *gridLayout_62;
    QGridLayout *gridLayout_61;
    QLabel *janela_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_114;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_default;
    QPushButton *pushButton_apply;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout_60;
    QGridLayout *gridLayout_59;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_58;
    QGridLayout *gridLayout_53;
    QGridLayout *gridLayout_52;
    QGridLayout *gridLayout_51;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBox_cont;
    QSpinBox *spinBox_sat;
    QLabel *label_sat;
    QSpinBox *spinBox_hue;
    QSlider *saturacao;
    QSlider *hue;
    QSlider *exposicao;
    QSpinBox *spinBox_exp;
    QSlider *brilho;
    QLabel *label_exp;
    QSpinBox *spinBox_bri;
    QLabel *label_hue;
    QLabel *label_bri;
    QLabel *label_cont;
    QSlider *contraste;
    QGridLayout *gridLayout_6;
    QLabel *label_back_comp;
    QSpinBox *spinBox_back_compensation;
    QSlider *white_balance;
    QSlider *Gamma;
    QSpinBox *spinBox_wb;
    QSlider *Gain;
    QSpinBox *spinBox_gain;
    QLabel *label_wb;
    QSlider *Back_Compensation;
    QSlider *nitidez;
    QLabel *label_gamma;
    QLabel *label_gain;
    QLabel *label_nitidez;
    QSpinBox *spinBox_gamma;
    QSpinBox *spinBox_nitidez;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QFrame *line_22;
    QFrame *line_23;
    QSpacerItem *verticalSpacer_7;
    QGridLayout *gridLayout_11;
    QCheckBox *checkBox_expo_auto;
    QCheckBox *checkBox_wb_auto;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_57;
    QGridLayout *gridLayout_56;
    QGridLayout *gridLayout_55;
    QSpacerItem *verticalSpacer_9;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *Resolucao;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QPushButton *pushButton_cortar;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QLabel *label_11;
    QFrame *line_24;
    QFrame *line_30;
    QLabel *label_5;
    QFrame *line_27;
    QFrame *line_32;
    QFrame *line_31;
    QFrame *line_28;
    QSpinBox *spinBox_cut_height;
    QFrame *line_25;
    QLabel *label_6;
    QSpinBox *spinBox_cut_y;
    QFrame *line_26;
    QFrame *line_29;
    QLabel *label_13;
    QSpinBox *spinBox_cut_width;
    QLabel *label_12;
    QSpinBox *spinBox_cut_x;
    QFrame *line_33;
    QFrame *line_34;
    QFrame *line_35;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout_54;
    QCheckBox *checkBox_flip;
    QCheckBox *checkBox_resolution;
    QWidget *tab_2;
    QGridLayout *gridLayout_50;
    QGridLayout *gridLayout_49;
    QGroupBox *groupBox_limiares;
    QGridLayout *gridLayout_46;
    QGridLayout *gridLayout_45;
    QGridLayout *gridLayout_10;
    QCheckBox *checkBox_limiar;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_cor;
    QComboBox *comboBox_colors;
    QTabWidget *MenuColorSpace;
    QWidget *tab_3;
    QGridLayout *gridLayout_33;
    QGridLayout *gridLayout_32;
    QGroupBox *groupBox_r;
    QGridLayout *gridLayout_30;
    QGridLayout *gridLayout_14;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_rmax;
    QSlider *rmax;
    QSpinBox *spinBox_rmax;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_rmin;
    QSlider *rmin;
    QSpinBox *spinBox_rmin;
    QFrame *line_7;
    QGroupBox *groupBox_g;
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_15;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_gmin;
    QSlider *gmin;
    QSpinBox *spinBox_gmin;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_gmax;
    QSlider *gmax;
    QSpinBox *spinBox_gmax;
    QFrame *line_8;
    QGroupBox *groupBox_b;
    QGridLayout *gridLayout_31;
    QGridLayout *gridLayout_16;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_bmax;
    QSlider *bmax;
    QSpinBox *spinBox_bmax;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_bmin;
    QSlider *bmin;
    QSpinBox *spinBox_bmin;
    QFrame *line_9;
    QWidget *tab_4;
    QGridLayout *gridLayout_38;
    QGridLayout *gridLayout_37;
    QGroupBox *groupBox_h;
    QGridLayout *gridLayout_35;
    QGridLayout *gridLayout_20;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_36;
    QSlider *HSV_HMin;
    QSpinBox *HSV_HMin_2;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_35;
    QSlider *HSV_HMax;
    QSpinBox *HSV_HMax_2;
    QFrame *line_10;
    QGroupBox *groupBox_s;
    QGridLayout *gridLayout_34;
    QGridLayout *gridLayout_21;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_38;
    QSlider *HSV_SMin;
    QSpinBox *HSV_SMin_2;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_37;
    QSlider *HSV_SMax;
    QSpinBox *HSV_SMax_2;
    QFrame *line_11;
    QGroupBox *groupBox_v;
    QGridLayout *gridLayout_36;
    QGridLayout *gridLayout_22;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_39;
    QSlider *HSV_VMax;
    QSpinBox *HSV_VMax_2;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_40;
    QSlider *HSV_VMin;
    QSpinBox *HSV_VMin_2;
    QFrame *line_12;
    QWidget *tab_5;
    QGridLayout *gridLayout_44;
    QGridLayout *gridLayout_43;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_40;
    QGridLayout *gridLayout_23;
    QHBoxLayout *horizontalLayout_39;
    QLabel *label_41;
    QSlider *horizontalSlider_26;
    QSpinBox *spinBox_30;
    QHBoxLayout *horizontalLayout_40;
    QLabel *label_42;
    QSlider *horizontalSlider_27;
    QSpinBox *spinBox_31;
    QFrame *line_13;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_39;
    QGridLayout *gridLayout_24;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_44;
    QSlider *horizontalSlider_29;
    QSpinBox *spinBox_33;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_43;
    QSlider *horizontalSlider_28;
    QSpinBox *spinBox_32;
    QFrame *line_14;
    QGroupBox *groupBox_20;
    QGridLayout *gridLayout_41;
    QGridLayout *gridLayout_25;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_46;
    QSlider *horizontalSlider_31;
    QSpinBox *spinBox_35;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_45;
    QSlider *horizontalSlider_30;
    QSpinBox *spinBox_34;
    QFrame *line_15;
    QGridLayout *gridLayout_48;
    QGroupBox *groupBox_mask;
    QGridLayout *gridLayout_47;
    QGridLayout *gridLayout_29;
    QGridLayout *gridLayout_26;
    QLabel *label_tipomask;
    QComboBox *comboBox_tipomask;
    QGridLayout *gridLayout_27;
    QLabel *label_fechamento;
    QSpinBox *spinBox_fechamento;
    QFrame *line_17;
    QGridLayout *gridLayout_9;
    QLabel *label_abertura;
    QSpinBox *spinBox_abertura;
    QGridLayout *gridLayout_28;
    QCheckBox *checkBox_mask;
    QFrame *line_16;
    QFrame *line_18;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_6;
    QGridLayout *gridLayout_18;
    QGridLayout *gridLayout_17;
    QGroupBox *groupBox_variaveis;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_42;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_60;
    QLabel *label_73;
    QSpinBox *spinBox_gleft;
    QFrame *line_41;
    QHBoxLayout *horizontalLayout_61;
    QLabel *label_74;
    QSpinBox *spinBox_gright;
    QFrame *line_42;
    QHBoxLayout *horizontalLayout_70;
    QLabel *label_83;
    QSpinBox *spinBox_area_left;
    QFrame *line_43;
    QHBoxLayout *horizontalLayout_71;
    QLabel *label_84;
    QSpinBox *spinBox_area_right;
    QFrame *line_44;
    QHBoxLayout *horizontalLayout_72;
    QHBoxLayout *horizontalLayout_74;
    QLabel *label_87;
    QSpinBox *spinBox_lzagueiro;
    QFrame *line_45;
    QHBoxLayout *horizontalLayout_73;
    QLabel *label_86;
    QSpinBox *spinBox_lgoleiro;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QSpinBox *spinBox_ftop;
    QFrame *line_38;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_17;
    QSpinBox *spinBox_fbot;
    QFrame *line_37;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_69;
    QSpinBox *spinBox_gtopy;
    QFrame *line_36;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_70;
    QSpinBox *spinBox_gboty;
    QFrame *line_39;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_71;
    QSpinBox *spinBox_fleftx;
    QFrame *line_40;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_72;
    QSpinBox *spinBox_frightx;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_75;
    QLabel *label_88;
    QSpinBox *spinBox_area_topy;
    QFrame *line_48;
    QHBoxLayout *horizontalLayout_76;
    QLabel *label_89;
    QSpinBox *spinBox_area_boty;
    QFrame *line_47;
    QHBoxLayout *horizontalLayout_77;
    QLabel *label_90;
    QSpinBox *spinBox_p_area_b;
    QFrame *line_46;
    QHBoxLayout *horizontalLayout_78;
    QLabel *label_91;
    QSpinBox *spinBox_p_area_t;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_help_lines;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_12;
    QFrame *line_5;
    QCheckBox *checkBox_linha_principais;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_linhas_campo;
    QCheckBox *checkBox_linha_secundaria;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_10;
    QWidget *tab_7;
    QGroupBox *groupBox_4;
    QLabel *label_10;
    QLabel *monitor;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_70;
    QGridLayout *gridLayout_69;
    QGridLayout *gridLayout_66;
    QPushButton *write_data;
    QLineEdit *send_data;
    QLabel *label_14;
    QGridLayout *gridLayout_68;
    QGridLayout *gridLayout_67;
    QPushButton *read_data;
    QLineEdit *receive_data;
    QLabel *label_15;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_71;
    QGridLayout *gridLayout_65;
    QPushButton *connect_disconnect;
    QGridLayout *gridLayout_64;
    QLabel *label_9;
    QComboBox *select_ports;
    QPushButton *refresh_ports;
    QLabel *status;
    QCustomPlot *qcustomplot;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_81;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_79;
    QLabel *label_21;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QGridLayout *gridLayout_80;
    QLabel *label_22;
    QLCDNumber *lcdNumber_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_73;
    QLabel *label_18;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_10;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_78;
    QGridLayout *gridLayout_77;
    QGridLayout *gridLayout_75;
    QGridLayout *gridLayout_72;
    QLabel *label_19;
    QSlider *sendvl;
    QSpinBox *sendvl2;
    QGridLayout *gridLayout_76;
    QGridLayout *gridLayout_74;
    QSlider *sendvr;
    QLabel *label_20;
    QSpinBox *sendvr2;
    QMenuBar *menuBar;
    QMenu *menu_Classificadores;
    QMenu *menuTime;
    QMenu *menuEspa_o_de_cores;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1476, 1013);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(136, 138, 133, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(204, 207, 200, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(170, 172, 166, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(68, 69, 67, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(91, 92, 89, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(84, 2, 2, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        QBrush brush8(QColor(195, 196, 194, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush11(QColor(145, 145, 145, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icone/imagens/oie_transparent.png"), QSize(), QIcon::Active, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        actionKmeans = new QAction(MainWindow);
        actionKmeans->setObjectName(QString::fromUtf8("actionKmeans"));
        actionKmeans->setCheckable(false);
        actionKmeans->setChecked(false);
        actionFind_Contours = new QAction(MainWindow);
        actionFind_Contours->setObjectName(QString::fromUtf8("actionFind_Contours"));
        actionFind_Contours->setCheckable(false);
        actionComandos = new QAction(MainWindow);
        actionComandos->setObjectName(QString::fromUtf8("actionComandos"));
        actionAzul = new QAction(MainWindow);
        actionAzul->setObjectName(QString::fromUtf8("actionAzul"));
        actionAzul->setCheckable(true);
        actionAzul->setChecked(true);
        actionAmarelo = new QAction(MainWindow);
        actionAmarelo->setObjectName(QString::fromUtf8("actionAmarelo"));
        actionAmarelo->setCheckable(true);
        select_azul = new QAction(MainWindow);
        select_azul->setObjectName(QString::fromUtf8("select_azul"));
        select_azul->setCheckable(true);
        select_azul->setChecked(true);
        select_amarelo = new QAction(MainWindow);
        select_amarelo->setObjectName(QString::fromUtf8("select_amarelo"));
        select_amarelo->setCheckable(true);
        select_amarelo->setChecked(false);
        actionAbrir_Settings = new QAction(MainWindow);
        actionAbrir_Settings->setObjectName(QString::fromUtf8("actionAbrir_Settings"));
        select_RGB = new QAction(MainWindow);
        select_RGB->setObjectName(QString::fromUtf8("select_RGB"));
        select_RGB->setCheckable(true);
        select_RGB->setChecked(true);
        select_New_RGB = new QAction(MainWindow);
        select_New_RGB->setObjectName(QString::fromUtf8("select_New_RGB"));
        select_New_RGB->setCheckable(true);
        select_New_RGB->setChecked(false);
        select_HSV = new QAction(MainWindow);
        select_HSV->setObjectName(QString::fromUtf8("select_HSV"));
        select_HSV->setCheckable(true);
        select_HSV->setChecked(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Tempo = new QLabel(centralWidget);
        Tempo->setObjectName(QString::fromUtf8("Tempo"));
        Tempo->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(Tempo);

        milesegundos = new QLabel(centralWidget);
        milesegundos->setObjectName(QString::fromUtf8("milesegundos"));
        milesegundos->setMaximumSize(QSize(15, 16777215));

        horizontalLayout->addWidget(milesegundos);

        Tempoms = new QLabel(centralWidget);
        Tempoms->setObjectName(QString::fromUtf8("Tempoms"));

        horizontalLayout->addWidget(Tempoms);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush12(QColor(238, 238, 236, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        scrollArea->setPalette(palette1);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 1442, 975));
        gridLayout_63 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_63->setSpacing(6);
        gridLayout_63->setContentsMargins(11, 11, 11, 11);
        gridLayout_63->setObjectName(QString::fromUtf8("gridLayout_63"));
        tabWidget = new QTabWidget(scrollAreaWidgetContents_4);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush12);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush12);
        QBrush brush14(QColor(0, 0, 0, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        QBrush brush15(QColor(0, 0, 0, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        tabWidget->setPalette(palette2);
        Principal = new QWidget();
        Principal->setObjectName(QString::fromUtf8("Principal"));
        gridLayout_3 = new QGridLayout(Principal);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        janela = new QLabel(Principal);
        janela->setObjectName(QString::fromUtf8("janela"));
        janela->setMinimumSize(QSize(640, 480));
        janela->setFrameShape(QFrame::Box);
        janela->setFrameShadow(QFrame::Raised);
        janela->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(janela);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        groupBox = new QGroupBox(Principal);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        groupBox->setPalette(palette3);
        QFont font;
        font.setPointSize(16);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        combo_atacante = new QComboBox(groupBox);
        combo_atacante->setObjectName(QString::fromUtf8("combo_atacante"));

        gridLayout_2->addWidget(combo_atacante, 2, 1, 1, 2);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 5, 0, 1, 3);

        combo_zagueiro = new QComboBox(groupBox);
        combo_zagueiro->setObjectName(QString::fromUtf8("combo_zagueiro"));

        gridLayout_2->addWidget(combo_zagueiro, 3, 1, 1, 2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 6, 1, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 0, 1, 3);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 6, 2, 1, 1);

        combo_goleiro = new QComboBox(groupBox);
        combo_goleiro->setObjectName(QString::fromUtf8("combo_goleiro"));

        gridLayout_2->addWidget(combo_goleiro, 4, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 4, 3, 1, 1);


        horizontalLayout_2->addWidget(groupBox);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 2, 1, 1);

        tabWidget->addTab(Principal, QString());
        calibracao = new QWidget();
        calibracao->setObjectName(QString::fromUtf8("calibracao"));
        gridLayout_62 = new QGridLayout(calibracao);
        gridLayout_62->setSpacing(6);
        gridLayout_62->setContentsMargins(11, 11, 11, 11);
        gridLayout_62->setObjectName(QString::fromUtf8("gridLayout_62"));
        gridLayout_61 = new QGridLayout();
        gridLayout_61->setSpacing(6);
        gridLayout_61->setObjectName(QString::fromUtf8("gridLayout_61"));
        janela_2 = new QLabel(calibracao);
        janela_2->setObjectName(QString::fromUtf8("janela_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(janela_2->sizePolicy().hasHeightForWidth());
        janela_2->setSizePolicy(sizePolicy);
        janela_2->setMinimumSize(QSize(901, 491));
        janela_2->setMaximumSize(QSize(1000, 500));
        janela_2->setStyleSheet(QString::fromUtf8("background:  "));
        janela_2->setFrameShape(QFrame::Box);
        janela_2->setFrameShadow(QFrame::Raised);

        gridLayout_61->addWidget(janela_2, 0, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_114 = new QHBoxLayout();
        horizontalLayout_114->setSpacing(6);
        horizontalLayout_114->setObjectName(QString::fromUtf8("horizontalLayout_114"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_114->addItem(horizontalSpacer_7);

        pushButton_default = new QPushButton(calibracao);
        pushButton_default->setObjectName(QString::fromUtf8("pushButton_default"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        pushButton_default->setPalette(palette4);

        horizontalLayout_114->addWidget(pushButton_default);

        pushButton_apply = new QPushButton(calibracao);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        pushButton_apply->setPalette(palette5);

        horizontalLayout_114->addWidget(pushButton_apply);


        verticalLayout_7->addLayout(horizontalLayout_114);

        tabWidget_2 = new QTabWidget(calibracao);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush);
        QBrush brush16(QColor(0, 0, 0, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        QBrush brush17(QColor(0, 0, 0, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush17);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        QBrush brush18(QColor(0, 0, 0, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush18);
#endif
        tabWidget_2->setPalette(palette6);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_60 = new QGridLayout(tab);
        gridLayout_60->setSpacing(6);
        gridLayout_60->setContentsMargins(11, 11, 11, 11);
        gridLayout_60->setObjectName(QString::fromUtf8("gridLayout_60"));
        gridLayout_59 = new QGridLayout();
        gridLayout_59->setSpacing(6);
        gridLayout_59->setObjectName(QString::fromUtf8("gridLayout_59"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_58 = new QGridLayout(groupBox_2);
        gridLayout_58->setSpacing(6);
        gridLayout_58->setContentsMargins(11, 11, 11, 11);
        gridLayout_58->setObjectName(QString::fromUtf8("gridLayout_58"));
        gridLayout_53 = new QGridLayout();
        gridLayout_53->setSpacing(6);
        gridLayout_53->setObjectName(QString::fromUtf8("gridLayout_53"));
        gridLayout_52 = new QGridLayout();
        gridLayout_52->setSpacing(6);
        gridLayout_52->setObjectName(QString::fromUtf8("gridLayout_52"));
        gridLayout_51 = new QGridLayout();
        gridLayout_51->setSpacing(6);
        gridLayout_51->setObjectName(QString::fromUtf8("gridLayout_51"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        spinBox_cont = new QSpinBox(groupBox_2);
        spinBox_cont->setObjectName(QString::fromUtf8("spinBox_cont"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_cont->setPalette(palette7);
        spinBox_cont->setMaximum(100);

        gridLayout_4->addWidget(spinBox_cont, 0, 2, 1, 1);

        spinBox_sat = new QSpinBox(groupBox_2);
        spinBox_sat->setObjectName(QString::fromUtf8("spinBox_sat"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_sat->setPalette(palette8);
        spinBox_sat->setMaximum(100);

        gridLayout_4->addWidget(spinBox_sat, 1, 2, 1, 1);

        label_sat = new QLabel(groupBox_2);
        label_sat->setObjectName(QString::fromUtf8("label_sat"));
        QFont font1;
        font1.setPointSize(12);
        label_sat->setFont(font1);

        gridLayout_4->addWidget(label_sat, 1, 0, 1, 1);

        spinBox_hue = new QSpinBox(groupBox_2);
        spinBox_hue->setObjectName(QString::fromUtf8("spinBox_hue"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_hue->setPalette(palette9);
        spinBox_hue->setMinimum(-180);
        spinBox_hue->setMaximum(180);

        gridLayout_4->addWidget(spinBox_hue, 4, 2, 1, 1);

        saturacao = new QSlider(groupBox_2);
        saturacao->setObjectName(QString::fromUtf8("saturacao"));
        saturacao->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(saturacao, 1, 1, 1, 1);

        hue = new QSlider(groupBox_2);
        hue->setObjectName(QString::fromUtf8("hue"));
        hue->setMinimum(-180);
        hue->setMaximum(180);
        hue->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(hue, 4, 1, 1, 1);

        exposicao = new QSlider(groupBox_2);
        exposicao->setObjectName(QString::fromUtf8("exposicao"));
        exposicao->setMinimum(39);
        exposicao->setMaximum(10000);
        exposicao->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(exposicao, 3, 1, 1, 1);

        spinBox_exp = new QSpinBox(groupBox_2);
        spinBox_exp->setObjectName(QString::fromUtf8("spinBox_exp"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_exp->setPalette(palette10);
        spinBox_exp->setMinimum(39);
        spinBox_exp->setMaximum(10000);

        gridLayout_4->addWidget(spinBox_exp, 3, 2, 1, 1);

        brilho = new QSlider(groupBox_2);
        brilho->setObjectName(QString::fromUtf8("brilho"));
        brilho->setMinimum(-64);
        brilho->setMaximum(64);
        brilho->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(brilho, 2, 1, 1, 1);

        label_exp = new QLabel(groupBox_2);
        label_exp->setObjectName(QString::fromUtf8("label_exp"));
        label_exp->setFont(font1);

        gridLayout_4->addWidget(label_exp, 3, 0, 1, 1);

        spinBox_bri = new QSpinBox(groupBox_2);
        spinBox_bri->setObjectName(QString::fromUtf8("spinBox_bri"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_bri->setPalette(palette11);
        spinBox_bri->setMinimum(-64);
        spinBox_bri->setMaximum(64);

        gridLayout_4->addWidget(spinBox_bri, 2, 2, 1, 1);

        label_hue = new QLabel(groupBox_2);
        label_hue->setObjectName(QString::fromUtf8("label_hue"));
        label_hue->setFont(font1);

        gridLayout_4->addWidget(label_hue, 4, 0, 1, 1);

        label_bri = new QLabel(groupBox_2);
        label_bri->setObjectName(QString::fromUtf8("label_bri"));
        label_bri->setFont(font1);

        gridLayout_4->addWidget(label_bri, 2, 0, 1, 1);

        label_cont = new QLabel(groupBox_2);
        label_cont->setObjectName(QString::fromUtf8("label_cont"));
        label_cont->setFont(font1);

        gridLayout_4->addWidget(label_cont, 0, 0, 1, 1);

        contraste = new QSlider(groupBox_2);
        contraste->setObjectName(QString::fromUtf8("contraste"));
        contraste->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(contraste, 0, 1, 1, 1);


        gridLayout_51->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_back_comp = new QLabel(groupBox_2);
        label_back_comp->setObjectName(QString::fromUtf8("label_back_comp"));
        QFont font2;
        font2.setPointSize(11);
        label_back_comp->setFont(font2);

        gridLayout_6->addWidget(label_back_comp, 3, 1, 1, 1);

        spinBox_back_compensation = new QSpinBox(groupBox_2);
        spinBox_back_compensation->setObjectName(QString::fromUtf8("spinBox_back_compensation"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_back_compensation->setPalette(palette12);
        spinBox_back_compensation->setMaximum(4);

        gridLayout_6->addWidget(spinBox_back_compensation, 3, 3, 1, 1);

        white_balance = new QSlider(groupBox_2);
        white_balance->setObjectName(QString::fromUtf8("white_balance"));
        white_balance->setMaximum(10000);
        white_balance->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(white_balance, 0, 2, 1, 1);

        Gamma = new QSlider(groupBox_2);
        Gamma->setObjectName(QString::fromUtf8("Gamma"));
        Gamma->setMinimum(100);
        Gamma->setMaximum(500);
        Gamma->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(Gamma, 1, 2, 1, 1);

        spinBox_wb = new QSpinBox(groupBox_2);
        spinBox_wb->setObjectName(QString::fromUtf8("spinBox_wb"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_wb->setPalette(palette13);
        spinBox_wb->setMaximum(10000);

        gridLayout_6->addWidget(spinBox_wb, 0, 3, 1, 1);

        Gain = new QSlider(groupBox_2);
        Gain->setObjectName(QString::fromUtf8("Gain"));
        Gain->setMinimum(0);
        Gain->setMaximum(128);
        Gain->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(Gain, 2, 2, 1, 1);

        spinBox_gain = new QSpinBox(groupBox_2);
        spinBox_gain->setObjectName(QString::fromUtf8("spinBox_gain"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gain->setPalette(palette14);
        spinBox_gain->setMinimum(0);
        spinBox_gain->setMaximum(128);

        gridLayout_6->addWidget(spinBox_gain, 2, 3, 1, 1);

        label_wb = new QLabel(groupBox_2);
        label_wb->setObjectName(QString::fromUtf8("label_wb"));
        label_wb->setFont(font1);

        gridLayout_6->addWidget(label_wb, 0, 1, 1, 1);

        Back_Compensation = new QSlider(groupBox_2);
        Back_Compensation->setObjectName(QString::fromUtf8("Back_Compensation"));
        Back_Compensation->setMaximum(4);
        Back_Compensation->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(Back_Compensation, 3, 2, 1, 1);

        nitidez = new QSlider(groupBox_2);
        nitidez->setObjectName(QString::fromUtf8("nitidez"));
        nitidez->setMaximum(100);
        nitidez->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(nitidez, 4, 2, 1, 1);

        label_gamma = new QLabel(groupBox_2);
        label_gamma->setObjectName(QString::fromUtf8("label_gamma"));
        label_gamma->setFont(font1);

        gridLayout_6->addWidget(label_gamma, 1, 1, 1, 1);

        label_gain = new QLabel(groupBox_2);
        label_gain->setObjectName(QString::fromUtf8("label_gain"));
        label_gain->setFont(font1);

        gridLayout_6->addWidget(label_gain, 2, 1, 1, 1);

        label_nitidez = new QLabel(groupBox_2);
        label_nitidez->setObjectName(QString::fromUtf8("label_nitidez"));
        label_nitidez->setFont(font2);

        gridLayout_6->addWidget(label_nitidez, 4, 1, 1, 1);

        spinBox_gamma = new QSpinBox(groupBox_2);
        spinBox_gamma->setObjectName(QString::fromUtf8("spinBox_gamma"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gamma->setPalette(palette15);
        spinBox_gamma->setMinimum(100);
        spinBox_gamma->setMaximum(500);

        gridLayout_6->addWidget(spinBox_gamma, 1, 3, 1, 1);

        spinBox_nitidez = new QSpinBox(groupBox_2);
        spinBox_nitidez->setObjectName(QString::fromUtf8("spinBox_nitidez"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_nitidez->setPalette(palette16);
        spinBox_nitidez->setMaximum(100);

        gridLayout_6->addWidget(spinBox_nitidez, 4, 3, 1, 1);

        line_19 = new QFrame(groupBox_2);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_19, 0, 0, 1, 1);

        line_20 = new QFrame(groupBox_2);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setFrameShape(QFrame::VLine);
        line_20->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_20, 1, 0, 1, 1);

        line_21 = new QFrame(groupBox_2);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setFrameShape(QFrame::VLine);
        line_21->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_21, 2, 0, 1, 1);

        line_22 = new QFrame(groupBox_2);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setFrameShape(QFrame::VLine);
        line_22->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_22, 3, 0, 1, 1);

        line_23 = new QFrame(groupBox_2);
        line_23->setObjectName(QString::fromUtf8("line_23"));
        line_23->setFrameShape(QFrame::VLine);
        line_23->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_23, 4, 0, 1, 1);


        gridLayout_51->addLayout(gridLayout_6, 0, 1, 1, 1);


        gridLayout_52->addLayout(gridLayout_51, 0, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_52->addItem(verticalSpacer_7, 0, 1, 1, 1);


        gridLayout_53->addLayout(gridLayout_52, 0, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        checkBox_expo_auto = new QCheckBox(groupBox_2);
        checkBox_expo_auto->setObjectName(QString::fromUtf8("checkBox_expo_auto"));
        checkBox_expo_auto->setChecked(true);

        gridLayout_11->addWidget(checkBox_expo_auto, 0, 0, 1, 1);

        checkBox_wb_auto = new QCheckBox(groupBox_2);
        checkBox_wb_auto->setObjectName(QString::fromUtf8("checkBox_wb_auto"));
        checkBox_wb_auto->setChecked(true);

        gridLayout_11->addWidget(checkBox_wb_auto, 0, 1, 1, 1);


        gridLayout_53->addLayout(gridLayout_11, 1, 0, 1, 1);


        gridLayout_58->addLayout(gridLayout_53, 0, 0, 1, 1);


        gridLayout_59->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_57 = new QGridLayout(groupBox_3);
        gridLayout_57->setSpacing(6);
        gridLayout_57->setContentsMargins(11, 11, 11, 11);
        gridLayout_57->setObjectName(QString::fromUtf8("gridLayout_57"));
        gridLayout_56 = new QGridLayout();
        gridLayout_56->setSpacing(6);
        gridLayout_56->setObjectName(QString::fromUtf8("gridLayout_56"));
        gridLayout_55 = new QGridLayout();
        gridLayout_55->setSpacing(6);
        gridLayout_55->setObjectName(QString::fromUtf8("gridLayout_55"));
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_55->addItem(verticalSpacer_9, 2, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        Resolucao = new QComboBox(groupBox_3);
        Resolucao->addItem(QString());
        Resolucao->addItem(QString());
        Resolucao->addItem(QString());
        Resolucao->addItem(QString());
        Resolucao->addItem(QString());
        Resolucao->setObjectName(QString::fromUtf8("Resolucao"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        Resolucao->setPalette(palette17);

        horizontalLayout_4->addWidget(Resolucao);


        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        pushButton_cortar = new QPushButton(groupBox_3);
        pushButton_cortar->setObjectName(QString::fromUtf8("pushButton_cortar"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        pushButton_cortar->setPalette(palette18);

        horizontalLayout_3->addWidget(pushButton_cortar);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_55->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        line_24 = new QFrame(groupBox_3);
        line_24->setObjectName(QString::fromUtf8("line_24"));
        line_24->setFrameShape(QFrame::VLine);
        line_24->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_24, 2, 1, 1, 1);

        line_30 = new QFrame(groupBox_3);
        line_30->setObjectName(QString::fromUtf8("line_30"));
        line_30->setFrameShape(QFrame::HLine);
        line_30->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_30, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        line_27 = new QFrame(groupBox_3);
        line_27->setObjectName(QString::fromUtf8("line_27"));
        line_27->setFrameShape(QFrame::VLine);
        line_27->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_27, 0, 3, 1, 1);

        line_32 = new QFrame(groupBox_3);
        line_32->setObjectName(QString::fromUtf8("line_32"));
        line_32->setFrameShape(QFrame::HLine);
        line_32->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_32, 1, 4, 1, 1);

        line_31 = new QFrame(groupBox_3);
        line_31->setObjectName(QString::fromUtf8("line_31"));
        line_31->setFrameShape(QFrame::HLine);
        line_31->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_31, 1, 2, 1, 1);

        line_28 = new QFrame(groupBox_3);
        line_28->setObjectName(QString::fromUtf8("line_28"));
        line_28->setFrameShape(QFrame::VLine);
        line_28->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_28, 2, 3, 1, 1);

        spinBox_cut_height = new QSpinBox(groupBox_3);
        spinBox_cut_height->setObjectName(QString::fromUtf8("spinBox_cut_height"));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_cut_height->setPalette(palette19);
        spinBox_cut_height->setMaximum(2000);

        gridLayout_5->addWidget(spinBox_cut_height, 4, 4, 1, 1);

        line_25 = new QFrame(groupBox_3);
        line_25->setObjectName(QString::fromUtf8("line_25"));
        line_25->setFrameShape(QFrame::VLine);
        line_25->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_25, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 4, 0, 1, 1);

        spinBox_cut_y = new QSpinBox(groupBox_3);
        spinBox_cut_y->setObjectName(QString::fromUtf8("spinBox_cut_y"));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_cut_y->setPalette(palette20);
        spinBox_cut_y->setMaximum(2000);

        gridLayout_5->addWidget(spinBox_cut_y, 4, 2, 1, 1);

        line_26 = new QFrame(groupBox_3);
        line_26->setObjectName(QString::fromUtf8("line_26"));
        line_26->setFrameShape(QFrame::VLine);
        line_26->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_26, 0, 1, 1, 1);

        line_29 = new QFrame(groupBox_3);
        line_29->setObjectName(QString::fromUtf8("line_29"));
        line_29->setFrameShape(QFrame::VLine);
        line_29->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_29, 4, 3, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_5->addWidget(label_13, 0, 4, 1, 1);

        spinBox_cut_width = new QSpinBox(groupBox_3);
        spinBox_cut_width->setObjectName(QString::fromUtf8("spinBox_cut_width"));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_cut_width->setPalette(palette21);
        spinBox_cut_width->setMaximum(2000);

        gridLayout_5->addWidget(spinBox_cut_width, 2, 4, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 0, 2, 1, 1);

        spinBox_cut_x = new QSpinBox(groupBox_3);
        spinBox_cut_x->setObjectName(QString::fromUtf8("spinBox_cut_x"));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_cut_x->setPalette(palette22);
        spinBox_cut_x->setMaximum(2000);

        gridLayout_5->addWidget(spinBox_cut_x, 2, 2, 1, 1);

        line_33 = new QFrame(groupBox_3);
        line_33->setObjectName(QString::fromUtf8("line_33"));
        line_33->setFrameShape(QFrame::HLine);
        line_33->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_33, 3, 0, 1, 1);

        line_34 = new QFrame(groupBox_3);
        line_34->setObjectName(QString::fromUtf8("line_34"));
        line_34->setFrameShape(QFrame::HLine);
        line_34->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_34, 3, 2, 1, 1);

        line_35 = new QFrame(groupBox_3);
        line_35->setObjectName(QString::fromUtf8("line_35"));
        line_35->setFrameShape(QFrame::HLine);
        line_35->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_35, 3, 4, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_6, 0, 1, 1, 1);


        gridLayout_55->addLayout(gridLayout_8, 1, 0, 1, 1);


        gridLayout_56->addLayout(gridLayout_55, 0, 0, 1, 1);

        gridLayout_54 = new QGridLayout();
        gridLayout_54->setSpacing(6);
        gridLayout_54->setObjectName(QString::fromUtf8("gridLayout_54"));
        checkBox_flip = new QCheckBox(groupBox_3);
        checkBox_flip->setObjectName(QString::fromUtf8("checkBox_flip"));

        gridLayout_54->addWidget(checkBox_flip, 0, 0, 1, 1);

        checkBox_resolution = new QCheckBox(groupBox_3);
        checkBox_resolution->setObjectName(QString::fromUtf8("checkBox_resolution"));

        gridLayout_54->addWidget(checkBox_resolution, 0, 1, 1, 1);


        gridLayout_56->addLayout(gridLayout_54, 1, 0, 1, 1);


        gridLayout_57->addLayout(gridLayout_56, 0, 0, 1, 1);


        gridLayout_59->addWidget(groupBox_3, 0, 1, 1, 1);


        gridLayout_60->addLayout(gridLayout_59, 0, 0, 1, 1);

        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_50 = new QGridLayout(tab_2);
        gridLayout_50->setSpacing(6);
        gridLayout_50->setContentsMargins(11, 11, 11, 11);
        gridLayout_50->setObjectName(QString::fromUtf8("gridLayout_50"));
        gridLayout_49 = new QGridLayout();
        gridLayout_49->setSpacing(6);
        gridLayout_49->setObjectName(QString::fromUtf8("gridLayout_49"));
        groupBox_limiares = new QGroupBox(tab_2);
        groupBox_limiares->setObjectName(QString::fromUtf8("groupBox_limiares"));
        gridLayout_46 = new QGridLayout(groupBox_limiares);
        gridLayout_46->setSpacing(6);
        gridLayout_46->setContentsMargins(11, 11, 11, 11);
        gridLayout_46->setObjectName(QString::fromUtf8("gridLayout_46"));
        gridLayout_45 = new QGridLayout();
        gridLayout_45->setSpacing(6);
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        checkBox_limiar = new QCheckBox(groupBox_limiares);
        checkBox_limiar->setObjectName(QString::fromUtf8("checkBox_limiar"));

        gridLayout_10->addWidget(checkBox_limiar, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_9, 0, 1, 1, 1);

        label_cor = new QLabel(groupBox_limiares);
        label_cor->setObjectName(QString::fromUtf8("label_cor"));

        gridLayout_10->addWidget(label_cor, 0, 2, 1, 1);

        comboBox_colors = new QComboBox(groupBox_limiares);
        comboBox_colors->addItem(QString());
        comboBox_colors->addItem(QString());
        comboBox_colors->addItem(QString());
        comboBox_colors->addItem(QString());
        comboBox_colors->addItem(QString());
        comboBox_colors->addItem(QString());
        comboBox_colors->setObjectName(QString::fromUtf8("comboBox_colors"));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        comboBox_colors->setPalette(palette23);

        gridLayout_10->addWidget(comboBox_colors, 0, 3, 1, 1);


        gridLayout_45->addLayout(gridLayout_10, 0, 0, 1, 1);

        MenuColorSpace = new QTabWidget(groupBox_limiares);
        MenuColorSpace->setObjectName(QString::fromUtf8("MenuColorSpace"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_33 = new QGridLayout(tab_3);
        gridLayout_33->setSpacing(6);
        gridLayout_33->setContentsMargins(11, 11, 11, 11);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_32 = new QGridLayout();
        gridLayout_32->setSpacing(6);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        groupBox_r = new QGroupBox(tab_3);
        groupBox_r->setObjectName(QString::fromUtf8("groupBox_r"));
        gridLayout_30 = new QGridLayout(groupBox_r);
        gridLayout_30->setSpacing(6);
        gridLayout_30->setContentsMargins(11, 11, 11, 11);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_rmax = new QLabel(groupBox_r);
        label_rmax->setObjectName(QString::fromUtf8("label_rmax"));

        horizontalLayout_17->addWidget(label_rmax);

        rmax = new QSlider(groupBox_r);
        rmax->setObjectName(QString::fromUtf8("rmax"));
        rmax->setMaximum(255);
        rmax->setOrientation(Qt::Horizontal);

        horizontalLayout_17->addWidget(rmax);

        spinBox_rmax = new QSpinBox(groupBox_r);
        spinBox_rmax->setObjectName(QString::fromUtf8("spinBox_rmax"));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_rmax->setPalette(palette24);
        spinBox_rmax->setMaximum(255);

        horizontalLayout_17->addWidget(spinBox_rmax);


        gridLayout_14->addLayout(horizontalLayout_17, 0, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_rmin = new QLabel(groupBox_r);
        label_rmin->setObjectName(QString::fromUtf8("label_rmin"));

        horizontalLayout_18->addWidget(label_rmin);

        rmin = new QSlider(groupBox_r);
        rmin->setObjectName(QString::fromUtf8("rmin"));
        rmin->setMaximum(255);
        rmin->setOrientation(Qt::Horizontal);

        horizontalLayout_18->addWidget(rmin);

        spinBox_rmin = new QSpinBox(groupBox_r);
        spinBox_rmin->setObjectName(QString::fromUtf8("spinBox_rmin"));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_rmin->setPalette(palette25);
        spinBox_rmin->setMaximum(255);

        horizontalLayout_18->addWidget(spinBox_rmin);


        gridLayout_14->addLayout(horizontalLayout_18, 2, 0, 1, 1);

        line_7 = new QFrame(groupBox_r);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_14->addWidget(line_7, 1, 0, 1, 1);


        gridLayout_30->addLayout(gridLayout_14, 0, 0, 1, 1);


        gridLayout_32->addWidget(groupBox_r, 0, 0, 1, 1);

        groupBox_g = new QGroupBox(tab_3);
        groupBox_g->setObjectName(QString::fromUtf8("groupBox_g"));
        gridLayout_19 = new QGridLayout(groupBox_g);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_gmin = new QLabel(groupBox_g);
        label_gmin->setObjectName(QString::fromUtf8("label_gmin"));

        horizontalLayout_20->addWidget(label_gmin);

        gmin = new QSlider(groupBox_g);
        gmin->setObjectName(QString::fromUtf8("gmin"));
        gmin->setMaximum(255);
        gmin->setOrientation(Qt::Horizontal);

        horizontalLayout_20->addWidget(gmin);

        spinBox_gmin = new QSpinBox(groupBox_g);
        spinBox_gmin->setObjectName(QString::fromUtf8("spinBox_gmin"));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gmin->setPalette(palette26);
        spinBox_gmin->setMaximum(255);

        horizontalLayout_20->addWidget(spinBox_gmin);


        gridLayout_15->addLayout(horizontalLayout_20, 2, 0, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_gmax = new QLabel(groupBox_g);
        label_gmax->setObjectName(QString::fromUtf8("label_gmax"));

        horizontalLayout_19->addWidget(label_gmax);

        gmax = new QSlider(groupBox_g);
        gmax->setObjectName(QString::fromUtf8("gmax"));
        gmax->setMaximum(255);
        gmax->setOrientation(Qt::Horizontal);

        horizontalLayout_19->addWidget(gmax);

        spinBox_gmax = new QSpinBox(groupBox_g);
        spinBox_gmax->setObjectName(QString::fromUtf8("spinBox_gmax"));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gmax->setPalette(palette27);
        spinBox_gmax->setMaximum(255);

        horizontalLayout_19->addWidget(spinBox_gmax);


        gridLayout_15->addLayout(horizontalLayout_19, 0, 0, 1, 1);

        line_8 = new QFrame(groupBox_g);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_8, 1, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_32->addWidget(groupBox_g, 0, 1, 1, 1);

        groupBox_b = new QGroupBox(tab_3);
        groupBox_b->setObjectName(QString::fromUtf8("groupBox_b"));
        gridLayout_31 = new QGridLayout(groupBox_b);
        gridLayout_31->setSpacing(6);
        gridLayout_31->setContentsMargins(11, 11, 11, 11);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_bmax = new QLabel(groupBox_b);
        label_bmax->setObjectName(QString::fromUtf8("label_bmax"));

        horizontalLayout_21->addWidget(label_bmax);

        bmax = new QSlider(groupBox_b);
        bmax->setObjectName(QString::fromUtf8("bmax"));
        bmax->setMaximum(255);
        bmax->setOrientation(Qt::Horizontal);

        horizontalLayout_21->addWidget(bmax);

        spinBox_bmax = new QSpinBox(groupBox_b);
        spinBox_bmax->setObjectName(QString::fromUtf8("spinBox_bmax"));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette28.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette28.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_bmax->setPalette(palette28);
        spinBox_bmax->setMaximum(255);

        horizontalLayout_21->addWidget(spinBox_bmax);


        gridLayout_16->addLayout(horizontalLayout_21, 0, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_bmin = new QLabel(groupBox_b);
        label_bmin->setObjectName(QString::fromUtf8("label_bmin"));

        horizontalLayout_22->addWidget(label_bmin);

        bmin = new QSlider(groupBox_b);
        bmin->setObjectName(QString::fromUtf8("bmin"));
        bmin->setMaximum(255);
        bmin->setOrientation(Qt::Horizontal);

        horizontalLayout_22->addWidget(bmin);

        spinBox_bmin = new QSpinBox(groupBox_b);
        spinBox_bmin->setObjectName(QString::fromUtf8("spinBox_bmin"));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette29.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette29.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_bmin->setPalette(palette29);
        spinBox_bmin->setMaximum(255);

        horizontalLayout_22->addWidget(spinBox_bmin);


        gridLayout_16->addLayout(horizontalLayout_22, 2, 0, 1, 1);

        line_9 = new QFrame(groupBox_b);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_16->addWidget(line_9, 1, 0, 1, 1);


        gridLayout_31->addLayout(gridLayout_16, 0, 0, 1, 1);


        gridLayout_32->addWidget(groupBox_b, 0, 2, 1, 1);


        gridLayout_33->addLayout(gridLayout_32, 0, 0, 1, 1);

        MenuColorSpace->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_38 = new QGridLayout(tab_4);
        gridLayout_38->setSpacing(6);
        gridLayout_38->setContentsMargins(11, 11, 11, 11);
        gridLayout_38->setObjectName(QString::fromUtf8("gridLayout_38"));
        gridLayout_37 = new QGridLayout();
        gridLayout_37->setSpacing(6);
        gridLayout_37->setObjectName(QString::fromUtf8("gridLayout_37"));
        groupBox_h = new QGroupBox(tab_4);
        groupBox_h->setObjectName(QString::fromUtf8("groupBox_h"));
        gridLayout_35 = new QGridLayout(groupBox_h);
        gridLayout_35->setSpacing(6);
        gridLayout_35->setContentsMargins(11, 11, 11, 11);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        gridLayout_20 = new QGridLayout();
        gridLayout_20->setSpacing(6);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_36 = new QLabel(groupBox_h);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_33->addWidget(label_36);

        HSV_HMin = new QSlider(groupBox_h);
        HSV_HMin->setObjectName(QString::fromUtf8("HSV_HMin"));
        HSV_HMin->setMaximum(255);
        HSV_HMin->setOrientation(Qt::Horizontal);

        horizontalLayout_33->addWidget(HSV_HMin);

        HSV_HMin_2 = new QSpinBox(groupBox_h);
        HSV_HMin_2->setObjectName(QString::fromUtf8("HSV_HMin_2"));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette30.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette30.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        HSV_HMin_2->setPalette(palette30);
        HSV_HMin_2->setMaximum(255);

        horizontalLayout_33->addWidget(HSV_HMin_2);


        gridLayout_20->addLayout(horizontalLayout_33, 2, 0, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_35 = new QLabel(groupBox_h);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_32->addWidget(label_35);

        HSV_HMax = new QSlider(groupBox_h);
        HSV_HMax->setObjectName(QString::fromUtf8("HSV_HMax"));
        HSV_HMax->setMaximum(255);
        HSV_HMax->setOrientation(Qt::Horizontal);

        horizontalLayout_32->addWidget(HSV_HMax);

        HSV_HMax_2 = new QSpinBox(groupBox_h);
        HSV_HMax_2->setObjectName(QString::fromUtf8("HSV_HMax_2"));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette31.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette31.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        HSV_HMax_2->setPalette(palette31);
        HSV_HMax_2->setMaximum(255);

        horizontalLayout_32->addWidget(HSV_HMax_2);


        gridLayout_20->addLayout(horizontalLayout_32, 0, 0, 1, 1);

        line_10 = new QFrame(groupBox_h);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_20->addWidget(line_10, 1, 0, 1, 1);


        gridLayout_35->addLayout(gridLayout_20, 0, 0, 1, 1);


        gridLayout_37->addWidget(groupBox_h, 0, 0, 1, 1);

        groupBox_s = new QGroupBox(tab_4);
        groupBox_s->setObjectName(QString::fromUtf8("groupBox_s"));
        gridLayout_34 = new QGridLayout(groupBox_s);
        gridLayout_34->setSpacing(6);
        gridLayout_34->setContentsMargins(11, 11, 11, 11);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setSpacing(6);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        label_38 = new QLabel(groupBox_s);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_35->addWidget(label_38);

        HSV_SMin = new QSlider(groupBox_s);
        HSV_SMin->setObjectName(QString::fromUtf8("HSV_SMin"));
        HSV_SMin->setMaximum(255);
        HSV_SMin->setOrientation(Qt::Horizontal);

        horizontalLayout_35->addWidget(HSV_SMin);

        HSV_SMin_2 = new QSpinBox(groupBox_s);
        HSV_SMin_2->setObjectName(QString::fromUtf8("HSV_SMin_2"));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette32.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette32.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        HSV_SMin_2->setPalette(palette32);
        HSV_SMin_2->setMaximum(255);

        horizontalLayout_35->addWidget(HSV_SMin_2);


        gridLayout_21->addLayout(horizontalLayout_35, 2, 0, 1, 1);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        label_37 = new QLabel(groupBox_s);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_34->addWidget(label_37);

        HSV_SMax = new QSlider(groupBox_s);
        HSV_SMax->setObjectName(QString::fromUtf8("HSV_SMax"));
        HSV_SMax->setMaximum(255);
        HSV_SMax->setOrientation(Qt::Horizontal);

        horizontalLayout_34->addWidget(HSV_SMax);

        HSV_SMax_2 = new QSpinBox(groupBox_s);
        HSV_SMax_2->setObjectName(QString::fromUtf8("HSV_SMax_2"));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette33.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette33.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        HSV_SMax_2->setPalette(palette33);
        HSV_SMax_2->setMaximum(255);

        horizontalLayout_34->addWidget(HSV_SMax_2);


        gridLayout_21->addLayout(horizontalLayout_34, 0, 0, 1, 1);

        line_11 = new QFrame(groupBox_s);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_21->addWidget(line_11, 1, 0, 1, 1);


        gridLayout_34->addLayout(gridLayout_21, 0, 0, 1, 1);


        gridLayout_37->addWidget(groupBox_s, 0, 1, 1, 1);

        groupBox_v = new QGroupBox(tab_4);
        groupBox_v->setObjectName(QString::fromUtf8("groupBox_v"));
        gridLayout_36 = new QGridLayout(groupBox_v);
        gridLayout_36->setSpacing(6);
        gridLayout_36->setContentsMargins(11, 11, 11, 11);
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        gridLayout_22 = new QGridLayout();
        gridLayout_22->setSpacing(6);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        label_39 = new QLabel(groupBox_v);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_36->addWidget(label_39);

        HSV_VMax = new QSlider(groupBox_v);
        HSV_VMax->setObjectName(QString::fromUtf8("HSV_VMax"));
        HSV_VMax->setMaximum(255);
        HSV_VMax->setOrientation(Qt::Horizontal);

        horizontalLayout_36->addWidget(HSV_VMax);

        HSV_VMax_2 = new QSpinBox(groupBox_v);
        HSV_VMax_2->setObjectName(QString::fromUtf8("HSV_VMax_2"));
        QPalette palette34;
        palette34.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette34.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette34.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        HSV_VMax_2->setPalette(palette34);
        HSV_VMax_2->setMaximum(255);

        horizontalLayout_36->addWidget(HSV_VMax_2);


        gridLayout_22->addLayout(horizontalLayout_36, 0, 0, 1, 1);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        label_40 = new QLabel(groupBox_v);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_37->addWidget(label_40);

        HSV_VMin = new QSlider(groupBox_v);
        HSV_VMin->setObjectName(QString::fromUtf8("HSV_VMin"));
        HSV_VMin->setMaximum(255);
        HSV_VMin->setOrientation(Qt::Horizontal);

        horizontalLayout_37->addWidget(HSV_VMin);

        HSV_VMin_2 = new QSpinBox(groupBox_v);
        HSV_VMin_2->setObjectName(QString::fromUtf8("HSV_VMin_2"));
        QPalette palette35;
        palette35.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette35.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette35.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        HSV_VMin_2->setPalette(palette35);
        HSV_VMin_2->setMaximum(255);

        horizontalLayout_37->addWidget(HSV_VMin_2);


        gridLayout_22->addLayout(horizontalLayout_37, 2, 0, 1, 1);

        line_12 = new QFrame(groupBox_v);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_22->addWidget(line_12, 1, 0, 1, 1);


        gridLayout_36->addLayout(gridLayout_22, 0, 0, 1, 1);


        gridLayout_37->addWidget(groupBox_v, 0, 2, 1, 1);


        gridLayout_38->addLayout(gridLayout_37, 0, 0, 1, 1);

        MenuColorSpace->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_44 = new QGridLayout(tab_5);
        gridLayout_44->setSpacing(6);
        gridLayout_44->setContentsMargins(11, 11, 11, 11);
        gridLayout_44->setObjectName(QString::fromUtf8("gridLayout_44"));
        gridLayout_43 = new QGridLayout();
        gridLayout_43->setSpacing(6);
        gridLayout_43->setObjectName(QString::fromUtf8("gridLayout_43"));
        groupBox_18 = new QGroupBox(tab_5);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        gridLayout_40 = new QGridLayout(groupBox_18);
        gridLayout_40->setSpacing(6);
        gridLayout_40->setContentsMargins(11, 11, 11, 11);
        gridLayout_40->setObjectName(QString::fromUtf8("gridLayout_40"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setSpacing(6);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        label_41 = new QLabel(groupBox_18);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_39->addWidget(label_41);

        horizontalSlider_26 = new QSlider(groupBox_18);
        horizontalSlider_26->setObjectName(QString::fromUtf8("horizontalSlider_26"));
        horizontalSlider_26->setMaximum(255);
        horizontalSlider_26->setOrientation(Qt::Horizontal);

        horizontalLayout_39->addWidget(horizontalSlider_26);

        spinBox_30 = new QSpinBox(groupBox_18);
        spinBox_30->setObjectName(QString::fromUtf8("spinBox_30"));
        QPalette palette36;
        palette36.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette36.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette36.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_30->setPalette(palette36);
        spinBox_30->setMaximum(255);

        horizontalLayout_39->addWidget(spinBox_30);


        gridLayout_23->addLayout(horizontalLayout_39, 0, 0, 1, 1);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        label_42 = new QLabel(groupBox_18);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_40->addWidget(label_42);

        horizontalSlider_27 = new QSlider(groupBox_18);
        horizontalSlider_27->setObjectName(QString::fromUtf8("horizontalSlider_27"));
        horizontalSlider_27->setMaximum(255);
        horizontalSlider_27->setOrientation(Qt::Horizontal);

        horizontalLayout_40->addWidget(horizontalSlider_27);

        spinBox_31 = new QSpinBox(groupBox_18);
        spinBox_31->setObjectName(QString::fromUtf8("spinBox_31"));
        QPalette palette37;
        palette37.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette37.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette37.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_31->setPalette(palette37);
        spinBox_31->setMaximum(255);

        horizontalLayout_40->addWidget(spinBox_31);


        gridLayout_23->addLayout(horizontalLayout_40, 2, 0, 1, 1);

        line_13 = new QFrame(groupBox_18);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout_23->addWidget(line_13, 1, 0, 1, 1);


        gridLayout_40->addLayout(gridLayout_23, 0, 0, 1, 1);


        gridLayout_43->addWidget(groupBox_18, 0, 0, 1, 1);

        groupBox_19 = new QGroupBox(tab_5);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        gridLayout_39 = new QGridLayout(groupBox_19);
        gridLayout_39->setSpacing(6);
        gridLayout_39->setContentsMargins(11, 11, 11, 11);
        gridLayout_39->setObjectName(QString::fromUtf8("gridLayout_39"));
        gridLayout_24 = new QGridLayout();
        gridLayout_24->setSpacing(6);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_44 = new QLabel(groupBox_19);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_42->addWidget(label_44);

        horizontalSlider_29 = new QSlider(groupBox_19);
        horizontalSlider_29->setObjectName(QString::fromUtf8("horizontalSlider_29"));
        horizontalSlider_29->setMaximum(255);
        horizontalSlider_29->setOrientation(Qt::Horizontal);

        horizontalLayout_42->addWidget(horizontalSlider_29);

        spinBox_33 = new QSpinBox(groupBox_19);
        spinBox_33->setObjectName(QString::fromUtf8("spinBox_33"));
        QPalette palette38;
        palette38.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette38.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette38.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_33->setPalette(palette38);
        spinBox_33->setMaximum(255);

        horizontalLayout_42->addWidget(spinBox_33);


        gridLayout_24->addLayout(horizontalLayout_42, 2, 0, 1, 1);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label_43 = new QLabel(groupBox_19);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_41->addWidget(label_43);

        horizontalSlider_28 = new QSlider(groupBox_19);
        horizontalSlider_28->setObjectName(QString::fromUtf8("horizontalSlider_28"));
        horizontalSlider_28->setMaximum(255);
        horizontalSlider_28->setOrientation(Qt::Horizontal);

        horizontalLayout_41->addWidget(horizontalSlider_28);

        spinBox_32 = new QSpinBox(groupBox_19);
        spinBox_32->setObjectName(QString::fromUtf8("spinBox_32"));
        QPalette palette39;
        palette39.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette39.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette39.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_32->setPalette(palette39);
        spinBox_32->setMaximum(255);

        horizontalLayout_41->addWidget(spinBox_32);


        gridLayout_24->addLayout(horizontalLayout_41, 0, 0, 1, 1);

        line_14 = new QFrame(groupBox_19);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_24->addWidget(line_14, 1, 0, 1, 1);


        gridLayout_39->addLayout(gridLayout_24, 0, 0, 1, 1);


        gridLayout_43->addWidget(groupBox_19, 0, 1, 1, 1);

        groupBox_20 = new QGroupBox(tab_5);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        gridLayout_41 = new QGridLayout(groupBox_20);
        gridLayout_41->setSpacing(6);
        gridLayout_41->setContentsMargins(11, 11, 11, 11);
        gridLayout_41->setObjectName(QString::fromUtf8("gridLayout_41"));
        gridLayout_25 = new QGridLayout();
        gridLayout_25->setSpacing(6);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_46 = new QLabel(groupBox_20);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_44->addWidget(label_46);

        horizontalSlider_31 = new QSlider(groupBox_20);
        horizontalSlider_31->setObjectName(QString::fromUtf8("horizontalSlider_31"));
        horizontalSlider_31->setMaximum(255);
        horizontalSlider_31->setOrientation(Qt::Horizontal);

        horizontalLayout_44->addWidget(horizontalSlider_31);

        spinBox_35 = new QSpinBox(groupBox_20);
        spinBox_35->setObjectName(QString::fromUtf8("spinBox_35"));
        QPalette palette40;
        palette40.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette40.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette40.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_35->setPalette(palette40);
        spinBox_35->setMaximum(255);

        horizontalLayout_44->addWidget(spinBox_35);


        gridLayout_25->addLayout(horizontalLayout_44, 2, 0, 1, 1);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_45 = new QLabel(groupBox_20);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        horizontalLayout_43->addWidget(label_45);

        horizontalSlider_30 = new QSlider(groupBox_20);
        horizontalSlider_30->setObjectName(QString::fromUtf8("horizontalSlider_30"));
        horizontalSlider_30->setMaximum(255);
        horizontalSlider_30->setOrientation(Qt::Horizontal);

        horizontalLayout_43->addWidget(horizontalSlider_30);

        spinBox_34 = new QSpinBox(groupBox_20);
        spinBox_34->setObjectName(QString::fromUtf8("spinBox_34"));
        QPalette palette41;
        palette41.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette41.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette41.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_34->setPalette(palette41);
        spinBox_34->setMaximum(255);

        horizontalLayout_43->addWidget(spinBox_34);


        gridLayout_25->addLayout(horizontalLayout_43, 0, 0, 1, 1);

        line_15 = new QFrame(groupBox_20);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_25->addWidget(line_15, 1, 0, 1, 1);


        gridLayout_41->addLayout(gridLayout_25, 0, 0, 1, 1);


        gridLayout_43->addWidget(groupBox_20, 0, 2, 1, 1);


        gridLayout_44->addLayout(gridLayout_43, 0, 0, 1, 1);

        MenuColorSpace->addTab(tab_5, QString());

        gridLayout_45->addWidget(MenuColorSpace, 1, 0, 1, 1);


        gridLayout_46->addLayout(gridLayout_45, 0, 0, 1, 1);


        gridLayout_49->addWidget(groupBox_limiares, 0, 0, 1, 1);

        gridLayout_48 = new QGridLayout();
        gridLayout_48->setSpacing(6);
        gridLayout_48->setObjectName(QString::fromUtf8("gridLayout_48"));
        groupBox_mask = new QGroupBox(tab_2);
        groupBox_mask->setObjectName(QString::fromUtf8("groupBox_mask"));
        gridLayout_47 = new QGridLayout(groupBox_mask);
        gridLayout_47->setSpacing(6);
        gridLayout_47->setContentsMargins(11, 11, 11, 11);
        gridLayout_47->setObjectName(QString::fromUtf8("gridLayout_47"));
        gridLayout_29 = new QGridLayout();
        gridLayout_29->setSpacing(6);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_26 = new QGridLayout();
        gridLayout_26->setSpacing(6);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        label_tipomask = new QLabel(groupBox_mask);
        label_tipomask->setObjectName(QString::fromUtf8("label_tipomask"));

        gridLayout_26->addWidget(label_tipomask, 0, 0, 1, 1);

        comboBox_tipomask = new QComboBox(groupBox_mask);
        comboBox_tipomask->addItem(QString());
        comboBox_tipomask->addItem(QString());
        comboBox_tipomask->addItem(QString());
        comboBox_tipomask->setObjectName(QString::fromUtf8("comboBox_tipomask"));
        QPalette palette42;
        palette42.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette42.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette42.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        comboBox_tipomask->setPalette(palette42);

        gridLayout_26->addWidget(comboBox_tipomask, 0, 1, 1, 1);


        gridLayout_29->addLayout(gridLayout_26, 0, 0, 1, 1);

        gridLayout_27 = new QGridLayout();
        gridLayout_27->setSpacing(6);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        label_fechamento = new QLabel(groupBox_mask);
        label_fechamento->setObjectName(QString::fromUtf8("label_fechamento"));

        gridLayout_27->addWidget(label_fechamento, 1, 0, 1, 1);

        spinBox_fechamento = new QSpinBox(groupBox_mask);
        spinBox_fechamento->setObjectName(QString::fromUtf8("spinBox_fechamento"));
        QPalette palette43;
        palette43.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette43.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette43.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_fechamento->setPalette(palette43);
        spinBox_fechamento->setMinimum(1);

        gridLayout_27->addWidget(spinBox_fechamento, 1, 1, 1, 1);

        line_17 = new QFrame(groupBox_mask);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);

        gridLayout_27->addWidget(line_17, 0, 0, 1, 1);


        gridLayout_29->addLayout(gridLayout_27, 3, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_abertura = new QLabel(groupBox_mask);
        label_abertura->setObjectName(QString::fromUtf8("label_abertura"));

        gridLayout_9->addWidget(label_abertura, 0, 0, 1, 1);

        spinBox_abertura = new QSpinBox(groupBox_mask);
        spinBox_abertura->setObjectName(QString::fromUtf8("spinBox_abertura"));
        QPalette palette44;
        palette44.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette44.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette44.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_abertura->setPalette(palette44);
        spinBox_abertura->setMinimum(1);

        gridLayout_9->addWidget(spinBox_abertura, 0, 1, 1, 1);


        gridLayout_29->addLayout(gridLayout_9, 2, 0, 1, 1);

        gridLayout_28 = new QGridLayout();
        gridLayout_28->setSpacing(6);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        checkBox_mask = new QCheckBox(groupBox_mask);
        checkBox_mask->setObjectName(QString::fromUtf8("checkBox_mask"));

        gridLayout_28->addWidget(checkBox_mask, 1, 0, 1, 1);

        line_16 = new QFrame(groupBox_mask);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);

        gridLayout_28->addWidget(line_16, 0, 0, 1, 1);


        gridLayout_29->addLayout(gridLayout_28, 4, 0, 1, 1);

        line_18 = new QFrame(groupBox_mask);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);

        gridLayout_29->addWidget(line_18, 1, 0, 1, 1);


        gridLayout_47->addLayout(gridLayout_29, 0, 0, 1, 1);


        gridLayout_48->addWidget(groupBox_mask, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_48->addItem(verticalSpacer_5, 1, 0, 1, 1);


        gridLayout_49->addLayout(gridLayout_48, 0, 1, 1, 1);


        gridLayout_50->addLayout(gridLayout_49, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_18 = new QGridLayout(tab_6);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(6);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        groupBox_variaveis = new QGroupBox(tab_6);
        groupBox_variaveis->setObjectName(QString::fromUtf8("groupBox_variaveis"));
        gridLayout_13 = new QGridLayout(groupBox_variaveis);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_42 = new QGridLayout();
        gridLayout_42->setSpacing(6);
        gridLayout_42->setObjectName(QString::fromUtf8("gridLayout_42"));
        line_3 = new QFrame(groupBox_variaveis);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_42->addWidget(line_3, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setSpacing(6);
        horizontalLayout_60->setObjectName(QString::fromUtf8("horizontalLayout_60"));
        label_73 = new QLabel(groupBox_variaveis);
        label_73->setObjectName(QString::fromUtf8("label_73"));

        horizontalLayout_60->addWidget(label_73);

        spinBox_gleft = new QSpinBox(groupBox_variaveis);
        spinBox_gleft->setObjectName(QString::fromUtf8("spinBox_gleft"));
        QPalette palette45;
        palette45.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette45.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette45.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gleft->setPalette(palette45);
        spinBox_gleft->setMaximum(2000);

        horizontalLayout_60->addWidget(spinBox_gleft);


        verticalLayout_2->addLayout(horizontalLayout_60);

        line_41 = new QFrame(groupBox_variaveis);
        line_41->setObjectName(QString::fromUtf8("line_41"));
        line_41->setFrameShape(QFrame::HLine);
        line_41->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_41);

        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setSpacing(6);
        horizontalLayout_61->setObjectName(QString::fromUtf8("horizontalLayout_61"));
        label_74 = new QLabel(groupBox_variaveis);
        label_74->setObjectName(QString::fromUtf8("label_74"));

        horizontalLayout_61->addWidget(label_74);

        spinBox_gright = new QSpinBox(groupBox_variaveis);
        spinBox_gright->setObjectName(QString::fromUtf8("spinBox_gright"));
        QPalette palette46;
        palette46.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette46.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette46.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gright->setPalette(palette46);
        spinBox_gright->setMaximum(2000);

        horizontalLayout_61->addWidget(spinBox_gright);


        verticalLayout_2->addLayout(horizontalLayout_61);

        line_42 = new QFrame(groupBox_variaveis);
        line_42->setObjectName(QString::fromUtf8("line_42"));
        line_42->setFrameShape(QFrame::HLine);
        line_42->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_42);

        horizontalLayout_70 = new QHBoxLayout();
        horizontalLayout_70->setSpacing(6);
        horizontalLayout_70->setObjectName(QString::fromUtf8("horizontalLayout_70"));
        label_83 = new QLabel(groupBox_variaveis);
        label_83->setObjectName(QString::fromUtf8("label_83"));

        horizontalLayout_70->addWidget(label_83);

        spinBox_area_left = new QSpinBox(groupBox_variaveis);
        spinBox_area_left->setObjectName(QString::fromUtf8("spinBox_area_left"));
        QPalette palette47;
        palette47.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette47.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette47.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_area_left->setPalette(palette47);
        spinBox_area_left->setMaximum(2000);

        horizontalLayout_70->addWidget(spinBox_area_left);


        verticalLayout_2->addLayout(horizontalLayout_70);

        line_43 = new QFrame(groupBox_variaveis);
        line_43->setObjectName(QString::fromUtf8("line_43"));
        line_43->setFrameShape(QFrame::HLine);
        line_43->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_43);

        horizontalLayout_71 = new QHBoxLayout();
        horizontalLayout_71->setSpacing(6);
        horizontalLayout_71->setObjectName(QString::fromUtf8("horizontalLayout_71"));
        label_84 = new QLabel(groupBox_variaveis);
        label_84->setObjectName(QString::fromUtf8("label_84"));

        horizontalLayout_71->addWidget(label_84);

        spinBox_area_right = new QSpinBox(groupBox_variaveis);
        spinBox_area_right->setObjectName(QString::fromUtf8("spinBox_area_right"));
        QPalette palette48;
        palette48.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette48.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette48.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_area_right->setPalette(palette48);
        spinBox_area_right->setMaximum(2000);

        horizontalLayout_71->addWidget(spinBox_area_right);


        verticalLayout_2->addLayout(horizontalLayout_71);

        line_44 = new QFrame(groupBox_variaveis);
        line_44->setObjectName(QString::fromUtf8("line_44"));
        line_44->setFrameShape(QFrame::HLine);
        line_44->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_44);

        horizontalLayout_72 = new QHBoxLayout();
        horizontalLayout_72->setSpacing(6);
        horizontalLayout_72->setObjectName(QString::fromUtf8("horizontalLayout_72"));
        horizontalLayout_74 = new QHBoxLayout();
        horizontalLayout_74->setSpacing(6);
        horizontalLayout_74->setObjectName(QString::fromUtf8("horizontalLayout_74"));
        label_87 = new QLabel(groupBox_variaveis);
        label_87->setObjectName(QString::fromUtf8("label_87"));

        horizontalLayout_74->addWidget(label_87);

        spinBox_lzagueiro = new QSpinBox(groupBox_variaveis);
        spinBox_lzagueiro->setObjectName(QString::fromUtf8("spinBox_lzagueiro"));
        QPalette palette49;
        palette49.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette49.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette49.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_lzagueiro->setPalette(palette49);
        spinBox_lzagueiro->setMaximum(2000);

        horizontalLayout_74->addWidget(spinBox_lzagueiro);


        horizontalLayout_72->addLayout(horizontalLayout_74);


        verticalLayout_2->addLayout(horizontalLayout_72);

        line_45 = new QFrame(groupBox_variaveis);
        line_45->setObjectName(QString::fromUtf8("line_45"));
        line_45->setFrameShape(QFrame::HLine);
        line_45->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_45);

        horizontalLayout_73 = new QHBoxLayout();
        horizontalLayout_73->setSpacing(6);
        horizontalLayout_73->setObjectName(QString::fromUtf8("horizontalLayout_73"));
        label_86 = new QLabel(groupBox_variaveis);
        label_86->setObjectName(QString::fromUtf8("label_86"));

        horizontalLayout_73->addWidget(label_86);

        spinBox_lgoleiro = new QSpinBox(groupBox_variaveis);
        spinBox_lgoleiro->setObjectName(QString::fromUtf8("spinBox_lgoleiro"));
        QPalette palette50;
        palette50.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette50.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette50.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_lgoleiro->setPalette(palette50);
        spinBox_lgoleiro->setMaximum(2000);

        horizontalLayout_73->addWidget(spinBox_lgoleiro);


        verticalLayout_2->addLayout(horizontalLayout_73);


        gridLayout_42->addLayout(verticalLayout_2, 0, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_16 = new QLabel(groupBox_variaveis);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_6->addWidget(label_16);

        spinBox_ftop = new QSpinBox(groupBox_variaveis);
        spinBox_ftop->setObjectName(QString::fromUtf8("spinBox_ftop"));
        QPalette palette51;
        palette51.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette51.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette51.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_ftop->setPalette(palette51);
        spinBox_ftop->setMaximum(2000);

        horizontalLayout_6->addWidget(spinBox_ftop);


        verticalLayout_4->addLayout(horizontalLayout_6);

        line_38 = new QFrame(groupBox_variaveis);
        line_38->setObjectName(QString::fromUtf8("line_38"));
        line_38->setFrameShape(QFrame::HLine);
        line_38->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_38);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_17 = new QLabel(groupBox_variaveis);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_7->addWidget(label_17);

        spinBox_fbot = new QSpinBox(groupBox_variaveis);
        spinBox_fbot->setObjectName(QString::fromUtf8("spinBox_fbot"));
        QPalette palette52;
        palette52.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette52.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette52.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_fbot->setPalette(palette52);
        spinBox_fbot->setMaximum(2000);

        horizontalLayout_7->addWidget(spinBox_fbot);


        verticalLayout_4->addLayout(horizontalLayout_7);

        line_37 = new QFrame(groupBox_variaveis);
        line_37->setObjectName(QString::fromUtf8("line_37"));
        line_37->setFrameShape(QFrame::HLine);
        line_37->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_37);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_69 = new QLabel(groupBox_variaveis);
        label_69->setObjectName(QString::fromUtf8("label_69"));

        horizontalLayout_12->addWidget(label_69);

        spinBox_gtopy = new QSpinBox(groupBox_variaveis);
        spinBox_gtopy->setObjectName(QString::fromUtf8("spinBox_gtopy"));
        QPalette palette53;
        palette53.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette53.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette53.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gtopy->setPalette(palette53);
        spinBox_gtopy->setMaximum(2000);

        horizontalLayout_12->addWidget(spinBox_gtopy);


        verticalLayout_4->addLayout(horizontalLayout_12);

        line_36 = new QFrame(groupBox_variaveis);
        line_36->setObjectName(QString::fromUtf8("line_36"));
        line_36->setFrameShape(QFrame::HLine);
        line_36->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_36);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_70 = new QLabel(groupBox_variaveis);
        label_70->setObjectName(QString::fromUtf8("label_70"));

        horizontalLayout_13->addWidget(label_70);

        spinBox_gboty = new QSpinBox(groupBox_variaveis);
        spinBox_gboty->setObjectName(QString::fromUtf8("spinBox_gboty"));
        QPalette palette54;
        palette54.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette54.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_gboty->setPalette(palette54);
        spinBox_gboty->setMaximum(2000);

        horizontalLayout_13->addWidget(spinBox_gboty);


        verticalLayout_4->addLayout(horizontalLayout_13);

        line_39 = new QFrame(groupBox_variaveis);
        line_39->setObjectName(QString::fromUtf8("line_39"));
        line_39->setFrameShape(QFrame::HLine);
        line_39->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_39);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_71 = new QLabel(groupBox_variaveis);
        label_71->setObjectName(QString::fromUtf8("label_71"));

        horizontalLayout_14->addWidget(label_71);

        spinBox_fleftx = new QSpinBox(groupBox_variaveis);
        spinBox_fleftx->setObjectName(QString::fromUtf8("spinBox_fleftx"));
        QPalette palette55;
        palette55.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette55.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette55.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_fleftx->setPalette(palette55);
        spinBox_fleftx->setMaximum(2000);

        horizontalLayout_14->addWidget(spinBox_fleftx);


        verticalLayout_4->addLayout(horizontalLayout_14);

        line_40 = new QFrame(groupBox_variaveis);
        line_40->setObjectName(QString::fromUtf8("line_40"));
        line_40->setFrameShape(QFrame::HLine);
        line_40->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_40);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_72 = new QLabel(groupBox_variaveis);
        label_72->setObjectName(QString::fromUtf8("label_72"));

        horizontalLayout_15->addWidget(label_72);

        spinBox_frightx = new QSpinBox(groupBox_variaveis);
        spinBox_frightx->setObjectName(QString::fromUtf8("spinBox_frightx"));
        QPalette palette56;
        palette56.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette56.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette56.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_frightx->setPalette(palette56);
        spinBox_frightx->setMaximum(2000);

        horizontalLayout_15->addWidget(spinBox_frightx);


        verticalLayout_4->addLayout(horizontalLayout_15);


        gridLayout_42->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_75 = new QHBoxLayout();
        horizontalLayout_75->setSpacing(6);
        horizontalLayout_75->setObjectName(QString::fromUtf8("horizontalLayout_75"));
        label_88 = new QLabel(groupBox_variaveis);
        label_88->setObjectName(QString::fromUtf8("label_88"));

        horizontalLayout_75->addWidget(label_88);

        spinBox_area_topy = new QSpinBox(groupBox_variaveis);
        spinBox_area_topy->setObjectName(QString::fromUtf8("spinBox_area_topy"));
        QPalette palette57;
        palette57.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette57.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette57.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_area_topy->setPalette(palette57);
        spinBox_area_topy->setMaximum(2000);

        horizontalLayout_75->addWidget(spinBox_area_topy);


        verticalLayout_5->addLayout(horizontalLayout_75);

        line_48 = new QFrame(groupBox_variaveis);
        line_48->setObjectName(QString::fromUtf8("line_48"));
        line_48->setFrameShape(QFrame::HLine);
        line_48->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_48);

        horizontalLayout_76 = new QHBoxLayout();
        horizontalLayout_76->setSpacing(6);
        horizontalLayout_76->setObjectName(QString::fromUtf8("horizontalLayout_76"));
        label_89 = new QLabel(groupBox_variaveis);
        label_89->setObjectName(QString::fromUtf8("label_89"));

        horizontalLayout_76->addWidget(label_89);

        spinBox_area_boty = new QSpinBox(groupBox_variaveis);
        spinBox_area_boty->setObjectName(QString::fromUtf8("spinBox_area_boty"));
        QPalette palette58;
        palette58.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette58.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette58.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_area_boty->setPalette(palette58);
        spinBox_area_boty->setMaximum(2000);

        horizontalLayout_76->addWidget(spinBox_area_boty);


        verticalLayout_5->addLayout(horizontalLayout_76);

        line_47 = new QFrame(groupBox_variaveis);
        line_47->setObjectName(QString::fromUtf8("line_47"));
        line_47->setFrameShape(QFrame::HLine);
        line_47->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_47);

        horizontalLayout_77 = new QHBoxLayout();
        horizontalLayout_77->setSpacing(6);
        horizontalLayout_77->setObjectName(QString::fromUtf8("horizontalLayout_77"));
        label_90 = new QLabel(groupBox_variaveis);
        label_90->setObjectName(QString::fromUtf8("label_90"));

        horizontalLayout_77->addWidget(label_90);

        spinBox_p_area_b = new QSpinBox(groupBox_variaveis);
        spinBox_p_area_b->setObjectName(QString::fromUtf8("spinBox_p_area_b"));
        QPalette palette59;
        palette59.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette59.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette59.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_p_area_b->setPalette(palette59);
        spinBox_p_area_b->setMaximum(2000);

        horizontalLayout_77->addWidget(spinBox_p_area_b);


        verticalLayout_5->addLayout(horizontalLayout_77);

        line_46 = new QFrame(groupBox_variaveis);
        line_46->setObjectName(QString::fromUtf8("line_46"));
        line_46->setFrameShape(QFrame::HLine);
        line_46->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_46);

        horizontalLayout_78 = new QHBoxLayout();
        horizontalLayout_78->setSpacing(6);
        horizontalLayout_78->setObjectName(QString::fromUtf8("horizontalLayout_78"));
        label_91 = new QLabel(groupBox_variaveis);
        label_91->setObjectName(QString::fromUtf8("label_91"));

        horizontalLayout_78->addWidget(label_91);

        spinBox_p_area_t = new QSpinBox(groupBox_variaveis);
        spinBox_p_area_t->setObjectName(QString::fromUtf8("spinBox_p_area_t"));
        QPalette palette60;
        palette60.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette60.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette60.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        spinBox_p_area_t->setPalette(palette60);
        spinBox_p_area_t->setMaximum(2000);

        horizontalLayout_78->addWidget(spinBox_p_area_t);


        verticalLayout_5->addLayout(horizontalLayout_78);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));

        verticalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox_help_lines = new QCheckBox(groupBox_variaveis);
        checkBox_help_lines->setObjectName(QString::fromUtf8("checkBox_help_lines"));

        verticalLayout_3->addWidget(checkBox_help_lines);


        verticalLayout_5->addLayout(verticalLayout_3);


        gridLayout_42->addLayout(verticalLayout_5, 0, 4, 1, 1);

        line_4 = new QFrame(groupBox_variaveis);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_42->addWidget(line_4, 0, 3, 1, 1);


        gridLayout_13->addLayout(gridLayout_42, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_8, 1, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_variaveis, 0, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        line_5 = new QFrame(tab_6);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_5, 1, 0, 1, 1);

        checkBox_linha_principais = new QCheckBox(tab_6);
        checkBox_linha_principais->setObjectName(QString::fromUtf8("checkBox_linha_principais"));

        gridLayout_12->addWidget(checkBox_linha_principais, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_3, 6, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_4, 0, 0, 1, 1);

        pushButton_linhas_campo = new QPushButton(tab_6);
        pushButton_linhas_campo->setObjectName(QString::fromUtf8("pushButton_linhas_campo"));
        QPalette palette61;
        palette61.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette61.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette61.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        pushButton_linhas_campo->setPalette(palette61);

        gridLayout_12->addWidget(pushButton_linhas_campo, 4, 0, 1, 1);

        checkBox_linha_secundaria = new QCheckBox(tab_6);
        checkBox_linha_secundaria->setObjectName(QString::fromUtf8("checkBox_linha_secundaria"));

        gridLayout_12->addWidget(checkBox_linha_secundaria, 3, 0, 1, 1);

        line_6 = new QFrame(tab_6);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_6, 5, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_12, 0, 1, 1, 1);


        gridLayout_18->addLayout(gridLayout_17, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());

        verticalLayout_7->addWidget(tabWidget_2);


        gridLayout_61->addLayout(verticalLayout_7, 1, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_61->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_61->addItem(verticalSpacer_8, 0, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_61->addItem(horizontalSpacer_11, 1, 2, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_61->addItem(verticalSpacer_10, 0, 2, 1, 1);


        gridLayout_62->addLayout(gridLayout_61, 0, 0, 1, 1);

        tabWidget->addTab(calibracao, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        groupBox_4 = new QGroupBox(tab_7);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 521, 311));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(60, 140, 62, 17));
        monitor = new QLabel(groupBox_4);
        monitor->setObjectName(QString::fromUtf8("monitor"));
        monitor->setGeometry(QRect(270, 40, 221, 141));
        monitor->setFrameShape(QFrame::Box);
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 210, 381, 66));
        gridLayout_70 = new QGridLayout(layoutWidget);
        gridLayout_70->setSpacing(6);
        gridLayout_70->setContentsMargins(11, 11, 11, 11);
        gridLayout_70->setObjectName(QString::fromUtf8("gridLayout_70"));
        gridLayout_70->setContentsMargins(0, 0, 0, 0);
        gridLayout_69 = new QGridLayout();
        gridLayout_69->setSpacing(6);
        gridLayout_69->setObjectName(QString::fromUtf8("gridLayout_69"));
        gridLayout_66 = new QGridLayout();
        gridLayout_66->setSpacing(6);
        gridLayout_66->setObjectName(QString::fromUtf8("gridLayout_66"));
        write_data = new QPushButton(layoutWidget);
        write_data->setObjectName(QString::fromUtf8("write_data"));
        QPalette palette62;
        palette62.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette62.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette62.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        write_data->setPalette(palette62);

        gridLayout_66->addWidget(write_data, 0, 0, 1, 1);

        send_data = new QLineEdit(layoutWidget);
        send_data->setObjectName(QString::fromUtf8("send_data"));

        gridLayout_66->addWidget(send_data, 0, 1, 1, 1);


        gridLayout_69->addLayout(gridLayout_66, 0, 0, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_69->addWidget(label_14, 0, 1, 1, 1);


        gridLayout_70->addLayout(gridLayout_69, 0, 0, 1, 1);

        gridLayout_68 = new QGridLayout();
        gridLayout_68->setSpacing(6);
        gridLayout_68->setObjectName(QString::fromUtf8("gridLayout_68"));
        gridLayout_67 = new QGridLayout();
        gridLayout_67->setSpacing(6);
        gridLayout_67->setObjectName(QString::fromUtf8("gridLayout_67"));
        read_data = new QPushButton(layoutWidget);
        read_data->setObjectName(QString::fromUtf8("read_data"));
        QPalette palette63;
        palette63.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette63.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette63.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        read_data->setPalette(palette63);

        gridLayout_67->addWidget(read_data, 0, 0, 1, 1);

        receive_data = new QLineEdit(layoutWidget);
        receive_data->setObjectName(QString::fromUtf8("receive_data"));

        gridLayout_67->addWidget(receive_data, 0, 1, 1, 1);


        gridLayout_68->addLayout(gridLayout_67, 0, 0, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_68->addWidget(label_15, 0, 1, 1, 1);


        gridLayout_70->addLayout(gridLayout_68, 1, 0, 1, 1);

        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 251, 93));
        gridLayout_71 = new QGridLayout(layoutWidget1);
        gridLayout_71->setSpacing(6);
        gridLayout_71->setContentsMargins(11, 11, 11, 11);
        gridLayout_71->setObjectName(QString::fromUtf8("gridLayout_71"));
        gridLayout_71->setContentsMargins(0, 0, 0, 0);
        gridLayout_65 = new QGridLayout();
        gridLayout_65->setSpacing(6);
        gridLayout_65->setObjectName(QString::fromUtf8("gridLayout_65"));
        connect_disconnect = new QPushButton(layoutWidget1);
        connect_disconnect->setObjectName(QString::fromUtf8("connect_disconnect"));
        QPalette palette64;
        palette64.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette64.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette64.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        connect_disconnect->setPalette(palette64);

        gridLayout_65->addWidget(connect_disconnect, 0, 0, 1, 1);

        gridLayout_64 = new QGridLayout();
        gridLayout_64->setSpacing(6);
        gridLayout_64->setObjectName(QString::fromUtf8("gridLayout_64"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_64->addWidget(label_9, 0, 0, 1, 1);

        select_ports = new QComboBox(layoutWidget1);
        select_ports->setObjectName(QString::fromUtf8("select_ports"));
        QPalette palette65;
        palette65.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette65.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette65.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        select_ports->setPalette(palette65);

        gridLayout_64->addWidget(select_ports, 0, 1, 1, 1);


        gridLayout_65->addLayout(gridLayout_64, 1, 0, 1, 1);

        refresh_ports = new QPushButton(layoutWidget1);
        refresh_ports->setObjectName(QString::fromUtf8("refresh_ports"));
        QPalette palette66;
        palette66.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette66.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette66.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        refresh_ports->setPalette(palette66);

        gridLayout_65->addWidget(refresh_ports, 2, 0, 1, 1);


        gridLayout_71->addLayout(gridLayout_65, 0, 0, 1, 1);

        status = new QLabel(layoutWidget1);
        status->setObjectName(QString::fromUtf8("status"));

        gridLayout_71->addWidget(status, 0, 1, 1, 1);

        qcustomplot = new QCustomPlot(tab_7);
        qcustomplot->setObjectName(QString::fromUtf8("qcustomplot"));
        qcustomplot->setGeometry(QRect(570, 50, 811, 251));
        groupBox_6 = new QGroupBox(tab_7);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(980, 330, 291, 111));
        gridLayout_81 = new QGridLayout(groupBox_6);
        gridLayout_81->setSpacing(6);
        gridLayout_81->setContentsMargins(11, 11, 11, 11);
        gridLayout_81->setObjectName(QString::fromUtf8("gridLayout_81"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_79 = new QGridLayout();
        gridLayout_79->setSpacing(6);
        gridLayout_79->setObjectName(QString::fromUtf8("gridLayout_79"));
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_79->addWidget(label_21, 0, 1, 1, 1);

        lcdNumber = new QLCDNumber(groupBox_6);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setProperty("value", QVariant(0.000000000000000));
        lcdNumber->setProperty("intValue", QVariant(0));

        gridLayout_79->addWidget(lcdNumber, 0, 3, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_79->addItem(horizontalSpacer_14, 0, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_79);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);

        gridLayout_80 = new QGridLayout();
        gridLayout_80->setSpacing(6);
        gridLayout_80->setObjectName(QString::fromUtf8("gridLayout_80"));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_80->addWidget(label_22, 0, 0, 1, 1);

        lcdNumber_2 = new QLCDNumber(groupBox_6);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        gridLayout_80->addWidget(lcdNumber_2, 0, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_80);


        gridLayout_81->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        widget = new QWidget(tab_7);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(600, 320, 311, 143));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_73 = new QGridLayout();
        gridLayout_73->setSpacing(6);
        gridLayout_73->setObjectName(QString::fromUtf8("gridLayout_73"));
        label_18 = new QLabel(widget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_73->addWidget(label_18, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_73->addWidget(comboBox_2, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_73->addItem(horizontalSpacer_10, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_73);

        groupBox_5 = new QGroupBox(widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_78 = new QGridLayout(groupBox_5);
        gridLayout_78->setSpacing(6);
        gridLayout_78->setContentsMargins(11, 11, 11, 11);
        gridLayout_78->setObjectName(QString::fromUtf8("gridLayout_78"));
        gridLayout_77 = new QGridLayout();
        gridLayout_77->setSpacing(6);
        gridLayout_77->setObjectName(QString::fromUtf8("gridLayout_77"));
        gridLayout_75 = new QGridLayout();
        gridLayout_75->setSpacing(6);
        gridLayout_75->setObjectName(QString::fromUtf8("gridLayout_75"));
        gridLayout_72 = new QGridLayout();
        gridLayout_72->setSpacing(6);
        gridLayout_72->setObjectName(QString::fromUtf8("gridLayout_72"));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_72->addWidget(label_19, 0, 0, 1, 1);

        sendvl = new QSlider(groupBox_5);
        sendvl->setObjectName(QString::fromUtf8("sendvl"));
        sendvl->setMinimum(-100);
        sendvl->setMaximum(100);
        sendvl->setOrientation(Qt::Horizontal);

        gridLayout_72->addWidget(sendvl, 0, 1, 1, 1);


        gridLayout_75->addLayout(gridLayout_72, 0, 0, 1, 1);

        sendvl2 = new QSpinBox(groupBox_5);
        sendvl2->setObjectName(QString::fromUtf8("sendvl2"));
        sendvl2->setMinimum(-100);
        sendvl2->setMaximum(100);

        gridLayout_75->addWidget(sendvl2, 0, 1, 1, 1);


        gridLayout_77->addLayout(gridLayout_75, 0, 0, 1, 1);

        gridLayout_76 = new QGridLayout();
        gridLayout_76->setSpacing(6);
        gridLayout_76->setObjectName(QString::fromUtf8("gridLayout_76"));
        gridLayout_74 = new QGridLayout();
        gridLayout_74->setSpacing(6);
        gridLayout_74->setObjectName(QString::fromUtf8("gridLayout_74"));
        sendvr = new QSlider(groupBox_5);
        sendvr->setObjectName(QString::fromUtf8("sendvr"));
        sendvr->setMinimum(-100);
        sendvr->setMaximum(100);
        sendvr->setOrientation(Qt::Horizontal);

        gridLayout_74->addWidget(sendvr, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_74->addWidget(label_20, 0, 0, 1, 1);


        gridLayout_76->addLayout(gridLayout_74, 0, 0, 1, 1);

        sendvr2 = new QSpinBox(groupBox_5);
        sendvr2->setObjectName(QString::fromUtf8("sendvr2"));
        sendvr2->setMinimum(-100);
        sendvr2->setMaximum(100);

        gridLayout_76->addWidget(sendvr2, 0, 1, 1, 1);


        gridLayout_77->addLayout(gridLayout_76, 1, 0, 1, 1);


        gridLayout_78->addLayout(gridLayout_77, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_5);

        tabWidget->addTab(tab_7, QString());

        gridLayout_63->addWidget(tabWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_4);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1476, 22));
        menu_Classificadores = new QMenu(menuBar);
        menu_Classificadores->setObjectName(QString::fromUtf8("menu_Classificadores"));
        menuTime = new QMenu(menuBar);
        menuTime->setObjectName(QString::fromUtf8("menuTime"));
        menuEspa_o_de_cores = new QMenu(menuBar);
        menuEspa_o_de_cores->setObjectName(QString::fromUtf8("menuEspa_o_de_cores"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Classificadores->menuAction());
        menuBar->addAction(menuTime->menuAction());
        menuBar->addAction(menuEspa_o_de_cores->menuAction());
        menu_Classificadores->addAction(actionAbrir_Settings);
        menu_Classificadores->addAction(actionKmeans);
        menuTime->addAction(select_azul);
        menuTime->addAction(select_amarelo);
        menuEspa_o_de_cores->addAction(select_RGB);
        menuEspa_o_de_cores->addAction(select_New_RGB);
        menuEspa_o_de_cores->addAction(select_HSV);

        retranslateUi(MainWindow);
        QObject::connect(contraste, SIGNAL(valueChanged(int)), spinBox_cont, SLOT(setValue(int)));
        QObject::connect(brilho, SIGNAL(valueChanged(int)), spinBox_bri, SLOT(setValue(int)));
        QObject::connect(Gain, SIGNAL(valueChanged(int)), spinBox_gain, SLOT(setValue(int)));
        QObject::connect(nitidez, SIGNAL(valueChanged(int)), spinBox_nitidez, SLOT(setValue(int)));
        QObject::connect(hue, SIGNAL(valueChanged(int)), spinBox_hue, SLOT(setValue(int)));
        QObject::connect(exposicao, SIGNAL(valueChanged(int)), spinBox_exp, SLOT(setValue(int)));
        QObject::connect(white_balance, SIGNAL(valueChanged(int)), spinBox_wb, SLOT(setValue(int)));
        QObject::connect(saturacao, SIGNAL(valueChanged(int)), spinBox_sat, SLOT(setValue(int)));
        QObject::connect(Gamma, SIGNAL(valueChanged(int)), spinBox_gamma, SLOT(setValue(int)));
        QObject::connect(Back_Compensation, SIGNAL(valueChanged(int)), spinBox_back_compensation, SLOT(setValue(int)));
        QObject::connect(spinBox_back_compensation, SIGNAL(valueChanged(int)), Back_Compensation, SLOT(setValue(int)));
        QObject::connect(spinBox_nitidez, SIGNAL(valueChanged(int)), nitidez, SLOT(setValue(int)));
        QObject::connect(spinBox_hue, SIGNAL(valueChanged(int)), hue, SLOT(setValue(int)));
        QObject::connect(spinBox_exp, SIGNAL(valueChanged(int)), exposicao, SLOT(setValue(int)));
        QObject::connect(spinBox_wb, SIGNAL(valueChanged(int)), white_balance, SLOT(setValue(int)));
        QObject::connect(spinBox_sat, SIGNAL(valueChanged(int)), saturacao, SLOT(setValue(int)));
        QObject::connect(spinBox_gamma, SIGNAL(valueChanged(int)), Gamma, SLOT(setValue(int)));
        QObject::connect(spinBox_cont, SIGNAL(valueChanged(int)), contraste, SLOT(setValue(int)));
        QObject::connect(spinBox_bri, SIGNAL(valueChanged(int)), brilho, SLOT(setValue(int)));
        QObject::connect(spinBox_gain, SIGNAL(valueChanged(int)), Gain, SLOT(setValue(int)));
        QObject::connect(bmax, SIGNAL(valueChanged(int)), spinBox_bmax, SLOT(setValue(int)));
        QObject::connect(bmin, SIGNAL(valueChanged(int)), spinBox_bmin, SLOT(setValue(int)));
        QObject::connect(rmax, SIGNAL(valueChanged(int)), spinBox_rmax, SLOT(setValue(int)));
        QObject::connect(gmax, SIGNAL(valueChanged(int)), spinBox_gmax, SLOT(setValue(int)));
        QObject::connect(gmin, SIGNAL(valueChanged(int)), spinBox_gmin, SLOT(setValue(int)));
        QObject::connect(spinBox_bmax, SIGNAL(valueChanged(int)), bmax, SLOT(setValue(int)));
        QObject::connect(spinBox_bmin, SIGNAL(valueChanged(int)), bmin, SLOT(setValue(int)));
        QObject::connect(rmin, SIGNAL(valueChanged(int)), spinBox_rmin, SLOT(setValue(int)));
        QObject::connect(spinBox_gmax, SIGNAL(valueChanged(int)), gmax, SLOT(setValue(int)));
        QObject::connect(spinBox_gmin, SIGNAL(valueChanged(int)), gmin, SLOT(setValue(int)));
        QObject::connect(spinBox_rmax, SIGNAL(valueChanged(int)), rmax, SLOT(setValue(int)));
        QObject::connect(spinBox_rmin, SIGNAL(valueChanged(int)), rmin, SLOT(setValue(int)));
        QObject::connect(sendvl, SIGNAL(valueChanged(int)), sendvl2, SLOT(setValue(int)));
        QObject::connect(sendvl2, SIGNAL(valueChanged(int)), sendvl, SLOT(setValue(int)));
        QObject::connect(sendvr, SIGNAL(valueChanged(int)), sendvr2, SLOT(setValue(int)));
        QObject::connect(sendvr2, SIGNAL(valueChanged(int)), sendvr, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(1);
        MenuColorSpace->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lambe Sujo", nullptr));
        actionKmeans->setText(QCoreApplication::translate("MainWindow", "Constantes", nullptr));
        actionFind_Contours->setText(QCoreApplication::translate("MainWindow", "Find Contours", nullptr));
        actionComandos->setText(QCoreApplication::translate("MainWindow", "Comandos", nullptr));
        actionAzul->setText(QCoreApplication::translate("MainWindow", "Azul", nullptr));
        actionAmarelo->setText(QCoreApplication::translate("MainWindow", "Amarelo", nullptr));
        select_azul->setText(QCoreApplication::translate("MainWindow", "Azul", nullptr));
        select_amarelo->setText(QCoreApplication::translate("MainWindow", "Amarelo", nullptr));
        actionAbrir_Settings->setText(QCoreApplication::translate("MainWindow", "Abrir Settings", nullptr));
        select_RGB->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        select_New_RGB->setText(QCoreApplication::translate("MainWindow", "New RGB", nullptr));
        select_HSV->setText(QCoreApplication::translate("MainWindow", "HSV", nullptr));
        Tempo->setText(QCoreApplication::translate("MainWindow", "Tempo:", nullptr));
        milesegundos->setText(QString());
        Tempoms->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        janela->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Comandos", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Atacante", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Zagueiro", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Estrategia", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Goleiro", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Principal), QCoreApplication::translate("MainWindow", "Principal", nullptr));
        janela_2->setText(QString());
        pushButton_default->setText(QCoreApplication::translate("MainWindow", "Defaut", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "Aplicar", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Defini\303\247\303\265es de Imagem", nullptr));
        label_sat->setText(QCoreApplication::translate("MainWindow", "Satura\303\247\303\243o", nullptr));
        label_exp->setText(QCoreApplication::translate("MainWindow", "Exposi\303\247\303\243o", nullptr));
        label_hue->setText(QCoreApplication::translate("MainWindow", "Hue", nullptr));
        label_bri->setText(QCoreApplication::translate("MainWindow", "Brilho", nullptr));
        label_cont->setText(QCoreApplication::translate("MainWindow", "Contraste", nullptr));
        label_back_comp->setText(QCoreApplication::translate("MainWindow", "B. Compensat.", nullptr));
        label_wb->setText(QCoreApplication::translate("MainWindow", "W. Balance", nullptr));
        label_gamma->setText(QCoreApplication::translate("MainWindow", "Gamma", nullptr));
        label_gain->setText(QCoreApplication::translate("MainWindow", "Gain", nullptr));
        label_nitidez->setText(QCoreApplication::translate("MainWindow", "Nitidez", nullptr));
        checkBox_expo_auto->setText(QCoreApplication::translate("MainWindow", "Exposi\303\247\303\243o Autom\303\241tica", nullptr));
        checkBox_wb_auto->setText(QCoreApplication::translate("MainWindow", "W. Balance Autom\303\241tico", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Resolu\303\247\303\243o e corte", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Resolu\303\247\303\243o:", nullptr));
        Resolucao->setItemText(0, QCoreApplication::translate("MainWindow", "640x480", nullptr));
        Resolucao->setItemText(1, QCoreApplication::translate("MainWindow", "800x600", nullptr));
        Resolucao->setItemText(2, QCoreApplication::translate("MainWindow", "1024x768", nullptr));
        Resolucao->setItemText(3, QCoreApplication::translate("MainWindow", "1280x720", nullptr));
        Resolucao->setItemText(4, QCoreApplication::translate("MainWindow", "1920x1080", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Corte:", nullptr));
        pushButton_cortar->setText(QCoreApplication::translate("MainWindow", "Cortar", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Corte", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "M\303\255n", nullptr));
        checkBox_flip->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        checkBox_resolution->setText(QCoreApplication::translate("MainWindow", "Resolution", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("MainWindow", "Camera Settings", nullptr));
        groupBox_limiares->setTitle(QCoreApplication::translate("MainWindow", "Limiares", nullptr));
        checkBox_limiar->setText(QCoreApplication::translate("MainWindow", "Exibir Limiar", nullptr));
        label_cor->setText(QCoreApplication::translate("MainWindow", "Cor:", nullptr));
        comboBox_colors->setItemText(0, QCoreApplication::translate("MainWindow", "Azul", nullptr));
        comboBox_colors->setItemText(1, QCoreApplication::translate("MainWindow", "Amarelo", nullptr));
        comboBox_colors->setItemText(2, QCoreApplication::translate("MainWindow", "Verde", nullptr));
        comboBox_colors->setItemText(3, QCoreApplication::translate("MainWindow", "Laranja", nullptr));
        comboBox_colors->setItemText(4, QCoreApplication::translate("MainWindow", "Vermelho", nullptr));
        comboBox_colors->setItemText(5, QCoreApplication::translate("MainWindow", "Magenta", nullptr));

        groupBox_r->setTitle(QCoreApplication::translate("MainWindow", " R", nullptr));
        label_rmax->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        label_rmin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        groupBox_g->setTitle(QCoreApplication::translate("MainWindow", " G", nullptr));
        label_gmin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_gmax->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        groupBox_b->setTitle(QCoreApplication::translate("MainWindow", " B", nullptr));
        label_bmax->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        label_bmin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        MenuColorSpace->setTabText(MenuColorSpace->indexOf(tab_3), QCoreApplication::translate("MainWindow", "RGB", nullptr));
        groupBox_h->setTitle(QCoreApplication::translate("MainWindow", " H", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        groupBox_s->setTitle(QCoreApplication::translate("MainWindow", "S", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        groupBox_v->setTitle(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        MenuColorSpace->setTabText(MenuColorSpace->indexOf(tab_4), QCoreApplication::translate("MainWindow", "HSV", nullptr));
        groupBox_18->setTitle(QCoreApplication::translate("MainWindow", " R", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", " G", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", " B", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "M\303\241x", nullptr));
        MenuColorSpace->setTabText(MenuColorSpace->indexOf(tab_5), QCoreApplication::translate("MainWindow", "NEW_RGB", nullptr));
        groupBox_mask->setTitle(QCoreApplication::translate("MainWindow", "M\303\241scara", nullptr));
        label_tipomask->setText(QCoreApplication::translate("MainWindow", "Tipo de M\303\241scara:", nullptr));
        comboBox_tipomask->setItemText(0, QCoreApplication::translate("MainWindow", "Rect", nullptr));
        comboBox_tipomask->setItemText(1, QCoreApplication::translate("MainWindow", "cross", nullptr));
        comboBox_tipomask->setItemText(2, QCoreApplication::translate("MainWindow", "Ellipse", nullptr));

        label_fechamento->setText(QCoreApplication::translate("MainWindow", "Tamanho Fechamento:", nullptr));
        label_abertura->setText(QCoreApplication::translate("MainWindow", "Tamanho Abertura:       ", nullptr));
        checkBox_mask->setText(QCoreApplication::translate("MainWindow", "Exibir M\303\241scara", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Limiar e M\303\241scara", nullptr));
        groupBox_variaveis->setTitle(QCoreApplication::translate("MainWindow", "Vari\303\241veis", nullptr));
        label_73->setText(QCoreApplication::translate("MainWindow", "gLeft", nullptr));
        label_74->setText(QCoreApplication::translate("MainWindow", "gRight", nullptr));
        label_83->setText(QCoreApplication::translate("MainWindow", "aLeft", nullptr));
        label_84->setText(QCoreApplication::translate("MainWindow", "aRight", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "lZagueiro", nullptr));
        label_86->setText(QCoreApplication::translate("MainWindow", "lGoleiro", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "fTop", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "fBot", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "gTop", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "gBot", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "fLeft", nullptr));
        label_72->setText(QCoreApplication::translate("MainWindow", "fRight", nullptr));
        label_88->setText(QCoreApplication::translate("MainWindow", "aTop", nullptr));
        label_89->setText(QCoreApplication::translate("MainWindow", "aBot", nullptr));
        label_90->setText(QCoreApplication::translate("MainWindow", "p_area_b", nullptr));
        label_91->setText(QCoreApplication::translate("MainWindow", "p_area_t", nullptr));
        checkBox_help_lines->setText(QCoreApplication::translate("MainWindow", "Ajuda", nullptr));
        checkBox_linha_principais->setText(QCoreApplication::translate("MainWindow", "Linhas Principais", nullptr));
        pushButton_linhas_campo->setText(QCoreApplication::translate("MainWindow", "Estimar", nullptr));
        checkBox_linha_secundaria->setText(QCoreApplication::translate("MainWindow", "Linhas Secund\303\241rias", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Linhas do Campo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(calibracao), QCoreApplication::translate("MainWindow", "Calibra\303\247\303\243o", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Teste de Conec\303\247\303\243o", nullptr));
        label_10->setText(QString());
        monitor->setText(QString());
        write_data->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Enviado  ", nullptr));
        read_data->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Recebido", nullptr));
        connect_disconnect->setText(QCoreApplication::translate("MainWindow", "Conetar", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Porta:", nullptr));
        refresh_ports->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        status->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Resposta", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "VL", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "VR", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Select Robot", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Enviar Velocidade", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "VL", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "VR", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Comunica\303\247\303\243o", nullptr));
        menu_Classificadores->setTitle(QCoreApplication::translate("MainWindow", "&Opcoes", nullptr));
        menuTime->setTitle(QCoreApplication::translate("MainWindow", "&Time", nullptr));
        menuEspa_o_de_cores->setTitle(QCoreApplication::translate("MainWindow", "Espa\303\247o de cores", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
