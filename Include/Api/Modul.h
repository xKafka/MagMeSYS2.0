#ifndef MODUL_H
#define MODUL_H

#include <QStringList>
#include <QObject>

class Modul
{

public:
    virtual QStringList parseCmd(const QStringList &cmdList) = 0;
};

#endif // MODUL_H
