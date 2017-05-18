#include "data.h"

QMap<QString,QVariantList> Data::m_variable=QMap<QString,QVariantList>();

Data::Data()
{

}

void Data::setVariable(const QString &key, const QVariantList& value)
{
    m_variable[key]=value;
}

void Data::setVariable(const QString &key, const QVariant &value)
{
    QVariantList list;
    list.append(value);
    m_variable[key]= list;
}

const QVariantList &Data::getVariable(const QString &key)
{
    return m_variable[key];
}
