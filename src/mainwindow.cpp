#include "../include/qtros/mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using namespace Qt;

MainWindow::MainWindow(int argc, char** argv, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/icon.jpg"));
    ros::init(init_argc,init_argv,"qtros");
    if ( ! ros::master::check() ) {
        return;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;

    th=std::thread(&MainWindow::run,this);
    return;
}

MainWindow::~MainWindow()
{
    if(ros::isStarted()) {
        ROS_INFO("exiting");
        ros::shutdown(); // explicitly needed since we use ros::start();
    }
    th.join();
    delete ui;
}

void MainWindow::run(){
    ros::Rate loop_rate(33);
    while ( ros::ok() ) {
        ros::spinOnce();
        loop_rate.sleep();
    }
}
