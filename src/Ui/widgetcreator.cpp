#include "Include/Ui/widgetcreator.h"

#include <QDebug>

WidgetCreator::WidgetCreator()
    : m_mainWindow(std::make_unique<MainWindow>())
{
    m_widgets.push_back(m_mainWindow.get());
}

MainWindow &WidgetCreator::mainWindow()
{
    return *m_mainWindow.get();
}
void WidgetCreator::showAll()
{
    for(const auto &widget : m_widgets)
        widget->show();
}
