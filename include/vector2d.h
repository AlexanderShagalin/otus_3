#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
    double m_x;
    double m_y;
public:
    Vector2D(double x = 0, double y = 0);
    double x() const;
    double y() const;
    friend int operator == (const Vector2D &a1, const Vector2D &a2);
    friend Vector2D operator + (const Vector2D &a1, const Vector2D &a2);
};

#endif // VECTOR2D_H
