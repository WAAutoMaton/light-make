#ifndef MAKEFILEWRITTER_H
#define MAKEFILEWRITTER_H

template <typename> class QList;
class QVariant;
using QVariantList=QList<QVariant>;
class QString;

void checkVariableSize(const QString& name,int min,int max);
QString generateMakeFile(const QString& fileName);
#endif // MAKEWRITTER_H
