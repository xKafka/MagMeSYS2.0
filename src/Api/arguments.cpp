#include "Include/Api/arguments.h"
#include <QDebug>

Arguments::Arguments()
{

}

void Arguments::parseAndShine(const QString &command)
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

void Arguments::echo(const QStringList &cmdList)
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
            const auto expre = [&cmdList]() -> const bool { for(const auto &cmd : cmdList) { if(cmd.contains("true")) return true; } return false; };

            emit setEcho(expre());
        }
    }
}

void Arguments::move(const QStringList &cmdList)
{

}

void Arguments::exit(const QStringList &cmdList)
{

}

void Arguments::close(const QStringList &cmdList)
{

}
