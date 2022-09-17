#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

template<typename T>
class Vector2D
{
private:
    T m_X, m_Y;

private:
    Vector2D<T> &Add(const Vector2D<T> &p_Vec)
    {
        this->m_X += p_Vec.m_X;
        this->m_Y += p_Vec.m_Y;
        return this;
    }
    Vector2D<T> &Subtract(const Vector2D<T> &p_Vec)
    {
        this->m_X -= p_Vec.m_X;
        this->m_Y -= p_Vec.m_Y;
        return this;
    }
    Vector2D<T> &Multiply(int p_Scale)
    {
        this->m_X *= p_Scale;
        this->m_Y *= p_Scale;
        return this;
    }
    Vector2D<T> &Devide(int p_Scale)
    {
        this->m_X /= p_Scale;
        this->m_Y /= p_Scale;
        return this;
    }
public:
    Vector2D(): m_X(0), m_Y(0){}
    Vector2D(T p_X, T p_Y): m_X(p_X), m_Y(p_Y){}

    friend Vector2D<T>&operator+(const Vector2D<T> &p_Vec1, const Vector2D<T> &p_Vec2)
    {
        return p_Vec1.Add(p_Vec2);
    }
    friend Vector2D<T>&operator-(const Vector2D<T> &p_Vec1, const Vector2D<T> &p_Vec2)
    {
        return p_Vec1.Subtract(p_Vec2);
    }
    friend Vector2D<T>&operator*(const Vector2D<T> &p_Vec, int p_Scale)
    {
        return p_Vec.Multiply(p_Scale);
    }
    friend Vector2D<T>&operator/(const Vector2D<T> &p_Vec, int p_Scale)
    {
        return p_Vec.Devide(p_Scale);
    }

    Vector2D<T>&operator+=(const Vector2D<T> &p_Vec)
    {
        return this->Add(p_Vec);
    }
    Vector2D<T>&operator-=(const Vector2D<T> &p_Vec)
    {
        return this->Subtract(p_Vec);
    }
    Vector2D<T>&operator*=(int p_Scale)
    {
        return this->Multiply(p_Scale);
    }
    Vector2D<T>&operator/=(int p_Scale)
    {
        return this->Devide(p_Scale);
    }

    Vector2D<T> &Ones()
    {
        this->m_X = static_cast<T>(1);
        this->m_Y = static_cast<T>(1);
    }

    Vector2D<T> &Zeros()
    {
        this->m_X = static_cast<T>(0);
        this->m_Y = static_cast<T>(0);
    }

    inline const T &getX() const
    {
        return m_X;
    }

    inline const T &getY() const
    {
        return m_Y;
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector2D<T> &vec)
    {
        out << "(" << vec.m_X << "," << vec.m_Y << ")";
        return out;
    }
    void printXY()
    {
        std::cout << m_X << ", " << m_Y << std::endl;
    }
    const T &X() const;
    const T &Y() const;
};


using d_Vector2D = Vector2D<int>;
using f_Vector2D = Vector2D<float>;
using lf_Vector2D = Vector2D<double>;

#endif // VECTOR2D_H
