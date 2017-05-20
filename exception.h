#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
public:
    Exception(const QString& errorMessage=QString(),int line=-1,const QString &fileName=QString());
    QString toString();
    Exception& setLine(int line);
    Exception& setFileName(const QString& fileName);
private:
    QString m_errorMessage;
    int m_line;
    QString m_fileName;
};

#endif // EXCEPTION_H
