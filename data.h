#ifndef DATA_H
#define DATA_H

#include <QMap>
#include <QVariantList>
#include <QString>

class Data
{
public:
    Data();
    void setVariable(const QString& key, const QVariantList &value);
    void setVariable(const QString& key, const QVariant &value);
    const QVariantList& getVariable(const QString& key);
private:
    static QMap<QString,QVariantList> m_variable;
};

#endif // DATA_H
