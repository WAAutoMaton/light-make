#include "data.h"

QMap<QString,QVariantList> Data::m_variable=QMap<QString,QVariantList>();

Data::Data()
{

}

/*!
 * 设置名为\a name的变量的值为\a value
 * \brief Data::setVariable
 * \param name 变量的名称
 * \param value 变量的值
 * \return 操作成功返回 \c true;操作失败返回 \c false;
 */
bool Data::setVariable(const QString &name, const QVariantList& value)
{
    m_variable[name]=value;
    return true;
}

/*!
 * \brief Data::setVariable
 * \param name
 * \param value
 * \return 操作成功返回 \c true;操作失败返回 \c false;
 */
bool Data::setVariable(const QString &name, const QVariant &value)
{
    QVariantList list;
    list.append(value);
    m_variable[name]= list;
    return true;
}

/*!
 * \brief Data::appendVariable
 * \param name
 * \param value
 * \return 操作成功返回 \c true;若有重复元素返回 \c false;
 */
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

/*!
 * \brief Data::appendVariable
 * \param name
 * \param value
 * \return 操作成功返回 \c true;若有重复元素返回 \c false;
 */
bool Data::appendVariable(const QString &name, const QVariantList &value)
{
    bool isSuccess=true;
    for(const auto &it : value)
    {
        isSuccess = appendVariable(name,it) && isSuccess;
    }
    return isSuccess;
}

/*!
 * \brief Data::deleteVariable
 * \param name
 * \return 删除成功返回 \c true;若该变量不存在返回 \c false;
 */
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

/*!
 * \brief Data::isVariable
 * \param name
 * \return 该变量存在返回 \c true;不存在返回 \c false
 */
bool Data::isVariable(const QString &name)
{
    return m_variable.find(name)!=m_variable.end();
}

/*!
 * \brief Data::isValueInVariable
 * \param name
 * \param value
 * \return \a value是否存在于 \a name中
 */
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

/*!
 * \brief Data::getVariable
 * \warning 调用该函数前请务必检查名为\a name的变量是否存在
 * \param name
 * \return 名为 \a name的变量的值
 */
const QVariantList &Data::getVariable(const QString &name)
{
    return m_variable[name];
}
