#include "widget.h"
#include "ui_widget.h"
#include "show_pic.h"
#include <qThread>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    show_pic * maodie=new show_pic(this);
    maodie->set_pic(":/pic/normal.jpg",":/pic/ready.jpg",":/pic/ha.jpg");
    maodie->show();
    connect(maodie,&show_pic::shakeSignal,this,&Widget::shake);
    setFixedSize(maodie->size());
}
void Widget::shake(){
    for(int i=0;i<5;i++){
        shakeStep(20,20);
        shakeStep(-20,-20);
    }
    qDebug("signal sent");
}
void Widget::shakeStep(int x,int y){
    move(this->pos().x()+x,this->pos().y()+y);
    update();
    QThread::msleep(50);
}
Widget::~Widget()
{
    delete ui;
}
