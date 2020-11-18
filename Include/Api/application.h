#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <memory>

#include "Include/Ui/widgetcreator.h"
#include "arguments.h"

class Application : public QObject
{
    Q_OBJECT

    std::unique_ptr<WidgetCreator> m_widgets;
    std::unique_ptr<Arguments> m_commander;

public:
    explicit Application(QObject *parent = nullptr);

signals:



};

#endif // APPLICATION_H
