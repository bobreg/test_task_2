#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    flag_pause = false;

// установим в графическом виджете элементы осей координат
    tx.setText("X");
    ty.setText("Y");
    tx.setX(10);
    tx.setY(10);
    ty.setX(670);
    ty.setY(430);

    line_x.setLine(10, 40, 10, 440);
    line_x1.setLine(10, 40, 15, 50);
    line_x2.setLine(10, 40, 5, 50);
    line_x.setPen(QPen(Qt::black, 2));
    line_x1.setPen(QPen(Qt::black, 2));
    line_x2.setPen(QPen(Qt::black, 2));
    line_y.setLine(10, 440, 650, 440);
    line_y1.setLine(650, 440, 640, 445);
    line_y2.setLine(650, 440, 640, 435);
    line_y.setPen(QPen(Qt::black, 2));
    line_y1.setPen(QPen(Qt::black, 2));
    line_y2.setPen(QPen(Qt::black, 2));
    my_graph.addItem(&tx);
    my_graph.addItem(&ty);
    my_graph.addItem(&line_x);
    my_graph.addItem(&line_x1);
    my_graph.addItem(&line_x2);
    my_graph.addItem(&line_y);
    my_graph.addItem(&line_y1);
    my_graph.addItem(&line_y2);

// проинициализируем массив точек для последующего включения в графический виджет
    for(int i = 0; i < COUNT_POINTS; i++){
        points.append(new QGraphicsSimpleTextItem("*"));
        points[i]->setFont(QFont("\"Times\", 20, QFont::Bold"));
    }
// отобразим графический виджет в графическом элементе окна
    ui->graphicsView->setScene(&my_graph);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()  // старт
{
    // добавим массив точек в графический виджет для отображения
    if(flag_pause == false){
        for(int i = 0; i < COUNT_POINTS; i++){
            my_graph.addItem(points[i]);
        }
    }
    // перенастроим кнопки
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    emit start_thread();

}

void Widget::on_pushButton_2_clicked()  // пауза
{
    flag_pause = true;
    ui->pushButton->setEnabled(true);
    emit pause_thread(false); // пошлём сигнал паузы в поток
}

void Widget::on_pushButton_3_clicked()  // стоп
{
    flag_pause = false;
    // удалим из графического виджета элементы точек
    for(int i = 0; i < COUNT_POINTS; i++){
        my_graph.removeItem(points[i]);
    }
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    emit stop_thread(); // оправим сигнал остановки потока

}


void Widget::pull_points(const QVector <coordinate> & incoming_points){
// для новых коосдинат из пришедщего списка установим новые координаты точек
    for(int i = 0; i < COUNT_POINTS; i++){
        points[i]->setX(incoming_points[i].x);
        points[i]->setY(incoming_points[i].y);
    }
// обновим графический виджет
    my_graph.update(0, 0 , 700, 450);
}

void Widget::closeEvent(QCloseEvent *event){
    Q_UNUSED(event);
    emit stop_thread();
}
