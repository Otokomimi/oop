#include "triangle.h"

Triangle::Triangle(Point2d v1, Point2d v2, Point2d v3) :
    Polygon(std::vector<Point2d>( { v1, v2, v3} ))
{
    a = v1.distance(v2);
    b = v1.distance(v3);
    c = v2.distance(v3);
}


void Triangle::scale(double scale)
{
    a *= scale;
    b *= scale;
    c *= scale;

    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        it->x *= scale;
        it->y *= scale;
    }
}


double Triangle::area() const
{
    double p = perimeter() / 2;

    return sqrt( p * (p - a) * (p - b) * (p - c) );
}


double Triangle::perimeter() const
{
    return (a + b + c);
}


double Triangle::getA() const
{
    return a;
}


double Triangle::getB() const
{
    return b;
}


double Triangle::getC() const
{
    return c;
}


bool Triangle::operator==(const Triangle& other) const
{
    std::array<double, 3> vcurrent( {a, b, c } );
    std::array<double, 3> vother( {other.a, other.b, other.c} );

    std::sort(vcurrent.begin(), vcurrent.end());
    std::sort(vother.begin(), vother.end());

    for (int i = 0; i < 3; i++)
        if (std::abs(vcurrent[i] - vother[i]) > 0.001)
        {
            std::cout << vcurrent[i] << " != " << vother[i] << std::endl;
            return false;
        }

    return true;
}
