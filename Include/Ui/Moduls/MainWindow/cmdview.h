#ifndef CMDVIEW_H
#define CMDVIEW_H

#include <QString>

class CmdView
{
    QString::iterator m_begin;
    int m_size;
    bool m_isEmpty;

public:
    CmdView(QString::iterator begin, QString::iterator end);
    CmdView(QString::iterator begin, const int size);

    QString toQString() const;
    bool isEmpty() const;
};

#endif // CMDVIEW_H
