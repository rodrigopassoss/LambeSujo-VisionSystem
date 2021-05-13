/********************************************************************************
** Form generated from reading UI file 'janelaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mouseevents.h>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *cortar;
    QPushButton *calibrar;
    QGroupBox *settings;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *guia;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *showPoint;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *showRect;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *num_pontos;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *applyAjuste;
    QGroupBox *groupBox_3;
    QCheckBox *customOrder;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *Ponto;
    QSpinBox *indexPoint;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QSpinBox *X_ponto;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QSpinBox *Y_ponto;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *marcar;
    QPushButton *remover;
    QPushButton *zerar;
    mouseevents *frame;
    QLabel *info;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *XY_pos;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *option;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *time;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QString::fromUtf8("JanelaPrincipal"));
        JanelaPrincipal->resize(795, 732);
        centralwidget = new QWidget(JanelaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 450, 751, 221));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 141, 171));
        QFont font;
        font.setPointSize(9);
        groupBox_2->setFont(font);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 121, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cortar = new QPushButton(layoutWidget);
        cortar->setObjectName(QString::fromUtf8("cortar"));

        verticalLayout->addWidget(cortar);

        calibrar = new QPushButton(layoutWidget);
        calibrar->setObjectName(QString::fromUtf8("calibrar"));

        verticalLayout->addWidget(calibrar);

        settings = new QGroupBox(groupBox);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setGeometry(QRect(160, 30, 321, 171));
        layoutWidget1 = new QWidget(settings);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(169, 36, 141, 111));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        guia = new QCheckBox(layoutWidget1);
        guia->setObjectName(QString::fromUtf8("guia"));

        horizontalLayout->addWidget(guia);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        showPoint = new QCheckBox(layoutWidget1);
        showPoint->setObjectName(QString::fromUtf8("showPoint"));

        horizontalLayout_5->addWidget(showPoint);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        showRect = new QCheckBox(layoutWidget1);
        showRect->setObjectName(QString::fromUtf8("showRect"));

        verticalLayout_3->addWidget(showRect);

        layoutWidget2 = new QWidget(settings);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 156, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        num_pontos = new QSpinBox(layoutWidget2);
        num_pontos->setObjectName(QString::fromUtf8("num_pontos"));
        num_pontos->setMinimum(6);
        num_pontos->setMaximum(19);

        horizontalLayout_2->addWidget(num_pontos);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));

        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        applyAjuste = new QPushButton(layoutWidget2);
        applyAjuste->setObjectName(QString::fromUtf8("applyAjuste"));

        horizontalLayout_4->addWidget(applyAjuste);


        verticalLayout_2->addLayout(horizontalLayout_4);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(490, 30, 241, 171));
        customOrder = new QCheckBox(groupBox_3);
        customOrder->setObjectName(QString::fromUtf8("customOrder"));
        customOrder->setGeometry(QRect(11, 31, 143, 21));
        customOrder->setFont(font);
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 60, 221, 103));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        Ponto = new QLabel(layoutWidget3);
        Ponto->setObjectName(QString::fromUtf8("Ponto"));

        horizontalLayout_3->addWidget(Ponto);

        indexPoint = new QSpinBox(layoutWidget3);
        indexPoint->setObjectName(QString::fromUtf8("indexPoint"));

        horizontalLayout_3->addWidget(indexPoint);


        horizontalLayout_13->addLayout(horizontalLayout_3);

        horizontalSpacer_6 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_10->addWidget(label_7);

        X_ponto = new QSpinBox(layoutWidget3);
        X_ponto->setObjectName(QString::fromUtf8("X_ponto"));

        horizontalLayout_10->addWidget(X_ponto);


        horizontalLayout_12->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        Y_ponto = new QSpinBox(layoutWidget3);
        Y_ponto->setObjectName(QString::fromUtf8("Y_ponto"));

        horizontalLayout_11->addWidget(Y_ponto);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_5->addLayout(horizontalLayout_12);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        marcar = new QPushButton(layoutWidget3);
        marcar->setObjectName(QString::fromUtf8("marcar"));

        horizontalLayout_14->addWidget(marcar);

        remover = new QPushButton(layoutWidget3);
        remover->setObjectName(QString::fromUtf8("remover"));

        horizontalLayout_14->addWidget(remover);

        zerar = new QPushButton(layoutWidget3);
        zerar->setObjectName(QString::fromUtf8("zerar"));

        horizontalLayout_14->addWidget(zerar);


        verticalLayout_4->addLayout(horizontalLayout_14);


        verticalLayout_5->addLayout(verticalLayout_4);

        frame = new mouseevents(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(70, 60, 640, 360));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background: Black\n"
"\n"
""));
        frame->setFrameShape(QFrame::Box);
        info = new QLabel(centralwidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(470, 70, 231, 20));
        info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(600, 420, 112, 23));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        XY_pos = new QLabel(layoutWidget4);
        XY_pos->setObjectName(QString::fromUtf8("XY_pos"));
        XY_pos->setFrameShape(QFrame::Box);
        XY_pos->setFrameShadow(QFrame::Raised);
        XY_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(XY_pos);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(70, 30, 639, 24));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(layoutWidget5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        option = new QLabel(layoutWidget5);
        option->setObjectName(QString::fromUtf8("option"));

        horizontalLayout_6->addWidget(option);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        horizontalSpacer_5 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(layoutWidget5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        label_6 = new QLabel(layoutWidget5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        time = new QLabel(centralwidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(80, 70, 221, 17));
        JanelaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JanelaPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 795, 22));
        JanelaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(JanelaPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        JanelaPrincipal->setStatusBar(statusbar);

        retranslateUi(JanelaPrincipal);

        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QCoreApplication::translate("JanelaPrincipal", "JanelaPrincipal", nullptr));
        groupBox->setTitle(QCoreApplication::translate("JanelaPrincipal", "Op\303\247\303\265es", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("JanelaPrincipal", "Modo de Opera\303\247\303\243o", nullptr));
        cortar->setText(QCoreApplication::translate("JanelaPrincipal", "Cortar", nullptr));
        calibrar->setText(QCoreApplication::translate("JanelaPrincipal", "Calibrar", nullptr));
        settings->setTitle(QCoreApplication::translate("JanelaPrincipal", "Defini\303\247\303\265es de Amostragem ", nullptr));
        guia->setText(QCoreApplication::translate("JanelaPrincipal", "Exibir Guia", nullptr));
        showPoint->setText(QCoreApplication::translate("JanelaPrincipal", "Mostrar Pontos", nullptr));
        showRect->setText(QCoreApplication::translate("JanelaPrincipal", "Exibir Ret\303\242ngulo", nullptr));
        label_3->setText(QCoreApplication::translate("JanelaPrincipal", "NumPoints", nullptr));
        label_5->setText(QCoreApplication::translate("JanelaPrincipal", "Ajuste", nullptr));
        applyAjuste->setText(QCoreApplication::translate("JanelaPrincipal", "Aplicar", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("JanelaPrincipal", "Ponto(Calibragem)", nullptr));
        customOrder->setText(QCoreApplication::translate("JanelaPrincipal", "Oredem Customizada", nullptr));
        label_4->setText(QCoreApplication::translate("JanelaPrincipal", "Ponto:", nullptr));
        Ponto->setText(QCoreApplication::translate("JanelaPrincipal", "O", nullptr));
        label_7->setText(QCoreApplication::translate("JanelaPrincipal", "X:", nullptr));
        label_8->setText(QCoreApplication::translate("JanelaPrincipal", "Y:", nullptr));
        marcar->setText(QCoreApplication::translate("JanelaPrincipal", "Marcar", nullptr));
        remover->setText(QCoreApplication::translate("JanelaPrincipal", "Desfazer", nullptr));
        zerar->setText(QCoreApplication::translate("JanelaPrincipal", "zerar", nullptr));
        frame->setText(QString());
        info->setText(QString());
        XY_pos->setText(QCoreApplication::translate("JanelaPrincipal", "X=0, Y=0", nullptr));
        label->setText(QCoreApplication::translate("JanelaPrincipal", "Opera\303\247\303\243o:", nullptr));
        option->setText(QCoreApplication::translate("JanelaPrincipal", "Cortar", nullptr));
        label_2->setText(QCoreApplication::translate("JanelaPrincipal", "Resolu\303\247\303\243o:", nullptr));
        label_6->setText(QCoreApplication::translate("JanelaPrincipal", "640x360", nullptr));
        time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
