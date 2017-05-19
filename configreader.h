#ifndef CONFIGREADER_H
#define CONFIGREADER_H

class QString;
class QFile;
class QStringList;

QString readFromConfigFile(QFile& file);
QString readFromSourceFile(QFile& file);

QStringList preprocessCode(const QString& code);
bool interpretCode(const QString& code);

QString deleteSpace(const QString &code);

bool isRightVariableName(const QString& code);


#endif // CONFIGREADER_H
