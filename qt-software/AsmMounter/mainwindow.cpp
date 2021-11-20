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
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::FileLoaded* MainWindow::openNewFile(QString fileDialogMessage, QString errorMessage)
{
    FileLoaded* fileLoaded = new FileLoaded();
    fileLoaded->fileSrc = QFileDialog::getOpenFileName(this, fileDialogMessage);

    fileLoaded->file = new QFile(fileLoaded->fileSrc);

    if(!fileLoaded->file->open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << errorMessage << "\n";
        return nullptr;
    }

    QTextStream currentTextFile(fileLoaded->file);
    fileLoaded->fileContent = currentTextFile.readAll();

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
    configFile = openNewFile("Open .config File", "Could Not Load .config File");

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
                    highlightedWords.append(QString::fromStdString(instruction));
                else
                {
                    qDebug() << "Instructions Wrong\n";
                    break;
                }
            }

            // Highlighter Add Special Words
            if(hightlighter != nullptr)
            {
                hightlighter->clearWords();
                for(auto word: highlightedWords)
                {
                    hightlighter->addSpecialWord(word);
                }
            }

            // Reset Current File
            if(ui->TabsTextEditor->currentIndex() != -1)
            {
                QString currentText = scriptsEditor[ui->TabsTextEditor->currentIndex()]->toPlainText();
                scriptsEditor[ui->TabsTextEditor->currentIndex()]->setPlainText("");
                scriptsEditor[ui->TabsTextEditor->currentIndex()]->setPlainText(currentText);

                std::cout<<currentText.toStdString()<<"\n";
            }
        }
        else
        {
            qDebug() << "No Instructions Defined!\n";
        }

        //qDebug() << configFile->fileContent << "\n";
    }
}

void MainWindow::on_actionNew_File_triggered()
{
    // Blank File
    FileLoaded *files = new FileLoaded;
    scriptsLoaded.append(files);

    newFile("Untitled", "");
    if(hightlighter == nullptr)
        newHighlighter(scriptsEditor[ui->TabsTextEditor->currentIndex()]->document());
}

