#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <ros/network.h>
#include <iostream>
#include <QtGui>
#include <thread>
#include <QThread>
#include <string>
#include <QStringListModel>
#endif

namespace Ui {
using namespace std;
using namespace Qt;
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = 0);
    virtual ~MainWindow();
    bool init();
    void run();

Q_SIGNALS:
    void rosShutdown();

private:
    Ui::MainWindow *ui;
    int init_argc;
    char** init_argv;
    std::thread th;
};

#endif // MAINWINDOW_H
