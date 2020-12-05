
#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include <QStringView>

#include "textholder.h"

class TextEdit : public QTextEdit
{
    Q_OBJECT

    TextHolder m_holder;

   // void emitCmd();
    void cursorMoveToEnd();
    void enterPressed();
  //  const QString &getCommand();
    void onConsoleWrite(const QString &toPush);
    void removeLastLine();

    size_t onLineItr;

public:
    TextEdit(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;

signals:
    void commandSig(const QString &command);
};

#endif // TEXTEDIT_H
