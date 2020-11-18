#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void constructConnecters();
    void constructWindow();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onPlainTextSet(const QStringList &list);

signals:
    void command(const QString &command);

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
};
#endif // MAINWINDOW_H
