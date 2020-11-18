#include "Include/Api/application.h"

#include <QDebug>

Application::Application(QObject *parent) :
    QObject(parent),
    m_widgets(std::make_unique<WidgetCreator>()),
    m_commander(std::make_unique<Arguments>())
{
    m_widgets->mainWindow().show();

    connect(&m_widgets->mainWindow(), &MainWindow::command, this,[this](const QString &command) {m_commander->parseAndShine(command);});


    connect(&*m_commander, &Arguments::setEcho, this, [](const bool isEchoUp) { qDebug() << QString{isEchoUp ? "echo setting up" : "echo setting down"}; });
    connect(&*m_commander, &Arguments::infoWindowSig, &m_widgets->mainWindow(), &MainWindow::onPlainTextSet);

}
