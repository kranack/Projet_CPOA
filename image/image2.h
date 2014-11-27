#ifndef IMAGE2_H
#define IMAGE2_H

#include "image.h"
#include "vec2f.h"

template<typename T>
class Image2 : public Image<2,T>
{
protected:

public:
    Image2();
    Image2(T x, T y);
    T &getPixel(const T &x, const T &y) const;
    void setSize(const T &x, const T &y);
};


template<typename T>
Image2<T>::Image2() :
    Image<2,T>()
{

}


template<typename T>
Image2<T>::Image2(T x, T y)
{
    this->setSize(x,y);
}


template<typename T>
T &Image2<T>::getPixel(const T &x, const T &y) const
{
    return this -> m_buffer[x+y*this->m_size[0]];
}


template<typename T>
void Image2<T>::setSize(const T &x, const T &y)
{
    this->m_nbpixels = x * y;
    this->m_size[0] = x;
    this->m_size[1] = y;

    if (this->m_nbpixels)
        this->m_buffer = new T[this->m_nbpixels];
    else
        this->m_buffer = NULL;
}

#endif // IMAGE2_H
