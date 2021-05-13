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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *frame;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *R_min;
    QSpinBox *R_min_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *R_max;
    QSpinBox *R_max_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *G_min;
    QSpinBox *G_min_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *G_max;
    QSpinBox *G_max_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSlider *B_min;
    QSpinBox *B_min_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSlider *B_max;
    QSpinBox *B_max_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QComboBox *comboBox;
    QCheckBox *enable_limiares;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QComboBox *kmeans;
    QWidget *tab_2;
    QLabel *time;
    QLabel *time_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *opencv;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *SelectColor;
    QPushButton *salve;
    QPushButton *defalt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(697, 657);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../gpr.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QLabel(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 20, 640, 360));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 440, 631, 171));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 601, 66));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        R_min = new QSlider(layoutWidget);
        R_min->setObjectName(QString::fromUtf8("R_min"));
        R_min->setMaximum(255);
        R_min->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(R_min);

        R_min_2 = new QSpinBox(layoutWidget);
        R_min_2->setObjectName(QString::fromUtf8("R_min_2"));
        R_min_2->setMaximum(255);

        horizontalLayout_2->addWidget(R_min_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        R_max = new QSlider(layoutWidget);
        R_max->setObjectName(QString::fromUtf8("R_max"));
        R_max->setMaximum(255);
        R_max->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(R_max);

        R_max_2 = new QSpinBox(layoutWidget);
        R_max_2->setObjectName(QString::fromUtf8("R_max_2"));
        R_max_2->setMaximum(255);

        horizontalLayout_3->addWidget(R_max_2);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        G_min = new QSlider(layoutWidget);
        G_min->setObjectName(QString::fromUtf8("G_min"));
        G_min->setMaximum(255);
        G_min->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(G_min);

        G_min_2 = new QSpinBox(layoutWidget);
        G_min_2->setObjectName(QString::fromUtf8("G_min_2"));
        G_min_2->setMaximum(255);

        horizontalLayout_4->addWidget(G_min_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        G_max = new QSlider(layoutWidget);
        G_max->setObjectName(QString::fromUtf8("G_max"));
        G_max->setMaximum(255);
        G_max->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(G_max);

        G_max_2 = new QSpinBox(layoutWidget);
        G_max_2->setObjectName(QString::fromUtf8("G_max_2"));
        G_max_2->setMaximum(255);

        horizontalLayout_5->addWidget(G_max_2);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        B_min = new QSlider(layoutWidget);
        B_min->setObjectName(QString::fromUtf8("B_min"));
        B_min->setMaximum(255);
        B_min->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(B_min);

        B_min_2 = new QSpinBox(layoutWidget);
        B_min_2->setObjectName(QString::fromUtf8("B_min_2"));
        B_min_2->setMaximum(255);

        horizontalLayout_6->addWidget(B_min_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        B_max = new QSlider(layoutWidget);
        B_max->setObjectName(QString::fromUtf8("B_max"));
        B_max->setMaximum(255);
        B_max->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(B_max);

        B_max_2 = new QSpinBox(layoutWidget);
        B_max_2->setObjectName(QString::fromUtf8("B_max_2"));
        B_max_2->setMaximum(255);

        horizontalLayout_7->addWidget(B_max_2);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 601, 29));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_10->addWidget(comboBox);

        enable_limiares = new QCheckBox(layoutWidget1);
        enable_limiares->setObjectName(QString::fromUtf8("enable_limiares"));
        QFont font;
        font.setPointSize(10);
        enable_limiares->setFont(font);

        horizontalLayout_10->addWidget(enable_limiares);


        horizontalLayout_12->addLayout(horizontalLayout_10);

        horizontalSpacer = new QSpacerItem(48, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_11->addWidget(label_9);

        kmeans = new QComboBox(layoutWidget1);
        kmeans->addItem(QString());
        kmeans->addItem(QString());
        kmeans->addItem(QString());
        kmeans->addItem(QString());
        kmeans->addItem(QString());
        kmeans->addItem(QString());
        kmeans->setObjectName(QString::fromUtf8("kmeans"));
        kmeans->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_11->addWidget(kmeans);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        time = new QLabel(centralwidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(450, 30, 181, 20));
        time->setStyleSheet(QString::fromUtf8("color: rgb(243, 243, 243);"));
        time->setAlignment(Qt::AlignCenter);
        time_2 = new QLabel(centralwidget);
        time_2->setObjectName(QString::fromUtf8("time_2"));
        time_2->setGeometry(QRect(450, 60, 181, 20));
        time_2->setStyleSheet(QString::fromUtf8("color: rgb(243, 243, 243);"));
        time_2->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(220, 390, 447, 31));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        opencv = new QPushButton(layoutWidget2);
        opencv->setObjectName(QString::fromUtf8("opencv"));

        horizontalLayout_13->addWidget(opencv);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        SelectColor = new QComboBox(layoutWidget2);
        SelectColor->addItem(QString());
        SelectColor->addItem(QString());
        SelectColor->addItem(QString());
        SelectColor->addItem(QString());
        SelectColor->addItem(QString());
        SelectColor->setObjectName(QString::fromUtf8("SelectColor"));

        horizontalLayout->addWidget(SelectColor);


        horizontalLayout_9->addLayout(horizontalLayout);

        salve = new QPushButton(layoutWidget2);
        salve->setObjectName(QString::fromUtf8("salve"));

        horizontalLayout_9->addWidget(salve);

        defalt = new QPushButton(layoutWidget2);
        defalt->setObjectName(QString::fromUtf8("defalt"));

        horizontalLayout_9->addWidget(defalt);


        horizontalLayout_13->addLayout(horizontalLayout_9);

        MainWindow->setCentralWidget(centralwidget);
        tabWidget->raise();
        layoutWidget->raise();
        frame->raise();
        time->raise();
        time_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 697, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Teste: Programa\303\247\303\243o Paralela", nullptr));
        frame->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "R_min", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "R_max", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "G_min", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "G_max", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "B_min", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "B_max", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Exibir:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Limiares", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Original", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Amarelo_binario", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Vermelho_binario", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Azul_binario", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Laranja_binario", nullptr));

        enable_limiares->setText(QCoreApplication::translate("MainWindow", "Alterar exibi\303\247\303\243o", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Clustering", nullptr));
        kmeans->setItemText(0, QCoreApplication::translate("MainWindow", "Disabilitado", nullptr));
        kmeans->setItemText(1, QCoreApplication::translate("MainWindow", "All", nullptr));
        kmeans->setItemText(2, QCoreApplication::translate("MainWindow", "Azul", nullptr));
        kmeans->setItemText(3, QCoreApplication::translate("MainWindow", "Amarelo", nullptr));
        kmeans->setItemText(4, QCoreApplication::translate("MainWindow", "Vermelho", nullptr));
        kmeans->setItemText(5, QCoreApplication::translate("MainWindow", "Laranja", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "RGB", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "HSV", nullptr));
        time->setText(QString());
        time_2->setText(QString());
        opencv->setText(QCoreApplication::translate("MainWindow", "Abrir com openCV", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cor:", nullptr));
        SelectColor->setItemText(0, QCoreApplication::translate("MainWindow", "Azul", nullptr));
        SelectColor->setItemText(1, QCoreApplication::translate("MainWindow", "Laranja", nullptr));
        SelectColor->setItemText(2, QCoreApplication::translate("MainWindow", "Amarelo", nullptr));
        SelectColor->setItemText(3, QCoreApplication::translate("MainWindow", "Verde", nullptr));
        SelectColor->setItemText(4, QCoreApplication::translate("MainWindow", "Vermelho", nullptr));

        salve->setText(QCoreApplication::translate("MainWindow", "Salvar", nullptr));
        defalt->setText(QCoreApplication::translate("MainWindow", "Defalt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
