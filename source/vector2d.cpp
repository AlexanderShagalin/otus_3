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
    return a1.x() == a2.x() && a1.y() == a2.y();
}

Vector2D operator + (const Vector2D &a1, const Vector2D &a2)
{
    return Vector2D(a1.x() + a2.x(), a1.y() + a2.y());
}
