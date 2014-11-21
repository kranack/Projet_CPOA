#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <fstream>
#include <cassert>


// La declaration de la classe
template <typename T, int N>
class Array
{
protected:
    // on remplace les "float" par des "T"
    T *m_data;
    int m_size;

public:
    Array();

    Array(const Array& vec);

    Array(const T& val);

    ~Array();

    T& operator[](int i);

    T operator[](int i) const;

    bool operator ==(const Array& arr) const;

    bool operator !=(const Array& arr) const;

    /*Array &operator =(const Array arr);*/

    int size();
};


template<typename T, int N>
Array<T,N>::Array():
    m_data(NULL),
    m_size(N)
{
    assert(m_size != 0);
    m_data = new T[N];
}

template<typename T, int N>
Array<T,N>::Array(const T& val):
    m_size(N)
{
    assert(m_size != 0);
    m_data = new T[N];
    for (int i=0; i<N; ++i)
    {
        m_data[i] = val;
    }
}

template<typename T, int N>
Array<T,N>::Array(const Array<T,N>& vec):
    m_size(N)
{
    assert(m_size != 0);
    m_data = new T[N];
    for (int i=0; i<N; i++)
        m_data[i] = vec[i];		// copie les données

}


template<typename T, int N>
Array<T,N>::~Array()
{
    if (m_data!=NULL)
        delete[] m_data;

}


template<typename T, int N>
T& Array<T,N>::operator[](int i)
{
    assert((i>=0)&&(i<N));
    return m_data[i];
}

template<typename T, int N>
T Array<T,N>::operator[](int i) const
{
    assert((i>=0)&&(i<N));
    return m_data[i];
}

template<typename T, int N>
bool Array<T,N>::operator==(const Array<T,N>& arr) const
{
    for(int i=0; i< N; ++i)
        if (m_data[i] != arr[i])
            return false;

    return true;
}


template<typename T, int N>
bool Array<T,N>::operator !=(const Array<T,N>& arr) const
{
    return (*this == arr) ? false : true;
}


/*template<typename T, int N>
Array<T,N> &Array<T,N>::operator =(const Array<T,N> arr)
{
    for (int i=0; i<N; ++i)
    {
        m_data[i] = arr[i];
    }

    return *this;
}*/


template<typename T, int N>
int Array<T,N>::size()
{
    return m_size;
}


template<typename T, int N>
std::ostream& operator << (std::ostream& os, const Array<T,N>& arr)
{
    os << arr[0];
    for(int i=1; i<N;++i)
        os << " " << arr[i];
    return os;
}

template<typename T, int N>
std::istream& operator >> (std::istream& is, Array<T,N>& arr)
{
    for(int i=0; i< N; ++i)
        is >> arr[i];
    return is;
}



#endif // ARRAY_H
