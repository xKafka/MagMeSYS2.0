#include "Include/Ui/MainWindow/mainwindow.h"
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
{
}

void MainWindow::constructConnecters()
{
    connect(m_ui->lineEdit_console, &QLineEdit::returnPressed, this, [this]()
    {
        emit command(m_ui->lineEdit_console->text());
        m_ui->lineEdit_console->clear();
    });
}
void MainWindow::constructWindow()
{
    m_ui->setupUi(this);
    m_ui->plainTextEdit_console->viewport()->setAutoFillBackground(false);
    m_ui->plainTextEdit_console->setFrameStyle(QFrame::NoFrame);
}
void MainWindow::onPlainTextSet(const QStringList &list)
{
    for(const auto &text : list)
        m_ui->plainTextEdit_console->appendPlainText(text);

}
