#include "textedit.h"

#include <QDebug>
#include <algorithm>

constexpr auto c_newLineChar = "\n->";

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent),
      m_holder()
{
    setText("->MagMeSYS new version 2020 by xKafka\n->");

    cursorMoveToEnd();
}

void TextEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Return : enterPressed();
        break;
    case Qt::Key_Up : removeLastLine(); m_holder.up(); onConsoleWrite(m_holder.cmd());
        break;
    case Qt::Key_Down : removeLastLine(); onConsoleWrite(m_holder.cmd());
        break;
    default:
        QTextEdit::keyPressEvent(event);
    }

}/*
void TextEdit::emitCmd()
{
    const auto newLine = m_text.lastIndexOf("\n");

    textCursor().insertText(m_newLineFeed);

    const auto command = m_text.mid(newLine + m_newLineFeed.size(), m_text.size() - newLine - 1);

    m_buffer.push(command);

    if(!command.isEmpty())
        emit commandSig(command);
}
const QString &TextEdit::getCommand()
{
    const auto newLinePosition = m_text.lastIndexOf('\n');

    m_buffer.push(m_text.mid(newLinePosition + m_newLineFeed.size(), m_text.size() - newLinePosition - 1));

    return m_buffer.last();
}*/
void TextEdit::cursorMoveToEnd()
{
    auto cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
}
void TextEdit::enterPressed()
{
    m_holder.renew(toPlainText());

    textCursor().insertText(c_newLineChar);

    qDebug() << m_holder.cmd();
  //  emitCmd();
}
void TextEdit::onConsoleWrite(const QString &toPush)
{
    moveCursor(QTextCursor::End);
    insertPlainText(toPush);
}
void TextEdit::removeLastLine()
{
    auto cursor = textCursor();

    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.removeSelectedText();
    cursor.deleteChar(); // clean up new line

    setTextCursor(cursor);
}
