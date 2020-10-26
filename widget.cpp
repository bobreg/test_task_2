#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tx.setText("X");
    ty.setText("Y");
    my_graph.addItem(&tx);
    my_graph.addItem(&ty);
    tx.setX(10);
    tx.setY(10);
    ty.setX(670);
    ty.setY(430);

    ui->graphicsView->setScene(&my_graph);



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    emit start_thread();

}

void Widget::on_pushButton_2_clicked()
{
    emit pause_thread(false);
}

void Widget::on_pushButton_3_clicked()
{
    emit stop_thread();
}


void Widget::pull_points(const QVector <coordinate> & points){
    for(auto i: points){
        qDebug() << i.x << i.y;
        // нужно сделать корректное завершение программы
    }
}
