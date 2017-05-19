#include "exception.h"

#include <QString>

Exception::Exception(const QString& errorMessage=QString(), int line=-1, const QString &fileName=QString())
    : m_errorMessage(errorMessage),
      m_line(line),
      m_fileName(fileName)
{

}

QString Exception::toString()
{
    return m_errorMessage;
}

Exception &Exception::setLine(int line)
{
    m_line=line;
    return *this;
}

Exception &Exception::setFileName(const QString &fileName)
{
    m_fileName=fileName;
    return *this;
}
