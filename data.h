#ifndef DATA_H
#define DATA_H

#include <QMap>
#include <QVariantList>
#include <QString>

class Data
{
public:
    Data();
    bool setVariable(const QString& name, const QVariantList &value);
    bool setVariable(const QString& name, const QVariant &value);
    bool appendVariable(const QString& name, const QVariant &value);
    bool appendVariable(const QString& name, const QVariantList &value);
    bool deleteVariable(const QString& name);
    bool isVariable(const QString& name);
    bool isValueInVariable(const QString& name, const QVariant &value);
    const QVariantList& getVariable(const QString& name);
private:
    static QMap<QString,QVariantList> m_variable;
};

#endif // DATA_H
