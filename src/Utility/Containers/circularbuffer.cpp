#include "Include/Utility/Containers/circularbuffer.h"

#include <QDebug>

template<typename T>
constexpr CircularBuffer<T>::CircularBuffer(const int max_size)
    : m_buffer(),
      m_maxSize(max_size),
      m_iterator(0)
{}

template<typename T>
constexpr void CircularBuffer<T>::checkRemoving()
{
    if(m_buffer.size() == m_maxSize)
        m_buffer.removeFirst();
}

template<typename T>
constexpr bool CircularBuffer<T>::isOnEnd() const noexcept
{
    return m_iterator == m_buffer.size() - 1;
}

template<typename T>
constexpr bool CircularBuffer<T>::isOnBeg() const noexcept
{
    return m_iterator == 0;
}

template<typename T>
constexpr void CircularBuffer<T>::push(T &&next)
{
    checkRemoving();

    if(!next.isEmpty())
        m_buffer.push_back(std::move(next));

    m_iterator = m_buffer.size() - 1;
}

template<typename T>
constexpr void CircularBuffer<T>::push(const T &next)
{
    checkRemoving();

    if(!next.isEmpty())
        m_buffer.push_back(next);

    m_iterator = m_buffer.size() - 1;
}

template<typename T>
constexpr const T &CircularBuffer<T>::inc()
{
    if(isOnEnd())
        m_iterator = -1;

    qDebug() << "Curr   " << m_iterator + 1 << "   Max size:  " << m_buffer.size();

    return m_buffer.at(++m_iterator);
}

template<typename T>
constexpr const T &CircularBuffer<T>::dec()
{
    if(isOnBeg())
        m_iterator = m_buffer.size();

    return m_buffer.at(--m_iterator);
}

template<typename T>
constexpr inline const T &CircularBuffer<T>::last()
{
   return m_buffer.last();
}

template<typename T>
constexpr inline const T &CircularBuffer<T>::curr()
{
    return m_buffer.at(m_iterator);
}

template class CircularBuffer<QString>;
template class CircularBuffer<CmdView>;

