/********************************************************************************
** Form generated from reading UI file 'Attribute.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTRIBUTE_H
#define UI_ATTRIBUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *groupBox;
    QLabel *nameLabel;
    QLineEdit *nameText;
    QLabel *modelLabel;
    QLineEdit *modelText;
    QLabel *produceLabel;
    QLineEdit *produceText;
    QLabel *dateLabel;
    QLineEdit *dateText;
    QLineEdit *proWaveText;
    QLabel *proWaveLabel;
    QLabel *unitLabel;
    QLineEdit *unitText;
    QLabel *minLabel;
    QLineEdit *minText;
    QLabel *maxLabel;
    QLineEdit *maxText;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(272, 387);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 261, 371));
        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(10, 40, 91, 16));
        nameText = new QLineEdit(groupBox);
        nameText->setObjectName(QString::fromUtf8("nameText"));
        nameText->setGeometry(QRect(130, 40, 113, 21));
        modelLabel = new QLabel(groupBox);
        modelLabel->setObjectName(QString::fromUtf8("modelLabel"));
        modelLabel->setGeometry(QRect(10, 90, 91, 16));
        modelText = new QLineEdit(groupBox);
        modelText->setObjectName(QString::fromUtf8("modelText"));
        modelText->setGeometry(QRect(130, 90, 113, 21));
        produceLabel = new QLabel(groupBox);
        produceLabel->setObjectName(QString::fromUtf8("produceLabel"));
        produceLabel->setGeometry(QRect(10, 140, 91, 16));
        produceText = new QLineEdit(groupBox);
        produceText->setObjectName(QString::fromUtf8("produceText"));
        produceText->setGeometry(QRect(130, 140, 113, 21));
        dateLabel = new QLabel(groupBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(10, 180, 101, 51));
        dateLabel->setAcceptDrops(false);
        dateLabel->setWordWrap(true);
        dateText = new QLineEdit(groupBox);
        dateText->setObjectName(QString::fromUtf8("dateText"));
        dateText->setGeometry(QRect(130, 180, 113, 21));
        dateText->setAcceptDrops(false);
        proWaveText = new QLineEdit(groupBox);
        proWaveText->setObjectName(QString::fromUtf8("proWaveText"));
        proWaveText->setGeometry(QRect(130, 240, 113, 21));
        proWaveLabel = new QLabel(groupBox);
        proWaveLabel->setObjectName(QString::fromUtf8("proWaveLabel"));
        proWaveLabel->setGeometry(QRect(10, 240, 91, 16));
        unitLabel = new QLabel(groupBox);
        unitLabel->setObjectName(QString::fromUtf8("unitLabel"));
        unitLabel->setGeometry(QRect(10, 240, 91, 16));
        unitText = new QLineEdit(groupBox);
        unitText->setObjectName(QString::fromUtf8("unitText"));
        unitText->setGeometry(QRect(130, 240, 113, 21));
        minLabel = new QLabel(groupBox);
        minLabel->setObjectName(QString::fromUtf8("minLabel"));
        minLabel->setGeometry(QRect(10, 280, 91, 16));
        minText = new QLineEdit(groupBox);
        minText->setObjectName(QString::fromUtf8("minText"));
        minText->setGeometry(QRect(130, 280, 113, 21));
        maxLabel = new QLabel(groupBox);
        maxLabel->setObjectName(QString::fromUtf8("maxLabel"));
        maxLabel->setGeometry(QRect(10, 240, 91, 16));
        maxText = new QLineEdit(groupBox);
        maxText->setObjectName(QString::fromUtf8("maxText"));
        maxText->setGeometry(QRect(130, 240, 113, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 330, 93, 28));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Form", "\344\274\240\346\204\237\345\231\250\344\277\256\346\224\271", nullptr));
        nameLabel->setText(QApplication::translate("Form", "name(\347\274\226\345\217\267)", nullptr));
        modelLabel->setText(QApplication::translate("Form", "\350\247\204\346\240\274", nullptr));
        produceLabel->setText(QApplication::translate("Form", "\347\224\237\344\272\247\345\216\202\345\225\206", nullptr));
        dateLabel->setText(QApplication::translate("Form", "\345\207\272\345\216\202\346\227\245\346\234\237(yyyy/mm/dd)", nullptr));
        proWaveLabel->setText(QApplication::translate("Form", "\345\207\272\345\216\202\344\270\255\345\277\203\346\263\242\351\225\277", nullptr));
        unitLabel->setText(QApplication::translate("Form", "\345\215\225\344\275\215", nullptr));
        minLabel->setText(QApplication::translate("Form", "\351\207\217\347\250\213\344\270\213\351\231\220", nullptr));
        maxLabel->setText(QApplication::translate("Form", "\351\207\217\347\250\213\344\270\212\351\231\220", nullptr));
        pushButton->setText(QApplication::translate("Form", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTRIBUTE_H
