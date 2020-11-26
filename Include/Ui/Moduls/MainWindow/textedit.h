#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include "circularbuffer.h"

class TextEdit : public QTextEdit
{
    Q_OBJECT

    bool m_isCapsPressed;
    QString m_newLineFeed;
    QString m_text;
    size_t m_line;

    CircularBuffer<QString> m_buffer;

    void emitCmd();
    void cursorMoveToEnd();
    void enterPressed();
    const QString &getCommand();
    void onConsoleWrite(const QString &toPush);
    void removeLine(const size_t line);

    size_t onLineItr;

public:
    TextEdit(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;

signals:
    void commandSig(const QString &command);
};

#endif // TEXTEDIT_H
