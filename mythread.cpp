#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}


void MyThread::run(){
    MainLogic return_xy;
    connect(this, &MyThread::pause_th, &return_xy, &MainLogic::start_stop_timer);
    connect(&return_xy, &MainLogic::send_list_points, this, &MyThread::send_list_points, Qt::QueuedConnection);
    return_xy.start_stop_timer(true);
    exec();
}

void MyThread::start_th(){
    if(this->isRunning() == false){
        this->start();
        qDebug() << "поток запущен";
    }else{
        emit pause_th(true);
        qDebug() << "поток снова запущен";

    }
}


void MyThread::stop_th(){
    this->quit();
    qDebug() << "поток остановлен";
}

