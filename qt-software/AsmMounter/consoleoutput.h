#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QDebug>

#include "highlighter.h"

class ConsoleOutput: public QPlainTextEdit
{
    Q_OBJECT
public:
    ConsoleOutput(QWidget *parent = nullptr);

    void clear();

    void sendMessage(QString Message);
    void sendWarning(QString Message);
    void sendError(QString Message);
    void sendSuccess(QString Message);
    void sendInfo(QString Message);

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    Highlighter* consoleHighlighter;
};

#endif // CONSOLEOUTPUT_H
