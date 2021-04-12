/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <statusbar.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionphotoInfo;
    QWidget *centralWidget;
    QTabWidget *tabWidget_2;
    QWidget *onePhotoTab;
    QWidget *MainWidget;
    QGroupBox *mainDivisionGroupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *topHorizontalLayout;
    QLabel *PhotoLocationLabel;
    QLineEdit *PhotoLocationLineEdit;
    QPushButton *PhotoLocationButton;
    QPushButton *PhotoLocationClear;
    QGroupBox *modelGroupBox;
    QRadioButton *ModelRadioButton;
    QGroupBox *filterTypeGroupBox_2;
    QCheckBox *midValueCheckBox;
    QCheckBox *gaussCheckBox;
    QGroupBox *GenGroupBox;
    QPushButton *GenButton;
    QCheckBox *GenMaskCheckBox;
    QCheckBox *GenResultCheckBox;
    QCheckBox *displayImageCheckBox;
    QGroupBox *IoUCalGroupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *bottomHorizontalLayout;
    QLabel *TrueMaskLabel;
    QLineEdit *TrueMaskLineEdit;
    QPushButton *TrueMaskButton;
    QPushButton *TrueMaskClear;
    QWidget *IoUResultWidget;
    QLabel *IoUResultLabel;
    QLabel *IoUResult;
    QPushButton *IoUResultCalButton;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menunew;
    StatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(660, 510);
        actionphotoInfo = new QAction(MainWindow);
        actionphotoInfo->setObjectName(QString::fromUtf8("actionphotoInfo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 0, 641, 461));
        onePhotoTab = new QWidget();
        onePhotoTab->setObjectName(QString::fromUtf8("onePhotoTab"));
        MainWidget = new QWidget(onePhotoTab);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->setGeometry(QRect(20, 0, 628, 311));
        MainWidget->setBaseSize(QSize(0, 0));
        mainDivisionGroupBox = new QGroupBox(MainWidget);
        mainDivisionGroupBox->setObjectName(QString::fromUtf8("mainDivisionGroupBox"));
        mainDivisionGroupBox->setGeometry(QRect(0, 10, 601, 291));
        QFont font;
        font.setPointSize(12);
        mainDivisionGroupBox->setFont(font);
        horizontalLayoutWidget = new QWidget(mainDivisionGroupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 581, 81));
        topHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        topHorizontalLayout->setSpacing(6);
        topHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        topHorizontalLayout->setObjectName(QString::fromUtf8("topHorizontalLayout"));
        topHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        PhotoLocationLabel = new QLabel(horizontalLayoutWidget);
        PhotoLocationLabel->setObjectName(QString::fromUtf8("PhotoLocationLabel"));

        topHorizontalLayout->addWidget(PhotoLocationLabel);

        PhotoLocationLineEdit = new QLineEdit(horizontalLayoutWidget);
        PhotoLocationLineEdit->setObjectName(QString::fromUtf8("PhotoLocationLineEdit"));

        topHorizontalLayout->addWidget(PhotoLocationLineEdit);

        PhotoLocationButton = new QPushButton(horizontalLayoutWidget);
        PhotoLocationButton->setObjectName(QString::fromUtf8("PhotoLocationButton"));

        topHorizontalLayout->addWidget(PhotoLocationButton);

        PhotoLocationClear = new QPushButton(horizontalLayoutWidget);
        PhotoLocationClear->setObjectName(QString::fromUtf8("PhotoLocationClear"));

        topHorizontalLayout->addWidget(PhotoLocationClear);

        modelGroupBox = new QGroupBox(mainDivisionGroupBox);
        modelGroupBox->setObjectName(QString::fromUtf8("modelGroupBox"));
        modelGroupBox->setGeometry(QRect(20, 110, 271, 70));
        modelGroupBox->setFont(font);
        ModelRadioButton = new QRadioButton(modelGroupBox);
        ModelRadioButton->setObjectName(QString::fromUtf8("ModelRadioButton"));
        ModelRadioButton->setGeometry(QRect(80, 30, 89, 16));
        ModelRadioButton->setFont(font);
        filterTypeGroupBox_2 = new QGroupBox(mainDivisionGroupBox);
        filterTypeGroupBox_2->setObjectName(QString::fromUtf8("filterTypeGroupBox_2"));
        filterTypeGroupBox_2->setGeometry(QRect(310, 110, 271, 70));
        midValueCheckBox = new QCheckBox(filterTypeGroupBox_2);
        midValueCheckBox->setObjectName(QString::fromUtf8("midValueCheckBox"));
        midValueCheckBox->setGeometry(QRect(40, 30, 91, 16));
        gaussCheckBox = new QCheckBox(filterTypeGroupBox_2);
        gaussCheckBox->setObjectName(QString::fromUtf8("gaussCheckBox"));
        gaussCheckBox->setGeometry(QRect(150, 30, 91, 16));
        GenGroupBox = new QGroupBox(mainDivisionGroupBox);
        GenGroupBox->setObjectName(QString::fromUtf8("GenGroupBox"));
        GenGroupBox->setGeometry(QRect(20, 190, 571, 61));
        GenButton = new QPushButton(GenGroupBox);
        GenButton->setObjectName(QString::fromUtf8("GenButton"));
        GenButton->setGeometry(QRect(442, 13, 111, 41));
        GenMaskCheckBox = new QCheckBox(GenGroupBox);
        GenMaskCheckBox->setObjectName(QString::fromUtf8("GenMaskCheckBox"));
        GenMaskCheckBox->setGeometry(QRect(130, 30, 71, 16));
        GenResultCheckBox = new QCheckBox(GenGroupBox);
        GenResultCheckBox->setObjectName(QString::fromUtf8("GenResultCheckBox"));
        GenResultCheckBox->setGeometry(QRect(240, 30, 101, 16));
        displayImageCheckBox = new QCheckBox(mainDivisionGroupBox);
        displayImageCheckBox->setObjectName(QString::fromUtf8("displayImageCheckBox"));
        displayImageCheckBox->setGeometry(QRect(30, 260, 551, 16));
        IoUCalGroupBox = new QGroupBox(onePhotoTab);
        IoUCalGroupBox->setObjectName(QString::fromUtf8("IoUCalGroupBox"));
        IoUCalGroupBox->setGeometry(QRect(20, 320, 601, 111));
        IoUCalGroupBox->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(IoUCalGroupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 10, 581, 71));
        bottomHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        bottomHorizontalLayout->setSpacing(6);
        bottomHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        bottomHorizontalLayout->setObjectName(QString::fromUtf8("bottomHorizontalLayout"));
        bottomHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        TrueMaskLabel = new QLabel(horizontalLayoutWidget_2);
        TrueMaskLabel->setObjectName(QString::fromUtf8("TrueMaskLabel"));

        bottomHorizontalLayout->addWidget(TrueMaskLabel);

        TrueMaskLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        TrueMaskLineEdit->setObjectName(QString::fromUtf8("TrueMaskLineEdit"));

        bottomHorizontalLayout->addWidget(TrueMaskLineEdit);

        TrueMaskButton = new QPushButton(horizontalLayoutWidget_2);
        TrueMaskButton->setObjectName(QString::fromUtf8("TrueMaskButton"));

        bottomHorizontalLayout->addWidget(TrueMaskButton);

        TrueMaskClear = new QPushButton(horizontalLayoutWidget_2);
        TrueMaskClear->setObjectName(QString::fromUtf8("TrueMaskClear"));

        bottomHorizontalLayout->addWidget(TrueMaskClear);

        IoUResultWidget = new QWidget(IoUCalGroupBox);
        IoUResultWidget->setObjectName(QString::fromUtf8("IoUResultWidget"));
        IoUResultWidget->setGeometry(QRect(10, 70, 571, 31));
        IoUResultLabel = new QLabel(IoUResultWidget);
        IoUResultLabel->setObjectName(QString::fromUtf8("IoUResultLabel"));
        IoUResultLabel->setGeometry(QRect(210, 10, 31, 16));
        IoUResultLabel->setFont(font);
        IoUResult = new QLabel(IoUResultWidget);
        IoUResult->setObjectName(QString::fromUtf8("IoUResult"));
        IoUResult->setGeometry(QRect(259, 12, 54, 12));
        IoUResult->setFont(font);
        IoUResultCalButton = new QPushButton(IoUResultWidget);
        IoUResultCalButton->setObjectName(QString::fromUtf8("IoUResultCalButton"));
        IoUResultCalButton->setGeometry(QRect(330, 7, 75, 23));
        tabWidget_2->addTab(onePhotoTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_2->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 660, 23));
        menunew = new QMenu(menuBar);
        menunew->setObjectName(QString::fromUtf8("menunew"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new StatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menunew->menuAction());

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionphotoInfo->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\241\346\201\257\347\252\227\345\217\243", nullptr));
        mainDivisionGroupBox->setTitle(QApplication::translate("MainWindow", "\344\270\273\344\275\223\345\210\206\345\211\262", nullptr));
        PhotoLocationLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\233\276\347\211\207\344\275\215\347\275\256", nullptr));
        PhotoLocationButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        PhotoLocationClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        modelGroupBox->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\236\213", nullptr));
        ModelRadioButton->setText(QApplication::translate("MainWindow", "U^2-Net", nullptr));
        filterTypeGroupBox_2->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\216\273\345\231\252", nullptr));
        midValueCheckBox->setText(QApplication::translate("MainWindow", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        gaussCheckBox->setText(QApplication::translate("MainWindow", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        GenGroupBox->setTitle(QApplication::translate("MainWindow", "\347\224\237\346\210\220\351\200\211\351\241\271", nullptr));
        GenButton->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220", nullptr));
        GenMaskCheckBox->setText(QApplication::translate("MainWindow", "MASK", nullptr));
        GenResultCheckBox->setText(QApplication::translate("MainWindow", "\345\215\212\351\200\217\346\230\216\345\233\276\345\203\217", nullptr));
        displayImageCheckBox->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\276\347\211\207\345\220\216\345\261\225\347\244\272", nullptr));
        IoUCalGroupBox->setTitle(QApplication::translate("MainWindow", "Iou\350\256\241\347\256\227", nullptr));
        TrueMaskLabel->setText(QApplication::translate("MainWindow", "\351\242\204\346\234\237MASK\344\275\215\347\275\256", nullptr));
        TrueMaskButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        TrueMaskClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        IoUResultLabel->setText(QApplication::translate("MainWindow", "Iou:", nullptr));
        IoUResult->setText(QApplication::translate("MainWindow", "0.70", nullptr));
        IoUResultCalButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(onePhotoTab), QApplication::translate("MainWindow", "\345\215\225\345\274\240\345\233\276\347\211\207", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "\346\211\271\351\207\217\345\244\204\347\220\206", nullptr));
#ifndef QT_NO_TOOLTIP
        menunew->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        menunew->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
