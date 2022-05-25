/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(639, 268);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 30, 89, 25));
        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 150, 89, 25));
        pushButton_3 = new QPushButton(MainWindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 90, 89, 25));
        pushButton_4 = new QPushButton(MainWindow);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 20, 311, 221));
        QFont font;
        font.setPointSize(25);
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(MainWindow);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(500, 150, 89, 25));
        pushButton_6 = new QPushButton(MainWindow);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(500, 220, 89, 25));
        pushButton_8 = new QPushButton(MainWindow);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(500, 90, 89, 25));
        pushButton_8->setAutoRepeat(true);
        pushButton_7 = new QPushButton(MainWindow);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(500, 30, 89, 25));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\351\200\243\347\267\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\226\213\345\247\213\351\201\212\346\210\262", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\351\226\213\345\225\237\347\233\270\346\251\237", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\213\215\347\205\247", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\347\265\220\346\235\237\351\201\212\346\210\262", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\351\233\242\351\226\213", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "\351\227\234\351\226\211\347\233\270\346\251\237", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "\346\226\267\351\226\213\351\200\243\347\265\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
