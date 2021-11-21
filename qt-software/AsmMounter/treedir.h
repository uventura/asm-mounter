#ifndef TREEDIR_H
#define TREEDIR_H

#include <QString>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QDir>
#include <QTreeView>
#include <QScroller>
#include <QFileDialog>
#include <QItemSelectionModel>
#include <QAbstractItemView>

class TreeDir: public QTreeView
{
    Q_OBJECT
public:
    TreeDir(QWidget *parent = nullptr);

    void loadFolder();
    QString getRootFolderName();

signals:
    void doubleClickFileTreeItem(QString& fileSrc);

private slots:
    void doubleClickTreeItem(const QModelIndex &element);

private:
    QFileSystemModel* m_model;
    QString m_currentPath;
};

#endif // TREEDIR_H
