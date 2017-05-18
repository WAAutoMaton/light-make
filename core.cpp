#include "core.h"
#include <QMap>
#include <QVariantList>

QMap<QString,QSet<QVariant>> Core::variable=QMap<QString,QSet<QVariant>>();
const QString Core::versionString="0.0.1";

Core::Core()
{

}
