#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <QList>
#include <QString>

#include <QDebug>

template<typename T>
class CircularBuffer
{
    QList<T> m_buffer;
    const int m_maxSize;
    int m_iterator;

public:
    constexpr explicit CircularBuffer(const int max_size)
        : m_buffer{},
          m_maxSize{ max_size },
          m_iterator{}
    {}

    constexpr void push(T &&next)
    {
        if(m_buffer.size() == m_maxSize) m_buffer.removeFirst();

        if(!next.isEmpty()) m_buffer.push_back(next);

        m_iterator = m_buffer.size() - 1;
    }

    constexpr void push(const T &next)
    {
        if(m_buffer.size() == m_maxSize) m_buffer.removeFirst();

        if(!next.isEmpty()) m_buffer.push_back(next);

        m_iterator = m_buffer.size() - 1;
    }
//toto prerobit je to napicu
    constexpr const T &up()
    {
        if(m_iterator == -1) m_iterator = m_buffer.size() - 1;

        qDebug() << "up " << m_iterator << "after    " << m_iterator - 1;

        return m_buffer.at(--m_iterator);
    }

    constexpr const T &down()
    {
        if(++m_iterator == m_buffer.size()) m_iterator = 0;

        qDebug() << "down " << m_iterator << "after    " << m_iterator + 1;


        return m_buffer.at(m_iterator);
    }

    constexpr const T& last()
    {
       return m_buffer.last();
    }
};

#endif // CIRCULARBUFFER_H
