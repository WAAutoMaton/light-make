#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <cstdio>
#include <QDebug>
#include <cstring>
#include "core.h"

void printHelp()
{
    QString fileURL=":/text/help_zh_cn.txt";
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
    }
    return a.exec();
}
