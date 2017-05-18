#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
public:
    Exception(const QString& errorMessage);
    QString toString();
private:
    QString m_errorMessage;
};

#endif // EXCEPTION_H
