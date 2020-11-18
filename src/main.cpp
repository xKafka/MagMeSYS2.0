#include "Include/Api/magmesys.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    MagMeSYS a(argc, argv);

    return a.exec();
}
