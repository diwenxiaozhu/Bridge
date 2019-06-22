/********************************************************************************
** Form generated from reading UI file 'Bridge.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIDGE_H
#define UI_BRIDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BridgeClass
{
public:
    QAction *AddYB;
    QAction *AddND;
    QAction *AddWY;
    QAction *actionQT;
    QAction *actionAuthor;
    QWidget *centralWidget;
    QGraphicsView *bridgeImage;
    QGroupBox *groupBox;
    QLabel *NDLabel;
    QLabel *NDNum;
    QLabel *YBNum;
    QLabel *YBLabel;
    QLabel *WYNum;
    QLabel *WYLabel;
    QGroupBox *groupBox_2;
    QLabel *Info;
    QGroupBox *groupBox_3;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BridgeClass)
    {
        if (BridgeClass->objectName().isEmpty())
            BridgeClass->setObjectName(QString::fromUtf8("BridgeClass"));
        BridgeClass->resize(1003, 615);
        AddYB = new QAction(BridgeClass);
        AddYB->setObjectName(QString::fromUtf8("AddYB"));
        AddND = new QAction(BridgeClass);
        AddND->setObjectName(QString::fromUtf8("AddND"));
        AddWY = new QAction(BridgeClass);
        AddWY->setObjectName(QString::fromUtf8("AddWY"));
        actionQT = new QAction(BridgeClass);
        actionQT->setObjectName(QString::fromUtf8("actionQT"));
        actionAuthor = new QAction(BridgeClass);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        centralWidget = new QWidget(BridgeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bridgeImage = new QGraphicsView(centralWidget);
        bridgeImage->setObjectName(QString::fromUtf8("bridgeImage"));
        bridgeImage->setGeometry(QRect(0, 0, 181, 81));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 320, 281, 231));
        NDLabel = new QLabel(groupBox);
        NDLabel->setObjectName(QString::fromUtf8("NDLabel"));
        NDLabel->setGeometry(QRect(20, 60, 111, 16));
        NDNum = new QLabel(groupBox);
        NDNum->setObjectName(QString::fromUtf8("NDNum"));
        NDNum->setGeometry(QRect(160, 60, 72, 15));
        YBNum = new QLabel(groupBox);
        YBNum->setObjectName(QString::fromUtf8("YBNum"));
        YBNum->setGeometry(QRect(160, 110, 72, 15));
        YBLabel = new QLabel(groupBox);
        YBLabel->setObjectName(QString::fromUtf8("YBLabel"));
        YBLabel->setGeometry(QRect(20, 110, 111, 16));
        WYNum = new QLabel(groupBox);
        WYNum->setObjectName(QString::fromUtf8("WYNum"));
        WYNum->setGeometry(QRect(160, 150, 72, 15));
        WYLabel = new QLabel(groupBox);
        WYLabel->setObjectName(QString::fromUtf8("WYLabel"));
        WYLabel->setGeometry(QRect(20, 150, 111, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 320, 281, 231));
        Info = new QLabel(groupBox_2);
        Info->setObjectName(QString::fromUtf8("Info"));
        Info->setGeometry(QRect(20, 40, 241, 171));
        Info->setWordWrap(true);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(580, 320, 401, 231));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 291, 141));
        label->setWordWrap(true);
        BridgeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BridgeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1003, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        BridgeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BridgeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BridgeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BridgeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BridgeClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(AddYB);
        menu->addAction(AddND);
        menu->addAction(AddWY);
        menu_2->addAction(actionQT);
        menu_2->addAction(actionAuthor);

        retranslateUi(BridgeClass);

        QMetaObject::connectSlotsByName(BridgeClass);
    } // setupUi

    void retranslateUi(QMainWindow *BridgeClass)
    {
        BridgeClass->setWindowTitle(QApplication::translate("BridgeClass", "Bridge", nullptr));
        AddYB->setText(QApplication::translate("BridgeClass", "\345\242\236\345\212\240\345\272\224\345\217\230\344\274\240\346\204\237\345\231\250", nullptr));
        AddND->setText(QApplication::translate("BridgeClass", "\345\242\236\345\212\240\346\214\240\345\272\246\344\274\240\346\204\237\345\231\250", nullptr));
        AddWY->setText(QApplication::translate("BridgeClass", "\345\242\236\345\212\240\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        actionQT->setText(QApplication::translate("BridgeClass", "\345\205\263\344\272\216QT", nullptr));
        actionAuthor->setText(QApplication::translate("BridgeClass", "\345\205\263\344\272\216\344\275\234\350\200\205", nullptr));
        groupBox->setTitle(QApplication::translate("BridgeClass", "\344\274\240\346\204\237\345\231\250\346\225\260\351\207\217", nullptr));
        NDLabel->setText(QApplication::translate("BridgeClass", "\346\214\240\345\272\246\344\274\240\346\204\237\345\231\250\346\225\260\351\207\217", nullptr));
        NDNum->setText(QApplication::translate("BridgeClass", "0", nullptr));
        YBNum->setText(QApplication::translate("BridgeClass", "0", nullptr));
        YBLabel->setText(QApplication::translate("BridgeClass", "\345\272\224\345\217\230\344\274\240\346\204\237\345\231\250\346\225\260\351\207\217", nullptr));
        WYNum->setText(QApplication::translate("BridgeClass", "0", nullptr));
        WYLabel->setText(QApplication::translate("BridgeClass", "\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250\346\225\260\351\207\217", nullptr));
        groupBox_2->setTitle(QApplication::translate("BridgeClass", "\344\274\240\346\204\237\345\231\250\345\256\236\346\227\266\344\277\241\346\201\257", nullptr));
        Info->setText(QString());
        groupBox_3->setTitle(QApplication::translate("BridgeClass", "\344\275\277\347\224\250\345\270\256\345\212\251", nullptr));
        label->setText(QApplication::translate("BridgeClass", "<html><head/><body><p>\346\267\273\345\212\240\344\274\240\346\204\237\345\231\250\357\274\232\351\200\232\350\277\207\345\267\246\344\270\212\350\247\222\346\214\211\351\222\256</p><p>\345\210\240\351\231\244\344\274\240\346\204\237\345\231\250\357\274\232\351\200\211\344\270\255\344\274\240\346\204\237\345\231\250 \346\214\211BACKSPACE\351\224\256</p><p>\351\200\211\344\270\255\344\274\240\346\204\237\345\231\250\357\274\232\351\274\240\346\240\207\345\267\246\351\224\256\345\215\225\345\207\273</p><p>\345\205\250\351\200\211\344\274\240\346\204\237\345\231\250\357\274\232\351\200\232\350\277\207CTRL+\351\274\240\346\240\207\345\267\246\351\224\256</p><p>\345\261\225\347\244\272\345\233\276\345\203\217\357\274\232  \351\274\240\346\240\207\345\217\263\351\224\256\344\274\240\346\204\237\345\231\250</p><p>\344\277\256\346\224\271\344\274\240\346\204\237\345\231\250\357\274\232\351\274\240\346\240\207\345\267\246\351\224\256\345\217\214\345\207\273</p></body></html>", nullptr));
        menu->setTitle(QApplication::translate("BridgeClass", "\345\242\236\345\212\240\344\274\240\346\204\237\345\231\250", nullptr));
        menu_2->setTitle(QApplication::translate("BridgeClass", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BridgeClass: public Ui_BridgeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIDGE_H
