#ifndef VECTOR_H
#define VECTOR_H

#include "array.h"


template<typename T, int N>
class Vector : public Array<T,N>
{
public:
    Vector();

    Vector(const T& value);

    Vector operator +(const Vector& vec) const;

    Vector operator -(const Vector& vec) const;

    Vector& operator -=(const Vector& v);

    Vector& operator +=(const Vector& v);

    T operator *(Vector& vec) const;
    T operator /(Vector& vec) const;
    Vector &operator *=(T val);
    Vector &operator *=(Vector v);
    Vector &operator /=(T val);
    Vector &operator =(const Vector& v);

    void zero();
    T* data() { return this->m_data; }
};

template<typename T, int N>
Vector<T,N>& operator*(T val, const Vector<T,N>& vec);


template<typename T,int N>
Vector<T,N>::Vector()
{
    Array<T,N>();
}


template<typename T,int N>
Vector<T,N>::Vector(const T& value)
{
    Array<T,N>();
}


template<typename T, int N>
Vector<T,N> Vector<T,N>::operator +(const Vector<T,N>& vec) const
{
    Vector<T,N> vector;
    for (int i=0; i<N; ++i)
    {
        vector[i] = this->m_data[i] + vec[i];
    }
    return vector;
}


template<typename T, int N>
Vector<T,N> Vector<T,N>::operator -(const Vector<T,N>& vec) const
{
    Vector<T,N> vector;
    for (int i=0; i<N; ++i)
    {
        vector[i] = this->m_data[i] - vec[i];
    }
    return vector;
}


template<typename T, int N>
Vector<T,N>& Vector<T,N>::operator -=(const Vector<T,N>& v)
{
    for(int i=0; i<N; ++i)
    {
        this[i] = this->m_data[i] - v[i];
    }
    return *this;
}


template<typename T, int N>
Vector<T,N>& Vector<T,N>::operator +=(const Vector<T,N>& v)
{
    for(int i=0; i<N; ++i)
    {
        this->m_data[i] = this->m_data[i] + v[i];
    }
    return *this;
}


template<typename T, int N>
T Vector<T,N>::operator *(Vector<T,N>& vec) const
{
    T res;
    for (int i=0; i<N; ++i)
    {
        res += this->m_data[i] * vec[i];
    }
    return res;
}

template<typename T, int N>
T Vector<T,N>::operator /(Vector<T,N>& vec) const
{
    T res;
    for (int i=0; i<N; ++i)
    {
        res += this->m_data[i] / vec[i];
    }
    return res;
}


template<typename T, int N>
Vector<T,N>& Vector<T,N>::operator *=(T val)
{
    for (int i=0; i<N; ++i)
    {
        this->m_data[i] *= val;
    }

    return *this;
}


template<typename T, int N>
Vector<T,N> &Vector<T,N>::operator *=(Vector<T,N> v)
{
    for (int i=0; i<N; ++i)
    {
        this->m_data[i] *= v[i];
    }

    return *this;
}


template<typename T,int N>
Vector<T,N>& Vector<T,N>::operator /=(T val)
{
    for (int i=0; i<N; ++i)
    {
        this->m_data[i] /= val;
    }

    return *this;
}


template<typename T,int N>
Vector<T,N> &Vector<T,N>::operator =(const Vector<T,N> &v)
{
    for (int i=0; i<N; ++i)
    {
        this->m_data[i] = v[i];
    }

    return *this;
}


template<typename T, int N>
Vector<T,N>& operator*(T val, const Vector<T,N>& vec)
{
    Vector<T,N> res;
    for (int i=0; i<N; ++i)
    {
        res[i] += vec[i] * val;
    }
    return res;
}


template<typename T,int N>
void Vector<T,N>::zero()
{
    for (int i=0; i<N; ++i)
    {
        this->m_data[i] = 0.0;
    }
}

#endif // VECTOR_H
