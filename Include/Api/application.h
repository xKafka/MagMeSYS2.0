#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMap>

#include "Include/Ui/Moduls/MainWindow/mainwindow.h"
#include "Moduls/commander.h"

class Application : public QObject
{
    Q_OBJECT
//Api moduls
    std::unique_ptr<Commander> m_commander;
    std::unique_ptr<MainWindow> m_mainWindow;

    QMap<QString, QObject *> m_moduls;

public:
    explicit Application(QObject *parent = nullptr);

//    void multiplexCommand(const QString &command);

private slots:
    void multiplexCommand(const QString &command);

private:
    void sendCmdSetAsyn(const QStringList &cmdList);

signals:



};

#endif // APPLICATION_H
