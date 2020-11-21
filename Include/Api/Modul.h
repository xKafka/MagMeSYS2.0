#ifndef MODUL_H
#define MODUL_H

#include <QStringList>

class Modul
{
    virtual void parseCmd(const QStringList &cmdList) = 0;

};

#endif // MODUL_H
