// Autor    Alex Krieg
// Version  00.00.00
// Datum    30.09.2018

#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <QtCore>
#include <vector>
#include <QApplication>
#include <QtGui>
#include <math.h>

#ifndef PI
    #define PI 3.141592653589793238462643383279502884
#endif

namespace geometry {
    class Angle;

    QPoint                  rotate(QPoint point,QPoint rotationPoint,Angle angle);
    std::vector<QPoint>     rotate(std::vector<QPoint> points ,QPoint rotationPoint,Angle angle);
    QPointF                 rotate(QPointF point,QPointF rotationPoint,Angle angle);
    std::vector<QPointF>    rotate(std::vector<QPointF> points ,QPointF rotationPoint,Angle angle);


    class Angle
    {
        public:
            Angle();
            Angle(float degree);
            ~Angle();

            void degree(float deg);
            float degree();
            void rad(float rad);
            float rad();

            Angle& operator=(Angle &angle);
            float operator=(float degree);
            Angle& operator+(Angle &angle);
            float operator+(float degree);
            Angle& operator-(Angle &angle);
            float operator-(float degree);


            static float degToRad(float degree);
            static float radToDeg(float rad);
            static float degAbs(float degree);
            static float radAbs(float rad);

        private:
            float _angle;
    };
}




#endif // GEOMETRY_H
