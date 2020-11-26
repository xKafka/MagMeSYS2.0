#include "Include/Ui/Moduls/MainWindow/mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_ui(std::make_unique<Ui::MainWindow>())
{
    constructWindow();
    constructConnecters();
}
MainWindow::~MainWindow()
{}
void MainWindow::constructConnecters()
{
    connect(m_ui->textEdit_console, &TextEdit::commandSig, this, [this](const QString &cmd) { emit command(cmd);});
}
void MainWindow::constructWindow()
{
    m_ui->setupUi(this);
}
void MainWindow::onPlainTextSet(const QStringList &list)
{

}
QStringList MainWindow::parseCmd(const QStringList &cmdList)
{
    qDebug() << "mainWindow";

    qDebug() << cmdList;

    return QStringList{"MainWindow ", "command ", "success"};
}
