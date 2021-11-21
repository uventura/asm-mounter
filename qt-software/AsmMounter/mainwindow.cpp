#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hightlighter = nullptr;

    // Set Base Widget Sizes
    QScreen *screen = QGuiApplication::primaryScreen();
    ui->mainProgramWidget->setMaximumSize(screen->size());

    ui->mainSplitter->setSizes(QList<int>()<<20<<200);

    // Setting Json
    configJson = "";

    // Blank File
    FileLoaded *files = new FileLoaded;
    scriptsLoaded.append(files);

    newFile("Untitled", "");
    newHighlighter(scriptsEditor[ui->TabsTextEditor->currentIndex()]->document());

    // Setting Working Directory
    connect(ui->FileTree, &TreeDir::doubleClickFileTreeItem, this, &MainWindow::on_selectTree_File);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFileNameFromSrc(QString src)
{
    auto splitedSrc = src.split("/");
    return splitedSrc[splitedSrc.size()-1];
}

void MainWindow::changeCurrentFileContent(int index, QString src)
{
    ui->TabsTextEditor->setTabText(index, getFileNameFromSrc(src));

    scriptsLoaded[index]->fileSrc = src;
    scriptsLoaded[index]->fileContent = scriptsEditor[index]->toPlainText();
}

void MainWindow::saveAsFile()
{
    int index = ui->TabsTextEditor->currentIndex();
    if(index != -1)
    {
        QString localfile = QFileDialog::getSaveFileName(this, "Save as");
        QFile file(localfile);

        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            //qDebug() << "Could not save as the file";
            ui->ConsoleOut->sendError("Could not 'save as' the file");
            return;
        }

        QTextStream out(&file);
        QString text = scriptsEditor[index]->toPlainText();

        out << text;

        changeCurrentFileContent(index, localfile);

        file.close();
    }
}

void MainWindow::saveFile()
{
    int index = ui->TabsTextEditor->currentIndex();
    QFile file(scriptsLoaded[index]->fileSrc);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        //Debug() << "Could not save the file";
        ui->ConsoleOut->sendError("Could not 'save' the file");
        return;
    }

    QTextStream out(&file);
    QString text = scriptsEditor[index]->toPlainText();

    ui->ConsoleOut->sendSuccess("File '"+scriptsLoaded[index]->fileSrc+"' saved!");

    out << text;
    file.close();
}

MainWindow::FileLoaded* MainWindow::openNewFile(QString fileDialogMessage, QString errorMessage)
{
    FileLoaded* fileLoaded = new FileLoaded();

    fileLoaded->fileSrc = QFileDialog::getOpenFileName(this, fileDialogMessage);

    QFile file(fileLoaded->fileSrc);

    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        //qDebug() << errorMessage << "\n";
        ui->ConsoleOut->sendError(errorMessage);
        delete(fileLoaded);

        return nullptr;
    }

    QTextStream currentTextFile(&file);
    fileLoaded->fileContent = currentTextFile.readAll();

    file.close();
    return fileLoaded;
}

void MainWindow::newFile(QString title, QString textContent)
{
    // New File
    CodeEditor *newScript = new CodeEditor();
    newScript->setPlainText(textContent);
    scriptsEditor.append(newScript);

    QGridLayout *layoutCode = new QGridLayout;
    layoutCode->addWidget(newScript);

    QWidget *newScriptWidget = new QWidget();
    newScriptWidget->setLayout(layoutCode);

    ui->TabsTextEditor->addTab(newScriptWidget, *(new QIcon), title);
    ui->TabsTextEditor->setCurrentIndex(ui->TabsTextEditor->count() - 1);
}

void MainWindow::newHighlighter(QTextDocument* document)
{
    delete(hightlighter);
    hightlighter = new Highlighter(document);

    if(!highlightedWords.isEmpty())
    {
        hightlighter->clearWords();

        for(auto word: highlightedWords)
        {
            hightlighter->addSpecialWord(word);
        }
    }
}

// EVENT FUNCTIONS
void MainWindow::on_actionOpen_File_triggered()
{
    ui->ConsoleOut->sendMessage("Opening File...");

    FileLoaded *scriptFile = openNewFile("Open .asm File", "Could Not Load .asm File");

    if(scriptFile != nullptr)
    {
        scriptsLoaded.append(scriptFile);

        auto splitSrc = scriptFile->fileSrc.split("/");
        QString tabTitle = splitSrc[splitSrc.size()-1];

        newFile(tabTitle, scriptFile->fileContent);
        newHighlighter(scriptsEditor[ui->TabsTextEditor->currentIndex()]->document());
    }
}

void MainWindow::on_TabsTextEditor_tabCloseRequested(int index)
{
    ui->ConsoleOut->sendInfo("Tab Closed");

    ui->TabsTextEditor->removeTab(index);

    if(scriptsLoaded.size() > index)
        scriptsLoaded.remove(index);
    if(scriptsEditor.size() > index)
        scriptsEditor.remove(index);

    if(ui->TabsTextEditor->currentIndex() != -1)
        newHighlighter(scriptsEditor[ui->TabsTextEditor->currentIndex()]->document());
    else
        delete(hightlighter),
        hightlighter = nullptr;
}

void MainWindow::on_TabsTextEditor_currentChanged(int index)
{
    if(index != -1 && scriptsEditor.size() > index)
        newHighlighter(scriptsEditor[index]->document());
}

void MainWindow::on_actionLoad_Config_File_triggered()
{
    ui->ConsoleOut->sendMessage("Opening Config File...");

    configFile = openNewFile("Open .config File", "Could Not Load .config File");
    bool gotError = false;

    if(configFile != nullptr)
    {
        std::ifstream configSrc;
        configSrc.open(configFile->fileSrc.toStdString());
        configSrc >> configJson;

        if(!configJson["set_instruction"].is_null())
        {
            // Get New Instructions
            for(auto instruction: configJson["set_instruction"])
            {
                if(instruction.is_string())
                {
                    QString temp_inst="";
                    //ui->ConsoleOut->sendMessage(QString::fromStdString(instruction));
                    temp_inst+=QString::fromStdString(instruction);
                    highlightedWords.append(temp_inst);
                }
                else
                {
                    ui->ConsoleOut->sendError("In 'set_instruction' you have an incorrect instruction");
                    gotError = true;
                    break;
                }
            }

            // Highlighter Add Special Words
            if(hightlighter != nullptr && !gotError)
            {
                hightlighter->clearWords();
                for(auto word: highlightedWords)
                {
                    hightlighter->addSpecialWord(word);
                }
            }

            // Reset Current File
            if(ui->TabsTextEditor->currentIndex() != -1 && !gotError)
            {
                QString currentText = scriptsEditor[ui->TabsTextEditor->currentIndex()]->toPlainText();
                scriptsEditor[ui->TabsTextEditor->currentIndex()]->setPlainText("");
                scriptsEditor[ui->TabsTextEditor->currentIndex()]->setPlainText(currentText);
            }
        }
        else
        {
            ui->ConsoleOut->sendError("Without Set Instructions Defined");
            gotError = true;
        }
    }

    if(gotError)
    {
        ui->ConsoleOut->sendError("Incorrect Config File");

        highlightedWords.clear();

        delete(configFile);
        configFile = nullptr;

        return;
    }

    ui->ConsoleOut->sendSuccess("Config File Defined!");
}

void MainWindow::on_actionNew_File_triggered()
{
    ui->ConsoleOut->sendInfo("New Blank File");

    // Blank File
    FileLoaded *files = new FileLoaded;
    files->fileSrc="";
    files->fileContent="";
    files->file=nullptr;

    scriptsLoaded.append(files);

    newFile("Untitled", "");
    if(hightlighter == nullptr)
        newHighlighter(scriptsEditor[ui->TabsTextEditor->currentIndex()]->document());
}

void MainWindow::on_actionOpen_Folder_triggered()
{
    ui->ConsoleOut->sendMessage("Opening Folder...");

    ui->FileTree->loadFolder();
    ui->FolderName->setText(ui->FileTree->getRootFolderName());
}

void MainWindow::on_selectTree_File(QString& fileSrc)
{
    QFile newFileTree(fileSrc);

    if(newFileTree.open(QIODevice::ReadOnly | QFile::Text))
    {
        ui->ConsoleOut->sendMessage("Opening "+fileSrc+" file...");

        FileLoaded* newFileLoaded = new FileLoaded();
        QTextStream newTextFile(&newFileTree);

        newFileLoaded->fileSrc = fileSrc;
        //newFileLoaded->file = newFileTree;
        newFileLoaded->fileContent = newTextFile.readAll();

        scriptsLoaded.append(newFileLoaded);
        auto splitSrc = newFileLoaded->fileSrc.split("/");
        QString tabTitle = splitSrc[splitSrc.size()-1];

        newFile(tabTitle, newFileLoaded->fileContent);
        newHighlighter(scriptsEditor[ui->TabsTextEditor->currentIndex()]->document());

        ui->ConsoleOut->sendSuccess("File Opened!");
    }
    else
    {
        ui->ConsoleOut->sendInfo("Double clicked "+fileSrc);
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    saveAsFile();
}


void MainWindow::on_actionSave_triggered()
{
    int index = ui->TabsTextEditor->currentIndex();
    if(scriptsLoaded[index]->fileSrc.isEmpty())
    {
        saveAsFile();
        return;
    }

    saveFile();
}

