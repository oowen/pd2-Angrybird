/********************************************************************************
** Form generated from reading UI file 'thanks.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THANKS_H
#define UI_THANKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_THANKS
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QWidget *THANKS)
    {
        if (THANKS->objectName().isEmpty())
            THANKS->setObjectName(QStringLiteral("THANKS"));
        THANKS->resize(277, 163);
        label = new QLabel(THANKS);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 201, 21));
        label_2 = new QLabel(THANKS);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 141, 21));
        label_3 = new QLabel(THANKS);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 80, 121, 21));
        label_4 = new QLabel(THANKS);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 110, 51, 16));
        pushButton = new QPushButton(THANKS);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 120, 75, 23));

        retranslateUi(THANKS);

        QMetaObject::connectSlotsByName(THANKS);
    } // setupUi

    void retranslateUi(QWidget *THANKS)
    {
        THANKS->setWindowTitle(QApplication::translate("THANKS", "Form", 0));
        label->setText(QApplication::translate("THANKS", "\350\254\235\350\254\235\345\212\251\346\225\231\345\200\221\351\200\231\345\215\212\345\271\264\344\276\206\350\276\233\350\213\246\347\232\204\345\220\204\347\250\256\345\212\252\345\212\233:)", 0));
        label_2->setText(QApplication::translate("THANKS", "\351\233\226\347\204\266\346\230\216\345\271\264\344\270\215\346\203\263\345\206\215\347\234\213\345\210\260\344\275\240\345\200\221", 0));
        label_3->setText(QApplication::translate("THANKS", "\351\202\204\346\230\257\346\204\237\346\277\200\346\277\200\346\277\200\346\277\200\346\277\200\350\220\254\345\210\206", 0));
        label_4->setText(QApplication::translate("THANKS", "\346\232\221\345\201\207\345\277\253\346\250\202", 0));
        pushButton->setText(QApplication::translate("THANKS", "\346\210\221\347\237\245\351\201\223\344\272\206", 0));
    } // retranslateUi

};

namespace Ui {
    class THANKS: public Ui_THANKS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THANKS_H
