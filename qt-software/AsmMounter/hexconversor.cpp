#include "hexconversor.h"

HexConversor::HexConversor()
{

}

void HexConversor::setCurrentConfigFile(QString configFile)
{
    m_configFile = configFile;
}

QString HexConversor::getConversion(QString text)
{
    QList<QString> initList = text.split("\n");

    QList<QString> code;
    QString current = "";

    for(auto sentence: initList)
    {
        current = "";
        for(auto symbol: sentence)
        {
            if(symbol == '#')
                break;
            if(symbol != '\t')
                current += symbol;
        }
        if(current.size() > 0 && current[0] != '#')
            code.append(current);
    }

    for(auto element: code)
    {
        qDebug() << "-> " << element;
    }
}
