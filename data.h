#ifndef DATA_H
#define DATA_H

#include <QMap>
#include <QVariantList>
#include <QString>

class Data
{
public:
    Data();
    bool setVariable(const QString& key, const QVariantList &value);
    bool setVariable(const QString& key, const QVariant &value);
    bool appendVariable(const QString& key, const QVariant &value);
    bool appendVariable(const QString& key, const QVariantList &value);
    bool deleteVariable(const QString& key);
    const QVariantList& getVariable(const QString& key);
private:
    static QMap<QString,QVariantList> m_variable;
};

#endif // DATA_H
