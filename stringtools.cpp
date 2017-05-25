#include "stringtools.h"

#include <QString>
#include <QRegExp>


QString removeExtension(const QString &source)
{
    QString pattern(R"(^(.*)\.[^/\\.]*$)");
    QString noExtensionSrc;
    QRegExp rx(pattern);
    if (rx.exactMatch(source))
    {
        return rx.cap(1);
        //qDebug()<<noExtensionSrc;
    }
    return QString();
}

QString removeSpace(const QString& code)
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
            formattedCode.append(' ');
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
