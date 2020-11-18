#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QObject>
#include <QThread>
#include <memory>

#include "commands.h"
#include "argworker.h"

class Arguments : public QObject
{
    Q_OBJECT

    std::unique_ptr<QThread> m_thread;
    std::unique_ptr<ArgWorker> m_worker;

public:
    Arguments();

    void parseAndShine(const QString &command);

    void echo(const QStringList &cmdList);
    void move(const QStringList &cmdList);
    void exit(const QStringList &cmdList);
    void close(const QStringList &cmdList);

signals:
    void infoWindowSig(const QStringList &info);
    void setEcho(const bool set);

};

#endif // ARGUMENTS_H
