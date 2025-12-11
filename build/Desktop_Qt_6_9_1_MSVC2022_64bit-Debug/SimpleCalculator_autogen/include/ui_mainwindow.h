/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Title;
    QHBoxLayout *horizontalLayout_Output;
    QLabel *label_Output;
    QLineEdit *lineEdit_Output;
    QGridLayout *gridLayout;
    QPushButton *button_Add;
    QPushButton *button_decimal;
    QPushButton *button_empty;
    QPushButton *button_CE;
    QPushButton *button_4;
    QPushButton *button_5;
    QPushButton *button_1;
    QPushButton *button_Backspace;
    QPushButton *button_7;
    QPushButton *button_3;
    QPushButton *button_6;
    QPushButton *button_0;
    QPushButton *button_9;
    QPushButton *button_2;
    QPushButton *button_Multiply;
    QPushButton *button_PosNeg;
    QPushButton *button_8;
    QPushButton *button_Divide;
    QPushButton *button_Minus;
    QPushButton *button_C;
    QPushButton *button_Equals;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(484, 412);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 0, 458, 371));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Title = new QLabel(verticalLayoutWidget);
        label_Title->setObjectName("label_Title");
        label_Title->setMaximumSize(QSize(16777215, 30));
        label_Title->setScaledContents(false);
        label_Title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_Title);

        horizontalLayout_Output = new QHBoxLayout();
        horizontalLayout_Output->setSpacing(1);
        horizontalLayout_Output->setObjectName("horizontalLayout_Output");
        horizontalLayout_Output->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        label_Output = new QLabel(verticalLayoutWidget);
        label_Output->setObjectName("label_Output");
        label_Output->setMaximumSize(QSize(16777215, 10));

        horizontalLayout_Output->addWidget(label_Output);

        lineEdit_Output = new QLineEdit(verticalLayoutWidget);
        lineEdit_Output->setObjectName("lineEdit_Output");

        horizontalLayout_Output->addWidget(lineEdit_Output);


        verticalLayout_3->addLayout(horizontalLayout_Output);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        gridLayout->setVerticalSpacing(30);
        button_Add = new QPushButton(verticalLayoutWidget);
        button_Add->setObjectName("button_Add");

        gridLayout->addWidget(button_Add, 3, 3, 1, 1);

        button_decimal = new QPushButton(verticalLayoutWidget);
        button_decimal->setObjectName("button_decimal");

        gridLayout->addWidget(button_decimal, 4, 2, 1, 1);

        button_empty = new QPushButton(verticalLayoutWidget);
        button_empty->setObjectName("button_empty");

        gridLayout->addWidget(button_empty, 0, 0, 1, 1);

        button_CE = new QPushButton(verticalLayoutWidget);
        button_CE->setObjectName("button_CE");

        gridLayout->addWidget(button_CE, 0, 1, 1, 1);

        button_4 = new QPushButton(verticalLayoutWidget);
        button_4->setObjectName("button_4");

        gridLayout->addWidget(button_4, 2, 0, 1, 1);

        button_5 = new QPushButton(verticalLayoutWidget);
        button_5->setObjectName("button_5");

        gridLayout->addWidget(button_5, 2, 1, 1, 1);

        button_1 = new QPushButton(verticalLayoutWidget);
        button_1->setObjectName("button_1");

        gridLayout->addWidget(button_1, 3, 0, 1, 1);

        button_Backspace = new QPushButton(verticalLayoutWidget);
        button_Backspace->setObjectName("button_Backspace");

        gridLayout->addWidget(button_Backspace, 0, 3, 1, 1);

        button_7 = new QPushButton(verticalLayoutWidget);
        button_7->setObjectName("button_7");

        gridLayout->addWidget(button_7, 1, 0, 1, 1);

        button_3 = new QPushButton(verticalLayoutWidget);
        button_3->setObjectName("button_3");

        gridLayout->addWidget(button_3, 3, 2, 1, 1);

        button_6 = new QPushButton(verticalLayoutWidget);
        button_6->setObjectName("button_6");

        gridLayout->addWidget(button_6, 2, 2, 1, 1);

        button_0 = new QPushButton(verticalLayoutWidget);
        button_0->setObjectName("button_0");

        gridLayout->addWidget(button_0, 4, 1, 1, 1);

        button_9 = new QPushButton(verticalLayoutWidget);
        button_9->setObjectName("button_9");

        gridLayout->addWidget(button_9, 1, 2, 1, 1);

        button_2 = new QPushButton(verticalLayoutWidget);
        button_2->setObjectName("button_2");

        gridLayout->addWidget(button_2, 3, 1, 1, 1);

        button_Multiply = new QPushButton(verticalLayoutWidget);
        button_Multiply->setObjectName("button_Multiply");

        gridLayout->addWidget(button_Multiply, 2, 3, 1, 1);

        button_PosNeg = new QPushButton(verticalLayoutWidget);
        button_PosNeg->setObjectName("button_PosNeg");

        gridLayout->addWidget(button_PosNeg, 4, 0, 1, 1);

        button_8 = new QPushButton(verticalLayoutWidget);
        button_8->setObjectName("button_8");

        gridLayout->addWidget(button_8, 1, 1, 1, 1);

        button_Divide = new QPushButton(verticalLayoutWidget);
        button_Divide->setObjectName("button_Divide");

        gridLayout->addWidget(button_Divide, 1, 3, 1, 1);

        button_Minus = new QPushButton(verticalLayoutWidget);
        button_Minus->setObjectName("button_Minus");

        gridLayout->addWidget(button_Minus, 4, 3, 1, 1);

        button_C = new QPushButton(verticalLayoutWidget);
        button_C->setObjectName("button_C");

        gridLayout->addWidget(button_C, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        button_Equals = new QPushButton(verticalLayoutWidget);
        button_Equals->setObjectName("button_Equals");
        button_Equals->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(button_Equals);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 484, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", "Simple Calculator", nullptr));
        label_Output->setText(QCoreApplication::translate("MainWindow", "Output:", nullptr));
        button_Add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        button_decimal->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        button_empty->setText(QString());
        button_CE->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_Backspace->setText(QCoreApplication::translate("MainWindow", "Backspace", nullptr));
        button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button_Multiply->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        button_PosNeg->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_Divide->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        button_Minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        button_C->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        button_Equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
