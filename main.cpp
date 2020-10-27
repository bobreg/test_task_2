#include "widget.h"
#include "mythread.h"

#include <QApplication>
// макрос который делает структуру известной для Qt (позволяет передавать свою структуру между потоками)
// необходимо Qt::QueuedConnection в соединении
Q_DECLARE_METATYPE ( coordinate );


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;  // объект класса окна
    MyThread t; // объект класса управления потоком в котором генерируются точки

    QApplication::connect(&w, &Widget::start_thread, &t, &MyThread::start_th);  // соединения сигналов и слотов управления отображения
    QApplication::connect(&w, &Widget::pause_thread, &t, &MyThread::pause_th);
    QApplication::connect(&w, &Widget::stop_thread, &t, &MyThread::stop_th);
// соединение сигнала и слота для возврата списка координат новых сгенерированных точек
    QApplication::connect(&t, &MyThread::send_list_points, &w, &Widget::pull_points, Qt::QueuedConnection);
    w.show();
    return a.exec();
}
