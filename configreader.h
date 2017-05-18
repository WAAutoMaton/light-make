#ifndef CONFIGREADER_H
#define CONFIGREADER_H

class QString;
class QFile;

QString readFromConfigFile(QFile& file);
QString readFromSourceFile(QFile& file);
bool interpretConfig(const QString& file);

QString deleteSpace(const QString &code);

#endif // CONFIGREADER_H
