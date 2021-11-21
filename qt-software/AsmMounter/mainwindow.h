#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <QWidget>
#include <QGridLayout>
#include <QDebug>
#include <QThread>
#include <QTimer>

#include "highlighter.h"
#include "codeeditor.h"
#include "json.h"

#include <fstream>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionOpen_File_triggered();

    void on_TabsTextEditor_tabCloseRequested(int index);

    void on_TabsTextEditor_currentChanged(int index);

    void on_actionLoad_Config_File_triggered();

    void on_actionNew_File_triggered();

    void on_actionOpen_Folder_triggered();

    void on_selectTree_File(QString& fileSrc);

    void on_actionSave_As_triggered();

    void on_actionSave_triggered();

private:
    struct FileLoaded
    {
        QString fileSrc;
        QString fileContent;
        QFile* file;
    };

private:
    Ui::MainWindow* ui;

    FileLoaded* configFile;

    Highlighter* hightlighter;
    Highlighter* outputHighlighter;

    QList<QString> highlightedWords;
    QList<CodeEditor*> scriptsEditor;
    QList<FileLoaded*> scriptsLoaded;

    nlohmann::json configJson;
private:
    QString getFileNameFromSrc(QString src);

    void saveAsFile();
    void saveFile();

    void changeCurrentFileContent(int index, QString src);
    FileLoaded* openNewFile(QString fileDialogMessage, QString errorMessage);
    void newFile(QString title, QString textContent);

    void newHighlighter(QTextDocument* document);
};
#endif // MAINWINDOW_H
