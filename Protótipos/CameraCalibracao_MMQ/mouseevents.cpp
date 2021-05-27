#include "mouseevents.h"

using namespace cv;

mouseevents::mouseevents(QWidget *parent) :
     QLabel(parent)
{

}

void mouseevents::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->pos().x();
    this->y = ev->pos().y();
    emit Mouse_pos();

}

void mouseevents::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
        {
            x_press = ev->localPos().x();
            y_press = ev->localPos().y();

            emit Mouse_pressed();

        }
}
