#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <QList>
#include <QString>

#include "Include/Ui/Moduls/MainWindow/cmdview.h"

template<typename T>
class CircularBuffer
{
    QList<T> m_buffer;
    const int m_maxSize;
    int m_iterator;

public:
    constexpr explicit CircularBuffer(const int max_size);

    constexpr inline void checkRemoving();

    constexpr inline const T &last();
    constexpr inline const T &curr();

    constexpr inline bool isOnEnd() const noexcept;
    constexpr inline bool isOnBeg() const noexcept;

    constexpr void push(T &&next);
    constexpr void push(const T &next);

    constexpr const T &inc();
    constexpr const T &dec();
};

#endif // CIRCULARBUFFER_H
