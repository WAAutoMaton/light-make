#include "makefilewritter.h"

#include "data.h"
#include "exception.h"
#include "stringtools.h"

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QRegExp>
#include <QVariantList>
#include <QVariant>

QString generateMakeFile(const QString &fileName)
{
    QString str;
    QTextStream ts(&str,QIODevice::WriteOnly);
    checkVariableSize("TEMPLATE",1,1);
    QVariantList Template = Data::getVariable("TEMPLATE");
    if (Template[0].toString()=="default")
    {
        checkVariableSize("SOURCES",1,10000);
        const QVariantList& sources=Data::getVariable("SOURCES");
        ts<<QString("%1 :").arg(fileName);
        for(const QVariant &i:sources)
        {
            QString objFileName=removeExtension(i.toString())+".o";
            ts<<QString(" %1").arg(objFileName);
        }
        ts<<QString("\n\tg++ -o %1").arg(fileName);
        for(const QVariant &i:sources)
        {
            QString objFileName=removeExtension(i.toString())+".o";
            ts<<QString(" %1").arg(objFileName);
        }
        ts<<'\n';
        for(const QVariant &i:sources)
        {
            QString objFileName=removeExtension(i.toString())+".o";
            ts<<QString("%1 : %2\n\tg++ -c %2").arg(objFileName,i.toString());
            ts<<"\n";
        }
        ts<<QString("clean:\n\trm %1").arg(fileName);
        for(const QVariant &i:sources)
        {
            QString objFileName=removeExtension(i.toString())+".o";
            ts<<QString(" %1").arg(objFileName);
        }
    }
    else Exception(QObject::tr("Unknown value %2 in variable %1").arg("TEMPLATE",Template[0].toString()));
    return str;
}


void checkVariableSize(const QString& name,int min,int max)
{
    if (!Data::isVariable(name)) throw Exception(QObject::tr("varibale %1 not foud").arg(name));
    const QVariantList& var = Data::getVariable(name);
    if (var.size()>max) throw Exception(QObject::tr("too much value in varibale %1").arg(name));
    if (var.size()<min) throw Exception(QObject::tr("too few value in varibale %1").arg(name));
}
