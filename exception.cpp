#include "exception.h"

#include <QString>
#include <QObject>

Exception::Exception(const QString& errorMessage, int line, const QString &fileName)
    : m_errorMessage(errorMessage),
      m_line(line),
      m_fileName(fileName)
{

}

QString Exception::toString()
{
    QString message;
    if (!m_fileName.isEmpty()) message.append(QObject::tr("At file %1,").arg(m_fileName));
    if (m_line!=-1) message.append(QObject::tr("At line %1,").arg(m_line));
    return message.append(m_errorMessage);
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
