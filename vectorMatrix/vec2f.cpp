#include "vec2f.h"

Vec2f::Vec2f():
    V2F(0.0f)
{
}

float Vec2f::operator *(const Vec2f& vec) const
{
    float res = 0.0f;
    for (int i=0; i<2; ++i)
    {
        res += m_data[i] * vec[i];
    }
    return res;
}
