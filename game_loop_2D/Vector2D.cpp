#include "Vector2D.hpp"

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}
Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}



Vector2D& Vector2D::Add(const Vector2D& v2)
{
    this->x += v2.x;
    this->y += v2.y;
    
    return *this;
}
Vector2D& Vector2D::Substract(const Vector2D& v2)
{
    this->x -= v2.x;
    this->y -= v2.y;
    
    return *this;
}
Vector2D& Vector2D::Multiply(const Vector2D& v2)
{
    this->x *= v2.x;
    this->y *= v2.y;
    
    return *this;
}
Vector2D& Vector2D::Divide(const Vector2D& v2)
{
    this->x /= v2.x;
    this->y /= v2.y;
    
    return *this;
}



Vector2D& operator+(Vector2D& v1,  const Vector2D& v2)
{
    return v1.Add(v2);
}
Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
    return v1.Substract(v2);
}
Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
    return v1.Multiply(v2);
}
Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
    return v1.Divide(v2);
}

Vector2D& Vector2D::operator +=(const Vector2D& v2)
{
    return this->Add(v2);
}
Vector2D& Vector2D::operator -=(const Vector2D& v2)
{
    return this->Substract(v2);
}
Vector2D& Vector2D::operator *=(const Vector2D& v2)
{
    return this->Multiply(v2);
}
Vector2D& Vector2D::operator /=(const Vector2D& v2)
{
    return this->Divide(v2);
}

Vector2D& Vector2D::operator*(const int& i)
{
    this->x *=i;
    this->y *=i;
    return *this;
}
Vector2D& Vector2D:: Zero()
{
    this->x *= 0;
    this->y *= 0;
    
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
    stream << "("<< vec.x << ","<< vec.y << ")";
    return stream;
}
