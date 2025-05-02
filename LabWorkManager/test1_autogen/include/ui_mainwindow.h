/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *ImportButton;
    QFrame *frame_2;
    QPushButton *newColumn;
    QPushButton *Request1;
    QPushButton *Request3;
    QPushButton *Request2;
    QPushButton *Request4;
    QPushButton *Request5;
    QPushButton *Request2_2;
    QPushButton *Diagram1;
    QPushButton *Diagram2;
    QPushButton *graphic;
    QPushButton *Diagram3;
    QPushButton *DeleteRecord_2;
    QPushButton *EditRecord;
    QPushButton *ExportButton;
    QPushButton *DeleteRecord;
    QPushButton *addLabwork;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1022, 582);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 90, 781, 351));
        ImportButton = new QPushButton(centralwidget);
        ImportButton->setObjectName(QString::fromUtf8("ImportButton"));
        ImportButton->setGeometry(QRect(30, 50, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiBold SemiConden"));
        font.setBold(true);
        font.setWeight(75);
        ImportButton->setFont(font);
        ImportButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 1031, 561));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        newColumn = new QPushButton(frame_2);
        newColumn->setObjectName(QString::fromUtf8("newColumn"));
        newColumn->setGeometry(QRect(790, 400, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiBold SemiConden"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        newColumn->setFont(font1);
        newColumn->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Request1 = new QPushButton(frame_2);
        Request1->setObjectName(QString::fromUtf8("Request1"));
        Request1->setGeometry(QRect(790, 100, 221, 31));
        Request1->setFont(font1);
        Request1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Request3 = new QPushButton(frame_2);
        Request3->setObjectName(QString::fromUtf8("Request3"));
        Request3->setGeometry(QRect(790, 180, 221, 31));
        Request3->setFont(font1);
        Request3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Request2 = new QPushButton(frame_2);
        Request2->setObjectName(QString::fromUtf8("Request2"));
        Request2->setGeometry(QRect(790, 140, 221, 31));
        Request2->setFont(font1);
        Request2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Request4 = new QPushButton(frame_2);
        Request4->setObjectName(QString::fromUtf8("Request4"));
        Request4->setGeometry(QRect(790, 220, 221, 31));
        Request4->setFont(font1);
        Request4->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Request5 = new QPushButton(frame_2);
        Request5->setObjectName(QString::fromUtf8("Request5"));
        Request5->setGeometry(QRect(790, 260, 221, 31));
        Request5->setFont(font1);
        Request5->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Request2_2 = new QPushButton(frame_2);
        Request2_2->setObjectName(QString::fromUtf8("Request2_2"));
        Request2_2->setGeometry(QRect(790, 300, 221, 31));
        Request2_2->setFont(font1);
        Request2_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Diagram1 = new QPushButton(frame_2);
        Diagram1->setObjectName(QString::fromUtf8("Diagram1"));
        Diagram1->setGeometry(QRect(20, 460, 201, 31));
        Diagram1->setFont(font1);
        Diagram1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Diagram2 = new QPushButton(frame_2);
        Diagram2->setObjectName(QString::fromUtf8("Diagram2"));
        Diagram2->setGeometry(QRect(20, 500, 201, 31));
        Diagram2->setFont(font1);
        Diagram2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        graphic = new QPushButton(frame_2);
        graphic->setObjectName(QString::fromUtf8("graphic"));
        graphic->setGeometry(QRect(230, 460, 201, 31));
        graphic->setFont(font1);
        graphic->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        Diagram3 = new QPushButton(frame_2);
        Diagram3->setObjectName(QString::fromUtf8("Diagram3"));
        Diagram3->setGeometry(QRect(230, 500, 201, 31));
        Diagram3->setFont(font1);
        Diagram3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        DeleteRecord_2 = new QPushButton(frame_2);
        DeleteRecord_2->setObjectName(QString::fromUtf8("DeleteRecord_2"));
        DeleteRecord_2->setGeometry(QRect(620, 10, 161, 31));
        DeleteRecord_2->setFont(font1);
        DeleteRecord_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        EditRecord = new QPushButton(frame_2);
        EditRecord->setObjectName(QString::fromUtf8("EditRecord"));
        EditRecord->setGeometry(QRect(440, 10, 141, 31));
        EditRecord->setFont(font1);
        EditRecord->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        ExportButton = new QPushButton(frame_2);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setGeometry(QRect(30, 10, 111, 31));
        ExportButton->setFont(font);
        ExportButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        DeleteRecord = new QPushButton(frame_2);
        DeleteRecord->setObjectName(QString::fromUtf8("DeleteRecord"));
        DeleteRecord->setGeometry(QRect(620, 50, 161, 31));
        DeleteRecord->setFont(font1);
        DeleteRecord->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        addLabwork = new QPushButton(frame_2);
        addLabwork->setObjectName(QString::fromUtf8("addLabwork"));
        addLabwork->setGeometry(QRect(440, 50, 141, 33));
        addLabwork->setFont(font);
        addLabwork->setAutoFillBackground(false);
        addLabwork->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 6px;"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 90, 761, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        frame_2->raise();
        tableWidget->raise();
        ImportButton->raise();
        verticalLayoutWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1022, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ImportButton->setText(QApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
        newColumn->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206 \"\320\224\320\260\321\202\320\260 \320\262\321\213\320\264\320\260\321\207\320\270\"", nullptr));
        Request1->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\273\321\214\320\272\320\276 \321\200\320\260\320\261\320\276\321\202 \321\201\320\264\320\260\320\273 \321\201\321\202\321\203\320\264\320\265\320\275\321\202", nullptr));
        Request3->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213, \321\201\320\264\320\260\320\262\321\210\320\270\320\265 \320\261\320\276\320\273\321\214\321\210\320\265 \320\264\320\262\321\203\321\205 \321\200\320\260\320\261\320\276\321\202 \320\267\320\260 \320\264\320\265\320\275\321\214", nullptr));
        Request2->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\273\321\214\320\272\320\276 \321\200\320\260\320\261\320\276\321\202 \321\201\320\264\320\260\320\273\320\260 \320\263\321\200\321\203\320\277\320\277\320\260", nullptr));
        Request4->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213, \321\201\320\264\320\260\320\262\321\210\320\270\320\265 \320\275\320\260 4 \320\270 5", nullptr));
        Request5->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213, \320\275\320\265 \321\201\320\264\320\260\320\262\321\210\320\270\320\265 \321\200\320\260\320\261\320\276\321\202\321\213 \320\267\320\260 2 \320\274\320\265\321\201\321\217\321\206\320\260 ", nullptr));
        Request2_2->setText(QApplication::translate("MainWindow", "\320\241\320\260\320\274\320\260\321\217 \320\264\320\276\320\273\320\263\320\260\321\217 \321\201\320\264\320\260\321\207\320\260 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        Diagram1->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\321\214 \320\276\321\202 \320\262\321\201\320\265\321\205 \321\200\320\260\320\261\320\276\321\202, \321\201\320\264\320\260\320\275\320\275\320\260\321\217 \320\272\321\203\321\200\321\201\320\276\320\274", nullptr));
        Diagram2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\321\201\320\265\321\205 \321\201\320\264\320\260\320\275\320\275\321\213\321\205 \321\200\320\260\320\261\320\276\321\202", nullptr));
        graphic->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270 \320\261\320\276\320\273\321\214\321\210\320\265 \320\276\320\264\320\275\320\276\320\263\320\276 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        Diagram3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\270, \321\201 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\320\276\320\271 \320\276\321\206\320\265\320\275\320\272\320\276\320\271", nullptr));
        DeleteRecord_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\267\320\260\320\277\320\270\321\201\320\270 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        EditRecord->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\276\321\206\320\265\320\275\320\272\321\203", nullptr));
        ExportButton->setText(QApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
        DeleteRecord->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        addLabwork->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
