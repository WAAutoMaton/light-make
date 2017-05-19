#include "data.h"

QMap<QString,QVariantList> Data::m_variable=QMap<QString,QVariantList>();

Data::Data()
{

}

bool Data::setVariable(const QString &name, const QVariantList& value)
{
    m_variable[name]=value;
    return true;
}

bool Data::setVariable(const QString &name, const QVariant &value)
{
    QVariantList list;
    list.append(value);
    m_variable[name]= list;
    return true;
}

bool Data::appendVariable(const QString &name, const QVariant &value)
{
    auto var=m_variable[name];
    for(const auto &it: var)
    {
        if (it.type()==value.type() && it==value) return false;
    }
    var.append(value);
    return true;
}

bool Data::appendVariable(const QString &name, const QVariantList &value)
{
    bool isSuccess=true;
    for(const auto &it : value)
    {
        isSuccess = appendVariable(name,it) && isSuccess;
    }
    return isSuccess;
}

bool Data::deleteVariable(const QString &name)
{
    auto it=m_variable.find(name);
    if (it!=m_variable.end())
    {
        m_variable.erase(it);
        return true;
    }
    return false;
}

bool Data::isVariable(const QString &name)
{
    return m_variable.find(name)!=m_variable.end();
}

bool Data::isValueInVariable(const QString &name, const QVariant &value)
{
    auto it=m_variable.find(name);
    if (it==m_variable.end()) return false;
    auto var=*it;
    for(const auto &i : var)
    {
        if (i.type()==value.type() && i==value) return true;
    }
    return false;
}

const QVariantList &Data::getVariable(const QString &name)
{
    return m_variable[name];
}
