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
#include <QtWidgets/QCheckBox>
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
    QLineEdit *Control_LineEdit;
    QLabel *Control;
    QRadioButton *Input_Ascii_Button;
    QRadioButton *Input_Unicode_Button;
    QRadioButton *Input_Hex_Button;
    QPlainTextEdit *OutPut_TextEdit;
    QRadioButton *Output_Ascii_Button;
    QRadioButton *Output_Hex_Button;
    QRadioButton *Output_Unicode_Button;
    QLineEdit *Input_lineEdit;
    QLabel *label_2;
    QPushButton *Send_Button;
    QLabel *label_3;
    QLineEdit *Input_Size_LineEdit;
    QLabel *label_4;
    QLineEdit *Output_Size_LineEdit;
    QCheckBox *MiniFilter_checkBox;
    QLabel *Control_2;
    QLineEdit *Device_Name_LineEdit;
    QCheckBox *Hex_checkBox;

    void setupUi(QMainWindow *QT_Driver_LoaderClass)
    {
        if (QT_Driver_LoaderClass->objectName().isEmpty())
            QT_Driver_LoaderClass->setObjectName(QStringLiteral("QT_Driver_LoaderClass"));
        QT_Driver_LoaderClass->resize(483, 377);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Qt_Driver_Loader/mywife.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QT_Driver_LoaderClass->setWindowIcon(icon);
        centralWidget = new QWidget(QT_Driver_LoaderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Register_Driver_Button = new QPushButton(centralWidget);
        Register_Driver_Button->setObjectName(QStringLiteral("Register_Driver_Button"));
        Register_Driver_Button->setGeometry(QRect(10, 66, 110, 31));
        Start_Driver_Button = new QPushButton(centralWidget);
        Start_Driver_Button->setObjectName(QStringLiteral("Start_Driver_Button"));
        Start_Driver_Button->setGeometry(QRect(130, 66, 109, 31));
        UnRegister_Driver_Button = new QPushButton(centralWidget);
        UnRegister_Driver_Button->setObjectName(QStringLiteral("UnRegister_Driver_Button"));
        UnRegister_Driver_Button->setGeometry(QRect(10, 106, 110, 31));
        Stop_Driver_Button = new QPushButton(centralWidget);
        Stop_Driver_Button->setObjectName(QStringLiteral("Stop_Driver_Button"));
        Stop_Driver_Button->setGeometry(QRect(130, 106, 110, 31));
        Driver_Path_lineEdit = new QLineEdit(centralWidget);
        Driver_Path_lineEdit->setObjectName(QStringLiteral("Driver_Path_lineEdit"));
        Driver_Path_lineEdit->setGeometry(QRect(10, 15, 171, 21));
        Open_File_Button = new QPushButton(centralWidget);
        Open_File_Button->setObjectName(QStringLiteral("Open_File_Button"));
        Open_File_Button->setGeometry(QRect(190, 13, 50, 23));
        Error_Lable = new QLabel(centralWidget);
        Error_Lable->setObjectName(QStringLiteral("Error_Lable"));
        Error_Lable->setGeometry(QRect(10, 342, 461, 21));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        Error_Lable->setFont(font);
        Error_Lable->setScaledContents(false);
        Control_LineEdit = new QLineEdit(centralWidget);
        Control_LineEdit->setObjectName(QStringLiteral("Control_LineEdit"));
        Control_LineEdit->setGeometry(QRect(100, 146, 90, 20));
        Control = new QLabel(centralWidget);
        Control->setObjectName(QStringLiteral("Control"));
        Control->setGeometry(QRect(10, 148, 81, 16));
        Input_Ascii_Button = new QRadioButton(centralWidget);
        Input_Ascii_Button->setObjectName(QStringLiteral("Input_Ascii_Button"));
        Input_Ascii_Button->setGeometry(QRect(10, 201, 51, 16));
        Input_Ascii_Button->setChecked(true);
        Input_Unicode_Button = new QRadioButton(centralWidget);
        Input_Unicode_Button->setObjectName(QStringLiteral("Input_Unicode_Button"));
        Input_Unicode_Button->setGeometry(QRect(86, 201, 71, 16));
        Input_Hex_Button = new QRadioButton(centralWidget);
        Input_Hex_Button->setObjectName(QStringLiteral("Input_Hex_Button"));
        Input_Hex_Button->setGeometry(QRect(180, 201, 51, 16));
        Input_Hex_Button->setCheckable(true);
        OutPut_TextEdit = new QPlainTextEdit(centralWidget);
        OutPut_TextEdit->setObjectName(QStringLiteral("OutPut_TextEdit"));
        OutPut_TextEdit->setGeometry(QRect(250, 10, 221, 291));
        Output_Ascii_Button = new QRadioButton(centralWidget);
        Output_Ascii_Button->setObjectName(QStringLiteral("Output_Ascii_Button"));
        Output_Ascii_Button->setGeometry(QRect(254, 312, 51, 16));
        Output_Hex_Button = new QRadioButton(centralWidget);
        Output_Hex_Button->setObjectName(QStringLiteral("Output_Hex_Button"));
        Output_Hex_Button->setGeometry(QRect(416, 312, 50, 16));
        Output_Unicode_Button = new QRadioButton(centralWidget);
        Output_Unicode_Button->setObjectName(QStringLiteral("Output_Unicode_Button"));
        Output_Unicode_Button->setGeometry(QRect(330, 312, 71, 16));
        Input_lineEdit = new QLineEdit(centralWidget);
        Input_lineEdit->setObjectName(QStringLiteral("Input_lineEdit"));
        Input_lineEdit->setGeometry(QRect(50, 172, 191, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 176, 54, 12));
        Send_Button = new QPushButton(centralWidget);
        Send_Button->setObjectName(QStringLiteral("Send_Button"));
        Send_Button->setGeometry(QRect(9, 307, 231, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 226, 111, 16));
        Input_Size_LineEdit = new QLineEdit(centralWidget);
        Input_Size_LineEdit->setObjectName(QStringLiteral("Input_Size_LineEdit"));
        Input_Size_LineEdit->setGeometry(QRect(130, 225, 111, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 251, 111, 16));
        Output_Size_LineEdit = new QLineEdit(centralWidget);
        Output_Size_LineEdit->setObjectName(QStringLiteral("Output_Size_LineEdit"));
        Output_Size_LineEdit->setGeometry(QRect(130, 250, 111, 20));
        MiniFilter_checkBox = new QCheckBox(centralWidget);
        MiniFilter_checkBox->setObjectName(QStringLiteral("MiniFilter_checkBox"));
        MiniFilter_checkBox->setGeometry(QRect(14, 43, 91, 16));
        Control_2 = new QLabel(centralWidget);
        Control_2->setObjectName(QStringLiteral("Control_2"));
        Control_2->setGeometry(QRect(10, 279, 71, 16));
        Device_Name_LineEdit = new QLineEdit(centralWidget);
        Device_Name_LineEdit->setObjectName(QStringLiteral("Device_Name_LineEdit"));
        Device_Name_LineEdit->setGeometry(QRect(80, 277, 161, 20));
        Hex_checkBox = new QCheckBox(centralWidget);
        Hex_checkBox->setObjectName(QStringLiteral("Hex_checkBox"));
        Hex_checkBox->setGeometry(QRect(200, 149, 51, 16));
        QT_Driver_LoaderClass->setCentralWidget(centralWidget);

        retranslateUi(QT_Driver_LoaderClass);

        QMetaObject::connectSlotsByName(QT_Driver_LoaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_Driver_LoaderClass)
    {
        QT_Driver_LoaderClass->setWindowTitle(QApplication::translate("QT_Driver_LoaderClass", "Driver Loader Pro", Q_NULLPTR));
        Register_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Register Driver", Q_NULLPTR));
        Start_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Start Driver", Q_NULLPTR));
        UnRegister_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "UnRegister Driver", Q_NULLPTR));
        Stop_Driver_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Stop Driver", Q_NULLPTR));
        Open_File_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "File", Q_NULLPTR));
        Error_Lable->setText(QString());
        Control->setText(QApplication::translate("QT_Driver_LoaderClass", "Control Code", Q_NULLPTR));
        Input_Ascii_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Ascii", Q_NULLPTR));
        Input_Unicode_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Unicode", Q_NULLPTR));
        Input_Hex_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Hex", Q_NULLPTR));
        Output_Ascii_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Ascii", Q_NULLPTR));
        Output_Hex_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Hex", Q_NULLPTR));
        Output_Unicode_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Unicode", Q_NULLPTR));
        label_2->setText(QApplication::translate("QT_Driver_LoaderClass", "Input", Q_NULLPTR));
        Send_Button->setText(QApplication::translate("QT_Driver_LoaderClass", "Send Driver Control", Q_NULLPTR));
        label_3->setText(QApplication::translate("QT_Driver_LoaderClass", "Input Buffer Size", Q_NULLPTR));
        label_4->setText(QApplication::translate("QT_Driver_LoaderClass", "Output Buffer Size", Q_NULLPTR));
        MiniFilter_checkBox->setText(QApplication::translate("QT_Driver_LoaderClass", "Minifilter", Q_NULLPTR));
        Control_2->setText(QApplication::translate("QT_Driver_LoaderClass", "Device Name", Q_NULLPTR));
        Hex_checkBox->setText(QApplication::translate("QT_Driver_LoaderClass", "Hex", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Driver_LoaderClass: public Ui_QT_Driver_LoaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_DRIVER_LOADER_H
