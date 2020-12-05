#ifndef TEXTHOLDER_H
#define TEXTHOLDER_H

#include <QDebug>

#include "Include/Utility/Containers/circularbuffer.h"

class TextHolder
{
    QString m_text;
    CircularBuffer<CmdView> m_cmd;

    int getEnd() const;

public:
    explicit TextHolder();

    void renew(QString &&text);

    QString cmd();

    inline QString up() { return m_cmd.inc().toQString(); }
    inline QString down() { return m_cmd.dec().toQString(); }
};

#endif // TEXTHOLDER_H
