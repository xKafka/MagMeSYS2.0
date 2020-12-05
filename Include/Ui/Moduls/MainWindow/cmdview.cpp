#include "cmdview.h"

#include <QDebug>

CmdView::CmdView(QString::iterator begin, QString::iterator end)
    : m_begin(begin),
      m_size(end - begin),
      m_isEmpty(!(end - begin))                //could be written nicely but its readable
{
    qDebug() << "Command pushed:: " << toQString();
}
CmdView::CmdView(QString::iterator begin, const int size)
    : m_begin(begin),
      m_size(size)
{}
QString CmdView::toQString() const
{
    return QString{m_begin, m_size};
}
bool CmdView::isEmpty() const
{
    return m_isEmpty;
}
