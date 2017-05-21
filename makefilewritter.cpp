#include <QString>
#include <QTextStream>

#include "data.h"
#include "exception.h"
#include <QObject>

QString generateMakeFile()
{
    QString str;
    QTextStream ts(&str,QIODevice::WriteOnly);
    if (!Data::isVariable("template")) throw Exception(QObject::tr("varibale TEMPLATE not foud"));
    QVariantList Template = Data::getVariable("template");
    if (Template.size()>1) throw Exception(QObject::tr("too much varibale in varibale TEMPLATE"));
    if (Template.size()<1) throw Exception(QObject::tr("too much varibale in varibale TEMPLATE"));

    if (Template[0].toString()=="")
    return str;
}

void checkVariableSize(QString name,int min,int max)
{

}
