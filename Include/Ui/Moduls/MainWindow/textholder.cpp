#include "textholder.h"

constexpr auto c_bufferSize = 64;

TextHolder::TextHolder()
    : m_text(),
      m_cmd(c_bufferSize)
{
}
void TextHolder::renew(QString &&text)
{
    m_text = std::move(text);

    m_cmd.push({m_text.begin() + getEnd() + 1, m_text.end()});
}
int TextHolder::getEnd() const
{
    return m_text.lastIndexOf("\n");
}
QString TextHolder::cmd()
{
    return m_cmd.curr().toQString();
}



