#include "data.h"
#include "core.h"
#include "configreader.h"
#include "error.h"
#include "makefilewritter.h"
#include "stringtools.h"

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <cstdio>
#include <QDebug>
#include <cstring>
#include <QObject>
#include <QUrl>
#include <QFileInfo>
#include <QRegExp>
#include <QTranslator>
#include <QLocale>

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
    out << QString("light make version %1\n").arg(Core::versionString);
}

void loadTranlateFile(QCoreApplication *app)
{
    QLocale locale;
    QString translatorFileName = "";
    QTranslator *translator = new QTranslator(app);
    QLocale::Country systemCountry = locale.system().country();
    if (systemCountry==QLocale::Country::China)
    {
        translatorFileName = ":/language/lmake_zh_CN.qm";
    }

    if (translatorFileName!="")
    {
        if (translator->load(translatorFileName))
        {
            app->installTranslator(translator);
        }
        else qDebug()<<"load translator error";
    }
    else
    {
        qDebug()<<"use English";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    loadTranlateFile(&a);
    try
    {
        QString sourceFileString;
        QUrl sourceFileUrl;

        for(int i=1; i<argc; ++i)
        {
            if (std::strcmp(argv[i],"-h")==0 || strcmp(argv[i],"--help")==0)
            {
                printHelp();
                return 0;
            }
            if (std::strcmp(argv[i],"-v")==0 || std::strcmp(argv[i],"--version")==0)
            {
                printVersion();
                return 0;
            }
            if (sourceFileString.isEmpty()) sourceFileString=argv[i];
            else throw Error(QObject::tr("too many source files"));
        }

        if (sourceFileString.isEmpty()) throw Error(QObject::tr("no source file"));
        sourceFileUrl.setUrl(sourceFileString);
        try
        {
            QFile configFile;
            configFile.setFileName(":/config/default.lm");
            configFile.open(QIODevice::ReadOnly);
            QStringList config=readFromConfigFile(configFile);
            interpretCode(config);
        }catch(Error &e)
        {
            throw e.setFileName("default.lm");
        }
#ifdef QT_DEBUG
        qDebug() <<sourceFileString;
#endif
        Data::appendVariable("SOURCES",sourceFileString);
        QString noExtensionSrc=removeExtension(sourceFileString);
        if (noExtensionSrc.isEmpty()) noExtensionSrc=sourceFileString+".cpp";
#ifdef Q_OS_WIN
        Data::setVariable("OUTPUT",noExtensionSrc+".exe");
#else
        Data::setVariable("OUTPUT",noExtensionSrc);
#endif
        try
        {
            QFileInfo sourceFileInfo(sourceFileString);
            if (!sourceFileInfo.exists()) throw Error(QObject::tr("No such file")).setFileName(sourceFileString);
            QFile sourceFile;
            sourceFile.setFileName(sourceFileString);
            sourceFile.open(QIODevice::ReadOnly);
            QStringList source=readFromSourceFile(sourceFile);
            interpretCode(source);
        }catch(Error &e)
        {
            throw e.setFileName(sourceFileString);
        }
#ifdef QT_DEBUG
        qDebug()<<Data::debugOnly_getVariableMap().isEmpty();
        qDebug()<<Data::debugOnly_getVariableMap();
#endif
        try
        {
            QString make=generateMakeFile();
            QFile makeFile;
            makeFile.setFileName(Data::getVariable("OUTPUT").at(0).toString()+".Makefile");
            makeFile.open(QIODevice::WriteOnly);
            makeFile.write(make.toLocal8Bit());
        }
        catch(Error &e)
        {
            throw e;
        }
    }catch(Error &e)
    {
        QTextStream err(stderr);
        err<<e.toString();
        return 127;
    }
    catch(...)
    {
        QTextStream err(stderr);
        err<<QObject::tr("Unknown Error!");
        return 127;
    }

    return 0;
    return a.exec();
}
