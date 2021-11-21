#include "treedir.h"

TreeDir::TreeDir(QWidget *parent):
      QTreeView(parent)
{
    m_currentPath = "";

    setAnimated(false);
    setIndentation(20);
    setSortingEnabled(true);

    // Click on Element
    connect(this, &TreeDir::doubleClicked, this, &TreeDir::doubleClickTreeItem);
}

void TreeDir::loadFolder()
{
    //[TODO] Verify Selected Path
    m_currentPath = QFileDialog::getExistingDirectoryUrl().path();

    m_model = new QFileSystemModel;
    QModelIndex pathIndex = m_model->setRootPath(m_currentPath);

    setModel(m_model);
    setRootIndex(pathIndex);
}

QString TreeDir::getRootFolderName()
{
    auto pathSplit = m_currentPath.split("/");
    return pathSplit[pathSplit.size()-1];
}

void TreeDir::doubleClickTreeItem(const QModelIndex &element)
{
    auto currentParent = element.parent();
    QDir dir;

    QString fileClickedSrc=element.siblingAtColumn(0).data().toString();

    while(currentParent.data().toString() != dir.rootPath())
    {
        fileClickedSrc = currentParent.data().toString() + "/" + fileClickedSrc;
        currentParent = currentParent.parent();
    }

    fileClickedSrc = dir.rootPath()+fileClickedSrc;

    emit doubleClickFileTreeItem(fileClickedSrc);
}
