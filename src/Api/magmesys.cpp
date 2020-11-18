#include "Include/Api/magmesys.h"

MagMeSYS::MagMeSYS(int argc, char *argv[]) :
    QApplication(argc, argv),
    m_widgets(std::make_unique<Application>())
{

}
