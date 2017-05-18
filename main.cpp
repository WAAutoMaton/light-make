#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <cstdio>
#include <QDebug>
#include <cstring>
#include <QObject>
#include "core.h"
#include "configreader.h"
#include "exception.h"

void printHelp()
{
    QString fileURL=":/text/help_zh_CN.txt";
    QFile file;
    file.setFileName(fileURL);
    file.open(QIODevice::ReadOnly);
    QTextStream out(stdout);
    out << file.readAll();
}
void printVersion()
{
    QTextStream out(stdout);
    out << QString("OI make version %1\n").arg(Core::versionString);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<argc;
    try
    {
        QString srcURL;
        for(int i=1; i<argc; ++i)
        {
            qDebug()<<argv[i];
            if (std::strcmp(argv[i],"-h")==0 || std::strcmp(argv[i],"--help")==0)
            {
                printHelp();
                return 0;
            }
            if (std::strcmp(argv[i],"-v")==0 || std::strcmp(argv[i],"--version")==0)
            {
                printVersion();
                return 0;
            }
            if (srcURL.isEmpty()) srcURL=argv[i];
            else throw Exception(QObject::tr("too many source files"));
        }
        if (srcURL.isEmpty()) throw Exception(QObject::tr("no source file"));
    }catch(Exception &e)
    {
        QTextStream err(stderr);
        err<<e.toString();
        return 127;
    }
    catch(...)
    {
        QTextStream err(stderr);
        err<<QObject::tr("Unknow Error!");
        return 127;
    }

    return a.exec();
}
