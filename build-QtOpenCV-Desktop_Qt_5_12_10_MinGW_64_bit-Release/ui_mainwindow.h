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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <imagebaseinfo.h>
#include <statusbar.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionphotoInfo;
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *topHorizontalLayout;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QPushButton *inputPushButton;
    QPushButton *inputLineClear;
    QGroupBox *filterTypeGroupBox;
    QRadioButton *medianBlurRadioButton;
    QRadioButton *gaussianBlurRradioButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *bottomHorizontalLayout;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;
    QPushButton *outputPushButton;
    QPushButton *outputGenerate;
    QCheckBox *displayImageCheckBox;
    QMenuBar *menuBar;
    QMenu *menunew;
    QMenu *menuwindows;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    ImageBaseInfo *tableView;
    StatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 450);
        actionphotoInfo = new QAction(MainWindow);
        actionphotoInfo->setObjectName(QString::fromUtf8("actionphotoInfo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 10, 628, 392));
        widget->setBaseSize(QSize(0, 0));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 0, 600, 54));
        topHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        topHorizontalLayout->setSpacing(6);
        topHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        topHorizontalLayout->setObjectName(QString::fromUtf8("topHorizontalLayout"));
        topHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputLabel = new QLabel(horizontalLayoutWidget);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        topHorizontalLayout->addWidget(inputLabel);

        inputLineEdit = new QLineEdit(horizontalLayoutWidget);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        topHorizontalLayout->addWidget(inputLineEdit);

        inputPushButton = new QPushButton(horizontalLayoutWidget);
        inputPushButton->setObjectName(QString::fromUtf8("inputPushButton"));

        topHorizontalLayout->addWidget(inputPushButton);

        inputLineClear = new QPushButton(horizontalLayoutWidget);
        inputLineClear->setObjectName(QString::fromUtf8("inputLineClear"));

        topHorizontalLayout->addWidget(inputLineClear);

        filterTypeGroupBox = new QGroupBox(widget);
        filterTypeGroupBox->setObjectName(QString::fromUtf8("filterTypeGroupBox"));
        filterTypeGroupBox->setGeometry(QRect(20, 60, 600, 73));
        medianBlurRadioButton = new QRadioButton(filterTypeGroupBox);
        medianBlurRadioButton->setObjectName(QString::fromUtf8("medianBlurRadioButton"));
        medianBlurRadioButton->setGeometry(QRect(50, 40, 89, 16));
        gaussianBlurRradioButton = new QRadioButton(filterTypeGroupBox);
        gaussianBlurRradioButton->setObjectName(QString::fromUtf8("gaussianBlurRradioButton"));
        gaussianBlurRradioButton->setGeometry(QRect(280, 40, 111, 16));
        horizontalLayoutWidget_2 = new QWidget(widget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 140, 600, 112));
        bottomHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        bottomHorizontalLayout->setSpacing(6);
        bottomHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        bottomHorizontalLayout->setObjectName(QString::fromUtf8("bottomHorizontalLayout"));
        bottomHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        outputLabel = new QLabel(horizontalLayoutWidget_2);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        bottomHorizontalLayout->addWidget(outputLabel);

        outputLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        bottomHorizontalLayout->addWidget(outputLineEdit);

        outputPushButton = new QPushButton(horizontalLayoutWidget_2);
        outputPushButton->setObjectName(QString::fromUtf8("outputPushButton"));

        bottomHorizontalLayout->addWidget(outputPushButton);

        outputGenerate = new QPushButton(horizontalLayoutWidget_2);
        outputGenerate->setObjectName(QString::fromUtf8("outputGenerate"));

        bottomHorizontalLayout->addWidget(outputGenerate);

        displayImageCheckBox = new QCheckBox(widget);
        displayImageCheckBox->setObjectName(QString::fromUtf8("displayImageCheckBox"));
        displayImageCheckBox->setGeometry(QRect(20, 300, 600, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 23));
        menunew = new QMenu(menuBar);
        menunew->setObjectName(QString::fromUtf8("menunew"));
        menuwindows = new QMenu(menuBar);
        menuwindows->setObjectName(QString::fromUtf8("menuwindows"));
        MainWindow->setMenuBar(menuBar);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        tableView = new ImageBaseInfo(dockWidgetContents_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 161, 242));
        tableView->setAutoScroll(false);
        tableView->horizontalHeader()->setVisible(false);
        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_3);
        statusBar = new StatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menunew->menuAction());
        menuBar->addAction(menuwindows->menuAction());
        menuwindows->addAction(actionphotoInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionphotoInfo->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\241\346\201\257\347\252\227\345\217\243", nullptr));
        inputLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\233\276\347\211\207\344\275\215\347\275\256", nullptr));
        inputPushButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        inputLineClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        filterTypeGroupBox->setTitle(QApplication::translate("MainWindow", "Filter Type", nullptr));
        medianBlurRadioButton->setText(QApplication::translate("MainWindow", "Median Blur", nullptr));
        gaussianBlurRradioButton->setText(QApplication::translate("MainWindow", "Gaussion Blur", nullptr));
        outputLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\233\276\347\211\207\344\275\215\347\275\256", nullptr));
        outputPushButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        outputGenerate->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220", nullptr));
        displayImageCheckBox->setText(QApplication::translate("MainWindow", "Display image after saving", nullptr));
#ifndef QT_NO_TOOLTIP
        menunew->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        menunew->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuwindows->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243", nullptr));
        dockWidget_3->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
