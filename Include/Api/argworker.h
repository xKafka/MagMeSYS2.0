#ifndef ARGWORKER_H
#define ARGWORKER_H

#include <QObject>

class ArgWorker : public QObject
{
    Q_OBJECT
public:
    explicit ArgWorker(QObject *parent = nullptr);

signals:
    void mainWindowOpen();
    void showApiInfo();

};

#endif // ARGWORKER_H
