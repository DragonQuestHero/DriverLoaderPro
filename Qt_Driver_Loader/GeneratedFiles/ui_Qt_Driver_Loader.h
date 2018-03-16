/********************************************************************************
** Form generated from reading UI file 'Qt_Driver_Loader.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_DRIVER_LOADER_H
#define UI_QT_DRIVER_LOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_Driver_LoaderClass
{
public:
    QWidget *centralWidget;
    QPushButton *Register_Driver_Button;
    QPushButton *Start_Driver_Button;
    QPushButton *UnRegister_Driver_Button;
    QPushButton *Stop_Driver_Button;
    QLineEdit *Driver_Path_lineEdit;
    QPushButton *Open_File_Button;
    QLabel *Error_Lable;
    QLineEdit *lineEdit;
    QLabel *label;
    QRadioButton *Ascii_Button;
    QRadioButton *Unicode_Button;
    QRadioButton *Hex_Button;
    QPlainTextEdit *plainTextEdit;
    QRadioButton *Ascii_Button_2;
    QRadioButton *Hex_Button_2;
    QRadioButton *Unicode_Button_2;

    void setupUi(QMainWindow *QT_Driver_LoaderClass)
    {
        if (QT_Driver_LoaderClass->objectName().isEmpty())
            QT_Driver_LoaderClass->setObjectName(QStringLiteral("QT_Driver_LoaderClass"));
        QT_Driver_LoaderClass->resize(250, 442);
        centralWidget = new QWidget(QT_Driver_LoaderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Register_Driver_Button = new QPushButton(centralWidget);
        Register_Driver_Button->setObjectName(QStringLiteral("Register_Driver_Button"));
        Register_Driver_Button->setGeometry(QRect(10, 50, 110, 31));
        Start_Driver_Button = new QPushButton(centralWidget);
        Start_Driver_Button->setObjectName(QStringLiteral("Start_Driver_Button"));
        Start_Driver_Button->setGeometry(QRect(130, 50, 109, 31));
        UnRegister_Driver_Button = new QPushButton(centralWidget);
        UnRegister_Driver_Button->setObjectName(QStringLiteral("UnRegister_Driver_Button"));
        UnRegister_Driver_Button->setGeometry(QRect(10, 90, 110, 31));
        Stop_Driver_Button = new QPushButton(centralWidget);
        Stop_Driver_Button->setObjectName(QStringLiteral("Stop_Driver_Button"));
        Stop_Driver_Button->setGeometry(QRect(130, 90, 110, 31));
        Driver_Path_lineEdit = new QLineEdit(centralWidget);
        Driver_Path_lineEdit->setObjectName(QStringLiteral("Driver_Path_lineEdit"));
        Driver_Path_lineEdit->setGeometry(QRect(10, 15, 171, 21));
        Open_File_Button = new QPushButton(centralWidget);
        Open_File_Button->setObjectName(QStringLiteral("Open_File_Button"));
        Open_File_Button->setGeometry(QRect(190, 13, 50, 23));
        Error_Lable = new QLabel(centralWidget);
        Error_Lable->setObjectName(QStringLiteral("Error_Lable"));
        Error_Lable->setGeometry(QRect(10, 410, 221, 21));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        Error_Lable->setFont(font);
        Error_Lable->setScaledContents(false);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 130, 191, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 134, 54, 12));
        Ascii_Button = new QRadioButton(centralWidget);
        Ascii_Button->setObjectName(QStringLiteral("Ascii_Button"));
        Ascii_Button->setGeometry(QRect(10, 160, 51, 16));
        Unicode_Button = new QRadioButton(centralWidget);
        Unicode_Button->setObjectName(QStringLiteral("Unicode_Button"));
        Unicode_Button->setGeometry(QRect(86, 160, 71, 16));
        Hex_Button = new QRadioButton(centralWidget);
        Hex_Button->setObjectName(QStringLiteral("Hex_Button"));
        Hex_Button->setGeometry(QRect(180, 160, 51, 16));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 180, 221, 201));
        Ascii_Button_2 = new QRadioButton(centralWidget);
        Ascii_Button_2->setObjectName(QStringLiteral("Ascii_Button_2"));
        Ascii_Button_2->setGeometry(QRect(14, 390, 51, 16));
        Hex_Button_2 = new QRadioButton(centralWidget);
        Hex_Button_2->setObjectName(QStringLiteral("Hex_Button_2"));
        Hex_Button_2->setGeometry(QRect(184, 390, 51, 16));
        Unicode_Button_2 = new QRadioButton(centralWidget);
        Unicode_Button_2->setObjectName(QStringLiteral("Unicode_Button_2"));
        Unicode_Button_2->setGeometry(QRect(90, 390, 71, 16));
        QT_Driver_LoaderClass->setCentralWidget(centralWidget);

        retranslateUi(QT_Driver_LoaderClass);

        QMetaObject::connectSlotsByName(QT_Driver_LoaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_Driver_LoaderClass)
    {
        QT_Driver_LoaderClass->setWindowTitle(QApplication::translate("QT_Driver_LoaderClass", "QT_Driver_Loader", Q_NULLPTR));
        Register_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Register Driver", Q_NULLPTR));
        Start_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Start Driver", Q_NULLPTR));
        UnRegister_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "UnRegister Driver", Q_NULLPTR));
        Stop_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Stop Driver", Q_NULLPTR));
        Open_File_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "File", Q_NULLPTR));
        Error_Lable->setText(QString());
        label->setText(QApplication::translate("QT_Driver_LoaderClass", "Input", Q_NULLPTR));
        Ascii_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Ascii", Q_NULLPTR));
        Unicode_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Unicode", Q_NULLPTR));
        Hex_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Hex", Q_NULLPTR));
        Ascii_Button_2->setText(QApplication::translate("QT_Driver_LoaderClass", "Ascii", Q_NULLPTR));
        Hex_Button_2->setText(QApplication::translate("QT_Driver_LoaderClass", "Hex", Q_NULLPTR));
        Unicode_Button_2->setText(QApplication::translate("QT_Driver_LoaderClass", "Unicode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Driver_LoaderClass: public Ui_QT_Driver_LoaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_DRIVER_LOADER_H
