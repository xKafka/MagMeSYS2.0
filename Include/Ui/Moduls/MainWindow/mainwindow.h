#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "Include/Api/Modul.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public Modul
{
    Q_OBJECT

    void constructConnecters();
    void constructWindow();

    //std::unique_ptr<Ui::MainWindow> m_ui;

    std::unique_ptr<Ui::MainWindow> m_ui;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Q_INVOKABLE QStringList parseCmd(const QStringList &cmdList) override final;

public slots:
    void onPlainTextSet(const QStringList &list);


signals:
    void command(const QString &command);

};

#endif // MAINWINDOW_H
