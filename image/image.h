#ifndef IMAGE_H
#define IMAGE_H

#include "array.h"

template<int D, typename T>
class Image
{
protected:
    T *m_buffer;
    Array<int,D> m_size;
    int m_nbpixels;

public:
    Image();
    Image(const Image &img);
    Image(const Array<int,D> &s);
    ~Image();
    Image &operator =(const Image<D,T> &img);
    void setSize(const Array<int,D>& s);
    T &getPixel(const Array<int,D> &c, const int id) const;
    T *getPtr() const;
};

template<int D, typename T>
Image<D,T>::Image() :
    m_buffer(NULL),
    m_size(0),
    m_nbpixels(0)
{

}


template<int D, typename T>
Image<D,T>::Image(const Image &img) :
    m_buffer(NULL)
{
    *this = img;
}

template<int D, typename T>
Image<D,T>::Image(const Array<int,D> &s) :
    m_buffer(NULL)
{
    this->setSize(s);
}


template<int D, typename T>
Image<D,T>::~Image()
{
    delete[] this->m_buffer;
}


template<int D, typename T>
void Image<D,T>::setSize(const Array<int, D> &s)
{
    m_nbpixels = 1;
    for(int i=0; i<D; ++i)
    {
        m_size[i] = s[i];
        m_nbpixels *= s[i];
    }
    delete[] m_buffer;
    if (m_nbpixels)
        m_buffer = new T[m_nbpixels];
    else
        m_buffer = NULL;
}


template<int D, typename T>
Image<D,T> &Image<D,T>::operator =(const Image<D,T> &img)
{
    m_nbpixels = img.m_nbpixels;
    m_size = img.m_size;
    delete[] m_buffer;

    memcpy(m_buffer, img.m_buffer, m_nbpixels * sizeof(T));

    return *this;
}


template<int D, typename T>
T &Image<D,T>::getPixel(const Array<int,D> &c, const int id) const
{
    int a= 0;
    for (int i=0; i<D; ++i)
    {
        a += c[i] * i+1;
    }
    return this->m_buffer[a];
}


template<int D, typename T>
T *Image<D,T>::getPtr() const
{
    return m_buffer;
}
#endif // IMAGE_H
