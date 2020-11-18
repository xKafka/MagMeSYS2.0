#ifndef WIDGETCREATOR_H
#define WIDGETCREATOR_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <memory>
#include <stdexcept>

#include "Include/Ui/MainWindow/mainwindow.h"

class WidgetCreator
{    

    std::unique_ptr<MainWindow> m_mainWindow;

    std::vector<QWidget*> m_widgets;

public:
    WidgetCreator();

    MainWindow &mainWindow();

    void showAll();

};

#endif // WIDGETCREATOR_H
