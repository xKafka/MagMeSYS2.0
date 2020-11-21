#include "Include/Api/application.h"

#include <QDebug>
#include <QThread>

Application::Application(QObject *parent) :
    QObject(parent),
    m_commander(std::make_unique<Commander>(this)),
    m_mainWindow(std::make_unique<MainWindow>()),
    //moduls summary

    m_moduls({
                { "MainWindow", &*m_mainWindow },
                { "Commander", &*m_commander}
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

void Application::sendCmdSetAsyn(const QStringList &cmdList)
{
    QString retVal;

    const auto toObjectSend = m_moduls[cmdList.first()];

    /*
     *
     *
     * every modul should be inherited by Modul class insted of QObject
     *
     *
     *
     *
     *
    */
  /*  QMetaObject::invokeMethod(obj, "compute", Qt::DirectConnection,Q_RETURN_ARG(QString, retVal),
                              Q_ARG(QString, "sqrt"),
                              Q_ARG(int, 42),
                              Q_ARG(double, 9.7));
*/
}



