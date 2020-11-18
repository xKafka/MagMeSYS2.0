#ifndef MAGMESYS_H
#define MAGMESYS_H

#include <QApplication>
#include <memory>

#include "application.h"

class MagMeSYS : public QApplication
{
    std::unique_ptr<Application> m_widgets;

public:
    explicit MagMeSYS(int argc, char *argv[]);

};

#endif // MAGMESYS_H
