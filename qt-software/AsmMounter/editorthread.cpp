#include "editorthread.h"

EditorThread::EditorThread():
    index(-1)
{

}


void EditorThread::on_changed()
{
    index = (index == -1?tabsWidget->currentIndex():index);
    qDebug("Entered");

    currentEditor->setTextEdit(openedFiles[index]);
    //QTextEdit *currentElement = textEdit;
    //std::cout<<currentElement->toPlainText().toStdString()<<"\n";

    //currentEditor.setTextEdit(currentElement);

    index = -1;
}

void EditorThread::setAsmEditor(AsmEditor* editor)
{
    currentEditor = editor;
}

void EditorThread::setTabsWidget(QTabWidget* tabWidget)
{
    tabsWidget = tabWidget;
}

void EditorThread::addFile(QTextEdit* file)
{
    openedFiles.append(file);
}
