// Autor    Alex Krieg
// Version  00.00.00
// Datum    30.09.2018

#include "geometry.h"

QPoint geometry::rotate(QPoint point,QPoint rotationPoint,Angle angle)
{
    point.setX(cos(angle.rad())*(point.x()-rotationPoint.x())-sin(angle.rad())*(point.y()-rotationPoint.y())+rotationPoint.x());
    point.setY(sin(angle.rad())*(point.x()-rotationPoint.x())+cos(angle.rad())*(point.y()-rotationPoint.y())+rotationPoint.y());
    return point;
}
std::vector<QPoint> geometry::rotate(std::vector<QPoint> points ,QPoint rotationPoint,Angle angle)
{
    for(int a=0; a<points.size(); a++)
    {
        points[a] = rotate(points[a],rotationPoint,angle);
    }
    return points;
}
QPointF geometry::rotate(QPointF point,QPointF rotationPoint,Angle angle)
{
    point.setX(cos(angle.rad())*(point.x()-rotationPoint.x())-sin(angle.rad())*(point.y()-rotationPoint.y())+rotationPoint.x());
    point.setY(sin(angle.rad())*(point.x()-rotationPoint.x())+cos(angle.rad())*(point.y()-rotationPoint.y())+rotationPoint.y());
    return point;
}
std::vector<QPointF> geometry::rotate(std::vector<QPointF> points ,QPointF rotationPoint,Angle angle)
{
    for(int a=0; a<points.size(); a++)
    {
        points[a] = rotate(points[a],rotationPoint,angle);
    }
    return points;
}

//-------------------------ANGLE------------------
geometry::Angle::Angle()
{
    this->degree(0);
}
geometry::Angle::Angle(float degree)
{
    this->degree(degree);
}
geometry::Angle::~Angle()
{

}
void geometry::Angle::degree(float deg)
{
    _angle = degAbs(deg);
}
float geometry::Angle::degree()
{
    return _angle;
}
void geometry::Angle::rad(float rad)
{
    _angle = radToDeg(radAbs(rad));
}
float geometry::Angle::rad()
{
    return degToRad(_angle);
}
geometry::Angle& geometry::Angle::operator=(Angle &angle)
{
    degree(angle.degree());
    return *this;
}
float geometry::Angle::operator=(float degree)
{
    this->degree(degree);
}
geometry::Angle& geometry::Angle::operator+(Angle &angle)
{
    degree(_angle + angle.degree());
    return *this;
}
float geometry::Angle::operator+(float degree)
{
    this->degree(_angle + degree);
}
geometry::Angle& geometry::Angle::operator-(Angle &angle)
{
    degree(_angle - angle.degree());
    return *this;
}
float geometry::Angle::operator-(float degree)
{
    this->degree(_angle - degree);
}
float geometry::Angle::degToRad(float degree)
{
    return PI * degAbs(degree)/180;
}
float geometry::Angle::radToDeg(float rad)
{
    return radAbs(rad) * 180/PI;
}
float geometry::Angle::degAbs(float degree)
{
    degree = (float)((int)degree%360 + degree - (int)degree);
    if(degree < 0)
    {
        degree+= 360;
    }
    return degree;
}
float geometry::Angle::radAbs(float rad)
{
    rad = ((float)((int)(rad*1000)%(int)(PI*1000) + rad*1000 - (int)(rad*1000)))/1000;
    if(rad < 0)
    {
        rad+= 2*PI;
    }
    return rad;
}
