#include "data.h"

QMap<QString,QVariantList> Data::m_variable=QMap<QString,QVariantList>();

Data::Data()
{

}

bool Data::setVariable(const QString &key, const QVariantList& value)
{
    m_variable[key]=value;
    return true;
}

bool Data::setVariable(const QString &key, const QVariant &value)
{
    QVariantList list;
    list.append(value);
    m_variable[key]= list;
    return true;
}

bool Data::appendVariable(const QString &key, const QVariant &value)
{
    auto var=m_variable[key];
    for(auto it: var)
    {
        if (it.type()==value.type() && it==value) return false;
    }
    var.append(value);
    return true;
}

bool Data::appendVariable(const QString &key, const QVariantList &value)
{
    bool isSuccess=true;
    for(auto it : value)
    {
        isSuccess = appendVariable(key,it) && isSuccess;
    }
    return isSuccess;
}

bool Data::deleteVariable(const QString &key)
{
    auto it=m_variable.find(key);
    if (it!=m_variable.end())
    {
        m_variable.erase(it);
        return true;
    }
    return false;
}

const QVariantList &Data::getVariable(const QString &key)
{
    return m_variable[key];
}
