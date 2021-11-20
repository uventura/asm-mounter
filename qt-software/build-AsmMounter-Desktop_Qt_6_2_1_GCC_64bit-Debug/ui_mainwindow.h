/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_File;
    QAction *actionNew_Config_File;
    QAction *actionOpen_File;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionNew_Processor_File;
    QAction *actionLoad_Config_File;
    QAction *actionLoad_Processor_FIle;
    QWidget *mainProgramWidget;
    QGridLayout *gridLayout_4;
    QSplitter *mainSplitter;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTreeView *FileTree;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTabWidget *TabsTextEditor;
    QTabWidget *StatusProgram;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QListView *listView;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(612, 463);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:#2D232E;\n"
"color: #F1F0EA;\n"
"font-size:15px;"));
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QString::fromUtf8("actionNew_File"));
        actionNew_Config_File = new QAction(MainWindow);
        actionNew_Config_File->setObjectName(QString::fromUtf8("actionNew_Config_File"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionNew_Processor_File = new QAction(MainWindow);
        actionNew_Processor_File->setObjectName(QString::fromUtf8("actionNew_Processor_File"));
        actionLoad_Config_File = new QAction(MainWindow);
        actionLoad_Config_File->setObjectName(QString::fromUtf8("actionLoad_Config_File"));
        actionLoad_Processor_FIle = new QAction(MainWindow);
        actionLoad_Processor_FIle->setObjectName(QString::fromUtf8("actionLoad_Processor_FIle"));
        mainProgramWidget = new QWidget(MainWindow);
        mainProgramWidget->setObjectName(QString::fromUtf8("mainProgramWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainProgramWidget->sizePolicy().hasHeightForWidth());
        mainProgramWidget->setSizePolicy(sizePolicy);
        mainProgramWidget->setMaximumSize(QSize(816, 529));
        gridLayout_4 = new QGridLayout(mainProgramWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mainSplitter = new QSplitter(mainProgramWidget);
        mainSplitter->setObjectName(QString::fromUtf8("mainSplitter"));
        mainSplitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget_2 = new QWidget(mainSplitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        FileTree = new QTreeView(verticalLayoutWidget_2);
        FileTree->setObjectName(QString::fromUtf8("FileTree"));

        verticalLayout_2->addWidget(FileTree);

        mainSplitter->addWidget(verticalLayoutWidget_2);
        verticalLayoutWidget = new QWidget(mainSplitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(verticalLayoutWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        TabsTextEditor = new QTabWidget(splitter);
        TabsTextEditor->setObjectName(QString::fromUtf8("TabsTextEditor"));
        TabsTextEditor->setTabsClosable(true);
        TabsTextEditor->setMovable(true);
        TabsTextEditor->setTabBarAutoHide(false);
        splitter->addWidget(TabsTextEditor);
        StatusProgram = new QTabWidget(splitter);
        StatusProgram->setObjectName(QString::fromUtf8("StatusProgram"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listView = new QListView(tab_3);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setStyleSheet(QString::fromUtf8("background-color:#474448;"));

        gridLayout_2->addWidget(listView, 0, 0, 1, 1);

        StatusProgram->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(tab_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        StatusProgram->addTab(tab_4, QString());
        splitter->addWidget(StatusProgram);

        verticalLayout->addWidget(splitter);

        mainSplitter->addWidget(verticalLayoutWidget);

        gridLayout_4->addWidget(mainSplitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(mainProgramWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 612, 27));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen_File);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_Config_File);
        menuFile->addAction(actionNew_Processor_File);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuOptions->addAction(actionLoad_Config_File);
        menuOptions->addAction(actionLoad_Processor_FIle);

        retranslateUi(MainWindow);

        TabsTextEditor->setCurrentIndex(-1);
        StatusProgram->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_File->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        actionNew_Config_File->setText(QCoreApplication::translate("MainWindow", "New Config File", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionNew_Processor_File->setText(QCoreApplication::translate("MainWindow", "New Processor File", nullptr));
        actionLoad_Config_File->setText(QCoreApplication::translate("MainWindow", "Load Config Script", nullptr));
        actionLoad_Processor_FIle->setText(QCoreApplication::translate("MainWindow", "Load Processor Script", nullptr));
        StatusProgram->setTabText(StatusProgram->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Output", nullptr));
        StatusProgram->setTabText(StatusProgram->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Console", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
