#include "Include/Api/Moduls/commander.h"
#include <QDebug>

Commander::Commander(QObject *parent)
    : QObject(parent)
{ }

void Commander::parseAndShine(const QString &command)
{
    auto commandList = command.split(QRegExp("[\r\n\t ]"), QString::SkipEmptyParts);
    const auto cmd = CMD::str2int(commandList.first().toLocal8Bit().data());
    commandList.removeFirst();

    switch(cmd)
    {
        case CMD::echo: echo(commandList);
            break;
        case CMD::move: move(commandList);
            break;
        case CMD::exit: exit(commandList);
            break;
        case CMD::close: close(commandList);
            break;
    }
}

void Commander::echo(const QStringList &cmdList)
{
    for(const auto &cmd : cmdList)
    {
        if(cmd.contains("help"))
            emit infoWindowSig(     {
                                        "command :: echo",
                                        "args.......:: help",
                                        "............-> shows commands help table",
                                        "............:: set",
                                        "............-> sets echo to console active/ inactive"
                                        ".............-><bool>"
                                    });
        if(cmd.contains("set"))
        {
            const auto setUp = [&cmdList]() -> const bool { for(const auto &cmd : cmdList) { if(cmd.contains("true")) return true; } return false; };
            const auto setDown = [&cmdList]() -> const bool { for(const auto &cmd : cmdList) { if(cmd.contains("false")) return true; } return false; };

            if(setUp()) emit setEchoSig(true);
            if(setDown()) emit setEchoSig(false);
        }
    }
}

void Commander::widgets()
{
    emit widgetsSig();
}

void Commander::move(const QStringList &cmdList)
{

}

void Commander::exit(const QStringList &cmdList)
{

}

void Commander::close(const QStringList &cmdList)
{

}
QStringList Commander::parseCmd(const QStringList &cmdList)
{

    qDebug() << "commander";

    qDebug() << cmdList;

    return QStringList{"Commander ", "command ", "success"};
}

