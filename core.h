#ifndef CORE_H
#define CORE_H

#include <QMap>
#include <QVariantList>
#include <QVariant>
#include <QSet>
class QString;

class Core
{
public:
    Core();
    static QVariantList& getVariable(const QString& varName);
    static QMap<QString,QSet<QVariant>> variable;
    const static QString versionString;
};

#endif // CORE_H
