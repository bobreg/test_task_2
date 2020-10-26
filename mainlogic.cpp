#include "mainlogic.h"

MainLogic::MainLogic(QObject *parent) : QObject(parent)
{
    qRegisterMetaType <coordinate> ( "coordinate" ) ;
    connect(timer, &QTimer::timeout, this, &MainLogic::my_rand);
}

MainLogic::~MainLogic(){
    delete timer;
}


void MainLogic::my_rand(){
    QVector <coordinate> points;
    coordinate temp;
    for(int i = 0; i < 10; i++){
        temp.x = rand() % 20;
        temp.y = rand() % 20;
        points.append(temp);
    }
    /*
    for(auto i: points){
        qDebug() << i.x << i.y;
    }
    */
    emit send_list_points((&points)[0]);
}

void MainLogic::start_stop_timer(bool flag = true){
    if(flag == true){
        timer->start(1000);
    }else{
        qDebug() << "поток приостановлен";
        timer->stop();
    }
}
