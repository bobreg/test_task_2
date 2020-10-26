#include "widget.h"
#include "mythread.h"

#include <QApplication>
Q_DECLARE_METATYPE ( coordinate );

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    MyThread t;

    QApplication::connect(&w, &Widget::start_thread, &t, &MyThread::start_th);
    QApplication::connect(&w, &Widget::pause_thread, &t, &MyThread::pause_th);
    QApplication::connect(&w, &Widget::stop_thread, &t, &MyThread::stop_th);

    QApplication::connect(&t, &MyThread::send_list_points, &w, &Widget::pull_points, Qt::QueuedConnection);
    w.show();
    return a.exec();
}
