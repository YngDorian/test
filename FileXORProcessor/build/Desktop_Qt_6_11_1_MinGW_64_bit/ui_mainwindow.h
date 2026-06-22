/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *settingsGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *fileMaskLabel;
    QLineEdit *fileMaskLineEdit;
    QLabel *InputDirLabel;
    QLineEdit *inputDirLineEdit;
    QPushButton *inputDirBrowseButton;
    QLabel *outputDirLabel;
    QLineEdit *outputDirLineEdit;
    QPushButton *outputDirBrowseButton;
    QLabel *keyLabel;
    QLineEdit *keyLineEdit;
    QCheckBox *deleteSourceCheckBox;
    QLabel *conflictLabel;
    QComboBox *conflictComboBox;
    QPushButton *pauseButton;
    QPushButton *startButton;
    QPushButton *stopButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(280, 430);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        settingsGroupBox = new QGroupBox(centralwidget);
        settingsGroupBox->setObjectName("settingsGroupBox");
        settingsGroupBox->setGeometry(QRect(10, 0, 258, 391));
        verticalLayout = new QVBoxLayout(settingsGroupBox);
        verticalLayout->setObjectName("verticalLayout");
        fileMaskLabel = new QLabel(settingsGroupBox);
        fileMaskLabel->setObjectName("fileMaskLabel");

        verticalLayout->addWidget(fileMaskLabel);

        fileMaskLineEdit = new QLineEdit(settingsGroupBox);
        fileMaskLineEdit->setObjectName("fileMaskLineEdit");

        verticalLayout->addWidget(fileMaskLineEdit);

        InputDirLabel = new QLabel(settingsGroupBox);
        InputDirLabel->setObjectName("InputDirLabel");

        verticalLayout->addWidget(InputDirLabel);

        inputDirLineEdit = new QLineEdit(settingsGroupBox);
        inputDirLineEdit->setObjectName("inputDirLineEdit");

        verticalLayout->addWidget(inputDirLineEdit);

        inputDirBrowseButton = new QPushButton(settingsGroupBox);
        inputDirBrowseButton->setObjectName("inputDirBrowseButton");

        verticalLayout->addWidget(inputDirBrowseButton);

        outputDirLabel = new QLabel(settingsGroupBox);
        outputDirLabel->setObjectName("outputDirLabel");

        verticalLayout->addWidget(outputDirLabel);

        outputDirLineEdit = new QLineEdit(settingsGroupBox);
        outputDirLineEdit->setObjectName("outputDirLineEdit");

        verticalLayout->addWidget(outputDirLineEdit);

        outputDirBrowseButton = new QPushButton(settingsGroupBox);
        outputDirBrowseButton->setObjectName("outputDirBrowseButton");

        verticalLayout->addWidget(outputDirBrowseButton);

        keyLabel = new QLabel(settingsGroupBox);
        keyLabel->setObjectName("keyLabel");

        verticalLayout->addWidget(keyLabel);

        keyLineEdit = new QLineEdit(settingsGroupBox);
        keyLineEdit->setObjectName("keyLineEdit");
        keyLineEdit->setMaxLength(16);
        keyLineEdit->setFrame(true);
        keyLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);

        verticalLayout->addWidget(keyLineEdit);

        deleteSourceCheckBox = new QCheckBox(settingsGroupBox);
        deleteSourceCheckBox->setObjectName("deleteSourceCheckBox");

        verticalLayout->addWidget(deleteSourceCheckBox);

        conflictLabel = new QLabel(settingsGroupBox);
        conflictLabel->setObjectName("conflictLabel");

        verticalLayout->addWidget(conflictLabel);

        conflictComboBox = new QComboBox(settingsGroupBox);
        conflictComboBox->setObjectName("conflictComboBox");

        verticalLayout->addWidget(conflictComboBox);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(100, 400, 80, 22));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(10, 400, 80, 22));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(188, 400, 80, 22));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        conflictComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        settingsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270", nullptr));
        fileMaskLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\320\272\320\260 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        fileMaskLineEdit->setText(QCoreApplication::translate("MainWindow", "*.bin", nullptr));
        InputDirLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\277\320\272\320\260 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        inputDirLineEdit->setText(QCoreApplication::translate("MainWindow", "C:\\input", nullptr));
        inputDirBrowseButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200..", nullptr));
        outputDirLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\277\320\272\320\260 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260", nullptr));
        outputDirLineEdit->setText(QCoreApplication::translate("MainWindow", "C:\\output", nullptr));
        outputDirBrowseButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200...", nullptr));
        keyLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207 (8 \320\261\320\260\320\271\321\202 \320\262 hex)", nullptr));
        keyLineEdit->setText(QCoreApplication::translate("MainWindow", "1234567890ABCDEF", nullptr));
        deleteSourceCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\321\217\321\202\321\214 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213 \320\277\320\276\321\201\320\273\320\265 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270", nullptr));
        conflictLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270 \321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\270 \320\270\320\274\320\265\320\275\320\270 \321\204\320\260\320\271\320\273\320\260", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "pauseButton", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "startButton", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "stopButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
