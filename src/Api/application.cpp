#include "Include/Api/application.h"

#include <QDebug>
#include <QThread>

Application::Application(QObject *parent) :
    QObject(parent),
    m_commander(std::make_unique<Commander>(this)),
    m_mainWindow(std::make_unique<MainWindow>()),
    //moduls summary
    m_moduls({
                { "MainWindow", m_mainWindow.get() },
                { "Commander", m_commander.get() }
             })
{

    m_mainWindow->show();

    connect(&*m_mainWindow, &MainWindow::command, this, &Application::multiplexCommand);
}

void Application::multiplexCommand(const QString &command)
{
    auto commandList = command.split(QRegExp("[\r\n\t ]"), QString::SkipEmptyParts);

    sendCmdSetAsyn(commandList);
}

void Application::sendCmdSetAsyn(QStringList &cmdList)
{
    //command multiplexer -> sends command to proper QObject via autoconnection

    QStringList retVal;

    const auto toObjectSend = m_moduls[cmdList.first()];
    cmdList.removeFirst();

    QMetaObject::invokeMethod(dynamic_cast<QObject*>(toObjectSend), "parseCmd", Qt::AutoConnection, Q_RETURN_ARG(QStringList, retVal), Q_ARG(const QStringList&, cmdList));
}



