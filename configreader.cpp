#include "configreader.h"

#include "core.h"
#include <QString>
#include <QFile>
#include <QTextStream>

QString readFromConfigFile(QFile& file)
{
    return file.readAll();
}

QString readFromSourceFile(QFile& file)
{
    //
}

bool interpretConfig(const QString& file)
{
    QTextStream ts;
    ts<<file;
    while(ts.atEnd())
    {
        QString code=ts.readLine();
        code=deleteSpace(code);
        if (code[0]=='#') continue;
    }
}

QString deleteSpace(const QString& code)
{
    QString formattedCode;
    //auto it=code.begin();
    //while(it!=code.end() && (*it==' ' || *it=='\t')) ++it;
    bool isSpace=false;
    for(auto it:code)
    {
        if (isSpace)
        {
            if (it==' ' || it=='\t') continue;
            if (!formattedCode.isEmpty()) formattedCode.append(it);
            isSpace=false;
        }
        else
        {
            if (it==' ' || it=='\t') isSpace=true;
            else formattedCode.append(it);
        }
    }
    return formattedCode;
}
