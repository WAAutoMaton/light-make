#include "exception.h"

#include <QString>

Exception::Exception(const QString& errorMessage=QString()) : m_errorMessage(errorMessage)
{

}

QString Exception::toString()
{
    return m_errorMessage;
}
