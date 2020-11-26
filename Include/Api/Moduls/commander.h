#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QThread>

#include "commands.h"
#include "Include/Api/Modul.h"

class Commander : public QObject, public Modul
{
    Q_OBJECT

    std::unique_ptr<QThread> m_thread;
    std::vector<QObject> m_objects;

public:
    Commander(QObject *parent);

    void parseAndShine(const QString &command);

    Q_INVOKABLE QStringList parseCmd(const QStringList &cmdList) override final;

    void echo(const QStringList &cmdList);
    void move(const QStringList &cmdList);
    void exit(const QStringList &cmdList);
    void close(const QStringList &cmdList);
    void widgets();

signals:
    void infoWindowSig(const QStringList &info);
    void setEchoSig(const bool set);
    void widgetsSig();
};

#endif // ARGUMENTS_H
