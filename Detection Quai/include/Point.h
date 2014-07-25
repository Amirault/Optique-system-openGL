#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(double valX, double valY, double valZ);   //constructeur
        virtual ~Point();                               //destructeur
        Point(const Point& other);                      //copy

        //Getter / Setter
        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }
        double Getz() { return z; }
        void Setz(double val) { z = val; }

        //Methodes

    protected:

    private:
        double x;
        double y;
        double z;
};

#endif // POINT_H
