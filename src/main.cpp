#include "Include/Ui/MainWindow/mainwindow.h"
#include "Include/Api/magmesys.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    MagMeSYS a(argc, argv);
    return a.exec();
}
