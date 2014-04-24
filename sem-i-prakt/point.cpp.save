#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    double x,y;

public:

    Point(const double _x=0,const double _y=0):x(_x),y(_y){}

    Point(const Point& p)
    {
        x=p.x;
        y=p.y;
    }

    Point& operator=(const Point& p)
    {
        if(this!=&p)
        {
            x=p.x;
            y=p.y;
        }
        return *this;
    }

    double get_distance(const Point& p) const
    {
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    }

    void write()
    {
        cout<<"("<<x<<","<<y<<")";
    }
};

class Circle
{
    Point O;
    double r;

public:

    Circle(const Point& O,const double r)
    {
        if(r>0)
        {
            this->O=O;
            this->r=r;
        }
        else
            cout<<"ERROR: Invalid radius!"<<endl;
    }

    Circle(const Circle& k)
    {
        O=k.O;
        r=k.r;
    }

    Circle& operator=(const Circle& k)
    {
        if(this!=&k)
        {
            O=k.O;
            r=k.r;
        }
        return *this;
    }

    bool is_point_inside(const Point& p) const
    {
        return O.get_distance(p)<=r;
    }

    void write()
    {
        cout<<"k";
        O.write();
    }
};

class Triangle
{
    double a,b,c;

public:

    Triangle(double a,double b,double c)
    {
        if(a>0 && b>0 && c>0 && a+b>c && b+c>a && a+c>b)
        {
            this->a=a;
            this->b=b;
            this->c=c;
        }
        else
            cout<<"ERROR: Invalid sides or they do not form a triangle!"<<endl;
    }

    Triangle(const Triangle& tr)
    {
        a=tr.a;
        b=tr.b;
        c=tr.c;
    }

    Triangle& operator=(const Triangle& tr)
    {
        a=tr.a;
        b=tr.b;
        c=tr.c;
    }

    double get_perimeter() const
    {
        return a+b+c;
    }

    double get_area() const
    {
        double p=get_perimeter()/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};

int main()
{
    Point p1(0,0),p2(1,1);
    p2=p1;
    p2.operator=(p1);
    p1.write();cout<<endl;
    p2.write();cout<<endl;
}

/*
Point f(Circle c)
{
    Point p(0,0);
    return p;
}

int main()
{
    Circle c(Point(1,2),5);
    Point p=f(c);
    c.write();cout<<endl;
    p.write();cout<<endl;
}
*/
/*
int main()
{
    Point p1(1,2),p2(2,3);
    double d=p1.get_distance(p2);
    cout<<d<<endl;
    Point p3(p1),p4(p2);
    p3.write();
    cout<<endl;
    p4.write();
}
*/
/*
int main()
{
    Point A(2.5,3.4),B(-0.5,-2);
    cout<<"Distance from ";A.write();cout<<" to ";B.write();cout<<" is: "<<A.get_distance(B)<<endl;
    Circle k(Point(0,0),5);
    A.write();cout<<" is"<<(k.is_point_inside(A)?"":" NOT")<<" inside ";k.write();cout<<endl;
    A.write();cout<<" is"<<(k.is_point_inside(Point(2.4,3.5))?"":" NOT")<<" inside ";Point(2.4,3.5).write();cout<<endl;
    Triangle ABC(2,4,5);
    cout<<"The perimeter of the triangle is: "<<ABC.get_perimeter()<<endl;
    cout<<"The area of the triangle is: "<<ABC.get_area()<<endl;

	return 0;
}
*/
