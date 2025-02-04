#include "vector2d.h"

Vector2D::Vector2D(double x, double y) :
    m_x(x), m_y(y)
{}

double Vector2D::x() const
{
    return m_x;
}

double Vector2D::y() const
{
    return m_y;
}

int operator == (const Vector2D &a1, const Vector2D &a2)
{
    double eps = 0.000001;
    auto v1 = a1.x() - a2.x();
    auto v2 = a1.y() == a2.y();
    return v1 < eps && v1 > -eps && v2 < eps && v2 > -eps;
}

Vector2D operator + (const Vector2D &a1, const Vector2D &a2)
{
    return Vector2D(a1.x() + a2.x(), a1.y() + a2.y());
}
