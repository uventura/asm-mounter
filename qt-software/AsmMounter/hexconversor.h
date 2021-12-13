#ifndef HEXCONVERSOR_H
#define HEXCONVERSOR_H

#include <QList>
#include <QStringList>
#include <QString>
#include <QDebug>

class HexConversor
{
public:
    HexConversor();

    void setCurrentConfigFile(QString configFile);
    QString getConversion(QString text);

private:
    QString m_configFile;
};

#endif // HEXCONVERSOR_H
