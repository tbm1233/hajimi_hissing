#ifndef SHOW_PIC_H
#define SHOW_PIC_H
#include<QPixmap>
#include <QWidget>

class show_pic : public QWidget
{
    Q_OBJECT
public:
    explicit show_pic(QWidget *parent = nullptr);
    void set_pic(QString normal,QString hover,QString press);
protected:
    void leaveEvent(QEvent *) override;
    void enterEvent(QEnterEvent *) override;
    void paintEvent(QPaintEvent *)override;
    void mousePressEvent(QMouseEvent*)override;
signals:
    void shakeSignal();
private:
    QPixmap normal_Q;
    QPixmap hover_Q;
    QPixmap current;
    QPixmap press_Q;
};

#endif // SHOW_PIC_H
