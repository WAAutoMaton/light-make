#include "core.h"
#include <QMap>
#include <QVariantList>

QMap<QString,QVariantList> Core::variable=QMap<QString,QVariantList>();
const QString Core::versionString="0.0.1";

Core::Core()
{

}
