#include "consoleoutput.h"

ConsoleOutput::ConsoleOutput(QWidget *parent) : QPlainTextEdit(parent)
{
    // Init Settings
    clear();

    consoleHighlighter = new Highlighter(this->document());

    consoleHighlighter->addSpecialWord("Out", Qt::gray);
    consoleHighlighter->addSpecialWord("Error", Qt::red);
    consoleHighlighter->addSpecialWord("Warning", Qt::yellow);
    consoleHighlighter->addSpecialWord("Success", Qt::green);
    consoleHighlighter->addSpecialWord("Info", Qt::darkMagenta);

    this->appendPlainText(" Current Output Console");

    // Console Style
    setStyleSheet("background-color: #252627;color:gray;");
    setTabStopDistance(30);
}

void ConsoleOutput::sendMessage(QString Message)
{
    this->appendPlainText("Out: "+Message);
}

void ConsoleOutput::sendWarning(QString Message)
{
    this->appendPlainText("Warning: "+Message);
}

void ConsoleOutput::sendError(QString Message)
{
    this->appendPlainText("Error: "+Message);
}

void ConsoleOutput::sendSuccess(QString Message)
{
    this->appendPlainText("Success: "+Message);
}

void ConsoleOutput::sendInfo(QString Message)
{
    this->appendPlainText("Info: "+Message);
}

void ConsoleOutput::clear()
{
    this->setPlainText("");
}

void ConsoleOutput::keyPressEvent(QKeyEvent* e)
{
    Q_UNUSED(e);
}

