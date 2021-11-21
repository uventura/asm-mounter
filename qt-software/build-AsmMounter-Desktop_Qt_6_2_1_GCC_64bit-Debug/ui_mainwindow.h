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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "consoleoutput.h"
#include "treedir.h"

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
    QAction *actionClear_Output;
    QAction *actionClear_Console;
    QAction *actionRun_Current_File;
    QAction *actionGenerate_Hex_File;
    QAction *actionExit;
    QAction *actionOpen_Folder;
    QWidget *mainProgramWidget;
    QGridLayout *gridLayout_4;
    QSplitter *mainSplitter;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *FolderName;
    TreeDir *FileTree;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTabWidget *TabsTextEditor;
    QTabWidget *StatusProgram;
    QWidget *OutputLayout;
    QGridLayout *gridLayout_2;
    ConsoleOutput *ConsoleOut;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuOptions;
    QMenu *menuExecution;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(612, 463);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:#262626;\n"
"color: #C9CEBD;\n"
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
        actionClear_Output = new QAction(MainWindow);
        actionClear_Output->setObjectName(QString::fromUtf8("actionClear_Output"));
        actionClear_Console = new QAction(MainWindow);
        actionClear_Console->setObjectName(QString::fromUtf8("actionClear_Console"));
        actionRun_Current_File = new QAction(MainWindow);
        actionRun_Current_File->setObjectName(QString::fromUtf8("actionRun_Current_File"));
        actionGenerate_Hex_File = new QAction(MainWindow);
        actionGenerate_Hex_File->setObjectName(QString::fromUtf8("actionGenerate_Hex_File"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName(QString::fromUtf8("actionOpen_Folder"));
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
        FolderName = new QLabel(verticalLayoutWidget_2);
        FolderName->setObjectName(QString::fromUtf8("FolderName"));
        FolderName->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"color:rgba(169, 169, 190, 192);"));

        verticalLayout_2->addWidget(FolderName);

        FileTree = new TreeDir(verticalLayoutWidget_2);
        FileTree->setObjectName(QString::fromUtf8("FileTree"));
        FileTree->setStyleSheet(QString::fromUtf8("background-color:#252627;"));

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
        OutputLayout = new QWidget();
        OutputLayout->setObjectName(QString::fromUtf8("OutputLayout"));
        gridLayout_2 = new QGridLayout(OutputLayout);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ConsoleOut = new ConsoleOutput(OutputLayout);
        ConsoleOut->setObjectName(QString::fromUtf8("ConsoleOut"));

        gridLayout_2->addWidget(ConsoleOut, 0, 0, 1, 1);

        StatusProgram->addTab(OutputLayout, QString());
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
        menuExecution = new QMenu(menubar);
        menuExecution->setObjectName(QString::fromUtf8("menuExecution"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuExecution->menuAction());
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen_File);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_Folder);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_Config_File);
        menuFile->addAction(actionNew_Processor_File);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuOptions->addAction(actionLoad_Config_File);
        menuOptions->addAction(actionLoad_Processor_FIle);
        menuOptions->addSeparator();
        menuOptions->addAction(actionClear_Output);
        menuOptions->addAction(actionClear_Console);
        menuExecution->addAction(actionRun_Current_File);
        menuExecution->addAction(actionGenerate_Hex_File);

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
        actionClear_Output->setText(QCoreApplication::translate("MainWindow", "Clear Output", nullptr));
        actionClear_Console->setText(QCoreApplication::translate("MainWindow", "Clear Console", nullptr));
        actionRun_Current_File->setText(QCoreApplication::translate("MainWindow", "Run Current File", nullptr));
        actionGenerate_Hex_File->setText(QCoreApplication::translate("MainWindow", "Save Hex File", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionOpen_Folder->setText(QCoreApplication::translate("MainWindow", "Open Folder", nullptr));
        FolderName->setText(QCoreApplication::translate("MainWindow", "  Current Folder", nullptr));
        StatusProgram->setTabText(StatusProgram->indexOf(OutputLayout), QCoreApplication::translate("MainWindow", "Output", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuExecution->setTitle(QCoreApplication::translate("MainWindow", "Build", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
