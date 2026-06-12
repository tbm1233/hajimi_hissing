#include "show_pic.h"
#include<QPainter>
#include<QTimer>
show_pic::show_pic(QWidget *parent)
    : QWidget{parent}
{}
void show_pic::enterEvent(QEnterEvent* ev){
    current=hover_Q;
    update();
}
void show_pic::leaveEvent(QEvent* ev){
    current=normal_Q;
    update();
}
void show_pic::paintEvent(QPaintEvent * ev){
    QPainter a(this);
    a.drawPixmap(rect(),current);
}
void show_pic::set_pic(QString normal,QString hover,QString press){
    bool a=normal_Q.load(normal);
    bool b=hover_Q.load(hover);
    bool c=press_Q.load(press);
    current=normal_Q;
    if(a&&b&&c){
        setFixedSize(current.size());
    }else{
        qDebug("load error");
    }
}
void show_pic::mousePressEvent(QMouseEvent * ev){
    current=press_Q;
    repaint();
    emit shakeSignal();
    current=hover_Q;
    update();

}